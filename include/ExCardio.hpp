#ifndef CARDIO_H
#define CARDIO_H

#include "Exercicio.hpp"

class ExCardio: public Exercicio {
    public:
        ExCardio(
                ExercicioBase *base,
                unsigned tempo_exec
                 );

        virtual ~ExCardio(){};
        virtual std::string get_descricao() override;  

    private:
        unsigned _tempo_execucao;
};


#endif
