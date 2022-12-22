#include "doctest.h"
#include "Administrador.hpp"

Administrador adm;
Aluno *Paulo;
std::map<unsigned, Aluno*> alunos;

TEST_CASE("Teste da senha"){   
    CHECK(adm.match_senha("senha_adm"));
    CHECK_FALSE(adm.match_senha("ta_errado"));
    CHECK_FALSE(adm.match_senha("senhaadm"));
}

TEST_CASE("Teste adicionar novo aluno"){
    Paulo = adm.novo_aluno("Paulo", 1);
    alunos.emplace(1, Paulo);
    Aluno *aluno = alunos.at(1);
    CHECK(aluno->get_matricula());
    CHECK_EQ(aluno->get_nome(), "Paulo");
    CHECK_EQ(aluno->get_matricula(), 1);
}

TEST_CASE("Teste de alterar situação do contrato de aluno"){
    CHECK(Paulo->status_contrato());
    adm.desligar_aluno(*Paulo);
    CHECK_FALSE(Paulo->status_contrato());
    adm.religar_aluno(*Paulo);
    CHECK(Paulo->status_contrato());
    delete Paulo;
}


