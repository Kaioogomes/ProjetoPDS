#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa{
    protected:
        std::string _nome;
        std::string _cpf;
    
    public:
        Pessoa(std::string nome, std::string cpf);
        std::string get_nome();
        std::string get_cpf();
};


#endif
