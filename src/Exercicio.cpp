#include "Exercicio.hpp"

Exercicio::Exercicio(
    std::string nome,
    tempo_t tempo,
    TipoExerc tipo):
    _nome(nome), 
    _tempo_descanso(tempo), 
    _tipo(tipo)
    {}

std::string Exercicio::get_descricao() const {
    //Formatar descricao padrao;
}

bool Exercicio::operator<(const Exercicio &ex){
    if(_tipo == ex._tipo){
        return (_nome < ex._nome);
    }

    return (_tipo < ex._tipo);
}