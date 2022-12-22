#include "Sistema.hpp"
#include <unistd.h>

int main(){   
    Sistema sistema;
    sistema.leitura_arquivos();
    sistema.inicializar_sistema();

    return 0;
}
