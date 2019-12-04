#ifndef FORMLISTAPROFESSORES_H
#define FORMLISTAPROFESSORES_H

#include <QDialog>
#include "professorcontroller.h"
#include "pessoacontroller.h"
#include "pessoamodel.h"

namespace Ui {
class formlistaprofessores;
}

class formlistaprofessores : public QDialog
{
    Q_OBJECT

public:
    explicit formlistaprofessores(QWidget *parent = nullptr);
    ~formlistaprofessores();

private slots:
    void on_pushButton_clicked();

private:
    Ui::formlistaprofessores *ui;
    ProfessorController profCont;
    PessoaModel pessModel;
    void formatarTableWidget();
    void atualizaDados();
    void apagarLista();
};

#endif // FORMLISTAPROFESSORES_H
