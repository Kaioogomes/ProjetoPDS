#ifndef EXERCICIO_H
#define EXERCICIO_H

#include <string>
#include "ExercicioBase.hpp"

class Exercicio{
    protected:
        ExercicioBase *_base;
        // std::string _nome;
        // TipoExerc _tipo;
        // std::string _instrucoes;   
        // tempo_t _tempo_descanso;
        // unsigned _series;
        // unsigned _repeticoes;
        // unsigned _tempo_descanso;

    public:
        Exercicio(
            ExercicioBase *base
            // std::string nome,
            // tempo_t tempo,
            // TipoExerc tipo
            // std::string instrucoes = 0
            // unsigned series = 3, 
            // unsigned repeticoes = 10,
            // unsigned tempo_descanso = 30
        );
        // std::string get_nome();

        virtual std::string get_descricao() const = 0;
        // virtual bool operator==(const Exercicio &ex) = 0;
        bool operator<(const Exercicio &ex);
        // virtual std::ostream& operator<<(const Exercicio &ex);
        // virtual std::ostream& operator>>(Exercicio &ex) = 0;
};

#endif
