#include "Exercicio.hpp"

Exercicio::Exercicio(ExercicioBase *base):_base(base){}

Exercicio::~Exercicio(){}

bool Exercicio::operator<(const Exercicio &ex){
    return *_base < *(ex._base);
}

ExercicioBase *Exercicio::get_exercicio_base(){
    return _base;
}

TipoExerc Exercicio::get_tipo(){
    return _base->get_tipo();
}
