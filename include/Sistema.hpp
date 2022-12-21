#ifndef SISTEMA_H
#define SISTEMA_H

#include <map>

#include "Aluno.hpp"
#include "Administrador.hpp"
#include "Professor.hpp"
#include "ExCardio.hpp"
#include "ExMusculacao.hpp"

class Sistema{
    private:
        Professor prof;
        Administrador adm;
        std::map<unsigned, Aluno>  aluno_db;
        std::map<unsigned, ExCardio> cardio_db;
        std::map<unsigned, ExMusculacao> musculacao_db;
        std::map<unsigned, Treino> treino_db;
    public:
        Sistema_classe();
        void inicializar_sistema();
        bool verificar_senha_professor();
        bool verificar_senha_administrador();
        unsigned entrar_sistema();
        void sistema_aluno(Aluno &aluno);
        void sistema_professor();
        void sistema_administrador();
};


#endif
