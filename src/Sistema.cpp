#include "Sistema.hpp"

using namespace std;

void inicializar_sistema(std::map<unsigned, Aluno>  &aluno_db,
                         std::map<unsigned, Exercicio> &exercicio_db,
                         std::map<unsigned, Treino> &treino_db){
    cout<<"Sistema Iniciado"<<endl;
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

bool verificar_senha(Professor &professor){
    string senha;
    cout<<endl<<"Senha: ";
    cin>>senha;
    if(professor.get_senha() == senha)
        return true;
    cout<<"Senha Incorreta"<<endl<<"1 - Tentar Novamente     2 - Voltar";
    unsigned opcao;
    cin>>opcao;
    while(opcao != 1 || opcao != 2){
        cout<<"Opcao Inválida ";
        cin>>opcao;
    }
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
    while(opcao != 1 || opcao != 2){
        cout<<"Opcao Inválida ";
        cin>>opcao;
    }
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
        //system("clear");
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
        //system("clear");
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
        //system("clear");
        cout<<"1 - Voltar ao Inicio     2 - Adicionar Novo Aluno"<<endl;
        cout<<"3 - Desligar Aluno       4 - Religar Aluno"<<endl;

        cin>>comando;
        switch(comando){
            case 1:
                return;
            case 2:
                break;
            case 3:{
                unsigned matricula;
                cout<<"Matrícula a ser desligada: ";
                cin>>matricula;
                //administrador.desligar_aluno();
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
