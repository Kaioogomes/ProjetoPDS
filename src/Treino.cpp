#include "Treino.hpp"

void Treino::adicionar_cardio(std::set<ExCardio *> ex_cardio){

}

void Treino::adicionar_musculacao(std::set<ExMusculacao *> ex_musc){
    
}

Treino::Treino(std::string categoria): _categoria(categoria){

}

Treino::~Treino(){
    for(ExCardio *ex_c: _exercicios_cardio){
        delete ex_c;
    }

    for(ExMusculacao *ex_m: _exercicio_musculacao){
        delete ex_m;
    }
}