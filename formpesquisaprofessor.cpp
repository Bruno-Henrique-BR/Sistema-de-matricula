#include "formpesquisaprofessor.h"
#include "ui_formpesquisaprofessor.h"

#include <QtSql>
#include <QMessageBox>

formpesquisaprofessor::formpesquisaprofessor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formpesquisaprofessor)
{
    pessCont.iniciaBanco();
    ui->setupUi(this);
    formatarTableWidget();
}

formpesquisaprofessor::~formpesquisaprofessor()
{
    delete ui;
}

void formpesquisaprofessor::on_btn_pesquisa_clicked()
{
    ui->tableWidget->removeRow(0);
    QString cpf = ui->cpf_pesquisa->text();
    if(!pessModel.validaCPF(cpf)){
        QMessageBox::warning(this, "Informação", "CPF Inválido, favor digite novamente");
        ui->cpf_pesquisa->clear();
        ui->cpf_pesquisa->setFocus();
    } else {
        QSqlQuery pesquisa = profCont.pesquisaProfessorCPF(cpf);
        if(pesquisa.exec()){
            pesquisa.next();
            if(!pesquisa.value(0).isNull()){
                ui->tableWidget->insertRow(0);
                ui->tableWidget->setItem(0, 0, new QTableWidgetItem(pesquisa.value(0).toString()));
                ui->tableWidget->setItem(0, 1, new QTableWidgetItem(pesquisa.value(1).toString()));
                ui->tableWidget->setItem(0, 2, new QTableWidgetItem(pesquisa.value(2).toString()));
                ui->tableWidget->setItem(0, 3, new QTableWidgetItem(pesquisa.value(3).toString()));
            } else {
                QMessageBox::warning(this, "Informação", "CPF não encontrado! Favor realizar cadastro do professor");
                ui->cpf_pesquisa->clear();
                ui->cpf_pesquisa->setFocus();
            }
            formatarTableWidget();
        } else {
            QMessageBox::warning(this, "Informação", "Não foi possível realizar a busca");
            ui->cpf_pesquisa->clear();
            ui->cpf_pesquisa->setFocus();
        }
    }
}

void formpesquisaprofessor::formatarTableWidget(){
    ui->tableWidget->setColumnCount(4);
    QStringList cabecalho = {"CPF", "Nome", "Titulação", "Graduação"};
    ui->tableWidget->setHorizontalHeaderLabels(cabecalho);
    ui->tableWidget->setRowHeight(0, 25);
    ui->tableWidget->setColumnWidth(0, 150);
    ui->tableWidget->setColumnWidth(1, 283);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->setVisible(false);
}
