#include "formlistadisciplina.h"
#include "ui_formlistadisciplina.h"

#include <QMessageBox>

formlistadisciplina::formlistadisciplina(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formlistadisciplina)
{
    pessCont.iniciaBanco();
    ui->setupUi(this);
    formatarTableWidget();
    atualizaDados();
}

formlistadisciplina::~formlistadisciplina()
{
    delete ui;
}

void formlistadisciplina::on_pushButton_clicked()
{
    ui->tableWidget->reset();
    atualizaDados();
}

void formlistadisciplina::atualizaDados(){
    apagarLista();
    QSqlQuery query = discControl.pesquisaTodasDisciplina();
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

void formlistadisciplina::formatarTableWidget(){
    ui->tableWidget->setColumnCount(5);
    QStringList cabecalho = {"Código", "Disciplina", "Carga Horária", "Professor", "CPF Professor"};
    ui->tableWidget->setHorizontalHeaderLabels(cabecalho);
    ui->tableWidget->setRowHeight(0, 25);
    ui->tableWidget->setColumnWidth(0, 50);
    ui->tableWidget->setColumnWidth(1, 150);
    ui->tableWidget->setColumnWidth(3, 183);
    ui->tableWidget->setColumnWidth(4, 150);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->setVisible(false);
}

void formlistadisciplina::apagarLista(){
    int aux = discControl.totalDisciplina();
    int i = 0;
    do {
        ui->tableWidget->removeRow(i);
        ui->tableWidget->removeRow(0);
        ui->tableWidget->removeRow(1);
        i++;
    } while(i < aux);
}
