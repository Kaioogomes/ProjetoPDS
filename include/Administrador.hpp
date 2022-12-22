#ifndef ADM_H
#define ADM_H

#include "Aluno.hpp"

#include <string>

#define SENHA_ADM "senha_adm"

class Administrador{
    private:
        std::string _senha = SENHA_ADM;
    public:
        Administrador();
        bool match_senha(std::string canditada);
        void religar_aluno(Aluno &aluno);
        void desligar_aluno(Aluno &aluno);
        Aluno *novo_aluno(std::string nome, unsigned matricula);
        std::string lista_alunos(std::map<unsigned, Aluno *> &alunos);
};


#endif
