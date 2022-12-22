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

bool Administrador::match_senha(std::string candidata){
    return _senha == candidata;
}

void Administrador::religar_aluno(Aluno &aluno){
    aluno.ativar_contrato();
}

void Administrador::desligar_aluno(Aluno &aluno){
    aluno.desativar_contrato();
}

Aluno *Administrador::novo_aluno(std::string nome, unsigned matricula){
    return new Aluno(nome, matricula);
}

std::string Administrador::lista_alunos(std::map<unsigned, Aluno *> &alunos){
    std::string lista;

    for(auto i = alunos.begin(); i != alunos.end(); i = next(i)){
        lista.append(i->second->get_info()+ '\n');
    }

    return lista;
}
