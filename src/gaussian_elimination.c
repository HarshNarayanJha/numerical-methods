#include <stdio.h>

#define n 3

int main() {
  float x[n];

  float a[n][n] = {
      {1, 1, 1},
      {4, 3, -1},
      {3, 5, 3},
  };

  float b[n] = {1, 6, 4};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%.2f ", a[i][j]);
    }
    printf("\n");
  }

  for (int k = 0; k < n; k++) {
    for (int i = k + 1; i < n; i++) {
      double factor = a[i][k] / a[k][k];
      for (int j = k; j < n; j++) {
        a[i][j] -= factor * a[k][j];
      }
      b[i] -= factor * b[k];
    }
  }

  printf("\n");

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%.2f ", a[i][j]);
    }
    printf("\n");
  }

  printf("\nSolution\n");

  for (int k = 0; k < n; k++) {
    int i = n - k - 1;
    x[i]  = b[i];

    for (int j = i + 1; j < n; j++) {
      x[i] -= a[i][j] * x[j];
    }
    x[i] /= a[i][i];
    printf("x[%d] = %.2f\n", i, x[i]);
  }

  printf("\n");
}
