#ifndef FORMPESQUISADISCIPLINA_H
#define FORMPESQUISADISCIPLINA_H
#include "disciplinacontroller.h"
#include "pessoacontroller.h"
#include "disciplinamodel.h"

#include <QDialog>

namespace Ui {
class formpesquisadisciplina;
}

class formpesquisadisciplina : public QDialog
{
    Q_OBJECT

public:
    explicit formpesquisadisciplina(QWidget *parent = nullptr);
    ~formpesquisadisciplina();

private slots:
    void on_btn_pesquisa_clicked();

private:
    Ui::formpesquisadisciplina *ui;
    disciplinacontroller discControl;
    PessoaController pessCont;
    void formatarTableWidget();
    disciplinamodel discModel;
};

#endif // FORMPESQUISADISCIPLINA_H
