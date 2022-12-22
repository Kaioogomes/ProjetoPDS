#include "Professor.hpp"

Professor::Professor(){};

bool Professor::match_senha(std::string candidata){
    return _senha == candidata;
}

void Professor::adicionar_treino(Aluno &aluno, Treino *treino){
    aluno.adicionar_treino(treino);
}

ExercicioBase *Professor::novo_exercicio_base(std::string nome, TipoExerc tipo, unsigned codigo){
    return new ExercicioBase(nome, tipo, codigo);
}

ExCardio *Professor::configurar_cardio(ExercicioBase *base, unsigned tempo){
    return new ExCardio(base, tempo);
}

ExMusculacao *Professor::configurar_musculacao(ExercicioBase *base, unsigned series, unsigned repeticoes){
    return new ExMusculacao(base, series, repeticoes);
}

void Professor::mudar_ficha(Aluno &aluno, std::set<Treino *> nova_ficha){
    aluno.trocar_ficha(nova_ficha);
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
