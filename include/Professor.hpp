#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Aluno.hpp"
#include "Exercicio.hpp"

class Professor{
    private:
        std::string _senha = "senha_prof";
    public:
        Professor();
        bool verificar_senha();
        Exercicio *novo_exercicio();
        //Treino *novo_treino();
        std::string ficha_aluno(Aluno &aluno);
        void modificar_treino(Aluno &aluno);
        //void associar_ficha(Aluno &aluno, std::map<unsigned, Treino *> ficha);
};

#endif   
