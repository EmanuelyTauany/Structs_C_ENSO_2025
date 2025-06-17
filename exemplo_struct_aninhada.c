#include <stdio.h>
#include <string.h>

struct Disciplina {
	char nome[30];
	char professor[50];
	int cargaHoraria;
};

struct Aluno{
	char nome[50];
	int idade;
	int matricula;
	struct Disciplina disciplinas[3];
};

void cadastrarDisciplina(struct Disciplina *disciplina,
 const char *nome, const char *professor, int cargaHoraria){
	strcpy(disciplina->nome, nome);
	strcpy(disciplina->professor, professor);
	disciplina->cargaHoraria = cargaHoraria;
}

void cadastrarAluno(struct Aluno *aluno, const char *nome,
 int idade, int matricula){
	strcpy(aluno->nome, nome);
	aluno->idade = idade;
	aluno->matricula = matricula;

	cadastrarDisciplina(&aluno->disciplinas[0], "Matematica",
     "Prof. Joao Silva", 60);
	cadastrarDisciplina(&aluno->disciplinas[1], "Historia", "Prof. Julia Costa",
	 45);
	cadastrarDisciplina(&aluno->disciplinas[2], "Quimica", "Prof. Carlos Souza",
	 50);
}

void exibirAluno(struct Aluno *aluno){
	int i;

	printf("Nome do aluno: %s\n", aluno->nome);
	printf("Idade: %d\n", aluno->idade);
	printf("Matricula: %d\n", aluno->matricula);

	printf("Disciplinas:\n");
	for(i = 0;i < 3; i++){
		printf("Disciplina %d:\n", i + 1);
		printf("    Nome: %s\n", aluno->disciplinas[i].nome);
		printf("    Professor: %s\n", aluno->disciplinas[i].professor);
	}
}

int main(){
	struct Aluno aluno1;
	cadastrarAluno(&aluno1, "Alana Lima", 20, 1234);
	exibirAluno(&aluno1);
	return 0;
}
