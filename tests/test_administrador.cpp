#include "doctest.h"
#include "Administrador.hpp"

TEST_CASE("Teste do construtor e da senha"){
    Administrador adm;
    CHECK(adm.match_senha("senha_adm"));
    CHECK_FALSE(adm.match_senha("ta_errado"));
    CHECK_FALSE(adm.match_senha("senhaadm"));
}

TEST_CASE("Teste de alterar situação do contrato de aluno"){
    Administrador adm;
    Aluno Paulo = Aluno ("Paulo", 1);
    CHECK_EQ(Paulo.status_contrato(), true);
    adm.desligar_aluno(Paulo);
    CHECK_EQ(Paulo.status_contrato(), false);
    adm.religar_aluno(Paulo);
    CHECK_EQ(Paulo.status_contrato(), true);
}
