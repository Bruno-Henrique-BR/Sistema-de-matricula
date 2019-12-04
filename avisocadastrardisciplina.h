#ifndef AVISOCADASTRARDISCIPLINA_H
#define AVISOCADASTRARDISCIPLINA_H

#include <QDialog>
#include "formcadastrodisciplina.h"

namespace Ui {
class avisocadastrardisciplina;
}

class avisocadastrardisciplina : public QDialog
{
    Q_OBJECT

public:
    explicit avisocadastrardisciplina(QWidget *parent = nullptr, QString codigo = "");
    ~avisocadastrardisciplina();

private slots:
    void on_btn_cadastrar_clicked();

    void on_cancelar_button_clicked();

private:
    Ui::avisocadastrardisciplina *ui;
};

#endif // AVISOCADASTRARDISCIPLINA_H
