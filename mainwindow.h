#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "comp.h"
#include "model.h"
#include <QMainWindow>
#include <QTableWidget>
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
    void on_button_1_clicked();

    void on_button_2_clicked();

    void on_button_3_clicked();


    void on_button_4_clicked();

    void on_button_5_clicked();

    void on_button_6_clicked();

    void on_button_7_clicked();

    void on_button_8_clicked();

private:
    Ui::MainWindow *ui;
    COMP<comp>*M1,*M2,*M3;
    COMP<bag>*K1,*K2,*K3;
    objModel1 *MM1, *MM2, *MM3;
    objModel2 *MK1, *MK2, *MK3;
};
#endif // MAINWINDOW_H
