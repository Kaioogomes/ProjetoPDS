#ifndef TREINO_H
#define TREINO_H

#include "Exercicio.hpp"
#include <set>
#include <vector>

// extern ExercicioBase exercicio_db;
// extern Treino treino_db;

class Treino{
    private:
        std::set<Exercicio *> _exercicios;
        std::string _categoria;
    public:
        Treino(std::vector<unsigned> _codigos);
        ~Treino();
};



#endif