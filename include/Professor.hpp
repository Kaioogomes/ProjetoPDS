#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Aluno.hpp"
#include "Treino.hpp"

#define SENHA_PROF "senha_prof"

class Professor{
    private:
        std::string _senha = SENHA_PROF;
    public:
        Professor();
        bool match_senha(std::string candidata);
        ExercicioBase *novo_exercicio(std::string nome, TipoExerc tipo, unsigned codigo);
        //Treino *novo_treino();
        // std::string ficha_aluno(unsigned matricula);
        void adicionar_treino(Aluno &aluno, Treino *treino);
        void remover_treino(Aluno &aluno, Treino *treino);
        //void associar_ficha(Aluno &aluno, std::map<unsigned, Treino *> ficha);
};

#endif   
