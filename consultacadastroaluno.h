#ifndef CONSULTACADASTROALUNO_H
#define CONSULTACADASTROALUNO_H
#include "alunocontroller.h"
#include "alunomodel.h"
#include "avisocadastroaluno.h"
#include <QDialog>

namespace Ui {
class consultacadastroaluno;
}

class consultacadastroaluno : public QDialog
{
    Q_OBJECT

public:
    explicit consultacadastroaluno(QWidget *parent = nullptr);
    ~consultacadastroaluno();

private slots:
    void on_btn_consulta_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::consultacadastroaluno *ui;
    alunocontroller alc;
};

#endif // CONSULTACADASTROALUNO_H
