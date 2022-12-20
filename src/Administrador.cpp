#include "Administrador.hpp"

Administrador::Administrador(){};

std::string Administrador::get_senha(){
    return _senha;
}

void Administrador::ativar_contrato(Aluno &aluno){
    aluno.ativar_contrato();
}

void Administrador::desligar_aluno(Aluno &aluno){
    aluno.desativar_contrato();
}
