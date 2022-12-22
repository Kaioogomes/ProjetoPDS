#ifndef MUSCULACAO_H
#define MUSCULACAO_H

#include "Exercicio.hpp"


class ExMusculacao: public Exercicio {
    public:
        ExMusculacao(
                     ExercicioBase *base,
                     unsigned series,
                     unsigned repeticoes
                     );

        virtual ~ExMusculacao(){};
        virtual std::string get_descricao() override;  
    private:
        unsigned _series;
        unsigned _repeticoes;
};




#endif
