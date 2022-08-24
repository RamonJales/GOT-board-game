#include <stdio.h>
#include <ctype.h>

void boardInit(char scenery[10][10], int jhonPosition[2]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == jhonPosition[0] && j == jhonPosition[1]) {
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

void jhonMovement(char scenery[10][10], int jhonPosition[2], int indexPreviousPosition, char rowOrColumn) {
    if (rowOrColumn == 'l') {
        scenery[jhonPosition[0] + indexPreviousPosition][jhonPosition[1]] = '-';
    }
    else if (rowOrColumn == 'c') {
        scenery[jhonPosition[0]][jhonPosition[1] + indexPreviousPosition] = '-';
    }

    scenery[jhonPosition[0]][jhonPosition[1]] = 'J';

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
    int jhonPosition[2];
    
    jhonPosition[0] = 1;
    jhonPosition[1] = 1;
    
    boardInit(scenery, jhonPosition);
    
    //--> começa loop
    while(1) {
        printScenery(scenery);
    
        //faz o movimento
        char movement;
        printf("faça o movimento(a, w, s, d): ");
        scanf("%c", &movement);
        movement = tolower(movement);
        
        if (movement == 'a') {
            jhonPosition[1] -= 1;
            jhonMovement(scenery, jhonPosition, 1, 'c');
        }
        else if (movement == 'w') {
            jhonPosition[0] -= 1;
            jhonMovement(scenery, jhonPosition, 1, 'l');
        }
        else if(movement == 's') {
            jhonPosition[0] += 1;
            jhonMovement(scenery, jhonPosition, -1, 'l');
        }
        else if (movement == 'd') {
            jhonPosition[1] += 1;
            jhonMovement(scenery, jhonPosition, -1, 'c');
        }

        getchar();
        printf("\n");
    }
    return 0;
}
