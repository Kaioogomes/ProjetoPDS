#include "ExMusculacao.hpp"

ExMusculacao::ExMusculacao(
                           ExercicioBase *base,
                           unsigned series,
                           unsigned repeticoes
                           ):
    
    Exercicio(base),
    _series(series),
    _repeticoes(repeticoes)
{
}

std::string ExMusculacao::get_descricao() const{
    //Definir descricao Musculacao
}
