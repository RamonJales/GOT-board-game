#include <stdio.h>

void boardInit(char scenery[10][10], int wPosition[2]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == wPosition[0] && j == wPosition[1]) {
                scenery[i][j] = 'J';
            }
            else if (i == 0 && j == 0) {
                scenery[i][j] = 'W';
            }
            else if (i == 4 && j == 4) {
                scenery[i][j] = 'C';
            }
            else if (i == 9 && j == 9) {
                scenery[i][j] = 'N';
            }
            else {
                scenery[i][j] = '-';
            }
        }
    }
}

void printScenery(char scenery[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", scenery[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char scenery[10][10];
    int wPosition[2];
    
    wPosition[0] = 1;
    wPosition[1] = 1;
    
    boardInit(scenery, wPosition);
    
    //--> começa loop
    printScenery(scenery);
    
    //faz o movimento
    char movement;
    printf("faça o movimento(a, w, s, d): ");
    scanf("%c", &movement);
    
    return 0;
}
