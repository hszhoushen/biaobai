#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

#include <QTime>
#define hername "Rui"
#define myname "我是LG"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->labelflower->show();
    ui->labelhername->setText(hername);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
    setFixedSize(this->width(),this->height());                     // 禁止拖动窗口大小
    setWindowTitle(myname);
    setWindowIcon(QIcon("./res/icon.jpg"));
 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnYes_clicked()
{
    static int cnt = 0;
    QMessageBox msgBox;

    if(cnt == 0)
    {
        msgBox.information(NULL, QString(hername), QString("往后余生，风雪是你~"));
        cnt++;
    }
    else if(cnt == 1){
        msgBox.information(NULL, QString(hername), QString("么么哒~"));
        cnt++;
    }
    else if(cnt == 2){
        msgBox.information(NULL, QString(hername), QString("爱你哦宝宝~"));
        cnt = 0;
        flag = 1;
        qDebug() << flag;
    }


}

void MainWindow::on_btnNo_clicked()
{
    static int cnt = 0;
    QMessageBox msgBox;

    if(cnt == 0)
    {
        msgBox.information(NULL, QString(hername), QString("要乖哦~"));
        //msgBox.setText("房子写你名字");
        //msgBox.exec();
        cnt++;
    }
    else if(cnt==1){
        msgBox.information(NULL, QString(hername), QString("么么哒~"));
        // msgBox.setText("我");
        //msgBox.exec();
        cnt++;
    }
    else if(cnt==2){
        msgBox.information(NULL, QString(hername), QString("抱起来么么哒！"));
        //msgBox.exec();
        cnt++;
    }
    else if(cnt==3){
        msgBox.information(NULL, QString(hername), QString("你赶快答应哦！！"));
        cnt = 0;
    }
}

void sleep(unsigned int msec)
{
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

// 重写closeEvent: 确认退出对话框
void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton button;
    button=QMessageBox::question(this,tr(hername),QString(tr("你要做我女朋友吗？")),QMessageBox::Yes|QMessageBox::No);
    if(button==QMessageBox::No)
    {
        qDebug() << flag;
        event->ignore(); // 忽略退出信号，程序继续进行
    }
    else if(button==QMessageBox::Yes && flag == 0)
    {
        qDebug() << flag;
        event->ignore(); // 接受退出信号，程序退出
    }
    else if(button==QMessageBox::Yes && flag == 1)
    {
        qDebug() << flag;
        sleep(1000);
        event->accept();
    }
}
