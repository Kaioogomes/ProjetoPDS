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
<<<<<<< HEAD
        void adicionar_treino(Treino *treino);
        void trocar_ficha(std::set<Treino *> ficha);
        bool status_contrato();
=======
        bool situacao_contrato();
        void adicionarTreino(Treino *treino);
        void set_ficha();
        void set_ficha(std::set<Exercicio *> ficha);
>>>>>>> 7c2fbe16988433c168f3b16a189ba003afe4702c
        void ativar_contrato();
        void desativar_contrato();
        void set_gerador_matricula(unsigned mat);
        // Treino *get_treino(unsigned n_treino);
        // void modificar_treino(unsigned n_treino, Treino treino);
    

};


#endif
