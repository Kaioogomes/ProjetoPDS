#ifndef TREINO_H
#define TREINO_H

#include "Exercicio.hpp"
#include <map>

class Treino{
    private:
        std::map<unsigned, Exercicio *> _exercicios;
    public:
        Treino();
        ~Treino();
};



#endif