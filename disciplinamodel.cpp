#include "disciplinamodel.h"

disciplinamodel::disciplinamodel()
{

}

disciplinamodel::disciplinamodel(QString cpf_prof, QString codigo, QString nome, QString cargaHoraria){
    this->cpf_professor = cpf_prof;
    this->codigo = codigo;
    this->nome = nome;
    this->cargaHoraria = cargaHoraria;
}

QString disciplinamodel::getCodigo() const
{
    return codigo;
}

void disciplinamodel::setCodigo(const QString &value)
{
    codigo = value;
}

QString disciplinamodel::getNome() const
{
    return nome;
}

void disciplinamodel::setNome(const QString &value)
{
    nome = value;
}

QString disciplinamodel::getCargaHoraria() const
{
    return cargaHoraria;
}

void disciplinamodel::setCargaHoraria(QString value)
{
    cargaHoraria = value;
}

QString disciplinamodel::getCpf_professor() const
{
    return cpf_professor;
}

void disciplinamodel::setCpf_professor(const QString &value)
{
    cpf_professor = value;
}

bool disciplinamodel::validaCodigo(QString codigo){
    bool statusCod;
    if(codigo.isNull()){
        statusCod = false;
    } else {
        statusCod = true;
    }
    return statusCod;
}
