#include "Exercicio.hpp"

Exercicio::Exercicio(
    std::string nome,
    tempo_t tempo,
    TipoExerc tipo,
    std::string instrucoes):
    _nome(nome), _tempo(tempo), 
    _instrucoes(instrucoes), _tipo(tipo)
    {
}

std::string Exercicio::get_descricao() const {
    //Formatar descricao padrao;
}

bool Exercicio::operator<(const Exercicio &ex){
    if(_tipo == ex._tipo){
        return (_nome < ex._nome);
    }

    return (_tipo < ex._tipo);
}