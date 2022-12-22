#ifndef MUSCULACAO_H
#define MUSCULACAO_H

#include "Exercicio.hpp"


class ExMusculacao: public Exercicio {
    public:
        ExMusculacao(
                     ExercicioBase *base,
                     unsigned series,
                     unsigned repeticoes
                    //  std::string nome,
                    //  unsigned series = 3,
                    //  unsigned repeticoes = 10,
                    //  tempo_t tempo = tempo_t(30)
                     );

        virtual ~ExMusculacao(){};
        virtual std::string get_descricao() override;
        // virtual bool operator==(const Exercicio &ex) override;
        // virtual std::ostream& operator<<(const Exercicio &ex) override;
        // virtual std::ostream& operator>>(Exercicio &ex) override;  

    private:
        unsigned _series;
        unsigned _repeticoes;
        // unsigned _tempo_descanso;
};




#endif