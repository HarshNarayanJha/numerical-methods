#include <math.h>
#include <stdio.h>

#define N 3

/// This is also know as Gauss Iteration Method
/// This is an iterative method, meaning it gives an approximate solution

int main() {
  float a[N][N] = {
      {54,  1,  1},
      { 2, 15,  6},
      {-1,  6, 27}
  };
  float b[N]        = {110, 72, 85};
  float x[N]        = {50, 50, 50};
  int maxIterations = 25;

  for (int i = 0; i < maxIterations; i++) {
    float x_old[N];

    for (int k = 0; k < N; k++) {
      x_old[k] = x[k];
    }

    for (int j = 0; j < N; j++) {
      float sum = 0;

      for (int k = 0; k < N; k++) {
        if (k != j) {
          sum += a[j][k] * x[k];
        }
      }

      x[j] = (b[j] - sum) / a[j][j];
    }

    float error = 0;
    for (int k = 0; k < N; k++) {
      error += (x[k] - x_old[k]) * (x[k] - x_old[k]);
    }
    error = sqrt(error);

    if (fabs(error) < 10e-6) {
      printf("Converged after %d iterations.\n", i + 1);
      break;
    }

    printf("Iteration %d: ", i + 1);

    for (int i = 0; i < N; i++) {
      printf("x[%d] = %.4f ", i, x[i]);
    }

    printf("\n");
  }

  printf("\nFinal Solution: ");
  for (int i = 0; i < N; i++) {
    printf("x[%d] = %.4f ", i, x[i]);
  }
  printf("\n");
  return 0;
}
