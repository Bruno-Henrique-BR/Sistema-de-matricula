#include "formexcluirdisciplina.h"
#include "ui_formexcluirdisciplina.h"

#include <QMessageBox>

formexcluirdisciplina::formexcluirdisciplina(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formexcluirdisciplina)
{
    ui->setupUi(this);
    ui->cod_pesquisa->clear();
    ui->cod_pesquisa->setFocus();
}

formexcluirdisciplina::~formexcluirdisciplina()
{
    delete ui;
}

void formexcluirdisciplina::on_btn_pesquisa_clicked()
{
    QString codigo = ui->cod_pesquisa->text();
    if(discModel.validaCodigo(codigo)){
        if(disCont.verificaDiscExists(codigo) > 0){
            if(disCont.excluirDisciplina(codigo)){
                QMessageBox::information(this, "Aviso", "Disciplina excluída com sucesso");
                ui->cod_pesquisa->clear();
                ui->cod_pesquisa->setFocus();
            } else {
                QMessageBox::warning(this, "Aviso", "Não foi possível excluir a disciplina");
                ui->cod_pesquisa->selectAll();
                ui->cod_pesquisa->setFocus();
            }
        } else {
            QMessageBox::warning(this, "Aviso", "Disciplina não encontrada para exclusão");
            ui->cod_pesquisa->selectAll();
            ui->cod_pesquisa->setFocus();
        }
    } else {
        QMessageBox::warning(this, "Aviso", "Disciplina Inválida");
        ui->cod_pesquisa->selectAll();
        ui->cod_pesquisa->setFocus();
    }
}

void formexcluirdisciplina::on_btn_cancelar_clicked()
{
    ui->cod_pesquisa->clear();
    this->close();
}
