#include "Professor.hpp"

Professor::Professor(){};

bool Professor::match_senha(std::string candidata){
    return _senha == candidata;
}

void Professor::adicionar_treino(Aluno &aluno, Treino *treino){
    aluno.adicionar_treino(treino);
}

ExercicioBase *novo_exercicio(std::string nome, TipoExerc tipo, unsigned codigo){
    return new ExercicioBase(nome, tipo, codigo);
}



Treino *Professor::novo_treino(std::string categoria,
                               std::set<Exercicio *> selecionados){
                            //    std::set<ExCardio *> selecionados_c,
                            //    std::set<ExMusculacao *> selecionados_m){
    Treino *novo = new Treino(categoria);

    novo->adicionar_exercicios(selecionados);

    return novo;
}

//Treino *novo_treino();

//std::string ficha_aluno(Aluno &aluno);

//void modificar_treino(Aluno &aluno);

//void associar_ficha(Aluno &aluno, std::map<unsigned, Treino *> ficha);
