#include "Treino.hpp"
    
void Treino::adicionar_exercicios(std::set<Exercicio *> novos_ex) {
    _exercicios.insert(novos_ex.begin(), novos_ex.end());
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
