#ifndef FORMCADASTROALUNO_H
#define FORMCADASTROALUNO_H

#include "alunomodel.h"
#include "alunocontroller.h"
#include "pessoacontroller.h"
#include <QDialog>

namespace Ui {
class formcadastroaluno;
}

class formcadastroaluno : public QDialog
{
    Q_OBJECT

public:
    explicit formcadastroaluno(QWidget *parent = nullptr, QString matricula = "");
    ~formcadastroaluno();

private slots:
    void on_btn_gravar_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::formcadastroaluno *ui;
    alunomodel *alunModel;
    alunocontroller alunoCont;
    PessoaController pesCont;
};

#endif // FORMCADASTROALUNO_H
