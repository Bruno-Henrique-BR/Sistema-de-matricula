#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(!pessCont.iniciaBanco()){
        qDebug()<<"Banco não iniciado";
        return;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_cadastrar_clicked()
{
    ccp.setModal(true);
    ccp.exec();
}

void MainWindow::on_btn_procurar_clicked()
{
    fpp.setModal(true);
    fpp.exec();
}

void MainWindow::on_btn_listar_clicked()
{
    flp.setModal(true);
    flp.exec();
}

void MainWindow::on_btn_cadastro_disciplina_clicked()
{
    ccd.setModal(true);
    ccd.exec();
}

void MainWindow::on_pushButton_clicked()
{
    cca.setModal(true);
    cca.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    fpa.setModal(true);
    fpa.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    fla.setModal(true);
    fla.exec();
}

void MainWindow::on_btn_excluir_clicked()
{
    fep.setModal(true);
    fep.exec();
}

void MainWindow::on_btn_listar_disciplina_clicked()
{
    fld.setModal(true);
    fld.exec();
}

void MainWindow::on_btn_procurar_disciplina_clicked()
{
    fpd.setModal(true);
    fpd.exec();
}

void MainWindow::on_btn_excluir_disciplina_clicked()
{
    fed.setModal(true);
    fed.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    fea.setModal(true);
    fea.exec();
}
