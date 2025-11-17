#include <stdio.h>
#include <stdlib.h>

void terminate(int a, int b, int *c) {
    if (a == -2 && b == -2) {
        printf("Exiting!\n");
        *c = 0;
    }
}

void print_board(char arr[][24])
{
    printf("  ");
    for (int p = 1; p < 23; p++) {
        if (arr[0][p] == 'Y') printf("🟡");
        else if (arr[0][p] == 'R') printf("🔴");
        else if (arr[0][p] == 'B') printf("🔵");
    }
    printf("\n");

    printf("   ");
    for (int k = 0; k < 44; k++) printf("—");
    printf("\n");

    for (int i = 1; i < 23; i++) {
        if (arr[i][0] == 'Y') printf("🟡");
        else if (arr[i][0] == 'R') printf("🔴");
        else if (arr[i][0] == 'B') printf("🔵");
        printf("|");
        for (int j = 1; j < 23; j++) {
            if (arr[i][j] == 'Y') printf("🟡");
            else if (arr[i][j] == 'R') printf("🔴");
            else if (arr[i][j] == 'B') printf("🔵");
        }
        printf("|");
        if (arr[i][23] == 'Y') printf("🟡");
        else if (arr[i][23] == 'R') printf("🔴");
        else if (arr[i][23] == 'B') printf("🔵");
        printf("\n");
    }

    printf("   ");
    for (int k = 0; k < 44; k++) printf("—");
    printf("\n");

    printf("   ");
    for (int p = 1; p < 23; p++) {
        if (arr[23][p] == 'Y') printf("🟡");
        else if (arr[23][p] == 'R') printf("🔴");
        else if (arr[23][p] == 'B') printf("🔵");
    }
    printf("\n");
}

int red_search(int a, int b, char arr[][24]) {
    if (arr[a][b] == 'B' || arr[a][b] == 'R') return 0;
    else if(a == 0 || a == 23) return 0;
    return 1;
}

int blue_search(int a, int b, char arr[][24]) {
    if (arr[a][b] == 'R' || arr[a][b] == 'B') return 0;
    else if(b == 0 || b == 23) return 0;
    return 1;
}

int main(void) {
    char board_copy[24][24];
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 24; j++) {
            board_copy[i][j] = 'Y';
        }
    }
    printf(" \t \t \t \t \t \t \t  Welcome to Twixt! \n \t \t \t \t \t \t \t  Enter -2 -2 to exit \n \n \n \n \n \n ");
    print_board(board_copy);
    int count = 1;
    int c = 1;
    while (c == 1) {
        if (count % 2 == 1) {
            int red_x, red_y;
            printf("Red's turn. Enter coordinates (y x): ");
            scanf("%d %d", &red_x, &red_y);
            if (red_x == -2 && red_y == -2) {
                terminate(red_x, red_y, &c);
                continue;
            }
            while (red_search(red_x-1, red_y-1, board_copy) == 0 || red_x > 23 || red_y > 23 || red_x < 1 || red_y < 1) {
                printf("Invalid move! Try again.\n");
                printf("Red's turn. Enter coordinates (y x): ");
                scanf("%d %d", &red_x, &red_y);
            }
            board_copy[red_x-1][red_y-1] = 'R';
            print_board(board_copy);
            count++;
        }
        else {
            int blue_x, blue_y;
            printf("Blue's turn. Enter coordinates (y x): ");
            scanf("%d %d", &blue_x, &blue_y);
            if (blue_x == -2 && blue_y == -2) {
                terminate(blue_x, blue_y, &c);
                continue;
            }
            while (blue_search(blue_x-1, blue_y-1, board_copy) == 0 || blue_x > 23 || blue_y > 23 || blue_x < 1 || blue_y < 1) {
                printf("Invalid move! Try again.\n");
                printf("Blue's turn. Enter coordinates (y x): ");
                scanf("%d %d", &blue_x, &blue_y);
            }
            board_copy[blue_x-1][blue_y-1] = 'B';
            print_board(board_copy);
            count++;
        }
    }
    return 0;
}
