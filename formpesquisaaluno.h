#ifndef FORMPESQUISAALUNO_H
#define FORMPESQUISAALUNO_H
#include "pessoacontroller.h"
#include "alunocontroller.h"
#include <QDialog>

namespace Ui {
class formpesquisaaluno;
}

class formpesquisaaluno : public QDialog
{
    Q_OBJECT

public:
    explicit formpesquisaaluno(QWidget *parent = nullptr);
    ~formpesquisaaluno();

private slots:
    void on_btn_pesquisa_clicked();

private:
    Ui::formpesquisaaluno *ui;
    void formatarTableWidget();
    PessoaController pessCont;
    alunocontroller aluCont;
};

#endif // FORMPESQUISAALUNO_H
