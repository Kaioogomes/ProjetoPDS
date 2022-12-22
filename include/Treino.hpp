#ifndef TREINO_H
#define TREINO_H

#include "ExCardio.hpp"
#include "ExMusculacao.hpp"
#include <set>
#include <vector>

// extern ExercicioBase exercicio_db;
// extern Treino treino_db;

class Treino{
    private:
        // std::set<ExCardio *> _exercicios_cardio;
        // std::set<ExMusculacao *> _exercicio_musculacao;
        std::string _categoria;
        std::set<Exercicio *> _exercicios;
    public:
        Treino(std::string categoria);
        ~Treino();
        // void adicionar_cardio(std::set<ExCardio *> ex_cardio);
        // void adicionar_musculacao(std::set<ExMusculacao *> ex_musc);
        void adicionar_exercicios(std::set<Exercicio *> novos_ex);
};



#endif
