#include "Aluno.hpp"
#include "Professor.hpp"
#include "Administrador.hpp"
#include "Sistema.hpp"

int main(){   
    Administrador adm;
    Professor prof;
    std::map<unsigned, Aluno> aluno_db;
    std::map<unsigned, Exercicio> exercicios_db;
    std::map<unsigned, Treino> treino_db;

    inicializar_sistema(aluno_db, exercicios_db, treino_db); 
}
