#include "doctest.h"
#include "Professor.hpp"

TEST_CASE("Teste do construtor e da senha"){
    Professor prof;
    CHECK_EQ(prof.get_senha(), SENHA_PROF);
}
