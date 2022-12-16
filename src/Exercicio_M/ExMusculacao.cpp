#include "ExMusculacao.hpp"

ExMusculacao::ExMusculacao(
                           std::string nome,
                           unsigned series,
                           unsigned repeticoes,
                           std::string instrucoes,
                           tempo_t tempo):
    
    Exercicio(nome, tempo, MUSCULACAO, instrucoes)
{
        _series = series;
        _repeticoes = repeticoes;
}

std::string ExMusculacao::get_descricao() const{
    //Definir descricao Musculacao
}
