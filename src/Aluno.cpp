#include "Aluno.hpp"

unsigned Aluno::_gera_matricula = 0;

Aluno::Aluno(std::string nome): _nome(nome){
    _matricula = ++_gera_matricula;
}

Aluno::~Aluno(){};

bool Aluno::status_contrato(){
    return _contrato_ativo;
}

void Aluno::ativar_contrato(){
    _contrato_ativo = true;
}

void Aluno::desativar_contrato(){
    _contrato_ativo = false;
}

void Aluno::adicionar_treino(Treino *treino){
    unsigned tam_ficha = _ficha.size();

    _ficha.insert(treino);
}

void Aluno::set_gerador_matricula(unsigned mat){
    _gera_matricula = mat;
}

// Treino *Aluno::get_treino(unsigned n_treino){
//     return _ficha.find(n_treino)->second;
// }

// void Aluno::modificar_treino(unsigned n_treino, Treino treino){
//     *(_ficha.find(n_treino)->second) = treino;
// }
