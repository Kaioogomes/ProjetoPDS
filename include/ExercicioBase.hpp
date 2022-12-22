#ifndef EXERCICIO_B_H
#define EXERCICIO_B_H

#include <string>

enum TipoExerc{
    CARDIO, MUSCULACAO
};

class ExercicioBase{
    private:
        std::string _nome;
        TipoExerc _tipo;
        unsigned _codigo;
    public:
        ExercicioBase(std::string nome, TipoExerc tipo, unsigned codigo);
        ExercicioBase(){};
        std::string get_nome();
        TipoExerc get_tipo() const;
        unsigned get_codigo();
        std::string get_descricao();
        bool operator<(const ExercicioBase &ex);
        bool operator==(const ExercicioBase &ex);
        std::string get_info();
};

#endif
