#ifndef FORMLISTADISCIPLINA_H
#define FORMLISTADISCIPLINA_H
#include "disciplinacontroller.h"
#include "pessoacontroller.h"

#include <QDialog>

namespace Ui {
class formlistadisciplina;
}

class formlistadisciplina : public QDialog
{
    Q_OBJECT

public:
    explicit formlistadisciplina(QWidget *parent = nullptr);
    ~formlistadisciplina();

private slots:
    void on_pushButton_clicked();

private:
    Ui::formlistadisciplina *ui;
    disciplinacontroller discControl;
    void formatarTableWidget();
    void atualizaDados();
    void apagarLista();
    PessoaController pessCont;
};

#endif // FORMLISTADISCIPLINA_H
