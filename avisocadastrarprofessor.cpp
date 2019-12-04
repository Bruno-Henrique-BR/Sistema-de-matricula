#include "avisocadastrarprofessor.h"
#include "ui_avisocadastrarprofessor.h"
#include "formcadastroprofessor.h"

static QString cpf_fm;

AvisoCadastrarProfessor::AvisoCadastrarProfessor(QWidget *parent, QString cpf) :
    QDialog(parent),
    ui(new Ui::AvisoCadastrarProfessor)
{
    ui->setupUi(this);
    cpf_fm = cpf;
}

AvisoCadastrarProfessor::~AvisoCadastrarProfessor()
{
    delete ui;
}

void AvisoCadastrarProfessor::on_btn_cadastrar_clicked()
{
    this->close();
    FormCadastroProfessor fcp(this, cpf_fm);
    fcp.setModal(true);
    fcp.exec();
}

void AvisoCadastrarProfessor::on_btn_cancelar_clicked()
{
    this->close();
}
