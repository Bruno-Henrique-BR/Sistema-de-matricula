#ifndef FORMEXCLUIRPROFESSOR_H
#define FORMEXCLUIRPROFESSOR_H
#include "professorcontroller.h"
#include "pessoamodel.h"

#include <QDialog>

namespace Ui {
class formexcluirprofessor;
}

class formexcluirprofessor : public QDialog
{
    Q_OBJECT

public:
    explicit formexcluirprofessor(QWidget *parent = nullptr);
    ~formexcluirprofessor();

private slots:

    void on_btn_pesquisa_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::formexcluirprofessor *ui;
    ProfessorController profControl;
    PessoaModel pessModel;
};

#endif // FORMEXCLUIRPROFESSOR_H
