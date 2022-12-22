#include "Treino.hpp"
    
void Treino::adicionar_exercicios(std::set<Exercicio *> novos_ex) {
    _exercicios.insert(novos_ex.begin(), novos_ex.end());
}

Treino::Treino(std::string tipo_treino): _tipo_treino(_tipo_treino){

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

std::string Treino::get_descricao(){
    std::string desc = _tipo_treino + ',' +
                       std::to_string(_exercicios.size()) + ',';

    for(auto &ex: _exercicios){
        desc += ex->get_descricao() + ',';
    }

    return desc;
}

std::string Treino::get_descricao_simplificada(){
    std::string desc = _tipo_treino + ',' +
                       std::to_string(_exercicios.size());

    return desc;
}
