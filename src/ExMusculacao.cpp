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

// ExMusculacao::~ExMusculacao(){
// }

std::string ExMusculacao::get_descricao() {
    std::string desc = _base->get_descricao()  + ',' +
                       std::to_string(_series) + ',' +
                       std::to_string(_repeticoes);
    return desc;
}
