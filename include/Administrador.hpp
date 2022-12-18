#ifndef ADM_H
#define ADM_H

#include "Pessoa.hpp"
#include "Aluno.hpp"

class Administrador: public Pessoa{
    private:


    public:
        Administrador(std::string nome, std::string cpf);
        void ativar_contrato(Aluno &aluno);
        void desligar_aluno(Aluno &aluno);
        

};


#endif
