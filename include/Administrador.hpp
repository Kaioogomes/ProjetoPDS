#ifndef ADM_H
#define ADM_H

#include "Aluno.hpp"

#include <string>

#define SENHA_ADM "senha_adm"

class Administrador{
    private:
        std::string _senha = SENHA_ADM;
        int teste;
    public:
        Administrador();
        std::string get_senha();
        void ativar_contrato(Aluno &aluno);
        void desligar_aluno(Aluno &aluno);
        

};


#endif
