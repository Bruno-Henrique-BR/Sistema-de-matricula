#include "formpesquisaaluno.h"
#include "ui_formpesquisaaluno.h"

#include <QMessageBox>
#include <QtSql>

formpesquisaaluno::formpesquisaaluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formpesquisaaluno)
{
    pessCont.iniciaBanco();
    ui->setupUi(this);
    formatarTableWidget();
}

formpesquisaaluno::~formpesquisaaluno()
{
    delete ui;
}

void formpesquisaaluno::on_btn_pesquisa_clicked()
{
    ui->tableWidget->removeRow(0);
    QString matricula = ui->matricula_pesquisa->text();

    QSqlQuery pesquisa = aluCont.pesquisaMatricula(matricula);
    if(pesquisa.exec()){
        pesquisa.next();
        if(!pesquisa.value(0).isNull()){
            ui->tableWidget->insertRow(0);
            ui->tableWidget->setItem(0, 0, new QTableWidgetItem(pesquisa.value(0).toString()));
            ui->tableWidget->setItem(0, 1, new QTableWidgetItem(pesquisa.value(1).toString()));
            ui->tableWidget->setItem(0, 2, new QTableWidgetItem(pesquisa.value(2).toString()));
            ui->tableWidget->setItem(0, 3, new QTableWidgetItem(pesquisa.value(3).toString()));
            ui->tableWidget->setItem(0, 4, new QTableWidgetItem(pesquisa.value(4).toString()));
        } else {
            QMessageBox::warning(this, "Informação", "Matrícula não encontrada!");
            ui->matricula_pesquisa->clear();
            ui->matricula_pesquisa->setFocus();
        }
        formatarTableWidget();
    } else {
        QMessageBox::warning(this, "Informação", "Não foi possível realizar a busca");
        ui->matricula_pesquisa->clear();
        ui->matricula_pesquisa->setFocus();
    }

}

void formpesquisaaluno::formatarTableWidget(){
    ui->tableWidget->setColumnCount(5);
    QStringList cabecalho = {"Matrícula", "CPF", "Nome", "ID Curso", "Ano Letivo"};
    ui->tableWidget->setHorizontalHeaderLabels(cabecalho);
    ui->tableWidget->setRowHeight(0, 25);
    ui->tableWidget->setColumnWidth(0, 100);
    ui->tableWidget->setColumnWidth(1, 150);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->setVisible(false);
}
