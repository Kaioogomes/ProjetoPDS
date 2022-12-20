#include "doctest.h"
#include "ExMusculacao.hpp"
#include "ExCardio.hpp"

extern unsigned seed_codigo;

extern ExercicioBase e;//("Supino", MUSCULACAO, ++seed_codigo);
extern ExercicioBase e2;//("Esteira", CARDIO, ++seed_codigo);

ExMusculacao em(&e, 3, 15);
ExCardio ec(&e2, 15);

TEST_CASE("Testando atribuição da base"){
    CHECK(*em.get_exercicio_base() == e);
    CHECK(*ec.get_exercicio_base() == e2);
}

TEST_CASE("Testando descrição"){
    CHECK_EQ(em.get_descricao(), "1,Supino,3,15");
    CHECK_EQ(ec.get_descricao(),"2,Esteira,15");    
}
