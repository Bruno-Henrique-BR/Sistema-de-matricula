#ifndef PROFESSORMODEL_H
#define PROFESSORMODEL_H

#include "pessoamodel.h"

class ProfessorModel: public PessoaModel
{
public:
    ProfessorModel();
    ProfessorModel(QString cpf
                   ,QString nome
                   ,QString logradouro
                   ,QString setor
                   ,QString cidade
                   ,QString estado
                   ,QString celular
                   ,QString email
                   ,QString graduacao
                   ,QString titulacao);

    QString getGraduacao() const;
    void setGraduacao(const QString &value);

    QString getTitulacao() const;
    void setTitulacao(const QString &value);

private:
    QString graduacao;
    QString titulacao;
};

#endif // PROFESSORMODEL_H
