#ifndef SISTEMA_H
#define SISTEMA_H

#include "Administrador.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"

#include <iostream>
using namespace std;

bool verificar_senha(Professor &professor);

bool verificar_senha(Administrador &administrador);

unsigned entrar_sistema();

void sistema_aluno(Aluno &aluno);

void sistema_professor();

void sistema_administrador();


#endif
