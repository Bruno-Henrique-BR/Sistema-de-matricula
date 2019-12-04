#include "formexcluiraluno.h"
#include "ui_formexcluiraluno.h"
#include <QMessageBox>

formexcluiraluno::formexcluiraluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formexcluiraluno)
{
    ui->setupUi(this);
}

formexcluiraluno::~formexcluiraluno()
{
    delete ui;
}

void formexcluiraluno::on_btn_pesquisa_2_clicked()
{
    QString matricula = ui->cod_pesquisa->text();
    if(alModel.validaMatricula(matricula)){
        if(alCont.verificaAlunoExists(matricula) > 0){
            if(alCont.excluirAluno(matricula)){
                QMessageBox::information(this, "Aviso", "Aluno excluído com sucesso");
                ui->cod_pesquisa->clear();
                ui->cod_pesquisa->setFocus();
            } else {
                QMessageBox::warning(this, "Aviso", "Não foi possível excluir o aluno");
                ui->cod_pesquisa->selectAll();
                ui->cod_pesquisa->setFocus();
            }
        } else {
            QMessageBox::warning(this, "Aviso", "Aluno não encontrado para exclusão");
            ui->cod_pesquisa->selectAll();
            ui->cod_pesquisa->setFocus();
        }
    } else {
        QMessageBox::warning(this, "Aviso", "Matrícula Inválida");
        ui->cod_pesquisa->selectAll();
        ui->cod_pesquisa->setFocus();
    }
}

void formexcluiraluno::on_btn_cancelar_clicked()
{
    ui->cod_pesquisa->clear();
    this->close();
}
