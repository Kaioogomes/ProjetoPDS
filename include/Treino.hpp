#ifndef TREINO_H
#define TREINO_H

#include "ExCardio.hpp"
#include "ExMusculacao.hpp"
#include <set>
#include <vector>


class Treino{
    private:
        std::string _tipo_treino;
        std::set<Exercicio *> _exercicios;
    public:
        Treino(std::string tipo_treino);
        ~Treino();
        void adicionar_exercicios(std::set<Exercicio *> novos_ex);
        std::string get_descricao();
        std::string get_descricao_simplificada();
};



#endif
