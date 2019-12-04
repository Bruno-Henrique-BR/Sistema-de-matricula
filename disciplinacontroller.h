#ifndef DISCIPLINACONTROLLER_H
#define DISCIPLINACONTROLLER_H


#include <QtSql>
#include <QFileInfo>
#include <QDebug>
#include <disciplinamodel.h>
#include <QString>

class disciplinacontroller
{
public:
    disciplinacontroller();
    bool iniciaBanco();
    bool PesquisaPorCodigo(QString codigo);
    bool salvarDados(disciplinamodel *discModel);
    QSqlQuery pesquisaTodasDisciplina();
    int totalDisciplina();
    QSqlQuery pesquisaDisciplinaCodigo(QString codigo);
    bool excluirDisciplina(QString codigo);
    int verificaDiscExists(QString codigo);
};
#endif // DISCIPLINACONTROLLER_H
