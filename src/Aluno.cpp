#include "Aluno.hpp"

Aluno::Aluno(std::string nome, std::string cpf):Pessoa(nome, cpf){}

Aluno::~Aluno(){};

void Aluno::ativar_contrato(){
    _contrato_ativo = true;
}

void Aluno::desativar_contrato(){
    _contrato_ativo = false;
}
