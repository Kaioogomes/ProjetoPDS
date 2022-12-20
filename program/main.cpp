#include "Aluno.hpp"
#include "Professor.hpp"
#include "Administrador.hpp"

using namespace std;

bool verificar_senha_professor(){
    // Professor professor;
    // return professor.verificar_senha();  
}

bool verificar_senha_administrador(){
    // Administrador administrador;
    // return administrador.verificar_senha();  
}

unsigned entrar_sistema(){
    unsigned i;
    cout<<endl<<"Selecione Tipo de Usuário:"<<endl;
    cout<<"1 - Aluno"<<endl<<"2 - Professor"<<endl<<"3 - Administrador"<<endl;
    cin>>i;
    switch(i){
        case 1: 
            return 1;
        case 2:
            if(verificar_senha_professor())
                return 2;
        case 3:
            if(verificar_senha_administrador())
                return 3;
        }
    return entrar_sistema();
}

void sistema_aluno(){};

void sistema_professor(){};

void sistem_administrador(){
    Administrador administrador;
    unsigned comando;
    for(;;){
        system("cls");
        cout<<"1 - Voltar            2 - Adicionar Novo Aluno"<<endl;
        cout<<"3 - Desligar Aluno    4 - Religar Aluno"<<endl;

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

int main(){   
    cout<<"Sistema Iniciado"<<endl;
    for(;;){
        switch(entrar_sistema()){
            case 1:
                break;
            case 2:
                break;
            case 3:
        }
    }
}
