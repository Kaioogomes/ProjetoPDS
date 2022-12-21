#include "Sistema.hpp"

#include <iostream>
using namespace std;

Sistema::Sistema(){}

void Sistema::inicializar_sistema(){
    for(;;){
        switch(entrar_sistema()){
            case 1:
                unsigned matricula;
                cout<<"Matrícula: ";
                cin>>matricula;
                for(auto it = aluno_db.begin(); it != aluno_db.end(); it = next(it)){
                    if(it->first == matricula)
                        sistema_aluno(it->second);
                    break;
                }
                break;
            case 2:
                sistema_professor();
                break;
            case 3:
                sistema_administrador();
                break;
         }
     }
}

bool Sistema::verificar_senha_professor(Professor &professor){
    string senha;
    cout<<endl<<"Senha: ";
    cin>>senha;
    if(professor.get_senha() == senha)
        return true;
    cout<<endl<<"Senha Incorreta"<<endl<<"1 - Tentar Novamente     2 - Voltar"<<endl;
    unsigned opcao;
    cin>>opcao;
    for(;;){
        if(opcao == 1)
            return verificar_senha(professor);
        if(opcao == 2)
            return false;
        cout<<"Opcao Inválida ";
        cin>>opcao;
    }
};

bool Sistema::verificar_senha_administrador(){
    string senha;
    cout<<endl<<"Senha: ";
    cin>>senha;
    if(adm.match_senha(senha))
        return true;
    cout<<endl<<"Senha Incorreta"<<endl<<"1 - Tentar Novamente          2 - Voltar"<<endl;
    unsigned opcao;
    cin>>opcao;
    for(;;){
        if(opcao == 1)
            return verificar_senha(adm);
        if(opcao == 2)
            return false;
        cout<<"Opcao Inválida ";
        cin>>opcao;
    }
}

unsigned Sistema::entrar_sistema(){
    unsigned i;
    system("clear");
    cout<<"Sistema Iniciado"<<endl;
    cout<<endl<<"Selecione Tipo de Usuário:"<<endl;
    cout<<"1 - Aluno"<<endl<<"2 - Professor"<<endl<<"3 - Administrador"<<endl;
    cin>>i;
    switch(i){
        case 1: 
            return 1;
        case 2:{
            if(verificar_senha(prof))
                return 2;
            }
        case 3:{
            if(verificar_senha(adm))
                return 3;
            }
        }
    return entrar_sistema();
}

void Sistema::sistema_aluno(Aluno &aluno){
    unsigned comando;
    for(;;){
        system("clear");
        cout<<"1 - Voltar ao Inicio     2 - Imprimir Treino"<<endl;

        cin>>comando;
        switch(comando){
            case 1:
                return;
            case 2:
            //aluno.imprimir_treino();
                break;
        }
    }
}

void Sistema::sistema_professor(){
    unsigned comando;
    for(;;){
        system("clear");
        cout<<"1 - Voltar ao Inicio     2 - "<<endl;

        cin>>comando;
        switch(comando){
            case 1:
                return;
            case 2:
                break;
        }
    }
}

void Sistema::sistema_administrador(){
    unsigned comando;
    for(;;){
        system("clear");
        cout<<"Modo de Administrador"<<endl<<endl;
        cout<<"1 - Voltar ao Inicio     2 - Adicionar Novo Aluno"<<endl;
        cout<<"3 - Desligar Aluno       4 - Religar Aluno"<<endl;

        cin>>comando;
        switch(comando){
            case 1:
                system("clear");
                return;
            case 2:
                break;
            case 3:{
                unsigned matricula;
                cout<<"Matrícula a ser desligada: ";
                cin>>matricula;
                for(auto it = aluno_db.begin(); it != aluno_db.end(); it = next(it)){
                    if(it->first == matricula){
                        adm.desligar_aluno(it->second);
                        cout<<"Aluno "<<(it->second).get_nome()<<" desligado"<<endl;
                        getchar();
                        getchar();
                        break;
                    }

                }
                break;
            }
            case 4:{
                unsigned matricula;
                cout<<"Matrícula a ser religada: ";
                cin>>matricula;
                //administrador.ativar_contrato();
                break;    
            }
        }        
    }
}
