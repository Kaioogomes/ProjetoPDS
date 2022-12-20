#ifndef ADM_H
#define ADM_H

#include "Aluno.hpp"

#include <string>
#include <iostream>

class Administrador{
    private:
        std::string _senha = "senha_adm";
    public:
        Administrador();
        bool verificar_senha();
        void ativar_contrato(Aluno &aluno);
        void desligar_aluno(Aluno &aluno);
        

};


#endif
