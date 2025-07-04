#include "comp.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "model.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , M1(new COMP<comp>())
    , M2(new COMP<comp>())
    , M3(new COMP<comp>())
    , K1(new COMP<bag>())
    , K2(new COMP<bag>())
    , K3(new COMP<bag>())
    , MM1(new objModel1())
    , MM2(new objModel1())
    , MM3(new objModel1())
    , MK1(new objModel2())
    , MK2(new objModel2())
    , MK3(new objModel2())

{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui, M1, M2, M3, K1, K2, K3;
}


void MainWindow::on_button_1_clicked()
{
    QFile f1("comp1.txt");
    QFile f2("comp2.txt");
    f1.open(QIODevice::ReadOnly);
    f2.open(QIODevice::ReadOnly);
    QTextStream p1(&f1);
    QTextStream p2(&f2);
    p1 >> *M1;
    p2 >> *M2;
    f1.close();
    f2.close();
    MM1->setModel(M1);
    MM2->setModel(M2);
    ui->tableView_1->setModel(MM1);
    ui->tableView_1->resizeColumnsToContents();
    ui->tableView_2->setModel(MM2);
    ui->tableView_2->resizeColumnsToContents();
}


void MainWindow::on_button_2_clicked()
{
    QFile f1("bag1.txt");
    QFile f2("bag2.txt");
    f1.open(QIODevice::ReadOnly);
    f2.open(QIODevice::ReadOnly);
    QTextStream p1(&f1);
    QTextStream p2(&f2);
    p1 >> *K1;
    p2 >> *K2;
    f1.close();
    f2.close();
    MK1->setModel(K1);
    MK2->setModel(K2);
    ui->tableView_4->setModel(MK1);
    ui->tableView_4->resizeColumnsToContents();
    ui->tableView_5->setModel(MK2);
    ui->tableView_5->resizeColumnsToContents();
}


void MainWindow::on_button_3_clicked()
{
    *M3 = *M1 + *M2;
    MM3->setModel(M3);
    ui->tableView_3->setModel(MM3);
    ui->tableView_3->resizeColumnsToContents();
}



void MainWindow::on_button_4_clicked()
{
    *K3 = *K1 + *K2;
    MK3->setModel(K3);
    ui->tableView_6->setModel(MK3);
    ui->tableView_6->resizeColumnsToContents();
}


void MainWindow::on_button_5_clicked()
{
    M3->reverse_sort();
    MM3->setModel(M3);
    ui->tableView_7->setModel(MM3);
    ui->tableView_7->resizeColumnsToContents();
}


void MainWindow::on_button_6_clicked()
{
    M3->sect_sort();
    MM3->setModel(M3);
    ui->tableView_7->setModel(MM3);
    ui->tableView_7->resizeColumnsToContents();
}


void MainWindow::on_button_7_clicked()
{
    K3->sort();
    M3->sort();
}


void MainWindow::on_button_8_clicked()
{
    QString what = ui->lineEdit->text();
    QString where = ui->lineEdit_2->text();


    if (where == "comp") {
        COMP<comp> temp;
        objModel1 *Mtemp;
        temp = M3->findItem(what);
        Mtemp->setModel(&temp);
        ui->tableView_7->setModel(Mtemp);
        ui->tableView_7->resizeColumnsToContents();
    } else if (where == "bag") {
        COMP<bag> temp;
        objModel2 *Mtemp;
        temp = K3->findItem(what);
        Mtemp->setModel(&temp);
        ui->tableView_7->setModel(Mtemp);
        ui->tableView_7->resizeColumnsToContents();
    } else {

    }


}

