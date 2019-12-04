#include "formcadastroaluno.h"
#include "ui_formcadastroaluno.h"

#include <QMessageBox>

static QString mat;

formcadastroaluno::formcadastroaluno(QWidget *parent, QString matricula) :
    QDialog(parent),
    ui(new Ui::formcadastroaluno)
{
    ui->setupUi(this);
    mat = matricula;
    ui->matricula_cadastro->setText(mat);
    ui->cpf_cadastro->setFocus();
}

formcadastroaluno::~formcadastroaluno()
{
    delete ui;
}

void formcadastroaluno::on_btn_gravar_clicked()
{
    QString matricula = ui->matricula_cadastro->text();
    QString cpf = ui->cpf_cadastro->text();
    QString nome = ui->nome_cadastro->text();
    QString logradouro = ui->logradouro_cadastro->text();
    QString setor = ui->setor_cadastro->text();
    QString cidade = ui->cidade_cadastro->text();
    QString estado = ui->estado_cadastro->text();
    QString celular = ui->celular_cadastro->text();
    QString email = ui->email_cadastro->text();
    QString ano  = ui->ano_cadastro->text();
    QString id_curso = ui->curso_cadastro->text();

    if(!alunModel->validaCPF(cpf)){
        QMessageBox::warning(this, "Informação", "CPF Inválido, favor digite novamente");
        ui->cpf_cadastro->setFocus();
    } else {
        if(pesCont.pesquisaPorCPF(cpf)){
            QMessageBox::warning(this, "Informação", "CPF já Cadastrado no sistema!");
            ui->cpf_cadastro->clear();
            ui->cpf_cadastro->setFocus();
        } else {
            alunModel = new alunomodel(cpf, nome, logradouro, setor, cidade, estado, celular, email, matricula, ano, id_curso);
            if(alunoCont.salvarDados(alunModel)){
                QMessageBox::information(this, "Informação", "Registro realizado com sucesso");
                ui->matricula_cadastro->clear();
                ui->cpf_cadastro->clear();
                ui->nome_cadastro->clear();
                ui->logradouro_cadastro->clear();
                ui->setor_cadastro->clear();
                ui->cidade_cadastro->clear();
                ui->estado_cadastro->clear();
                ui->celular_cadastro->clear();
                ui->email_cadastro->clear();
                ui->ano_cadastro->clear();
                ui->curso_cadastro->clear();
                ui->matricula_cadastro->setFocus();

            } else {
                QMessageBox::warning(this, "Informação", "Falha no registro do aluno");
            }
        }
    }
}

void formcadastroaluno::on_btn_cancelar_clicked()
{
    ui->matricula_cadastro->clear();
    ui->cpf_cadastro->clear();
    ui->nome_cadastro->clear();
    ui->logradouro_cadastro->clear();
    ui->setor_cadastro->clear();
    ui->cidade_cadastro->clear();
    ui->estado_cadastro->clear();
    ui->celular_cadastro->clear();
    ui->email_cadastro->clear();
    ui->ano_cadastro->clear();
    ui->curso_cadastro->clear();
    this->close();
}
