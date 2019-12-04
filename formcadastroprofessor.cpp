#include "formcadastroprofessor.h"
#include "ui_formcadastroprofessor.h"

static QString cpf_fm;

FormCadastroProfessor::FormCadastroProfessor(QWidget *parent, QString cpf_prof) :
    QDialog(parent),
    ui(new Ui::FormCadastroProfessor)
{
    ui->setupUi(this);
    ui->nome_cadastro->setFocus();
    cpf_fm = cpf_prof;
    ui->cpf_cadastro->setText(cpf_fm);
}

FormCadastroProfessor::~FormCadastroProfessor()
{
    delete ui;
}

void FormCadastroProfessor::on_btn_gravar_clicked()
{
    QString cpf = ui->cpf_cadastro->text();
    QString nome = ui->nome_cadastro->text();
    QString logradouro = ui->logradouro_cadastro->text();
    QString setor = ui->setor_cadastro->text();
    QString cidade = ui->cidade_cadastro->text();
    QString estado = ui->estado_cadastro->text();
    QString celular = ui->celular_cadastro->text();
    QString email = ui->email_cadastro->text();
    QString graduacao = ui->graduacao_cadastro->text();
    QString titulacao = ui->titulaco_cadastro->text();

    if(!profModel->validaCPF(cpf)){
        QMessageBox::warning(this, "Informação", "CPF Inválido, favor digite novamente");
        ui->cpf_cadastro->setFocus();
    } else{
        profModel = new ProfessorModel(cpf, nome, logradouro, setor, cidade, estado, celular, email, graduacao, titulacao);
        if(profControl.salvarDados(profModel)){
            QMessageBox::information(this, "Informação", "Registro realizado com sucesso");
            ui->cpf_cadastro->clear();
            ui->nome_cadastro->clear();
            ui->logradouro_cadastro->clear();
            ui->setor_cadastro->clear();
            ui->cidade_cadastro->clear();
            ui->estado_cadastro->clear();
            ui->celular_cadastro->clear();
            ui->email_cadastro->clear();
            ui->graduacao_cadastro->clear();
            ui->titulaco_cadastro->clear();
            ui->cpf_cadastro->setFocus();
        } else {
            QMessageBox::warning(this, "Informação", "Falha no registro do professor");
        }
    }
}

void FormCadastroProfessor::on_btn_cancelar_clicked()
{
    ui->cpf_cadastro->clear();
    ui->nome_cadastro->clear();
    ui->logradouro_cadastro->clear();
    ui->setor_cadastro->clear();
    ui->cidade_cadastro->clear();
    ui->estado_cadastro->clear();
    ui->celular_cadastro->clear();
    ui->email_cadastro->clear();
    ui->graduacao_cadastro->clear();
    ui->titulaco_cadastro->clear();
    this->close();
}
