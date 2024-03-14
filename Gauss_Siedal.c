#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k;
    float sum, error, E[10], a[10][10], b[10], new_x[10], old_x[10];

    printf("Enter Dimension of System of equations\n");
    scanf("%d", &n);

    printf("Enter coefficients row-wise\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter RHS vector\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    printf("Enter Accuracy Limit\n");
    scanf("%f", &error);

    // Initialize old_x with zeros
    for (i = 0; i < n; i++) {
        old_x[i] = 0;
    }

    int max_iterations = 100; // Set a maximum number of iterations to avoid infinite loops

    while (max_iterations-- > 0) { // Loop with a termination condition
        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (j != i) {
                    sum -= a[i][j] * old_x[j];
                }
            }
            new_x[i] = sum / a[i][i];

            // Calculate error for each variable
            E[i] = fabs(new_x[i] - old_x[i]) / fabs(new_x[i]);
        }

        // Check if all errors are below the tolerance
        int all_below_error = 1;
        for (i = 0; i < n; i++) {
            if (E[i] > error) {
                all_below_error = 0;
                break;
            }
        }

        if (all_below_error) {
            break;
        }

        // Update old_x for the next iteration
        for (j = 0; j < n; j++) {
            old_x[j] = new_x[j];
        }
    }

    if (max_iterations == 0) {
        printf("Solution not found within the maximum number of iterations.\n");
    } else {
        printf("Solution:\n");
        for (i = 0; i < n; i++) {
            printf("%6.2f\t", new_x[i]);
        }
    }

    return 0;
}