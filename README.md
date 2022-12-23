# Sistema de Administração de Academias

A proposta do projeto é criar um Sistema simples de Administração para Academias, englobando funcionalidades
para Alunos, Professores e funcionários da Administração.

## Integrantes:

1 - Arthur Freiman

2 - Edson Sousa

3 - Kaio Gomes

## Users Stories

1 - Como aluno eu gostaria de ter acesso ao meu planejamento para que eu possa treinar.

2 - Como aluno eu gostaria de registrar dados do meu treino para que eu possa acompanhar minha evolução.

3 - Como professor eu gostaria de criar e editar fichas de treino para que eu possa instruir meus alunos.

4 - Como professor eu gostaria de acessar o histórico de treino de um aluno para que seja possível planejar suas próximas fichas.

5 - Como administrador eu gostaria de adicionar e alterar alunos e professores para que eu possa ter um controle sobre quem acessa a rede.

6 - Como administrador eu gostaria de saber quem entra e quem sai da academia, para ter controle do fluxo de alunos e professores.

## O makefile utilizado usa os comandos a seguir

make - compila os arquivos
make tests - roda os testes de unidade
make run - compila e executa o programa
make clean - apaga os arquivos compilados e executáveis

## Como usar o programa
Ao executar o programa, será solicitado se o usuário é um aluno, professor ou administrador.

Como aluno, será solicitado sua matrícula e, em seguidas, apresentadas 2 opções imprimir seu treino ou verificar seu progresso.

Como professor,  será solicitada a senha dos professores para acessar ("senha_prof") e, a seguir, as opções serão: criar um novo exercício no banco de dados, alterar o treino de um aluno, adicionar um novo treino no banco de dados ou imprimir uma lista dos exercícios disponíveis, com seus códigos de armazenamento e tipo (sendo C representando o tipo cardio e M, musculação).

Como administrador,  será solicitada a senha dos administradores para acessar ("senha_adm"), poderá adicionar um novo aluno no sistema, desligar e religar o vínculo de um aluno, imprimir uma lista de todos os alunos, com suas respectivas matrículas e situação de contrato, e verificar a situação de contrato de um aluno em específico.

Além disso, todos os usuários possuem a opção de retornar ao início,  permitindo a entrada de outros usuários.

## Problemas encontrados

TIvemos problmea ao acessar a base de dados do treinos, mas treinos adicionados durante o programa funcionam normalmente.

