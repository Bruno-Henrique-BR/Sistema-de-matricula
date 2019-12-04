#include "alunomodel.h"

alunomodel::alunomodel()
{

}

alunomodel::alunomodel(QString cpf
                       ,QString nome
                       ,QString logradouro
                       ,QString setor
                       ,QString cidade
                       ,QString estado
                       ,QString celular
                       ,QString email
                       ,QString matricula
                       ,QString ano
                       ,QString id_curso){
    this->CPF = cpf;
    this->nome = nome;
    this->logradouro = logradouro;
    this->setor = setor;
    this->cidade = cidade;
    this->estado = estado;
    this->celular = celular;
    this->email = email;
    this->matricula = matricula;
    this->ano = ano;
    this->id_curso = id_curso;
}

QString alunomodel::getId_curso() const
{
    return id_curso;
}

void alunomodel::setId_curso(QString value)
{
    id_curso = value;
}

QString alunomodel::getAno() const
{
    return ano;
}

void alunomodel::setAno(QString value)
{
    ano = value;
}

QString alunomodel::getMatricula() const
{
    return matricula;
}

void alunomodel::setMatricula(const QString &value)
{
    matricula = value;
}

bool alunomodel::validaMatricula(QString matricula){
    bool statusCod;
    if(matricula.isNull()){
        statusCod = false;
    } else {
        statusCod = true;
    }
    return statusCod;
}
