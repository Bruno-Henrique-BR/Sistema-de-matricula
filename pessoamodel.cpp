#include "pessoamodel.h"

PessoaModel::PessoaModel()
{

}

QString PessoaModel::getCPF() const
{
    return CPF;
}

void PessoaModel::setCPF(const QString &value)
{
    CPF = value;
}

QString PessoaModel::getNome() const
{
    return nome;
}

void PessoaModel::setNome(const QString &value)
{
    nome = value;
}

QString PessoaModel::getLogradouro() const
{
    return logradouro;
}

void PessoaModel::setLogradouro(const QString &value)
{
    logradouro = value;
}

QString PessoaModel::getSetor() const
{
    return setor;
}

void PessoaModel::setSetor(const QString &value)
{
    setor = value;
}

QString PessoaModel::getCidade() const
{
    return cidade;
}

void PessoaModel::setCidade(const QString &value)
{
    cidade = value;
}

QString PessoaModel::getEstado() const
{
    return estado;
}

void PessoaModel::setEstado(const QString &value)
{
    estado = value;
}

QString PessoaModel::getCelular() const
{
    return celular;
}

void PessoaModel::setCelular(const QString &value)
{
    celular = value;
}

QString PessoaModel::getEmail() const
{
    return email;
}

void PessoaModel::setEmail(const QString &value)
{
    email = value;
}

bool PessoaModel::validaCPF(QString CPF){

    bool statusCPF;
    QString myString = CPF;
    QString cpf_aux[11];
    int cpfVetor[11];
    int primeiroElemento;
    int resPrimVerif = 0;
    int resSegVerif = 0;
    int multiplicadorPrimVerif = 10;
    int multiplicadorSegVerif = 11;
    bool tudoIgual = true;

    /* Pega cada elemento do CPF de entrada e coloca no vetor cpf_aux para o mesmo converter e enviar para o
   cpfVetor de forma int, visto que o QT não permite converter diretamente, utilizando o toInt();*/

    for (int i = 0; i < myString.length(); i++) {
        cpf_aux[i] = myString.at(i);
        cpfVetor[i] = cpf_aux[i].toInt();
    }

    primeiroElemento = cpfVetor[0];

    // Verifica se todos os dígitos são iguais

    for (int i = 1; i < 11; i++) {
        if (cpfVetor[i] != primeiroElemento) {
            tudoIgual = false;
            break;
        }
    }

    if (!tudoIgual) {

        for (int i = 0; i < 9; i++) {

            resPrimVerif = (cpfVetor[i] * multiplicadorPrimVerif) +
                    resPrimVerif;
            multiplicadorPrimVerif--;

        }

        resPrimVerif = resPrimVerif * 10;
        resPrimVerif = resPrimVerif % 11;

        if (resPrimVerif == 10) {
            resPrimVerif = 0;
        }

        for (int i = 0; i < 10; i++) {

            resSegVerif = (cpfVetor[i] * multiplicadorSegVerif) +
                    resSegVerif;
            multiplicadorSegVerif--;

        }

        resSegVerif = resSegVerif * 10;
        resSegVerif = resSegVerif % 11;

        if (resSegVerif == 10) {
            resSegVerif = 0;
        }

        if ((resPrimVerif == cpfVetor[9]) && (resSegVerif == cpfVetor[10])) {
            statusCPF = true;
        } else {
            statusCPF = false;
        }

    } else {
        statusCPF = false;
    }

    return statusCPF;

}
