#include "ExercicioBase.hpp"

// unsigned ExercicioBase::_gera_cod = 0;

ExercicioBase::ExercicioBase(std::string nome, TipoExerc tipo, unsigned codigo):
    _nome(nome),
    _tipo(tipo),
    _codigo(codigo)
{
    // _codigo = ++_gera_cod;
}

std::string ExercicioBase::get_nome(){
    return _nome;
}

TipoExerc ExercicioBase::get_tipo() const{
    return _tipo;
}

std::string ExercicioBase::get_descricao(){
    std::string desc = std::to_string(_codigo) + ',' + _nome;

    return desc;
}

bool ExercicioBase::operator<(const ExercicioBase &ex){
    if(_tipo == ex._tipo) return _nome < ex._nome;

    return _tipo < ex._tipo;
}

bool ExercicioBase::operator==(const ExercicioBase &ex){
    return (_nome == ex._nome) &&
           (_tipo == ex._tipo);
}


unsigned ExercicioBase::get_codigo(){
    return _codigo;
}
