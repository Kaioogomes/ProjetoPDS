#include "ExMusculacao.hpp"

ExMusculacao::ExMusculacao(
                           std::string nome,
                           unsigned series,
                           unsigned repeticoes,
                           tempo_t tempo):
    
    Exercicio(nome, tempo, MUSCULACAO),
    _series(series),
    _repeticoes(repeticoes)
{
}

std::string ExMusculacao::get_descricao() const{
    //Definir descricao Musculacao
}
