#ifndef EXERCICIO_H
#define EXERCICIO_H

#include <string>
#include "ExercicioBase.hpp"

class Exercicio{
    protected:
        ExercicioBase *_base;
    public:
        Exercicio(ExercicioBase *base);
        virtual ~Exercicio();
        virtual std::string get_descricao(){return "";};
        ExercicioBase *get_exercicio_base();
        TipoExerc get_tipo();
        bool operator<(const Exercicio &ex);
};

#endif
