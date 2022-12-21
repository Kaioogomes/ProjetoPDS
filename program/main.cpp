#include "Aluno.hpp"
#include "Professor.hpp"
#include "Administrador.hpp"
#include "Sistema.hpp"

int main(){   
    Administrador adm;
    Professor prof;
    std::map<unsigned, Aluno> aluno_db;
    std::map<unsigned, ExCardio> cardio_db;
    std::map<unsigned, ExMusculacao> musculacao_db;
    std::map<unsigned, Treino> treino_db;

    inicializar_sistema(aluno_db, cardio_db, musculacao_db,  treino_db); 
}
