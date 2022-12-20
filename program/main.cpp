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

    // cout<<"Sistema Iniciado"<<endl;
    // for(;;){
    //     switch(entrar_sistema()){
    //         case 1:
    //             unsigned matricula;
    //             cout<<"Matrícula: ";
    //             cin>>matricula;
    //             //sistema_aluno();
    //             break;
    //         case 2:
    //             sistema_professor();
    //             break;
    //         case 3:
    //             sistema_administrador();
    //             break;
    //     }
    // }
}
