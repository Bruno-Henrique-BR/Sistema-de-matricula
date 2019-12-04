#include "alunocontroller.h"

alunocontroller::alunocontroller()
{

}

bool alunocontroller::pesquisaPorMatricula(QString matricula){
    bool statusDB;
    QSqlQuery query;
    query.prepare("select * from aluno where matricula='"+matricula+"'");
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

bool alunocontroller::salvarDados(alunomodel *alunoModel){
    bool statusDB;
    qDebug() << alunoModel->getCPF();
    QSqlQuery query_pessoa;
    query_pessoa.prepare("insert into pessoa values"
                         "('"+alunoModel->getCPF()+"', '"+alunoModel->getNome()+"', '"+alunoModel->getLogradouro()+"', '"+alunoModel->getSetor()+"', '"+alunoModel->getCidade()+"', '"+alunoModel->getEstado()+"', '"+alunoModel->getCelular()+"', '"+alunoModel->getEmail()+"', 'A')");
    QSqlQuery query_aluno;
    query_aluno.prepare("insert into aluno values "
                       "('"+alunoModel->getMatricula()+"', '"+alunoModel->getCPF()+"', "+alunoModel->getId_curso()+", "+alunoModel->getAno()+")");
    if(query_pessoa.exec() && query_aluno.exec()){
        statusDB = true;
    } else {
        statusDB = false;
    }
    return statusDB;
}

QSqlQuery alunocontroller::pesquisaMatricula(QString matricula){    QSqlQuery query;
    query.prepare("select a.matricula, a.cpf, p.nome, a.id_curso, a.ano from aluno a, pessoa p where a.cpf = p.cpf and a.matricula = '"+matricula+"'");
    return query;
}

int alunocontroller::totalAlunos(){
    int qtdResult;
    QSqlQuery query;
    query.prepare("SELECT COUNT(CPF)FROM aluno;");
    if(query.exec()){
        query.next();
        qtdResult = query.value(0).toInt();
    } else {
        qtdResult = 0;
    }
    return qtdResult;
}

QSqlQuery alunocontroller::pesquisaTodosAlunos(){
    QSqlQuery query;
    query.prepare("select a.matricula, a.cpf, p.nome, a.id_curso, a.ano from aluno a, pessoa p where a.cpf = p.cpf");
    return query;
}

int alunocontroller::verificaAlunoExists(QString matricula){
    int qtdResult;
    QSqlQuery query;
    query.prepare("SELECT COUNT(CPF)FROM aluno where matricula = '"+matricula+"';");
    if(query.exec()){
        query.next();
        qtdResult = query.value(0).toInt();
    } else {
        qtdResult = 0;
    }
    return qtdResult;
}

bool alunocontroller::excluirAluno(QString matricula){
    bool statusDB;
    QSqlQuery query_aluno;
    query_aluno.prepare("delete from aluno where matricula = '"+matricula+"';");
    // Excluir pessoa
    QSqlQuery query_tmp;
    query_tmp.prepare("select cpf from aluno where matricula = '"+matricula+"'");
    query_tmp.exec();
    query_tmp.next();
    QString cpf_aluno = query_tmp.value(0).toString();
    QSqlQuery query_pessoa;
    query_pessoa.prepare("delete from pessoa where cpf ='"+cpf_aluno+"'");
    if(query_aluno.exec() && query_pessoa.exec()){
        statusDB = true;
    } else {
        statusDB = false;
    }
    return statusDB;
}
