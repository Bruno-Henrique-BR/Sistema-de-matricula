#include "avisocadastrardisciplina.h"
#include "ui_avisocadastrardisciplina.h"

static QString cod;

avisocadastrardisciplina::avisocadastrardisciplina(QWidget *parent, QString codigo) :
    QDialog(parent),
    ui(new Ui::avisocadastrardisciplina)
{
    ui->setupUi(this);
    cod = codigo;
}

avisocadastrardisciplina::~avisocadastrardisciplina()
{
    delete ui;
}

void avisocadastrardisciplina::on_btn_cadastrar_clicked()
{
    this->close();
    formcadastrodisciplina fcd(this, cod);
    fcd.setModal(true);
    fcd.exec();
}

void avisocadastrardisciplina::on_cancelar_button_clicked()
{
    this->close();
}
