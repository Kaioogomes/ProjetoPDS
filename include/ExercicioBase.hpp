#ifndef EXERCICIO_B_H
#define EXERCICIO_B_H

#include <string>

// extern ExercicioBase exercicio_db;

enum TipoExerc{
    CARDIO, MUSCULACAO
};

class ExercicioBase{
    private:
        std::string _nome;
        TipoExerc _tipo;
        unsigned _codigo;
        // static unsigned _gera_cod;
    public:
        ExercicioBase(std::string nome, TipoExerc tipo, unsigned codigo);
        std::string get_nome();
        TipoExerc get_tipo() const;
        unsigned get_codigo();
        std::string get_descricao();
        bool operator<(const ExercicioBase &ex);
        bool operator==(const ExercicioBase &ex);
};



#endif
