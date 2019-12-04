#include "consultacadastrodisciplina.h"
#include "ui_consultacadastrodisciplina.h"

#include <QMessageBox>

consultacadastrodisciplina::consultacadastrodisciplina(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::consultacadastrodisciplina)
{
    ui->setupUi(this);
    ui->codigo->clear();
}

consultacadastrodisciplina::~consultacadastrodisciplina()
{
    delete ui;
}

void consultacadastrodisciplina::on_btn_consulta_clicked()
{
    QString codigo = ui->codigo->text();
    if(discont.PesquisaPorCodigo(codigo)){
        QMessageBox::warning(this, "Informação", "codigo Cadastrado!");
        ui->codigo->clear();
        ui->codigo->setFocus();
    } else {
        this->close();
        avisocadastrardisciplina adc(this, codigo);
        adc.setModal(true);
        adc.exec();
    }
}

void consultacadastrodisciplina::on_btn_cancelar_clicked()
{
    ui->codigo->clear();
    this->close();
}
