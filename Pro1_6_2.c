
// Berker ÖNER 150122018

#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef int bool;

int a, b;
int start_i, start_j;
int longestPathLength = 0;
int matrix[MAX_ROWS][MAX_COLS];
int matrix2[MAX_ROWS][MAX_COLS];
int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int max(int a, int b) {
    return a > b ? a : b;
}

int calculateLongestPath(int i, int j) {
	
	int k;
	
    if (matrix2[i][j] != 0)
        return matrix2[i][j];

    int longest = 1;
    for (k = 0; k < 4; k++) {
    	
        int x = i + directions[k][0];
        int y = j + directions[k][1];
        if (x >= 0 && x < a && y >= 0 && y < b && matrix[x][y] > matrix[i][j]) {
            longest = max(longest, 1 + calculateLongestPath(x, y));
        }
    }

    matrix2[i][j] = longest;
    if (longest > longestPathLength) {
        longestPathLength = longest;
        start_i = i;
        start_j = j;
    }

    return longest;
}

bool isValid(int x, int y) {
    return x >= 0 && x < a && y >= 0 && y < b;
}

void printLongestPath(int i, int j, int length) {
	
	int k, x, y;
	
    if (length == 1) {
        printf("%d", matrix[i][j]);
        return;
    }

    while (length > 1) {
        int nextX = -1, nextY = -1;
        for (k = 0; k < 4; k++) {
            x = i + directions[k][0];
            y = j + directions[k][1];
            if (isValid(x, y) && matrix[x][y] > matrix[i][j] && matrix2[x][y] == length - 1) {
                nextX = x;
                nextY = y;
                break;
            }
        }
        printf("%d, ", matrix[i][j]);
        i = nextX;
        j = nextY;
        length--;
    }
    printf("%d", matrix[i][j]);
}

int main() {
	
	int i, j;

    printf("Enter number of rows: ");
    scanf("%d", &a);
    printf("Enter number of columns: ");
    scanf("%d", &b);

    printf("Enter input: matrix = ");
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            scanf("%d", &matrix[i][j]);
            matrix2[i][j] = 0;
        }
    }

    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            calculateLongestPath(i, j);
        }
    }

    printf("The longest increasing path is [");
    printLongestPath(start_i, start_j, longestPathLength);
    printf("] with visiting %d cells.\n", longestPathLength);

    return 0;
}

