#ifndef EXERCICIO_H
#define EXERCICIO_H

#include <string>
#include <iostream>

enum TipoExerc{
    ALONGAMENTO, CARDIO, MUSCULACAO
};

struct tempo_t{
    unsigned _min = 0;
    unsigned _seg = 0;

    tempo_t(unsigned min, unsigned seg){
        _seg = seg;
        _min = min;
    }

    tempo_t(unsigned seg){
        _seg = seg % 60;
        _min = seg / 60;
    }
};

class Exercicio{
    protected:
        std::string _nome;
        TipoExerc _tipo;
        std::string _instrucoes;   
        tempo_t _tempo;
        // unsigned _series;
        // unsigned _repeticoes;
        // unsigned _tempo_descanso;

    public:
        Exercicio(
            std::string nome,
            tempo_t tempo,
            TipoExerc tipo = CARDIO,
            std::string instrucoes = 0
            // unsigned series = 3, 
            // unsigned repeticoes = 10,
            // unsigned tempo_descanso = 30
        );
        std::string get_nome();

        virtual std::string get_descricao() const;
        // virtual bool operator==(const Exercicio &ex) = 0;
        bool operator<(const Exercicio &ex);
        // virtual std::ostream& operator<<(const Exercicio &ex);
        // virtual std::ostream& operator>>(Exercicio &ex) = 0;
};

sdighjfsgkjh
#endif
