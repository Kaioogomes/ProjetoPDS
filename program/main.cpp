// #include "Aluno.hpp"
// #include "Professor.hpp"
// #include "Administrador.hpp"
#include "Sistema.hpp"
#include <unistd.h>

int main(){   
    Sistema sistema;
    sistema.leitura_arquivos();
    sleep(15);
    sistema.inicializar_sistema();

    return 0;
}
