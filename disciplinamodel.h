#ifndef DISCIPLINAMODEL_H
#define DISCIPLINAMODEL_H

#include <QString>

class disciplinamodel
{
public:
    disciplinamodel();
    disciplinamodel(QString cpf_prof, QString codigo, QString nome, QString cargaHoraria);

    QString getCodigo() const;
    void setCodigo(const QString &value);

    QString getNome() const;
    void setNome(const QString &value);

    QString getCargaHoraria() const;
    void setCargaHoraria(QString value);

    QString getCpf_professor() const;
    void setCpf_professor(const QString &value);

    bool validaCodigo(QString codigo);

private:
    QString codigo;
    QString nome;
    QString cargaHoraria;
    QString cpf_professor;
};

#endif // DISCIPLINAMODEL_H
