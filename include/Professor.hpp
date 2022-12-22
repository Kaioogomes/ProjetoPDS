#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Aluno.hpp"
#include "Treino.hpp"

#define SENHA_PROF "senha_prof"

#define DEFALT_SERIES 3
#define DEFALT_REPETICOES 15
#define DEFALT_TEMPO 0

class Professor{
    private:
        std::string _senha = SENHA_PROF;
    public:
        Professor();
        bool match_senha(std::string candidata);
        ExercicioBase *novo_exercicio_base(std::string nome, TipoExerc tipo, unsigned codigo);
        ExCardio *configurar_cardio(ExercicioBase *base, 
                                    unsigned tempo = DEFALT_TEMPO);
        ExMusculacao *configurar_musculacao(ExercicioBase *base, 
                                            unsigned series = DEFALT_SERIES, 
                                            unsigned repeticoes = DEFALT_REPETICOES);
        Treino *novo_treino(std::string categoria, std::set<Exercicio *> selecionados);
        void mudar_ficha(Aluno &aluno, std::set<Treino *> nova_ficha);
        void adicionar_treino(Aluno &aluno, Treino *treino);
        void remover_treino(Aluno &aluno, Treino *treino);
        std::string lista_exercios(std::map<unsigned, ExercicioBase *> &exercicios);
};

#endif   
