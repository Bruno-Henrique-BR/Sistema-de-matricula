#ifndef FORMEXCLUIRALUNO_H
#define FORMEXCLUIRALUNO_H
#include "alunomodel.h"
#include "alunocontroller.h"

#include <QDialog>

namespace Ui {
class formexcluiraluno;
}

class formexcluiraluno : public QDialog
{
    Q_OBJECT

public:
    explicit formexcluiraluno(QWidget *parent = nullptr);
    ~formexcluiraluno();

private slots:
    void on_btn_pesquisa_2_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::formexcluiraluno *ui;
    alunomodel alModel;
    alunocontroller alCont;
};

#endif // FORMEXCLUIRALUNO_H
