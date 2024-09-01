#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Sendpacket_clicked();
    void on_Listen_clicked();

private:
    Ui::MainWindow *ui;

    void logMessage(const QString &message);

    int getSelectedPort();  // New method to get the selected port
};

#endif // MAINWINDOW_H
