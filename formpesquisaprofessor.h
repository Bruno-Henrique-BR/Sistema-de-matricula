#ifndef FORMPESQUISAPROFESSOR_H
#define FORMPESQUISAPROFESSOR_H

#include <QDialog>
#include "professorcontroller.h"
#include "pessoacontroller.h"
#include "pessoamodel.h"

namespace Ui {
class formpesquisaprofessor;
}

class formpesquisaprofessor : public QDialog
{
    Q_OBJECT

public:
    explicit formpesquisaprofessor(QWidget *parent = nullptr);
    ~formpesquisaprofessor();

private slots:
    void on_btn_pesquisa_clicked();

private:
    Ui::formpesquisaprofessor *ui;
    ProfessorController profCont;
    PessoaController pessCont;
    PessoaModel pessModel;
    void formatarTableWidget();
};

#endif // FORMPESQUISAPROFESSOR_H
