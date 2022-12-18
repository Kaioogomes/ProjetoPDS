#include "Aluno.hpp"

Aluno::Aluno(std::string nome, std::string cpf):Pessoa(nome, cpf){}

Aluno::~Aluno(){};

void Aluno::ativar_contrato(){
    _contrato_ativo = true;
}

void Aluno::desativar_contrato(){
    _contrato_ativo = false;
}

Treino *Aluno::get_treino(unsigned n_treino){
    return _ficha.find(n_treino)->second;
}

void Aluno::modificar_treino(unsigned n_treino, Treino treino){
    *(_ficha.find(n_treino)->second) = treino;
}
