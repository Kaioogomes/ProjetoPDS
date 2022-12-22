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
        ExercicioBase *novo_exercicio_base(std::string nome, TipoExerc tipo, unsigned codigo);
        ExCardio *configurar_cardio(ExercicioBase *base, unsigned tempo);
        ExMusculacao *configurar_musculacao(ExercicioBase *base, unsigned series, unsigned repeticoes);
        Treino *novo_treino(std::string categoria, 
                            std::set<Exercicio *> selecionados);
                            // std::set<ExCardio *> selecionados_c, 
                            // std::set<ExMusculacao *> selecionados_m);
        // std::string ficha_aluno(unsigned matricula);
        void adicionar_treino(Aluno &aluno, Treino *treino);
        void remover_treino(Aluno &aluno, Treino *treino);
        //void associar_ficha(Aluno &aluno, std::map<unsigned, Treino *> ficha);
};

#endif   
