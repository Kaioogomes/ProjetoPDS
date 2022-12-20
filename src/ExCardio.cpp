// std::string Exercicio::get_descricao() const {
//     //Formatar descricao padrao;
// }
#include "ExCardio.hpp"

ExCardio::ExCardio(
                           std::string nome,
                           tempo_t tempo_exec,
                           std::string instrucoes,
                           tempo_t tempo):
    
    Exercicio(nome, tempo, CARDIO),
    _tempo_execucao(tempo_exec),
    _instrucoes(instrucoes)
{
}

std::string ExCardio::get_descricao() const{
    //Definir descricao Cardio
}
