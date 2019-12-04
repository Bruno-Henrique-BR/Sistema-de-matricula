#ifndef AVISOCADASTROALUNO_H
#define AVISOCADASTROALUNO_H
#include "formcadastroaluno.h"

#include <QDialog>

namespace Ui {
class avisocadastroaluno;
}

class avisocadastroaluno : public QDialog
{
    Q_OBJECT

public:
    explicit avisocadastroaluno(QWidget *parent = nullptr, QString matricula = "");
    ~avisocadastroaluno();

private slots:
    void on_btn_cadastrar_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::avisocadastroaluno *ui;
};

#endif // AVISOCADASTROALUNO_H
