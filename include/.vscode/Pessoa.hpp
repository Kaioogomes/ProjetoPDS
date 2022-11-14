#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa{
    private:
        std::string _nome;
        std::string _cpf;
    
    public:
        Pessoa(std::string nome, std::string cpf);
};


#endif