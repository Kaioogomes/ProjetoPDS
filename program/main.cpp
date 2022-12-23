#include "Sistema.hpp"
#include <unistd.h>

int main(){   
    Sistema sistema;
    sistema.leitura_arquivos();
    sleep(10);
    sistema.inicializar_sistema();

    return 0;
}
