#include "doctest.h"
#include "Administrador.hpp"

TEST_CASE("Teste do construtor e da senha"){
    Administrador adm;
    CHECK_EQ(adm.get_senha(), SENHA_ADM);
}

TEST_CASE("Teste de alterar situação do contrato de aluno"){
    Administrador adm;
    Aluno Paulo = Aluno ("Paulo");
    CHECK_EQ(Paulo.status_contrato(), true);
    adm.desligar_aluno(Paulo);
    CHECK_EQ(Paulo.status_contrato(), false);
    adm.religar_aluno(Paulo);
    CHECK_EQ(Paulo.status_contrato(), true);
}
