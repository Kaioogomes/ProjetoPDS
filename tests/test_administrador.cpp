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
    CHECK(Paulo.status_contrato());
    adm.desligar_aluno(Paulo);
    CHECK_FALSE(Paulo.status_contrato());
    adm.religar_aluno(Paulo);
    CHECK(Paulo.status_contrato());
}

TEST_CASE("Teste adicionar novo aluno"){
    Administrador adm;
    std::map<unsigned, Aluno *> aluno_db;
    Aluno *Matheus = adm.novo_aluno("Matheus", 1);
    aluno_db.emplace(1, Matheus);
    Aluno *aluno = aluno_db.at(1);
    CHECK(aluno->get_matricula());
    CHECK_EQ(aluno->get_nome(), "Matheus");
    CHECK_EQ(aluno->get_matricula(), 1);
}
