#include "Aluno.hpp"

Aluno::Aluno(std::string nome, unsigned matricula): 
    _nome(nome),
    _matricula(matricula),
    _contrato_ativo(true){
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

void Aluno::trocar_ficha(std::set<Treino *> nova_ficha){
    _ficha = nova_ficha;
}

std::string Aluno::get_nome(){
    return _nome;
}

unsigned Aluno::get_matricula(){
    return _matricula;
}

bool Aluno::operator<(const Aluno &outro){
    return _matricula < outro._matricula;
}


std::string Aluno::get_info(){
    std::string info = std::to_string(_matricula) + ',' +
                       _nome + ',';
    
    info += (_contrato_ativo)?"1":"0";
    
    return info;
}
