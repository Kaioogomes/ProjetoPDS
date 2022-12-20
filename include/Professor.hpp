#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Aluno.hpp"
#include "Exercicio.hpp"

#define SENHA_PROF "senha_prof"

class Professor{
    private:
        std::string _senha = SENHA_PROF;
    public:
        Professor();
        std::string get_senha();
        Exercicio *novo_exercicio();
        //Treino *novo_treino();
        std::string ficha_aluno(Aluno &aluno);
        void modificar_treino(Aluno &aluno);
        //void associar_ficha(Aluno &aluno, std::map<unsigned, Treino *> ficha);
};

#endif   
