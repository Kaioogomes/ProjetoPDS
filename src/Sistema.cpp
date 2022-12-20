#include "Sistema.hpp"

bool verificar_senha(Professor &professor){
    std::string senha;
    std::cout<<std::endl<<"Senha: ";
    std::cin>>senha;
    if(professor.get_senha() == senha)
        return true;
    std::cout<<"Senha Incorreta"<<std::endl<<"1 - Tentar Novamente     2 - Voltar";
    unsigned opcao;
    std::cin>>opcao;
    if(opcao == 1)
        return verificar_senha(professor);
    if(opcao == 2)
        return false;
};

bool verificar_senha(Administrador &administrador){
    std::string senha;
    std::cout<<std::endl<<"Senha: ";
    std::cin>>senha;
    if(administrador.get_senha() == senha)
        return true;
    std::cout<<"Senha Incorreta"<<std::endl<<"1 - Tentar Novamente          2 - Voltar";
    unsigned opcao;
    std::cin>>opcao;
    if(opcao == 1)
        return verificar_senha(administrador);
    if(opcao == 2)
        return false;
}

unsigned entrar_sistema(){
    unsigned i;
    cout<<endl<<"Selecione Tipo de Usuário:"<<endl;
    cout<<"1 - Aluno"<<endl<<"2 - Professor"<<endl<<"3 - Administrador"<<endl;
    cin>>i;
    switch(i){
        case 1: 
            return 1;
        case 2:{
            Professor professor;
            if(verificar_senha(professor))
                return 2;
            }
        case 3:{
            Administrador administrador;
            if(verificar_senha(administrador))
                return 3;
            }
        }
    return entrar_sistema();
}

void sistema_aluno(Aluno &aluno){
    unsigned comando;
    for(;;){
        system("cls");
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

void sistema_professor(){
    Professor professor;
    unsigned comando;
    for(;;){
        system("cls");
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

void sistema_administrador(){
    Administrador administrador;
    unsigned comando;
    for(;;){
        system("cls");
        cout<<"1 - Voltar ao Inicio     2 - Adicionar Novo Aluno"<<endl;
        cout<<"3 - Desligar Aluno       4 - Religar Aluno"<<endl;

        cin>>comando;
        switch(comando){
            case 1:
                return;
            case 2:
                break;
            case 3:
                unsigned matricula;
                cout<<"Matrícula a ser desligada: ";
                cin>>matricula;
                //administrador.desligar_aluno();
                break;
            case 4:
                unsigned matricula;
                cout<<"Matrícula a ser religada: ";
                cin>>matricula;
                //administrador.ativar_contrato();
                break;    
        }        
    }
}
