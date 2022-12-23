#include "Professor.hpp"

Professor::Professor(){};

bool Professor::match_senha(std::string candidata){
    return _senha == candidata;
}

void Professor::adicionar_treino(Aluno &aluno, Treino *treino){
    aluno.adicionar_treino(treino);
}

void Professor::remover_treino(Aluno &aluno, char ident){
    aluno.remover_treino(ident);
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

Treino *Professor::novo_treino(std::string categoria, std::vector<Exercicio *> &selecionados){
    Treino *novo = new Treino(categoria, selecionados);

    // novo->adicionar_exercicios(selecionados);

    return novo;
}

std::string Professor::lista_exercios(std::map<unsigned, ExercicioBase *> &exercicios){
    std::string lista;

    for(auto i = exercicios.begin(); i != exercicios.end(); i = next(i)){
        lista.append(i->second->get_info()+ '\n');
    }

    return lista;
}

