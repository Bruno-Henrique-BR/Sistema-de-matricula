#ifndef AVISOCADASTRARPROFESSOR_H
#define AVISOCADASTRARPROFESSOR_H

#include <QDialog>

namespace Ui {
class AvisoCadastrarProfessor;
}

class AvisoCadastrarProfessor : public QDialog
{
    Q_OBJECT

public:
    explicit AvisoCadastrarProfessor(QWidget *parent = nullptr, QString cpf = "");
    ~AvisoCadastrarProfessor();

private slots:
    void on_btn_cadastrar_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::AvisoCadastrarProfessor *ui;
};

#endif // AVISOCADASTRARPROFESSOR_H
