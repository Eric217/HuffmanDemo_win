#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <map>
#include <QCloseEvent>
#include <QScrollArea>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QScrollArea * scroll;
    void drawTree();
    QPoint *getLocations();

private:
    Ui::MainWindow *ui;

private slots:
    void receivelogin();//与display中发射的信号相关联的槽函数
    void on_toolButton_clicked();//与back的click()关联的槽函数
    void on_btnDown_1_clicked();//与下载按钮相关的槽函数
    void on_btnDown_2_clicked();

signals:
    void dlgshow();//显示code对话框信号
};

#endif // MAINWINDOW_H
