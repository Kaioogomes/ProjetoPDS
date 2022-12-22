#include "doctest.h"
#include "Professor.hpp"


std::map<unsigned, ExercicioBase *> exercicios;
ExercicioBase *novo1;
ExercicioBase *novo2;
Professor prof;

TEST_CASE("Teste da senha"){
    CHECK(prof.match_senha("senha_prof"));
    CHECK_FALSE(prof.match_senha("blabla"));
    CHECK_FALSE(prof.match_senha("senha-prof"));
}

TEST_CASE("Teste novo exercício"){
    novo1 = prof.novo_exercicio_base("esteira", CARDIO, 1);
    exercicios.emplace(1, novo1);
    novo2 = prof.novo_exercicio_base("supino", MUSCULACAO, 2);
    exercicios.emplace(2, novo2);
    ExercicioBase exercicio1 = *(exercicios.find(1)->second);
    ExercicioBase exercicio2 = *(exercicios.find(2)->second);
    CHECK_EQ(novo1->get_nome(), "esteira");
    CHECK_EQ(novo1->get_tipo(), CARDIO);
    CHECK_EQ(novo1->get_descricao(), "1,esteira");
    CHECK_EQ(novo2->get_nome(), "supino");
    CHECK_EQ(novo2->get_tipo(), MUSCULACAO);
    CHECK_EQ(novo2->get_descricao(), "2,supino");
}

TEST_CASE("Teste configurar exercícios"){
    ExCardio *cardio = prof.configurar_cardio(novo1, 15);
    ExMusculacao *musculacao = prof.configurar_musculacao(novo2, 3, 15);
    CHECK_EQ(cardio->get_tipo(), CARDIO);
    CHECK_EQ(cardio->get_exercicio_base(), novo1);
    CHECK_EQ(cardio->get_descricao(), "1,esteira,15");
    CHECK_EQ(musculacao->get_tipo(), MUSCULACAO);
    CHECK_EQ(musculacao->get_exercicio_base(), novo2);
    CHECK_EQ(musculacao->get_descricao(), "2,supino,3,15");
    delete novo1;
    delete novo2;
}
