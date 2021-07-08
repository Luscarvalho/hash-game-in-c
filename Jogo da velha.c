#include <stdio.h>
#include <stdlib.h>
#define T 3
#define ANSI_COLOR_NEGRITO	"\033[;1m"
#define ANSI_COLOR_VERMELHOCLARO "\033[1;91m"
#define ANSI_COLOR_AZULCLARO "\033[1;94m"
#define ANSI_COLOR_AMARELOCLARO "\033[1;93m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int cont=0, cont1=0, cont2=0, totaljogos=0;

typedef struct jogo{
    char tabuleiro[T][T];
    int linha, coluna;
}Jogo;

typedef struct pessoa{
    float jogador1, jogador2;
}Pessoa;

void criar_tabuleiro(Jogo *j){
    printf(ANSI_COLOR_NEGRITO"  -------------------\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_AMARELOCLARO"     JOGO DA VELHA\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_NEGRITO"  -------------------"ANSI_COLOR_RESET);
	for(int l=0; l<T; l++){
        printf("\n");
		for(int c=0; c<T; c++){
			printf(ANSI_COLOR_VERMELHOCLARO"  |"ANSI_COLOR_RESET);
			j->tabuleiro[l][c]=' ';
			printf("  %c", j->tabuleiro[l][c]);
		}
        printf(ANSI_COLOR_VERMELHOCLARO"  |"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_NEGRITO"\n  -------------------"ANSI_COLOR_RESET);
	}
}

void mostrar_tabuleiro(Jogo j){
    system ("clear");
    printf(ANSI_COLOR_NEGRITO"  -------------------\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_AMARELOCLARO"     JOGO DA VELHA\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_NEGRITO"  -------------------"ANSI_COLOR_RESET);
    for (int l=0; l<T; l++){
		printf("\n");
		for (int c=0; c<T; c++){
			printf(ANSI_COLOR_VERMELHOCLARO"  |"ANSI_COLOR_RESET);
			printf(ANSI_COLOR_NEGRITO"  %c"ANSI_COLOR_RESET, j.tabuleiro[l][c]);
		}
        printf(ANSI_COLOR_VERMELHOCLARO"  |"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_NEGRITO"\n  -------------------"ANSI_COLOR_RESET);
	}
}

int verificar_jogo(Jogo j, int cont){
    if ((j.tabuleiro[0][0] == j.tabuleiro[0][1] && j.tabuleiro[0][0] == j.tabuleiro[0][2] && j.tabuleiro[0][0] != ' ') ||
		(j.tabuleiro[0][0] == j.tabuleiro[1][1] && j.tabuleiro[0][0] == j.tabuleiro[2][2] && j.tabuleiro[0][0] != ' ') ||
		(j.tabuleiro[0][0] == j.tabuleiro[1][0] && j.tabuleiro[0][0] == j.tabuleiro[2][0] && j.tabuleiro[0][0] != ' ') ||
		(j.tabuleiro[0][1] == j.tabuleiro[1][1] && j.tabuleiro[0][1] == j.tabuleiro[2][1] && j.tabuleiro[0][1] != ' ') ||
		(j.tabuleiro[0][2] == j.tabuleiro[1][2] && j.tabuleiro[0][2] == j.tabuleiro[2][2] && j.tabuleiro[0][2] != ' ') ||
		(j.tabuleiro[1][0] == j.tabuleiro[1][1] && j.tabuleiro[1][0] == j.tabuleiro[1][2] && j.tabuleiro[1][0] != ' ') ||
		(j.tabuleiro[2][0] == j.tabuleiro[2][1] && j.tabuleiro[2][0] == j.tabuleiro[2][2] && j.tabuleiro[2][0] != ' ') ||
		(j.tabuleiro[2][0] == j.tabuleiro[1][1] && j.tabuleiro[2][0] == j.tabuleiro[0][2] && j.tabuleiro[2][0] != ' ')){
		return 1;									
	}
    return 0;
}

void simbolos(Jogo *j, int cont){
    if (cont%2==0){
		j->tabuleiro[j->linha][j->coluna] = 'X';
	}
	else{
		j->tabuleiro[j->linha][j->coluna] = 'O';
	}
}

void jogar(Jogo j, int cont){
    int verificar_ganhador=0;
    while(verificar_ganhador==0 && cont<9){
        printf(ANSI_COLOR_AMARELOCLARO"\n\n  VEZ DO JOGADOR %d"ANSI_COLOR_RESET, (cont%2)+1);
		printf(ANSI_COLOR_AZULCLARO"\n\n  LINHA:"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_NEGRITO" ");
		scanf("%d", &j.linha);
		setbuf(stdin, NULL);
		j.linha--;

		printf(ANSI_COLOR_AZULCLARO"  COLUNA:");
        printf(ANSI_COLOR_NEGRITO" ");
		scanf("%d", &j.coluna);
		setbuf(stdin, NULL);
		j.coluna--;

		if (j.tabuleiro[j.linha][j.coluna]==' '){
			simbolos(&j, cont);
			mostrar_tabuleiro(j);
			verificar_ganhador=verificar_jogo(j, cont);
		}
		else{
            mostrar_tabuleiro(j);
			printf(ANSI_COLOR_AMARELOCLARO"\n\n  O ESPAÇO ESCOLHIDO JA ESTÁ OCUPADO OU NÃO É EXISTENTE!\n"ANSI_COLOR_RESET);
			cont--;
		}
    cont++;
	}
    if(verificar_ganhador!=0){
        if((cont%2)==0){
            printf(ANSI_COLOR_AZULCLARO"\n\n   JOGADOR 2 VENCEU!\n"ANSI_COLOR_RESET);
            cont2++;
        }else{
            printf(ANSI_COLOR_AZULCLARO"\n\n   JOGADOR 1 VENCEU!\n"ANSI_COLOR_RESET);
            cont1++;
        }
    }
    else{
        printf(ANSI_COLOR_VERMELHOCLARO"\n\n   DEU VELHA!\n"ANSI_COLOR_RESET);
    }
}

void relatorio_da_partida(Pessoa p){
    p.jogador1=(cont1*100)/totaljogos;
    p.jogador2=(cont2*100)/totaljogos;
    printf(ANSI_COLOR_AMARELOCLARO"  ==========RELATORIO DA PARTIDA==========");
    printf("\n\n  PARTIDAS JOGADAS: %d", totaljogos);
    printf("\n  PARTIDAS VENCIDAS PELO JOGADOR 1: %d\n  PARTIDAS VENCIDAS PELO JOGADOR 2: %d", cont1, cont2);
    printf("\n  PORCENTAGEM DE VITÓRIA DO JOGADOR 1: %.2f\n  PORCENTAGEM DE VITÓRIA DO JOGADOR 2: %.2f\n"ANSI_COLOR_RESET, p.jogador1, p.jogador2);
}

int main(){
    Jogo j;
    Pessoa p;
    int op;
    do{
        printf(ANSI_COLOR_AZULCLARO"\n\n==JOGO DA VELHA IPII==");
        printf(ANSI_COLOR_AMARELOCLARO"\n\n1--INICIAR JOGO\n\n0--SAIR\n\n-->"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_NEGRITO" ");
        scanf("%d", &op);
        system("clear");
        switch(op){
            case 1: criar_tabuleiro(&j);
                    jogar(j, cont);
                    break;
            case 0: system("clear");
                    relatorio_da_partida(p);
                    break;
            default: printf(ANSI_COLOR_VERMELHOCLARO"\n\nOPÇÃO INVÁLIDA!\n"ANSI_COLOR_RESET);
        }
    totaljogos++;
    }while(op==1);
    return 0;
}
