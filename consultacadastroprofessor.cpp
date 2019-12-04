#include "consultacadastroprofessor.h"
#include "ui_consultacadastroprofessor.h"

static QString cpf;

ConsultaCadastroProfessor::ConsultaCadastroProfessor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConsultaCadastroProfessor)
{
    ui->setupUi(this);
    ui->cpf->clear();
}

ConsultaCadastroProfessor::~ConsultaCadastroProfessor()
{
    delete ui;
}

void ConsultaCadastroProfessor::on_btn_consulta_clicked()
{
    QString cpf = ui->cpf->text();
    if(!pessModel.validaCPF(cpf)){
        QMessageBox::warning(this, "Informação", "CPF Inválido, favor digite novamente");
        ui->cpf->clear();
        ui->cpf->setFocus();
    } else{
        if(pessCont.pesquisaPorCPF(cpf)){
           QMessageBox::warning(this, "Informação", "CPF Cadastrado!");
           ui->cpf->clear();
           ui->cpf->setFocus();
        } else {
            this->close();
            AvisoCadastrarProfessor apc(this, cpf);
            apc.setModal(true);
            apc.exec();
        }
    }
}

void ConsultaCadastroProfessor::on_pushButton_clicked()
{
    ui->cpf->clear();
    this->close();
}
