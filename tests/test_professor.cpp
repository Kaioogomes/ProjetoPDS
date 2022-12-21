#include "doctest.h"
#include "Professor.hpp"

TEST_CASE("Teste do construtor e da senha"){
    Professor prof;
    CHECK(prof.match_senha("senha_prof"));
    CHECK_FALSE(prof.match_senha("blabla"));
    CHECK_FALSE(prof.match_senha("senha-prof"));
}
