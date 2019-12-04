#ifndef PESSOACONTROLLER_H
#define PESSOACONTROLLER_H

#include <QtSql>
#include <QFileInfo>
#include <QDebug>
class PessoaController
{
public:
    PessoaController();
    bool iniciaBanco();
    bool pesquisaPorCPF(QString cpf);
};

#endif // PESSOACONTROLLER_H
