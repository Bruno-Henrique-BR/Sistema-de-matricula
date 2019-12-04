#include "formpesquisadisciplina.h"
#include "ui_formpesquisadisciplina.h"
#include <QMessageBox>

formpesquisadisciplina::formpesquisadisciplina(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formpesquisadisciplina)
{
    pessCont.iniciaBanco();
    ui->setupUi(this);
    formatarTableWidget();
}

formpesquisadisciplina::~formpesquisadisciplina()
{
    delete ui;
}

void formpesquisadisciplina::on_btn_pesquisa_clicked()
{
    ui->tableWidget->removeRow(0);
    QString codigo = ui->matricula_pesquisa->text();
    if(!discModel.validaCodigo(codigo)){
        QMessageBox::warning(this, "Informação", "Código Inválido, favor digite novamente");
        ui->matricula_pesquisa->clear();
        ui->matricula_pesquisa->setFocus();
    } else {
        QSqlQuery pesquisa = discControl.pesquisaDisciplinaCodigo(codigo);
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
                QMessageBox::warning(this, "Informação", "Código não encontrado! Favor realizar cadastro da disciplina");
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
}

void formpesquisadisciplina::formatarTableWidget(){
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

