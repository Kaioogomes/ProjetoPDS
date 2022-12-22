#ifndef SISTEMA_H
#define SISTEMA_H

#include <map>

#include "Aluno.hpp"
#include "Administrador.hpp"
#include "Professor.hpp"
#include "ExCardio.hpp"
#include "ExMusculacao.hpp"
// #include <initializer_list>

class Sistema{
    private:
        Professor prof;
        Administrador adm;
        std::map<unsigned, Aluno *>  aluno_db;
        std::map<unsigned, ExercicioBase *> exercicio_base_db;
        // std::map<unsigned, ExCardio> cardio_db;
        // std::map<unsigned, ExMusculacao> musculacao_db;
        std::map<unsigned, Treino *> treino_db;
    public:
        Sistema();

        void inicializar_sistema();
        Aluno *encontrar_aluno(unsigned matricula);
        // bool verificar_senha_professor();
        // bool verificar_senha_administrador();
        std::string ler_senha();
        unsigned entrar_sistema();
        void sistema_aluno(Aluno &aluno);
        void sistema_professor();
        void sistema_administrador();
        void escolha_modo(unsigned modo);
        void lista_alunos();
};




#endif
