#ifndef EXERCICIO_B_H
#define EXERCICIO_B_H

#include <string>

// extern ExercicioBase exercicio_db;

enum TipoExerc{
    CARDIO, MUSCULACAO
};

class ExercicioBase{
    private:
        unsigned _codigo;
        std::string _nome;
        TipoExerc _tipo;
        static unsigned _gera_cod;
    public:
        ExercicioBase(std::string nome, TipoExerc tipo);
        std::string get_nome();
        TipoExerc get_tipo();
        std::string get_descricao();
        bool operator<(const ExercicioBase &ex);
};



#endif
