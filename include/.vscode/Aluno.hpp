#ifndef ALUNO_H
#define ALUNO_H

#include <set>
#include "Pessoa.hpp"
#include "Exercicio.hpp"

class Aluno: public Pessoa{
    private:
        bool _contrato_ativo;
        std::set<Exercicio *> _ficha;

        
    public:
        Aluno(std::string nome, std::string cpf);
        ~Aluno();
    

};


#endif