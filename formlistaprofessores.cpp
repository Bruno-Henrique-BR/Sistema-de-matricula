#include "formlistaprofessores.h"
#include "ui_formlistaprofessores.h"

#include <QtSql>
#include <QMessageBox>

formlistaprofessores::formlistaprofessores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formlistaprofessores)
{
    ui->setupUi(this);
    formatarTableWidget();
    atualizaDados();
}

formlistaprofessores::~formlistaprofessores()
{
    delete ui;
}

void formlistaprofessores::atualizaDados(){
    apagarLista();
    QSqlQuery query = profCont.pesquisaTodosProfessores();
    if(query.exec()){
        int linha = 0;
        while(query.next()){
            ui->tableWidget->insertRow(linha);
            ui->tableWidget->setItem(linha, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget->setItem(linha, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(linha, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget->setItem(linha, 3, new QTableWidgetItem(query.value(3).toString()));
            linha++;
        }
        formatarTableWidget();
    } else {
        QMessageBox::warning(this, "Informação", "Não foi possível realizar a busca!!");
    }
}

void formlistaprofessores::formatarTableWidget(){
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


void formlistaprofessores::on_pushButton_clicked()
{
    ui->tableWidget->reset();
    atualizaDados();
}

void formlistaprofessores::apagarLista(){
    int aux = profCont.totalProfessores();
    int i = 0;
    do {
        ui->tableWidget->removeRow(i);
        ui->tableWidget->removeRow(0);
        ui->tableWidget->removeRow(1);
        i++;
    } while(i < aux);
}
