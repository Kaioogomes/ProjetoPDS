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
        static unsigned _gera_matricula;

        
    public:
        Aluno(std::string nome);
        ~Aluno();
        void adicionarTreino(Treino *treino);
        void set_ficha();
        void set_ficha(std::set<Exercicio *> ficha);
        
        void ativar_contrato();
        void desativar_contrato();
        // Treino *get_treino(unsigned n_treino);
        // void modificar_treino(unsigned n_treino, Treino treino);
    

};


#endif
