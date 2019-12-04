#include "disciplinacontroller.h"
#include <QtSql>
#include <QFileInfo>
#include <QDebug>
#include <QString>

disciplinacontroller::disciplinacontroller()
{

}

bool disciplinacontroller::PesquisaPorCodigo(QString codigo){
    bool statusDB;
    QSqlQuery query;
    query.prepare("select * from disciplina where codigo='" + codigo + "'");
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

bool disciplinacontroller::salvarDados(disciplinamodel *discModel){

    QSqlQuery query_disciplina;
    query_disciplina.prepare("insert into disciplina values"
                  "('"+discModel->getCpf_professor()+"',"+discModel->getCodigo()+", '"+discModel->getNome()+"', "+discModel->getCargaHoraria()+")");
    if(query_disciplina.exec()){
        return true;
    } else {
        return false;
    }

}
int disciplinacontroller::totalDisciplina(){
    int qtdResult = 0;
    QSqlQuery query;
    query.prepare("SELECT COUNT(codigo)FROM disciplina");
    if(query.exec()){
        query.next();
        qtdResult = query.value(0).toInt();
    } else {
        qtdResult = 0;
    }
    return qtdResult;
}

QSqlQuery disciplinacontroller::pesquisaDisciplinaCodigo(QString codigo){
    QSqlQuery query;
    query.prepare("select disciplina.codigo, disciplina.nome, disciplina.carga_horaria, pessoa.nome, professor.cpf from disciplina, professor, pessoa  where professor.cpf = disciplina.cpf_professor  and professor.CPF = pessoa.cpf and disciplina.codigo = "+codigo+"");
    return query;
}

QSqlQuery disciplinacontroller::pesquisaTodasDisciplina(){
    QSqlQuery query;
    query.prepare("select disciplina.codigo, disciplina.nome, disciplina.carga_horaria, pessoa.nome, professor.cpf from disciplina, professor, pessoa  where professor.cpf = disciplina.cpf_professor  and professor.CPF = pessoa.cpf");
    return query;
}

bool disciplinacontroller::excluirDisciplina(QString codigo){
    bool statusDB;
    QSqlQuery query;
    query.prepare("delete from disciplina where codigo = '"+codigo+"';");
    if(query.exec()){
        statusDB = true;
    } else {
        statusDB = false;
    }
    return statusDB;
}

int disciplinacontroller::verificaDiscExists(QString codigo){
    int qtd;
    QSqlQuery query;
    query.prepare("SELECT COUNT(codigo)FROM disciplina WHERE codigo = '"+codigo+"';");
    if(query.exec()){
        query.next();
        qtd = query.value(0).toInt();
    } else {
        qtd = 0;
    }
    return qtd;
}
