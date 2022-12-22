#ifndef SISTEMA_H
#define SISTEMA_H

#include <map>

#include "Aluno.hpp"
#include "Administrador.hpp"
#include "Professor.hpp"
#include "ExCardio.hpp"
#include "ExMusculacao.hpp"
#include <iomanip>
#include <sstream>
#include <ostream>
#include <fstream>

class Sistema{
    private:
        Professor prof;
        Administrador adm;
        std::map<unsigned, Aluno *>  aluno_db;
        std::map<unsigned, ExercicioBase *> exercicio_base_db;
        std::map<unsigned, Treino *> treino_db;
    public:
        Sistema();
        ~Sistema();
        void inicializar_sistema();
        Aluno *encontrar_aluno(unsigned matricula);
        ExercicioBase *encontrar_ex_base(unsigned codigo);
        std::string ler_senha();
        unsigned entrar_sistema();
        void sistema_aluno(Aluno &aluno);
        void sistema_professor();
        void sistema_administrador();
        void escolha_modo(unsigned modo);
        void lista_alunos();
        void lista_exercicios();
        void leitura_arquivos();
        unsigned get_informacao_num(std::string msg);
        void ler_exercicio(const std::string &linha_exercicio);
        void ler_aluno(const std::string &linha_aluno);
};




#endif
