#include "doctest.h"
#include "ExercicioBase.hpp"

unsigned seed_codigo = 0;

ExercicioBase e("Supino", MUSCULACAO, ++seed_codigo);
ExercicioBase e2("Esteira", CARDIO, ++seed_codigo);


TEST_CASE("Testando construtor"){
    CHECK_EQ(e.get_nome(), "Supino");
    CHECK_EQ(e.get_tipo(), MUSCULACAO);     
    CHECK_EQ(e.get_codigo(), 1);


    CHECK_EQ(e2.get_nome(), "Esteira");
    CHECK_EQ(e2.get_tipo(), CARDIO);
    CHECK_EQ(e2.get_codigo(), 2);
}

// TEST_CASE("Teste geração de código"){
//     ExercicioBase e("Supino", MUSCULACAO);
//     ExercicioBase e2("Esteira", CARDIO);

//     CHECK_EQ(e.get_codigo(), 1);
//     CHECK_EQ(e2.get_codigo(), 2);
// }

TEST_CASE("Testando descrição"){
    CHECK_EQ(e.get_descricao(), "1,Supino");
    CHECK_EQ(e2.get_descricao(),"2,Esteira");
}