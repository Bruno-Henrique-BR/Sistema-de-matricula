#ifndef CONSULTACADASTRODISCIPLINA_H
#define CONSULTACADASTRODISCIPLINA_H

#include <QDialog>
#include "disciplinamodel.h"
#include "disciplinacontroller.h"
#include "avisocadastrardisciplina.h"

namespace Ui {
class consultacadastrodisciplina;
}

class consultacadastrodisciplina : public QDialog
{
    Q_OBJECT

public:
    explicit consultacadastrodisciplina(QWidget *parent = nullptr);
    ~consultacadastrodisciplina();

private slots:
    void on_btn_consulta_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::consultacadastrodisciplina *ui;
    disciplinamodel discmodel;
    disciplinacontroller discont;
};

#endif // CONSULTACADASTRODISCIPLINA_H
