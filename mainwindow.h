#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "consultacadastroprofessor.h"
#include "formpesquisaprofessor.h"
#include "pessoacontroller.h"
#include "formlistaprofessores.h"
#include "consultacadastrodisciplina.h"
#include "consultacadastroaluno.h"
#include "formpesquisaaluno.h"
#include "formlistaaluno.h"
#include "formexcluirprofessor.h"
#include "formlistadisciplina.h"
#include "formpesquisadisciplina.h"
#include "formexcluirdisciplina.h"
#include "formexcluiraluno.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_cadastrar_clicked();

    void on_btn_procurar_clicked();

    void on_btn_listar_clicked();

    void on_btn_cadastro_disciplina_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_btn_excluir_clicked();

    void on_btn_listar_disciplina_clicked();

    void on_btn_procurar_disciplina_clicked();

    void on_btn_excluir_disciplina_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    ConsultaCadastroProfessor ccp;
    PessoaController pessCont;
    formpesquisaprofessor fpp;
    formlistaprofessores flp;
    consultacadastrodisciplina ccd;
    consultacadastroaluno cca;
    formpesquisaaluno fpa;
    formlistaaluno fla;
    formexcluirprofessor fep;
    formlistadisciplina fld;
    formpesquisadisciplina fpd;
    formexcluirdisciplina fed;
    formexcluiraluno fea;
};

#endif // MAINWINDOW_H
