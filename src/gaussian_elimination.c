#include <stdio.h>

#define n 3

int main() {
  float x[n];

  // The coefficient matrix A in Ax = b
  float a[n][n] = {
      {1, 1, 1},   // First equation: x + y + z = 1
      {4, 3, -1},  // Second equation: 4x + 3y - z = 6  
      {3, 5, 3},   // Third equation: 3x + 5y + 3z = 4
  };

  // The constant vector b in Ax = b
  float b[n] = {1, 6, 4};

  // Print initial augmented matrix [A|b]
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%.2f ", a[i][j]);
    }
    printf("\n");
  }

  // Forward elimination - convert to upper triangular form
  // This is like reducing the system using row operations
  for (int k = 0; k < n; k++) {
    for (int i = k + 1; i < n; i++) {
      // Calculate factor for row operation (like multiplying row by a number)
      double factor = a[i][k] / a[k][k];
      // Subtract factor * upper row from current row (row operation)
      for (int j = k; j < n; j++) {
        a[i][j] -= factor * a[k][j];
      }
      // Do the same operation on b vector
      b[i] -= factor * b[k];
    }
  }

  // Print the upper triangular system
  printf("\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%.2f ", a[i][j]);
    }
    printf("\n");
  }

  printf("\nSolution\n");

  // Back substitution - solve from bottom to top
  // Once we have upper triangular form, we can solve for each variable
  for (int k = 0; k < n; k++) {
    int i = n - k - 1;  // Start from bottom row
    x[i] = b[i];  // Get the constant term

    // Subtract known terms (moving them to right side)
    for (int j = i + 1; j < n; j++) {
      x[i] -= a[i][j] * x[j];
    }
    // Divide by coefficient to get variable value
    x[i] /= a[i][i];
    printf("x[%d] = %.2f\n", i, x[i]);
  }

  printf("\n");
}
