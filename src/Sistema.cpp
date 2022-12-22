#include "Sistema.hpp"

#include <iostream>
using namespace std;

Sistema::Sistema(){}

void Sistema::inicializar_sistema(){
    for(;;){
            entrar_sistema();
    }
}

unsigned Sistema::get_informacao_num(std::string msg){
    std::cout << msg;

    unsigned info;

    std::cin >> info;

    std::cout << std::endl;

    return info;
}

Sistema::~Sistema(){
    for(auto pair: aluno_db){
        delete pair.second;
    }

    for(auto pair: exercicio_base_db){
        delete pair.second;
    }

    for(auto pair: treino_db){
        delete pair.second;
    }
}


std::string Sistema::ler_senha(){
    string senha;
    cout<<endl<<"Senha: ";
    cin>>senha;

    return senha;
}

Aluno *Sistema::encontrar_aluno(unsigned matricula){
    return (aluno_db.find(matricula))->second;
}

unsigned Sistema::entrar_sistema(){
    unsigned i;
    system("clear");
    cout<<"Sistema Iniciado"<<endl;
    // cout<<endl<<"Selecione Tipo de Usuário:"<<endl;
    // cout<<"1 - Aluno"<<endl<<"2 - Professor"<<endl<<"3 - Administrador"<<endl;

    i = get_informacao_num(std::string("Selecione Tipo de Usuário:\n") +
                           "1 - Aluno\n2 - Professor\n3 - Administrador\n\n");

    // cin>>i;
    escolha_modo(i);
    return entrar_sistema();
}

