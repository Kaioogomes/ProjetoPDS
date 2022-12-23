#ifndef TREINO_H
#define TREINO_H

#include "ExCardio.hpp"
#include "ExMusculacao.hpp"
#include <set>
#include <vector>


class Treino{
    private:
        std::string _tipo_treino;
        std::vector<Exercicio *> _exercicios;
    public:
        Treino(std::string tipo_treino, std::vector<Exercicio *> &selecionados);
        ~Treino();
        // void adicionar_exercicios(std::vector<Exercicio *> &novos_ex);
        std::string get_descricao();
        std::string get_descricao_simplificada();
};



#endif
