#ifndef ALUNO_H
#define ALUNO_H

#include <map>
#include <set>
#include "Treino.hpp"

class Aluno{
    private:
        std::string _nome;
        unsigned _matricula;
        bool _contrato_ativo;
        std::set<Treino *> _ficha;      
    public:
        Aluno(std::string nome, unsigned matricula);
        ~Aluno();
        void adicionar_treino(Treino *treino);
        void trocar_ficha(std::set<Treino *> nova_ficha);
        bool status_contrato();
        void ativar_contrato();
        void desativar_contrato();
        std::string get_nome();
        unsigned get_matricula();
        bool operator<(const Aluno &outro); //comparacao por matricula
        std::string get_info();
};


#endif
