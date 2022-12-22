#include "Treino.hpp"

// void Treino::adicionar_cardio(std::set<ExCardio *> ex_cardio){

// }

// void Treino::adicionar_musculacao(std::set<ExMusculacao *> ex_musc){
    
void Treino::adicionar_exercicios(std::set<Exercicio *> novos_ex) {

}

Treino::Treino(std::string categoria): _categoria(categoria){

}

Treino::~Treino(){
    
    for(Exercicio *ex: _exercicios){
        if(ex->get_tipo() == CARDIO){
            delete (ExCardio *) ex;
        } else{
            delete (ExMusculacao *) ex;
        }
    }

}