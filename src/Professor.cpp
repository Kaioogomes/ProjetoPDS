#include "Professor.hpp"
#include <iostream>

Professor::Professor(){};

// bool Professor::verificar_senha(){
//     std::string senha;
//     std::cout<<std::endl<<"Senha: ";
//     std::cin>>senha;
//     if(senha == _senha)
//         return true;
//     std::cout<<"Senha Incorreta"<<std::endl<<"1 - Tentar Novamente     2 - Voltar";
//     unsigned opcao;
//     std::cin>>opcao;
//     if(opcao == 1)
//         return verificar_senha();
//     if(opcao == 2)
//         return false;
// }

std::string Professor::get_senha(){
    return _senha;
}

//Exercicio *novo_exercicio();

//Treino *novo_treino();

//std::string ficha_aluno(Aluno &aluno);

//void modificar_treino(Aluno &aluno);

//void associar_ficha(Aluno &aluno, std::map<unsigned, Treino *> ficha);
