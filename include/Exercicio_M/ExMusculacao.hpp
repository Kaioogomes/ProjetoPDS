#ifndef MUSCULACAO_H
#define MUSCULACAO_H

#include "Exercicio.hpp"

class ExMusculacao: public Exercicio {
    public:
        ExMusculacao(std::string nome,
                     unsigned series = 3,
                     unsigned repeticoes = 10,
                     std::string instrucoes = 0,
                     unsigned tempo = 30);

        virtual std::string get_descricao() const override;
        // virtual bool operator==(const Exercicio &ex) override;
        virtual std::ostream& operator<<(const Exercicio &ex) override;
        // virtual std::ostream& operator>>(Exercicio &ex) override;  

    private:
        unsigned _series;
        unsigned _repeticoes;
        // unsigned _tempo_descanso;
};




#endif