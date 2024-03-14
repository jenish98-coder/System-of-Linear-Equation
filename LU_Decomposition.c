#include <stdio.h>

#define MAX 100

void luDecomposition(int mat[MAX][MAX], int n) {
    int lower[MAX][MAX];
    int upper[MAX][MAX];

    // Decomposing matrix into Upper and Lower triangular matrix
    for (int i = 0; i < n; i++) {
        // Upper Triangular
        for (int k = i; k < n; k++) {
            // Summation of L(i, j) * U(j, k)
            int sum = 0;
            for (int j = 0; j < i; j++)
                sum += (lower[i][j] * upper[j][k]);

            // Evaluating U(i, k)
            upper[i][k] = mat[i][k] - sum;
        }

        // Lower Triangular
        for (int k = i; k < n; k++) {
            if (i == k)
                lower[i][i] = 1; // Diagonal as 1
            else {
                // Summation of L(k, j) * U(j, i)
                int sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (lower[k][j] * upper[j][i]);

                // Evaluating L(k, i)
                lower[k][i] = (mat[k][i] - sum) / upper[i][i];
            }
        }
    }

    // Displaying the result
    printf("\tLower Triangular\t\tUpper Triangular\n");
    for (int i = 0; i < n; i++) {
        // Lower
        for (int j = 0; j < n; j++)
            printf("%4d\t", lower[i][j]);
        printf("\t");

        // Upper
        for (int j = 0; j < n; j++)
            printf("%4d\t", upper[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    int mat[MAX][MAX];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    luDecomposition(mat, n);
    return 0;
}
