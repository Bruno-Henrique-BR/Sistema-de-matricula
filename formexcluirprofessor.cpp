#include "formexcluirprofessor.h"
#include "ui_formexcluirprofessor.h"

#include <QMessageBox>

formexcluirprofessor::formexcluirprofessor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formexcluirprofessor)
{
    ui->setupUi(this);
    ui->cpf_pesquisa->clear();
    ui->cpf_pesquisa->setFocus();
}

formexcluirprofessor::~formexcluirprofessor()
{
    delete ui;
}

void formexcluirprofessor::on_btn_pesquisa_clicked()
{
    QString cpf = ui->cpf_pesquisa->text();
    if(pessModel.validaCPF(cpf)){
        if(profControl.verificaDisc(cpf) > 0){
            QMessageBox::warning(this, "Aviso", "Professor não pode ser excluído pois o mesmo está vinculado a outras disciplinas");
            ui->cpf_pesquisa->selectAll();
            ui->cpf_pesquisa->setFocus();
        } else {
            if(profControl.pesquisaProfessorCPFDisciplina(cpf) > 0){
                if(profControl.excluirProfessor(cpf)){
                    QMessageBox::information(this, "Aviso", "Professor excluído com sucesso");
                    ui->cpf_pesquisa->clear();
                    ui->cpf_pesquisa->setFocus();
                } else {
                    QMessageBox::warning(this, "Aviso", "Não foi possível excluir o professor");
                    ui->cpf_pesquisa->selectAll();
                    ui->cpf_pesquisa->setFocus();
                }
            }
            else {
                QMessageBox::warning(this, "Aviso", "Professor não encontrado para exclusão");
                ui->cpf_pesquisa->selectAll();
                ui->cpf_pesquisa->setFocus();
            }
        }
    } else {
        QMessageBox::warning(this, "Aviso", "CPF Inválido");
        ui->cpf_pesquisa->selectAll();
        ui->cpf_pesquisa->setFocus();
    }
}

void formexcluirprofessor::on_btn_cancelar_clicked()
{
    ui->cpf_pesquisa->clear();
    this->close();
}
