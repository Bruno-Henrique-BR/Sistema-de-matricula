#-------------------------------------------------
#
# Project created by QtCreator 2019-11-06T16:37:36
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SistemaDeMatricula
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        alunocontroller.cpp \
        alunomodel.cpp \
        avisocadastrardisciplina.cpp \
        avisocadastrarprofessor.cpp \
        avisocadastroaluno.cpp \
        consultacadastroaluno.cpp \
        consultacadastrodisciplina.cpp \
        consultacadastroprofessor.cpp \
        disciplinacontroller.cpp \
        disciplinamodel.cpp \
        formcadastroaluno.cpp \
        formcadastrodisciplina.cpp \
        formcadastroprofessor.cpp \
        formexcluiraluno.cpp \
        formexcluirdisciplina.cpp \
        formexcluirprofessor.cpp \
        formlistaaluno.cpp \
        formlistadisciplina.cpp \
        formlistaprofessores.cpp \
        formpesquisaaluno.cpp \
        formpesquisadisciplina.cpp \
        formpesquisaprofessor.cpp \
        main.cpp \
        mainwindow.cpp \
        pessoacontroller.cpp \
        pessoamodel.cpp \
        professorcontroller.cpp \
        professormodel.cpp

HEADERS += \
        alunocontroller.h \
        alunomodel.h \
        avisocadastrardisciplina.h \
        avisocadastrarprofessor.h \
        avisocadastroaluno.h \
        consultacadastroaluno.h \
        consultacadastrodisciplina.h \
        consultacadastroprofessor.h \
        disciplinacontroller.h \
        disciplinamodel.h \
        formcadastroaluno.h \
        formcadastrodisciplina.h \
        formcadastroprofessor.h \
        formexcluiraluno.h \
        formexcluirdisciplina.h \
        formexcluirprofessor.h \
        formlistaaluno.h \
        formlistadisciplina.h \
        formlistaprofessores.h \
        formpesquisaaluno.h \
        formpesquisadisciplina.h \
        formpesquisaprofessor.h \
        mainwindow.h \
        pessoacontroller.h \
        pessoamodel.h \
        professorcontroller.h \
        professormodel.h

FORMS += \
        avisocadastrardisciplina.ui \
        avisocadastrarprofessor.ui \
        avisocadastroaluno.ui \
        consultacadastroaluno.ui \
        consultacadastrodisciplina.ui \
        consultacadastroprofessor.ui \
        formcadastroaluno.ui \
        formcadastrodisciplina.ui \
        formcadastroprofessor.ui \
        formexcluiraluno.ui \
        formexcluirdisciplina.ui \
        formexcluirprofessor.ui \
        formlistaaluno.ui \
        formlistadisciplina.ui \
        formlistaprofessores.ui \
        formpesquisaaluno.ui \
        formpesquisadisciplina.ui \
        formpesquisaprofessor.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
