#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void button_pressed();
    void reach_max_slot();

private slots:
    void on_addButton_clicked();
    void on_minusButton_clicked();

    void on_upButton_clicked();

    void on_rightButton_clicked();

    void on_leftButton_clicked();

    void on_downButton_clicked();
    void timeout_print();

    void on_startButton_clicked();

    void on_stopButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;

signals:
    void reach_max();
};

#endif // MAINWINDOW_H
