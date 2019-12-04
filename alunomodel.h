#ifndef ALUNOMODEL_H
#define ALUNOMODEL_H
#include <QString>

#include "pessoamodel.h"

class alunomodel: public PessoaModel
{
public:
    alunomodel();
    alunomodel(QString cpf
               ,QString nome
               ,QString logradouro
               ,QString setor
               ,QString cidade
               ,QString estado
               ,QString celular
               ,QString email
               ,QString matricula
               ,QString ano
               ,QString id_curso);

    QString getId_curso() const;
    void setId_curso(QString value);

    QString getAno() const;
    void setAno(QString value);

    QString getMatricula() const;
    void setMatricula(const QString &value);

    bool validaMatricula(QString matricula);

private:
    QString matricula;
    QString ano;
    QString id_curso;
};

#endif // ALUNOMODEL_H
