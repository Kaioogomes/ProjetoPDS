#include "Sistema.hpp"

#include <unistd.h>
#include <iostream>


using namespace std;

Sistema::Sistema(){}
void Sistema::inicializar_sistema(){
    entrar_sistema();
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
    cout<<"Senha: ";
    cin>>senha;

    return senha;
}
Aluno *Sistema::encontrar_aluno(unsigned matricula){
    return (aluno_db.find(matricula))->second;
}

ExercicioBase *Sistema::encontrar_ex_base(unsigned codigo){
    return (exercicio_base_db.find(codigo)->second);
}
bool Sistema::entrar_sistema(){
    unsigned i;
    system("clear");
    cout<<"Sistema Iniciado"<<endl;
    i = get_informacao_num(std::string("Selecione Tipo de Usuário:\n") +
                           "1 - Aluno\n2 - Professor\n3 - Administrador\n4 - Fechar Sistema\n\n");

    if(escolha_modo(i))
        return true;
    return entrar_sistema();
}
void Sistema::sistema_aluno(Aluno &aluno){
    unsigned comando;
    for(;;){
        system("clear");
        comando = get_informacao_num(std::string ("Sistema de ") + aluno.get_nome()+ "\n"
                                                  "1 - Voltar ao Inicio     2 - Vizualizar ficha\n"+
                                                  "3 - Imprimir Treino\n");
        switch(comando){
            case 1:
                return;
            case 2:
                cout<<aluno.get_descricao_ficha();
                break;
        }
    }
}
void Sistema::sistema_professor(){
    unsigned comando;
    for(;;){
        system("clear");
        comando = get_informacao_num(std::string("Modo de professor\n") +
                                                "1 - Voltar ao Inicio           2 - Novo Exercício\n"+
                                                "3 - Alterar Treino de Aluno    4 - Novo Treino\n"+
                                                "5 - Listar Exercícios\n");
        switch(comando){
            case 1:
                return;
            case 2:{
                TipoExerc tipo;
                string nome; 
                unsigned opcao;
                unsigned codigo = exercicio_base_db.size()+1;
                opcao = get_informacao_num(std::string("Tipo do exercício: \n")+
                                                "1 - Musculação   2 - Cardio\n");
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
                                                       "3 -  Nova Ficha\n");
                switch (opcao){
                case 1:{
                    unsigned codigo;
                    codigo = get_informacao_num(std::string("Código do treino: \n"));
                    Treino *treino = treino_db.find(codigo)->second;
                    prof.adicionar_treino(aluno, treino);
                    cout<<endl<<"Treino de "<<aluno.get_nome()<<" adicionado"<<endl;
                    getchar();
                    getchar();
                    break;
                }
                case 2:{
                    unsigned codigo;
                    char ident;
                    std::cout<<"Identificação do treino: "<<endl;
                    std::cin>>ident;
                    prof.remover_treino(aluno, ident);
                    cout<<endl<<"Treino "<<ident<<" de "<<aluno.get_nome()<<" removido";
                    getchar();
                    getchar();
                    break;       
                }    
                case 3:{
                    unsigned numero;
                    std::set<Treino *> nova_ficha;
                    unsigned codigo;
                    codigo = get_informacao_num(std::string("Código do exercício: \n"));
                    Treino *treino = treino_db.find(codigo)->second;
                    nova_ficha.emplace(treino);                       
                    prof.mudar_ficha(aluno, nova_ficha);
                    cout<<endl<<"Ficha de "<<aluno.get_nome()<<" alterada";
                    getchar();
                    getchar();
                    break;  
                }   
                default:
                    break;
                }
                break;
            }
            case 4:{
                std::string categoria;
                getchar();
                std::cout<<"Tipo de treino: ";
                getline(cin, categoria);
                Treino treino = Treino (categoria);
                unsigned numero;
                numero = get_informacao_num("Número de exercícios: ");
                std::set<Exercicio *> selecionados;
                unsigned codigo;
                for(int i = 0; i<numero; i++){
                    codigo = get_informacao_num(std::string("Código do exercício: "));
                    ExercicioBase *exercicio_base = encontrar_ex_base(codigo);
                    if(exercicio_base->get_tipo()==CARDIO){
                        ExCardio *exercicio;
                        unsigned tempo;
                        tempo = get_informacao_num(std::string("Tempo: "));
                        exercicio = prof.configurar_cardio(exercicio_base, tempo);
                        selecionados.emplace(exercicio);
                    }
                    else{
                        ExMusculacao *exercicio;
                        unsigned series, repeticoes;
                        series = get_informacao_num(std::string("Séries: "));
                        repeticoes = get_informacao_num(std::string("Repetições: "));
                        exercicio = prof.configurar_musculacao(exercicio_base, series, repeticoes);
                        selecionados.emplace(exercicio);
                    }
                    std::cout<<endl<< exercicio_base->get_nome()<<" adiconado"<<endl;
                    getchar();
                }                    
                std::cout<<"Treino de "<<categoria<<" adiconado"<<endl;
                getchar();
                break;
            }
            case 5:{
                if(exercicio_base_db.size() != 0)
                    lista_exercicios();
                break;
            }
        }
    }
}
void Sistema::sistema_administrador(){
    unsigned comando;
    for(;;){
        system("clear");
        comando = get_informacao_num(std::string("Modo de Administrador\n")+
                                                 "1 - Voltar ao Inicio     2 - Adicionar Novo Aluno\n"+
                                                 "3 - Desligar Aluno       4 - Religar Aluno\n"+
                                                 "5 - Listar Alunos        6 - Verificar Situação de Contrato\n");
        unsigned matricula;
        switch(comando){
            case 1:
                system("clear");
                return;
            case 2:{
                string nome;
                matricula = aluno_db.size()+1;
                std::cout<<"Nome do aluno: ";
                getchar();
                getline(cin, nome);
                Aluno *novo = adm.novo_aluno(nome, matricula);
                aluno_db.emplace(matricula, novo);
                std::cout<<"Aluno "<<nome<<" adicionado com matricula "<<matricula<<endl;
                getchar();
                break;
            }
            case 3:{
                matricula = get_informacao_num("Matrícula a ser desligada: ");
                Aluno &aluno = (*aluno_db.find(matricula)->second);
                adm.desligar_aluno(aluno);
                std::cout<<"Contrato de "<<aluno.get_nome()<<" desligado"<<endl;
                getchar();
                getchar();
                break;
            }
            case 4:{
                matricula = get_informacao_num("Matrícula a ser religada: ");
                Aluno &aluno = *encontrar_aluno(matricula);
                adm.religar_aluno(aluno);
                std::cout<<"Contrato de "<<aluno.get_nome()<<" religado"<<endl;
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
                matricula = get_informacao_num("Matrícula: ");
                Aluno aluno = *encontrar_aluno(matricula);
                if(aluno.status_contrato())
                    std::cout<<"Contrato de "<<aluno.get_nome()<<" ativo"<<endl;
                else
                    std::cout<<"Contrato de "<<aluno.get_nome()<<" desativado"<<endl;
                getchar();
                getchar();
                break;
            }
        }        
    }
}
bool Sistema::escolha_modo(unsigned modo){
    switch(modo){
        case 1: {
            unsigned matricula = get_informacao_num("Matrícula: ");
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
        case 4:
            return fechar_sistema();
            break;
    }
    return false;
}
void Sistema::lista_alunos(){
    std::stringstream lista(adm.lista_alunos(aluno_db));

    unsigned esp1 = 9, esp2 = 16;
    system("clear");
    std::cout <<"Matrícula\t"<< "Nome\t\t\t\t"  <<"Situação contrato\n" << std::endl;


    std::string atual, info;
    while(std::getline(lista, atual)){
        std::stringstream at(atual);
        std::getline(at, info, ',');

        std::cout << setw(esp1) << left << info <<"\t" ;

        std::getline(at, info, ',');

        std::cout << setw(esp2) << left << info << "\t\t";

        std::getline(at, info);

        std::cout << ((info == "1")?"Ativo":"Desativo") << std::endl;
    }

    getchar();
    getchar();
}

void Sistema::lista_exercicios(){
    std::stringstream lista(prof.lista_exercios(exercicio_base_db));

    unsigned esp1 = 6, esp2 = 24;
    system("clear");
    std::cout <<"Código\t\t   "<<"Nome\t\t\t\t"<<"Tipo"<<std::endl;


    std::string atual, info;
    while(std::getline(lista, atual)){
        std::stringstream at(atual);
        std::getline(at, info, ',');
        

        std::cout << setw(esp1) << left << info <<"\t" ;

        std::getline(at, info, ',');

        std::cout << setw(esp2) << left << info <<"\t\t";
        
        std::getline(at, info);

        std::cout << setw(esp2)<<left <<((info == "0")?"C":"M") << std::endl;

    }

    getchar();
    getchar();
}

void Sistema::leitura_arquivos(){

    ifstream database;
    database.open("exercicios_b_db.txt");


    if(database.is_open()){
        int numero_de_exercicios;
        database >> numero_de_exercicios;
        database.ignore(1);

        for(int i = 0; i < numero_de_exercicios; ++i){
            // string nome;
            // unsigned tipo_n;
            // unsigned codigo;
            std::string linha_exercicio;
            std::getline(database, linha_exercicio);            

            ler_exercicio(linha_exercicio);

            // database >> tipo_n;

            // database >> codigo;

            // cout << i << '\t' << nome << '\t' << tipo_n << '\t' << codigo << endl;

            // ExercicioBase *novo = new ExercicioBase(nome,(tipo_n)?MUSCULACAO:CARDIO,codigo);

            // exercicio_base_db.emplace(codigo, novo);
            // database.ignore(1);
        }
    } 
    // else{
    //     cout << "Não consegue né" << endl;
    // }

    database.close();

    // ifstream database("alunos_db.txt");
    database.open("alunos_db.txt");
    

    if(database.is_open()){
        int numero_de_alunos;

        database >> numero_de_alunos;
        database.ignore(1);

        for(int i = 0; i < numero_de_alunos; i++){
            std::string linha_aluno;
            
            // string nome = "nem leu";
            // unsigned matricula = 69;
            // bool contrato_ativo;

            std::getline(database, linha_aluno);

            ler_aluno(linha_aluno);

            // database >> matricula;

            // database >> contrato_ativo;

            // Aluno *novo = new Aluno(nome,matricula);

            // aluno_db.emplace(matricula, novo);

            // if(contrato_ativo == false){
            //     adm.desligar_aluno(*novo);
            // }
            // database.ignore(1);
        }
    } 
    // else {
    //     cout << "Não consegue né" << endl;
    // }

    database.close();
}

void Sistema::ler_exercicio(const std::string &linha_exercicio){
    std::stringstream ss(linha_exercicio);
    // std::string buffer;

    std::string codigo_s;
    std::string nome;
    unsigned tipo_u;

    std::getline(ss, codigo_s, ',');
    std::getline(ss, nome, ',');
    ss >> tipo_u;

    unsigned codigo = std::atoi(codigo_s.c_str());

    ExercicioBase *novo = new ExercicioBase(nome, (tipo_u == 0)?CARDIO:MUSCULACAO, codigo);

    exercicio_base_db.emplace(codigo, novo);
}

void Sistema::ler_aluno(const std::string &linha_aluno){
    std::stringstream ss(linha_aluno);
    // std::string buffer;

    std::string codigo_s;
    std::string nome;
    bool status_contrato;

    std::getline(ss, codigo_s, ',');
    std::getline(ss, nome, ',');
    ss >> status_contrato;

    unsigned codigo = std::atoi(codigo_s.c_str());

    Aluno *novo = new Aluno(nome, codigo);

    if(!status_contrato) adm.desligar_aluno(*novo);

    aluno_db.emplace(codigo, novo);
}

void Sistema::vizualiza_ficha(Aluno &aluno){
    std::stringstream lista(aluno.get_descricao_ficha());
        unsigned esp1 = 6, esp2 = 20;
    system("clear");
    std::cout <<"Treino\t"<< "Tipo\t\t\t\t"  <<"Número de Exercícios\n" << std::endl;


    std::string atual, info;
    while(std::getline(lista, atual)){
        std::stringstream at(atual);
        std::getline(at, info, ',');

        std::cout << setw(esp1) << left << info <<"\t" ;

        std::getline(at, info, ',');

        std::cout << setw(esp2) << left << info << "\t\t";

        std::getline(at, info);

        std::cout << info<<endl;
    }

    getchar();
    getchar();
}

bool Sistema::fechar_sistema(){
    std::ofstream database_alunos;
    database_alunos.open("alunos_db.txt", std::ofstream::out | std::ofstream::trunc);
    unsigned qtd_alunos_atualizada = aluno_db.size();
    database_alunos << qtd_alunos_atualizada << std::endl;
    for(auto &a: aluno_db){
        database_alunos << a.second->get_info() << std::endl;
    }
    database_alunos.close();

    std::ofstream database_exercicio;
    database_exercicio.open("exercicios_b_db.txt", std::ofstream::out | std::ofstream::trunc);
    unsigned qtd_exercicio_atualizada = exercicio_base_db.size();
    database_exercicio << qtd_exercicio_atualizada << std::endl;
    for(auto &a: exercicio_base_db){
        database_exercicio << a.second->get_info() << std::endl;
    }
    database_exercicio.close();

    return true;
}
