#include "professorcontroller.h"
#include <QString>

ProfessorController::ProfessorController()
{

}

bool ProfessorController::salvarDados(ProfessorModel *profModel){
    bool statusDB;
    QSqlQuery query_pessoa;
    query_pessoa.prepare("insert into pessoa values"
                         "('"+profModel->getCPF()+"', '"+profModel->getNome()+"', '"+profModel->getLogradouro()+"', '"+profModel->getSetor()+"', '"+profModel->getCidade()+"', '"+profModel->getEstado()+"', '"+profModel->getCelular()+"', '"+profModel->getEmail()+"', 'P')");
    QSqlQuery query_prof;
    query_prof.prepare("insert into professor values "
                       "('"+profModel->getCPF()+"', '"+profModel->getTitulacao()+"', '"+profModel->getGraduacao()+"')");
    if(query_pessoa.exec() && query_prof.exec()){
        statusDB = true;
    } else {
        statusDB = false;
    }
    return statusDB;
}

int ProfessorController::totalProfessores(){
    int qtdResult;
    QSqlQuery query;
    query.prepare("SELECT COUNT(CPF)FROM professor;");
    if(query.exec()){
        query.next();
        qtdResult = query.value(0).toInt();
    } else {
        qtdResult = 0;
    }
    return qtdResult;
}

QSqlQuery ProfessorController::pesquisaProfessorCPF(QString cpf){
    QSqlQuery query;
    query.prepare("select professor.cpf, nome, titulacao, graduacao from pessoa, professor where pessoa.cpf = professor.cpf and professor.cpf = '"+cpf+"'");
    return query;
}

QSqlQuery ProfessorController::pesquisaTodosProfessores(){
    QSqlQuery query;
    query.prepare("select professor.cpf, nome, titulacao, graduacao from pessoa, professor where pessoa.cpf = professor.cpf;");
    return query;
}

int ProfessorController::pesquisaProfessorCPFDisciplina(QString cpf){
    int qtd;
    QSqlQuery query;
    query.prepare("SELECT COUNT(CPF)FROM professor WHERE cpf = '"+cpf+"';");
    if(query.exec()){
        query.next();
        qtd = query.value(0).toInt();
    } else {
        qtd = 0;
    }
    return qtd;
}

bool ProfessorController::excluirProfessor(QString cpf){
    bool statusDB;
    QSqlQuery query_prof;
    QSqlQuery query_pess;
    query_prof.prepare("delete from professor where cpf = '"+cpf+"';");
    query_pess.prepare("delete from pessoa where cpf = '"+cpf+"';");
    if(query_prof.exec() && query_pess.exec()){
        statusDB = true;
    } else {
        statusDB = false;
    }
    return statusDB;
}

int ProfessorController::verificaDisc(QString cpf){
    int qtd;
    QSqlQuery query;
    query.prepare("SELECT COUNT(CPF_professor)FROM disciplina WHERE CPF_professor = '"+cpf+"';");
    if(query.exec()){
        query.next();
        qtd = query.value(0).toInt();
    } else {
        qtd = 0;
    }
    return qtd;
}
