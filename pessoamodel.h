#ifndef PESSOAMODEL_H
#define PESSOAMODEL_H

#include <QString>

class PessoaModel
{
public:
    PessoaModel();

    bool validaCPF(QString CPF);

    QString getCPF() const;
    void setCPF(const QString &value);

    QString getNome() const;
    void setNome(const QString &value);

    QString getLogradouro() const;
    void setLogradouro(const QString &value);

    QString getSetor() const;
    void setSetor(const QString &value);

    QString getCidade() const;
    void setCidade(const QString &value);

    QString getEstado() const;
    void setEstado(const QString &value);

    QString getCelular() const;
    void setCelular(const QString &value);

    QString getEmail() const;
    void setEmail(const QString &value);

protected:
    QString CPF;
    QString nome;
    QString logradouro;
    QString setor;
    QString cidade;
    QString estado;
    QString celular;
    QString email;
};

#endif // PESSOAMODEL_H
