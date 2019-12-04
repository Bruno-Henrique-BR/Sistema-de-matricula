#ifndef PROFESSORCONTROLLER_H
#define PROFESSORCONTROLLER_H

#include  <QtSql>
#include "professormodel.h"
#include "ui_formpesquisaprofessor.h"
#include <QString>

class ProfessorController
{
public:
    ProfessorController();

    bool salvarDados(ProfessorModel *profModel);
    bool excluirProfessor(QString cpf);
    QSqlQuery pesquisaTodosProfessores();
    int totalProfessores();
    QSqlQuery pesquisaProfessorCPF(QString cpf);
    int pesquisaProfessorCPFDisciplina(QString cpf);
    int verificaDisc(QString cpf);
};

#endif // PROFESSORCONTROLLER_H
