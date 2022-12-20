#include "Administrador.hpp"

Administrador::Administrador(std::string nome, std::string cpf){}

void Administrador::ativar_contrato(Aluno &aluno){
    aluno.ativar_contrato();
}

void Administrador::desligar_aluno(Aluno &aluno){
    aluno.desativar_contrato();
}
