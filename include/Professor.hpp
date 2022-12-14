#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.hpp"
#include "Aluno.hpp"
#include "Exercicio.hpp"

class Professor: public Pessoa{
    private:

    public:
        Professor();
        Exercicio *novo_exercicio();
        Treino *novo_treino();
        std::string ficha_aluno(Aluno &aluno);
        void modificar_treino(Aluno &aluno);
        void associar_ficha(Aluno &aluno, std::set<Treino *> ficha);
};

#endif   