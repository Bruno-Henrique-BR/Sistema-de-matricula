#ifndef FORMEXCLUIRDISCIPLINA_H
#define FORMEXCLUIRDISCIPLINA_H
#include "disciplinamodel.h"
#include "disciplinacontroller.h"

#include <QDialog>

namespace Ui {
class formexcluirdisciplina;
}

class formexcluirdisciplina : public QDialog
{
    Q_OBJECT

public:
    explicit formexcluirdisciplina(QWidget *parent = nullptr);
    ~formexcluirdisciplina();

private slots:
    void on_btn_pesquisa_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::formexcluirdisciplina *ui;
    disciplinamodel discModel;
    disciplinacontroller disCont;
};

#endif // FORMEXCLUIRDISCIPLINA_H
