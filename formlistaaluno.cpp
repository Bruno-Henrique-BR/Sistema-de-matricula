#include "formlistaaluno.h"
#include "ui_formlistaaluno.h"
#include <QtSql>
#include <QMessageBox>

formlistaaluno::formlistaaluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formlistaaluno)
{
    ui->setupUi(this);
    formatarTableWidget();
    atualizaDados();
}

formlistaaluno::~formlistaaluno()
{
    delete ui;
}

void formlistaaluno::on_pushButton_clicked()
{
    ui->tableWidget->reset();
    atualizaDados();
}

void formlistaaluno::formatarTableWidget(){
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

void formlistaaluno::atualizaDados(){
    apagarLista();
    QSqlQuery query = alCont.pesquisaTodosAlunos();
    if(query.exec()){
        int linha = 0;
        while(query.next()){
            ui->tableWidget->insertRow(linha);
            ui->tableWidget->setItem(linha, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget->setItem(linha, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget->setItem(linha, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget->setItem(linha, 3, new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget->setItem(linha, 4, new QTableWidgetItem(query.value(4).toString()));
            linha++;
        }
        formatarTableWidget();
    } else {
        QMessageBox::warning(this, "Informação", "Não foi possível realizar a busca!!");
    }
}

void formlistaaluno::apagarLista(){
    int aux = alCont.totalAlunos();
    int i = 0;
    do {
        ui->tableWidget->removeRow(i);
        ui->tableWidget->removeRow(0);
        ui->tableWidget->removeRow(1);
        i++;
    } while(i < aux);
}
