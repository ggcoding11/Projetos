#include <stdio.h>
#include <locale.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void gerarResposta(int opcao, char resposta[30]){
	
	switch(opcao){
		case 1:
			strcpy(resposta, "Pedra");
		break;
		
		case 2:
			strcpy(resposta, "Papel");
		break;
		
		case 3:
			strcpy(resposta, "Tesoura");
		break;
	}
}

void realizarDuelo(char j1[30], char j2[30]){
	printf("%s X %s\n\n", j1, j2);
	
	if (!(strcmp(j1, j2))){
		printf("EMPATE!");
	} else {
		if ((strcmp(j1, "Tesoura") == 0 && strcmp(j2, "Pedra") == 0) || 
            (strcmp(j1, "Pedra") == 0 && strcmp(j2, "Papel") == 0) || 
            (strcmp(j1, "Papel") == 0 && strcmp(j2, "Tesoura") == 0)) {
        	printf("M�quina vence!\n");
        } else {
			printf("Jogador vence!\n");
		}
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	srand(time(NULL));
	
	int opcaoPlayer, opcaoCPU;
	char jogadaPlayer[30], jogadaCPU[30];
	char reiniciar;
	
	do {
		do { 
			limparTela();
					
			printf("PEDRA, PAPEL E TESOURA, por JeeJ\n\n");
		
			printf("Prepare - se...\n\n");
			
			printf("1 - Pedra\n");
			printf("2 - Papel\n");
			printf("3 - Tesoura\n\n");
			
			printf("Op��o: ");
			scanf("%d", &opcaoPlayer);
			
			printf("\n");
		} while ((opcaoPlayer < 1) || (opcaoPlayer > 3));
		
		gerarResposta(opcaoPlayer, jogadaPlayer);
		
		opcaoCPU = (rand() % 3) + 1;
		
		gerarResposta(opcaoCPU, jogadaCPU);
		
		realizarDuelo(jogadaPlayer, jogadaCPU);
		
		printf("\n");
		
		getchar();
		
		printf("Recome�ar? [S/N]: ");
		scanf("%c", &reiniciar);	
	} while (reiniciar == 'S' || reiniciar == 's');
	
	return 0;
}
