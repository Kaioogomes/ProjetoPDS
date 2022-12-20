#include "Exercicio.hpp"

Exercicio::Exercicio(
                     ExercicioBase *base

    // std::string nome,
    // tempo_t tempo,
    // TipoExerc tipo
                     ):
    _base(base)
    {}

// bool Exercicio::operator<(const Exercicio &ex){
//     if(_tipo == ex._tipo){
//         return (_nome < ex._nome);
//     }

//     return (_tipo < ex._tipo);
// }