#include "Administrador.hpp"

Administrador::Administrador(){};

// bool Administrador::verificar_senha(){
//     std::string senha;
//     std::cout<<std::endl<<"Senha: ";
//     std::cin>>senha;
//     if(senha == _senha)
//         return true;
//     std::cout<<"Senha Incorreta"<<std::endl<<"1 - Tentar Novamente        2 - Voltar";
//     unsigned opcao;
//     std::cin>>opcao;
//     if(opcao == 1)
//         return verificar_senha();
//     if(opcao == 2)
//         return false;
// }

std::string Administrador::get_senha(){
    return _senha;
}

void Administrador::religar_aluno(Aluno &aluno){
    aluno.ativar_contrato();
}

void Administrador::desligar_aluno(Aluno &aluno){
    aluno.desativar_contrato();
}

