#include <stdio.h>
#include <stdlib.h>

void imprimirTablero(char tablero[3][3]);
void borrarTablero(char tablero[3][3]);
int tableroLleno(char tablero[3][3]);
void mover(char tablero[3][3], char jugador1[20], char jugador2[20], char primerTurno);
int verificarGanador(char tablero[3][3], char jugador1[20], char jugador2[20]);
char determinarPrimero(int num, char jugador1[20], char jugador2[20]);

int main() {
    char tablero[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    char jugador1[20], jugador2[20];
    int num = rand() % 20 + 1;
    
    printf("Bienvenido al Tres en Raya\nIngrese el nombre de los jugadores\n");
    printf("Jugador 1: ");  
    scanf("%s", jugador1);
    printf("Jugador 2: ");
    scanf("%s", jugador2);
    printf("Los jugadores son: %s y %s\n", jugador1, jugador2);

    printf("Para elegir el primero en mover, ambos elegirán un número del 1 al 20.\n");
    char primerTurno = determinarPrimero(num, jugador1, jugador2);

    printf("El número aleatorio generado es: %d\n", num);
    printf("Comienza el juego\n");
    imprimirTablero(tablero);
    
    mover(tablero, jugador1, jugador2, primerTurno);

    return 0;
}

char determinarPrimero(int num, char jugador1[20], char jugador2[20]) {
    int num1, num2;
    printf("%s, elige un número: ", jugador1);
    scanf("%d", &num1);
    printf("%s, elige un número: ", jugador2);
    scanf("%d", &num2);
    
    if (abs(num - num1) < abs(num - num2)) {
        printf("%s comienza.\n", jugador1);
        return 'X';
    } else {
        printf("%s comienza.\n", jugador2);
        return 'O';
    }
}

void mover(char tablero[3][3], char jugador1[20], char jugador2[20], char primerTurno) {
    int fila, columna, turno = 0;
    char jugadorActual[20];
    char fichaActual = primerTurno;

    while (!tableroLleno(tablero)) {
        if (fichaActual == 'X') {
            sprintf(jugadorActual, "%s", jugador1);
        } else {
            sprintf(jugadorActual, "%s", jugador2);
        }

        printf("%s, introduce la fila y columna (0-2) donde quieres poner tu ficha: ", jugadorActual);
        scanf("%d %d", &fila, &columna);

        if (fila < 0 || fila > 2 || columna < 0 || columna > 2 || tablero[fila][columna] != '-') {
            printf("Movimiento inválido. Intenta de nuevo.\n");
            continue;
        }

        tablero[fila][columna] = fichaActual;
        imprimirTablero(tablero);

        if (verificarGanador(tablero, jugador1, jugador2)) {
            return;
        }

        fichaActual = (fichaActual == 'X') ? 'O' : 'X';
    }

    printf("Empate.\n");
}

int verificarGanador(char tablero[3][3], char jugador1[20], char jugador2[20]) {
    int i;
    for (i = 0; i < 3; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != '-') {
            printf("El ganador es: %s\n", (tablero[i][0] == 'X') ? jugador1 : jugador2);
            return 1;
        }
        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != '-') {
            printf("El ganador es: %s\n", (tablero[0][i] == 'X') ? jugador1 : jugador2);
            return 1;
        }
    }
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != '-') {
        printf("El ganador es: %s\n", (tablero[0][0] == 'X') ? jugador1 : jugador2);
        return 1;
    }
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != '-') {
        printf("El ganador es: %s\n", (tablero[0][2] == 'X') ? jugador1 : jugador2);
        return 1;
    }
    return 0;
}

int tableroLleno(char tablero[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (tablero[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

void imprimirTablero(char tablero[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

void borrarTablero(char tablero[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tablero[i][j] = '-';
        }
    }
}
