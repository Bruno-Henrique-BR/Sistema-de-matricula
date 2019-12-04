#include "pessoacontroller.h"

PessoaController::PessoaController()
{

}

bool PessoaController::iniciaBanco(){
    bool statusDB;
    QSqlDatabase bancoDeDados = QSqlDatabase::addDatabase("QSQLITE");
    QString dir = qApp->applicationDirPath();
    QString banco = dir + "/banco_de_dados/ProjetoFinalPOO";
    bancoDeDados.setDatabaseName(banco);

    if(bancoDeDados.open()){
        statusDB = true;
    } else {
        qDebug() << "banco de dados não aberto";
        statusDB = false;
    }

    return statusDB;
}

bool PessoaController::pesquisaPorCPF(QString cpf){
    bool statusDB;
    QSqlQuery query;
    query.prepare("select * from pessoa where CPF='"+cpf+"'");
    if(query.exec()){
        int cont = 0;
        while (query.next()) {
            cont ++;
        }
        if(cont>0){
            statusDB= true;
        } else {
            statusDB = false;
        }
    } else {
        statusDB = false;
    }
    return statusDB;
}
