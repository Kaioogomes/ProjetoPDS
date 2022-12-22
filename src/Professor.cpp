#include "Professor.hpp"

Professor::Professor(){};

bool Professor::match_senha(std::string candidata){
    return _senha == candidata;
}

void Professor::adicionar_treino(Aluno &aluno, Treino *treino){
    aluno.adicionar_treino(treino);
}

ExercicioBase *novo_exercicio(std::string nome, TipoExerc tipo, unsigned codigo){
    return new ExercicioBase(nome, tipo, codigo);
}

Treino *Professor::novo_treino(std::string categoria, std::set<ExercicioBase> selecionados, unsigned series_m, unsigned rep_m, unsigned tempo_c){
    Treino *novo = new Treino(categoria);

    std::set<ExCardio *> ex_cardio;
    std::set<ExMusculacao *> ex_musc;

    for(ExercicioBase ex: selecionados){
        if(ex.get_tipo() == CARDIO){
            ExCardio *novo_c = new ExCardio(&ex, tempo_c);

            ex_cardio.insert(novo_c);
        } else{
            ExMusculacao *novo_m = new ExMusculacao(&ex, series_m, rep_m);

            ex_musc.insert(novo_m);
        }
    }

    novo->adicionar_cardio(ex_cardio);
    novo->adicionar_musculacao(ex_musc);
}

//Treino *novo_treino();

//std::string ficha_aluno(Aluno &aluno);

//void modificar_treino(Aluno &aluno);

//void associar_ficha(Aluno &aluno, std::map<unsigned, Treino *> ficha);
