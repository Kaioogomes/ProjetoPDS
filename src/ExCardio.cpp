#include "ExCardio.hpp"

ExCardio::ExCardio(
                    ExercicioBase *base,
                    unsigned tempo_exec
                //    std::string nome,
                //    tempo_t tempo_exec,
                //    std::string instrucoes,
                //    tempo_t tempo
                   ):
    
    Exercicio(base),
    _tempo_execucao(tempo_exec)
    // _instrucoes(instrucoes)
{
}

std::string ExCardio::get_descricao() const{
    //Definir descricao Cardio
}
