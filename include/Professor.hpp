#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.hpp"
#include "Aluno.hpp"
#include "Exercicio.hpp"

class Professor: public Pessoa{
    private:

    public:
        Professor(std::string nome, std::string cpf);
        Exercicio *novo_exercicio();
        Treino *novo_treino();
        std::string ficha_aluno(Aluno &aluno); //
        void modificar_treino(Aluno &aluno);
        void associar_ficha(Aluno &aluno, std::map<unsigned, Treino *> ficha);
};

#endif   
