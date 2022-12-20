#ifndef TREINO_H
#define TREINO_H

#include "Exercicio.hpp"
#include <set>

class Treino{
    private:
        std::set<Exercicio *> _exercicios;
    public:
        Treino();
        ~Treino();
};



#endif