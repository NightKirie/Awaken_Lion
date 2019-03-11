#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(button_pressed()));
    connect(this, SIGNAL(reach_max()), this, SLOT(reach_max_slot()));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout_print()));
    timer->start(2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    ui->progressBar->setValue(ui->progressBar->value() + 5);
}

void MainWindow::on_minusButton_clicked()
{
    ui->progressBar->setValue(ui->progressBar->value() - 5);
    this->button_pressed();
}

void MainWindow::button_pressed()
{
    qDebug() << ui->progressBar->value();
    if(ui->progressBar->value() >= 100)
        emit reach_max();
}

void MainWindow::reach_max_slot()
{
    qDebug() << "Reach max value!";
}

void MainWindow::on_upButton_clicked()
{
    ui->progressBar->setGeometry(ui->progressBar->x(), ui->progressBar->y()-5, ui->progressBar->width(), ui->progressBar->height());
    //ui->progressBar->move(ui->progressBar->x(),ui->progressBar->y()-5);
}

void MainWindow::on_rightButton_clicked()
{
    ui->progressBar->setGeometry(ui->progressBar->x()+5, ui->progressBar->y(), ui->progressBar->width(), ui->progressBar->height());

}

void MainWindow::on_leftButton_clicked()
{
    ui->progressBar->setGeometry(ui->progressBar->x()-5, ui->progressBar->y(), ui->progressBar->width(), ui->progressBar->height());

}

void MainWindow::on_downButton_clicked()
{
    ui->progressBar->setGeometry(ui->progressBar->x(), ui->progressBar->y()+5, ui->progressBar->width(), ui->progressBar->height());

}

void MainWindow::timeout_print()
{
    qDebug() << "time out!";
}

void MainWindow::on_startButton_clicked()
{
    timer->start(2000);
}

void MainWindow::on_stopButton_clicked()
{
    timer->stop();

}
