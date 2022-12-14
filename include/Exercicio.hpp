#ifndef EXERCICIO_H
#define EXERCICIO_H

#include <string>
#include <iostream>

class Exercicio{
    private:
        std::string _nome;
        unsigned _series;
        unsigned _repeticoes;
        unsigned _tempo_descanso;

    public:
        Exercicio(
            std::string nome, 
            unsigned series = 3, 
            unsigned repeticoes = 10,
            unsigned tempo_descanso = 30
        );
        std::string get_nome();
        unsigned get_series();
        unsigned get_repeticoes();
        unsigned get_tempo_descanso();

        bool operator==(const Exercicio &ex);
        std::ostream& operator<<(const Exercicio &ex);
        std::ostream& operator>>(const Exercicio &ex);
};


#endif