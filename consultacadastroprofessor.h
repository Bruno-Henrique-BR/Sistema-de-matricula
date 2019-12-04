#ifndef CONSULTACADASTROPROFESSOR_H
#define CONSULTACADASTROPROFESSOR_H

#include <QDialog>
#include <QMessageBox>
#include "pessoamodel.h"
#include "pessoacontroller.h"
#include "avisocadastrarprofessor.h"
#include "professormodel.h"

namespace Ui {
class ConsultaCadastroProfessor;
}

class ConsultaCadastroProfessor : public QDialog
{
    Q_OBJECT

public:
    explicit ConsultaCadastroProfessor(QWidget *parent = nullptr);
    ~ConsultaCadastroProfessor();

private slots:
    void on_btn_consulta_clicked();

    void on_pushButton_clicked();

private:
    Ui::ConsultaCadastroProfessor *ui;
    PessoaModel pessModel;
    PessoaController pessCont;
};

#endif // CONSULTACADASTROPROFESSOR_H
