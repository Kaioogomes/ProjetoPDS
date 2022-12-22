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
    char ident = 'A' + _ficha.size();

    _ficha.emplace(ident, treino);
}

void Aluno::remover_treino(char ident){
    _ficha.erase(ident);
}

void Aluno::trocar_ficha(std::set<Treino *> nova_ficha){
    _ficha.clear();

    char ident = 'A';
    for(auto treino: nova_ficha){
        _ficha.emplace(ident, treino);
        ++ident;
    }
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

std::string Aluno::get_descricao_ficha(){
    std::string desc = get_info();

    for(auto &ex: _ficha){
        desc += ',' + ex.first + "," + ex.second->get_descricao_simplificada();
    }
    return desc;
}

std::string Aluno::ver_treino(char ident){
    Treino *procurado = _ficha.find(ident)->second;

    return procurado->get_descricao();
}
