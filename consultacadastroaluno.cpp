#include "consultacadastroaluno.h"
#include "ui_consultacadastroaluno.h"

#include <QMessageBox>

consultacadastroaluno::consultacadastroaluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::consultacadastroaluno)
{
    ui->setupUi(this);
}

consultacadastroaluno::~consultacadastroaluno()
{
    delete ui;
}

void consultacadastroaluno::on_btn_consulta_clicked()
{
    QString matricula = ui->matricula->text();
    if(alc.pesquisaPorMatricula(matricula)){
       QMessageBox::warning(this, "Informação", "Aluno já cadastrado");
       ui->matricula->clear();
       ui->matricula->setFocus();
    } else {
        this->close();
        avisocadastroaluno aca(this, matricula);
        aca.setModal(true);
        aca.exec();
    }
}

void consultacadastroaluno::on_btn_cancelar_clicked()
{
    ui->matricula->clear();
    this->close();
}