void Sistema::sistema_aluno(Aluno &aluno){
    unsigned comando;
    for(;;){
        comando = get_informacao_num(std::string ("1 - Voltar ao Inicio     2 - Imprimir Treino"));
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
        comando = get_informacao_num(std::string("Modo de professor\n") +
                                                "1 - Voltar ao Inicio     2 - Novo Exercício\n"+
                                                "3 - Alterar Treino de Aluno\n");
        switch(comando){
            case 1:
                return;
            case 2:{
                TipoExerc tipo;
                string nome; 
                unsigned codigo = exercicio_base_db.size()+1;
                comando = get_informacao_num(std::string("Tipo do exercício: \n")+
                                                "1 - Musculação   2 - Cardio\n");
                unsigned opcao;
                cin>>opcao;
                switch (opcao){
                case 1:
                    tipo = MUSCULACAO;
                    break;
                case 2:
                    tipo = CARDIO;
                    break;
                default:
                    return;
                }
                std::cout<<"Nome do exercício: "<<endl;
                cin>>nome;
                ExercicioBase *novo = prof.novo_exercicio_base(nome, tipo, codigo);
                exercicio_base_db.emplace(codigo, novo);
                std::cout<<"Exercício "<<nome<<" adicionado com código "<<codigo<<endl;
                getchar();
                getchar();
                break;
            }
            case 3:{
                unsigned matricula;
                matricula = get_informacao_num(std::string("Matrícula do aluno: "));
                Aluno aluno = (*encontrar_aluno(matricula));
                unsigned opcao;
                opcao = get_informacao_num(std::string("1 - Adicionar treino   2 - Remover treino\n")+
                                                       "3 -  Nova Ficha\n      4 - Novo Treino\n");
                switch (opcao){
                case 1:{
                    unsigned codigo;
                    codigo = get_informacao_num(std::string("Código do exercício: \n"));
                    Treino *treino = treino_db.find(codigo)->second;
                    prof.adicionar_treino(aluno, treino);
                    cout<<"Treino adicionado";
                    getchar();
                    getchar();
                    break;
                }
                //case 2:{
                    //unsigned codigo;
                    //codigo = get_informacao_num(std::string("Código do exercício: \n"));
                    //Treino *treino = treino_db.find(codigo)->second;
                    //prof.remover_treino(aluno, treino);
                    //cout<<"Treino remover";
                    //getchar();
                    //getchar();
                    //break;       
                //}    
                case 3:{
                    unsigned numero;
                    numero = get_informacao_num("Número de treinos: ");
                    std::set<Treino *> nova_ficha;
                    unsigned codigo;
                    for(int i = 0; i<numero; i++){
                        codigo = get_informacao_num(std::string("Código do exercício: \n"));
                        Treino *treino = treino_db.find(codigo)->second;
                        nova_ficha.emplace(treino);                       
                    }
                    prof.mudar_ficha(aluno, nova_ficha);
                    cout<<"Ficha de "<<aluno.get_nome()<<" alterada";
                    getchar();
                    getchar();
                    break;  
                }   
                default:
                    break;
                }
            }
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
        cout<<"5 - Listar Alunos        6 - Verificar Situação de Contrato"<<endl;

        unsigned matricula;

        cin>>comando;
        switch(comando){
            case 1:
                system("clear");
                return;
            case 2:{
                string nome;
                matricula = aluno_db.size()+1;
                cout<<"Nome do aluno: ";
                cin>>nome;
                Aluno *novo = adm.novo_aluno(nome, matricula);
                aluno_db.emplace(matricula, novo);
                cout<<"Aluno "<<nome<<" adicionado com matricula "<<matricula<<endl;
                getchar();
                getchar();
                break;
            }
            case 3:{
                // unsigned matricula;
                // cout<<"Matrícula a ser desligada: ";
                // cin>>matricula;
                matricula = get_informacao_num("Matrícula a ser desligada: ");
                Aluno aluno = (*aluno_db.find(matricula)->second);
                adm.desligar_aluno(aluno);
                cout<<"Contrato de "<<aluno.get_nome()<<" desligado"<<endl;
                getchar();
                getchar();
                break;
            }
            case 4:{
                // unsigned matricula;
                // cout<<"Matrícula a ser religada: ";
                // cin>>matricula;
                matricula = get_informacao_num("Matrícula a ser religada: ");

                Aluno aluno = *encontrar_aluno(matricula);
                adm.religar_aluno(aluno);
                cout<<"Contrato de "<<aluno.get_nome()<<" religado"<<endl;
                getchar();
                getchar();
                break;    
            }
            case 5:{
                if(aluno_db.size() != 0)
                    lista_alunos();
                break;
            }
            case 6:{
                // unsigned matricula;
                // cout<<"Matrícula: ";
                // cin>>matricula;
                matricula = get_informacao_num("Matrícula: ");

                Aluno aluno = *encontrar_aluno(matricula);
                if(aluno.status_contrato())
                    cout<<"Contrato de "<<aluno.get_nome()<<" ativo"<<endl;
                else
                    cout<<"Contrato de "<<aluno.get_nome()<<"desativado"<<endl;
                getchar();
                getchar();
                break;
            }

        }        
    }
}


void Sistema::escolha_modo(unsigned modo){
    switch(modo){
        case 1: {
            unsigned matricula = get_informacao_num("Matrícula: ");
            // cout<<"Matrícula: ";
            // cin>>matricula;
            Aluno aluno = *encontrar_aluno(matricula);
            sistema_aluno(aluno);
            break;
        }
        case 2:
            if(prof.match_senha(ler_senha()))
                sistema_professor();
            break;
        case 3:
            if(adm.match_senha(ler_senha()))
                sistema_administrador();
            break;
    }
}

void Sistema::lista_alunos(){
    std::stringstream lista(adm.lista_alunos(aluno_db));

    unsigned esp1 = 30, esp2 = 10;

    std::cout << "Matrícula" << setw(esp1) << "Nome" << setw(esp2) << "Situação contrato\n" << std::endl;


    std::string atual, info;

    while(std::getline(lista, atual)){
        std::stringstream at(atual);
        std::getline(at, info, ',');

        std::cout << info << setw(esp1);

        std::getline(at, info, ',');

        std::cout << info << setw(esp2);

        std::getline(at, info, ',');

        std::cout << info << std::endl;
    }

    getchar();
    getchar();
}
