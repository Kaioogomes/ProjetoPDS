#ifndef CARDIO_H
#define CARDIO_H

#include "Exercicio.hpp"

class ExCardio: public Exercicio {
    public:
        ExCardio(std::string nome,
                 tempo_t tempo_exec,    
                 std::string instrucoes = 0,
                 tempo_t tempo = tempo_t(0));

        virtual std::string get_descricao() const override;
        // virtual bool operator==(const Exercicio &ex) override;
        // virtual std::ostream& operator<<(const Exercicio &ex) override;
        // virtual std::ostream& operator>>(Exercicio &ex) override;  

    private:
        tempo_t _tempo_execucao;
        std::string _instrucoes;
        // unsigned _tempo_descanso;
};




#endif