#ifndef SISTEMA_H
#define SISTEMA_H

#include "Administrador.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Treino.hpp"

#include <iostream>

void inicializar_sistema(std::map<unsigned, Aluno>  &aluno_db,
                         std::map<unsigned, ExCardio> &cardio_db,
                         std::map<unsigned, ExMusculacao> &musculacao_db,
                         std::map<unsigned, Treino> &treino_db);

bool verificar_senha(Professor &professor);

bool verificar_senha(Administrador &administrador);

unsigned entrar_sistema();

void sistema_aluno(Aluno &aluno);

void sistema_professor();

void sistema_administrador();


#endif
