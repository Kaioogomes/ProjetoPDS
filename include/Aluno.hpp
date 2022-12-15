#ifndef ALUNO_H
#define ALUNO_H

#include <set>
#include "Pessoa.hpp"
#include "Treino.hpp"

class Aluno: public Pessoa{
    private:
        bool _contrato_ativo;
        std::set<Treino *> _ficha;

        
    public:
        Aluno(std::string nome, std::string cpf);
        ~Aluno();
        void ativar_contrato();
        void desativar_contrato();
    

};


#endif
