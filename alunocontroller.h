#ifndef ALUNOCONTROLLER_H
#define ALUNOCONTROLLER_H
#include "alunomodel.h"
#include <QtSql>
#include <QFileInfo>
#include <QDebug>

class alunocontroller
{
public:
    alunocontroller();
    bool pesquisaPorMatricula(QString matricula);
    bool salvarDados(alunomodel *alunoModel);
    QSqlQuery pesquisaMatricula(QString matricula);
    int totalAlunos();
    QSqlQuery pesquisaTodosAlunos();
    int verificaAlunoExists(QString matricula);
    bool excluirAluno (QString matricula);
};

#endif // ALUNOCONTROLLER_H
