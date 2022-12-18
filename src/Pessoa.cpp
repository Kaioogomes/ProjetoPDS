#include "Pessoa.hpp"

Pessoa::Pessoa(std::string nome, std::string cpf):_nome(nome), _cpf(cpf){}

std::string Pessoa::get_nome(){
    return _nome;
}

std::string Pessoa::get_cpf(){
    return _cpf;
}
