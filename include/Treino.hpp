#ifndef TREINO_H
#define TREINO_H

#include "ExCardio.hpp"
#include "ExMusculacao.hpp"
#include <set>
#include <vector>


class Treino{
    private:
        std::string _categoria;
        std::set<Exercicio *> _exercicios;
    public:
        Treino(std::string categoria);
        ~Treino();
        void adicionar_exercicios(std::set<Exercicio *> novos_ex);
};



#endif
