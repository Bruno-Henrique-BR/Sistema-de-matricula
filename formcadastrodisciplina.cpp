#include "formcadastrodisciplina.h"
#include "ui_formcadastrodisciplina.h"
#include "disciplinamodel.h"
#include <QMessageBox>
#include <QtSql>

static QString cod;

formcadastrodisciplina::formcadastrodisciplina(QWidget *parent, QString codigo) :
    QDialog(parent),
    ui(new Ui::formcadastrodisciplina)
{
    ui->setupUi(this);
    cod = codigo;
    ui->cadastro_codigo->setText(cod);
}

formcadastrodisciplina::~formcadastrodisciplina()
{
    delete ui;
}

void formcadastrodisciplina::on_btn_salvar_clicked()
{
    QString cpf_prof = ui->professor_disciplina->text();
    QString codigo = ui->cadastro_codigo->text();
    QString nome = ui->cadastro_nome->text();
    QString cargaHoraria = ui->cadastro_cargahoraria->text();

    if(pessModel.validaCPF(cpf_prof)){
        if(profControl.pesquisaProfessorCPFDisciplina(cpf_prof) <= 0){
            QMessageBox::warning(this, "Informação", "Professor não cadastrado no sistema");
            ui->professor_disciplina->setFocus();
        } else {
            discModel = new disciplinamodel(cpf_prof, codigo, nome, cargaHoraria);
            if(discControl.salvarDados(discModel)){
                QMessageBox::information(this, "Informação", "Registro realizado com sucesso");
                ui->professor_disciplina->clear();
                ui->cadastro_codigo->clear();
                ui->cadastro_nome->clear();
                ui->cadastro_cargahoraria->clear();
                ui->professor_disciplina->setFocus();
            } else {
                QMessageBox::warning(this, "Informação", "Não foi possível realizar o cadastro da disciplina");
            }
        }
    } else {
        QMessageBox::warning(this, "Informação", "CPF Inválido, digite novamente");
        ui->professor_disciplina->selectAll();
        ui->professor_disciplina->setFocus();
    }

}

void formcadastrodisciplina::on_btn_cancelar_clicked()
{
    ui->professor_disciplina->clear();
    ui->cadastro_codigo->clear();
    ui->cadastro_nome->clear();
    ui->cadastro_cargahoraria->clear();
    this->close();
}
