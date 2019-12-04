#ifndef FORMCADASTRODISCIPLINA_H
#define FORMCADASTRODISCIPLINA_H

#include <QDialog>
#include "disciplinamodel.h"
#include "disciplinacontroller.h"
#include "professorcontroller.h"
#include "pessoamodel.h"

namespace Ui {
class formcadastrodisciplina;
}

class formcadastrodisciplina : public QDialog
{
    Q_OBJECT

public:
    explicit formcadastrodisciplina(QWidget *parent = nullptr, QString codigo = "");
    ~formcadastrodisciplina();

private slots:
    void on_btn_salvar_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::formcadastrodisciplina *ui;
    disciplinamodel *discModel;
    disciplinacontroller discControl;
    ProfessorController profControl;
    PessoaModel pessModel;
};

#endif // FORMCADASTRODISCIPLINA_H
