#include "professormodel.h"

ProfessorModel::ProfessorModel()
{
    this->CPF = "";
    this->nome = "";
    this->logradouro = "";
    this->setor = "";
    this->cidade = "";
    this->estado = "";
    this->celular = "";
    this->email = "";
    this->graduacao = "";
    this->titulacao = "";
}

ProfessorModel::ProfessorModel(QString cpf
                               ,QString nome
                               ,QString logradouro
                               ,QString setor
                               ,QString cidade
                               ,QString estado
                               ,QString celular
                               ,QString email
                               ,QString graduacao
                               ,QString titulacao){

    this->CPF = cpf;
    this->nome = nome;
    this->logradouro = logradouro;
    this->setor = setor;
    this->cidade = cidade;
    this->estado = estado;
    this->celular = celular;
    this->email = email;
    this->graduacao = graduacao;
    this->titulacao = titulacao;

}

QString ProfessorModel::getGraduacao() const
{
    return graduacao;
}

void ProfessorModel::setGraduacao(const QString &value)
{
    graduacao = value;
}

QString ProfessorModel::getTitulacao() const
{
    return titulacao;
}

void ProfessorModel::setTitulacao(const QString &value)
{
    titulacao = value;
}
