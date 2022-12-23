#include "Treino.hpp"
    
// void Treino::adicionar_exercicios(std::vector<Exercicio *> &novos_ex) {
//     _exercicios.insert(_exercicios.end(), nop)
// }

Treino::Treino(std::string tipo_treino, std::vector<Exercicio *> &selecionados): 
_tipo_treino(tipo_treino)
{
    _exercicios = selecionados;
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
