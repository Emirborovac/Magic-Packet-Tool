#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QUdpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QDateTime>
#include <QThread>

// Worker class to handle the listening in a separate thread
class ListenerWorker : public QObject {
    Q_OBJECT

public:
    ListenerWorker(QObject *parent = nullptr) : QObject(parent) {}

    void setPort(int p) { port = p; }  // Set the port

public slots:
    void doWork() {
        QUdpSocket udpSocket;
        if (!udpSocket.bind(port, QUdpSocket::ShareAddress)) {
            emit logMessage("Error: Failed to bind to port " + QString::number(port) + ".");
            return;
        }

        emit logMessage("Listening for magic packets on port " + QString::number(port) + "...");

        while (true) {
            if (udpSocket.waitForReadyRead(5000)) {
                QByteArray datagram;
                datagram.resize(udpSocket.pendingDatagramSize());
                udpSocket.readDatagram(datagram.data(), datagram.size());

                if (datagram.startsWith(QByteArray(6, 0xFF))) {
                    QString receivedMac = datagram.mid(6, 6).toHex(':');
                    emit logMessage("Magic packet received from MAC: " + receivedMac);
                    break;
                } else {
                    emit logMessage("Received non-magic packet.");
                }
            }
        }
    }

signals:
    void logMessage(const QString &message);

private:
    int port;  // Store the port number
};

// MainWindow implementation
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Magic Packet Tool");  // Set the window title
    setWindowIcon(QIcon(":/icon.ico"));   // Set the window icon from the resource file
}


MainWindow::~MainWindow()
{
    delete ui;
}

// Function to log messages in the QTextEdit
void MainWindow::logMessage(const QString &message) {
    QString timestamp = QDateTime::currentDateTime().toString("[yyyy-MM-dd HH:mm:ss] ");
    ui->textEditOutput->append(timestamp + message);  // Append the message with a timestamp
}

void MainWindow::on_Sendpacket_clicked()
{
    QString mac = ui->lineEdit->text().trimmed();  // Get MAC address from input
    mac.remove(':').remove('-');
    if (mac.length() != 12) {
        logMessage("Error: Invalid MAC address format.");
        return;
    }

    QByteArray packet;
    packet.fill(0xFF, 6);
    for (int i = 0; i < 16; ++i)
        packet.append(QByteArray::fromHex(mac.toUtf8()));

    int port = ui->comboBox->currentText().toInt();  // Get the selected port from the combo box

    QUdpSocket udpSocket;
    udpSocket.writeDatagram(packet, QHostAddress::Broadcast, port);

    logMessage("Magic packet sent to " + mac + " on port " + QString::number(port));
}

void MainWindow::on_Listen_clicked()
{
    int port = ui->comboBox->currentText().toInt();  // Get the selected port from the combo box

    QThread *thread = new QThread;
    ListenerWorker *worker = new ListenerWorker();

    worker->setPort(port);  // Set the selected port in the worker

    worker->moveToThread(thread);

    connect(worker, &ListenerWorker::logMessage, this, &MainWindow::logMessage);
    connect(thread, &QThread::started, worker, &ListenerWorker::doWork);
    connect(worker, &ListenerWorker::logMessage, thread, &QThread::quit);
    connect(worker, &ListenerWorker::logMessage, worker, &ListenerWorker::deleteLater);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}

#include "mainwindow.moc"
