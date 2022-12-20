#include "ExercicioBase.hpp"

bool ExercicioBase::operator<(const ExercicioBase &ex){
    if(_tipo == ex._tipo) return _nome < ex._nome;

    return _tipo < ex._tipo;
}


