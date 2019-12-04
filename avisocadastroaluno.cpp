#include "avisocadastroaluno.h"
#include "ui_avisocadastroaluno.h"

static QString mat;

avisocadastroaluno::avisocadastroaluno(QWidget *parent, QString matricula) :
    QDialog(parent),
    ui(new Ui::avisocadastroaluno)
{
    ui->setupUi(this);
    mat = matricula;
}

avisocadastroaluno::~avisocadastroaluno()
{
    delete ui;
}

void avisocadastroaluno::on_btn_cadastrar_clicked()
{
    this->close();
    formcadastroaluno fca(this, mat);
    fca.setModal(true);
    fca.exec();
}

void avisocadastroaluno::on_btn_cancelar_clicked()
{
    this->close();
}
