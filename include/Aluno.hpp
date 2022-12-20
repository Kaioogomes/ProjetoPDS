#ifndef ALUNO_H
#define ALUNO_H

#include <map>
#include <set>
#include "Exercicio.hpp"

class Aluno{
    private:
        bool _contrato_ativo;
        std::map<unsigned, std::set<Exercicio *>> _ficha;

        
    public:
        Aluno(std::string nome, std::string cpf);
        ~Aluno();
        void ativar_contrato();
        void desativar_contrato();
        // Treino *get_treino(unsigned n_treino);
        // void modificar_treino(unsigned n_treino, Treino treino);
    

};


#endif
