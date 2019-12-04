#ifndef FORMLISTAALUNO_H
#define FORMLISTAALUNO_H
#include "alunocontroller.h"

#include <QDialog>

namespace Ui {
class formlistaaluno;
}

class formlistaaluno : public QDialog
{
    Q_OBJECT

public:
    explicit formlistaaluno(QWidget *parent = nullptr);
    ~formlistaaluno();

private slots:
    void on_pushButton_clicked();

private:
    Ui::formlistaaluno *ui;
    void formatarTableWidget();
    void atualizaDados();
    void apagarLista();
    alunocontroller alCont;
};

#endif // FORMLISTAALUNO_H
