#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int flag = 0;
protected:
    void closeEvent(QCloseEvent *event);
private slots:
    void on_btnYes_clicked();
    void on_btnNo_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
