#ifndef FORMCADASTROPROFESSOR_H
#define FORMCADASTROPROFESSOR_H

#include <QDialog>
#include <QMessageBox>
#include "professormodel.h"
#include "professorcontroller.h"

namespace Ui {
class FormCadastroProfessor;
}

class FormCadastroProfessor : public QDialog
{
    Q_OBJECT

public:
    explicit FormCadastroProfessor(QWidget *parent = nullptr, QString cpf_prof = "");
    ~FormCadastroProfessor();


private slots:
    void on_btn_gravar_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::FormCadastroProfessor *ui;
    ProfessorController profControl;
    ProfessorModel *profModel;
};

#endif // FORMCADASTROPROFESSOR_H
