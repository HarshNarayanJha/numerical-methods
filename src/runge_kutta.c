#include <stdio.h>

/// This is Runge Kutta method for approximating ordinary differential equations.

// dy/dx = x^2 + 2y
// y(0) = 1
double yp(double x, double y) {
  return x * x + y;
}

double runge_kutta_2nd(double x0, double y0, double h, double xn) {
  printf("Evaluating using 2nd order method\n");
  double x = x0, y = y0;

  while (x != xn) {
    double k1 = h * yp(x, y);
    double k2 = h * yp(x + h, y + k1);

    double yn = y + 0.5 * (k1 + k2);
    printf("x = %lf, y = %lf\n", x, y);
    x += h;
    y = yn;
  }

  return y;
}

double runge_kutta_4nd(double x0, double y0, double h, double xn) {
  printf("Evaluating using 4th order method\n");

  double x = x0, y = y0;
  while (x != xn) {
    double k1 = h * yp(x, y);
    double k2 = h * yp(x + 0.5 * h, y + k1);
    double k3 = h * yp(x + 0.5 * h, y + k2);
    double k4 = h * yp(x + h, y + k3);

    double yn = y + h / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
    printf("x = %lf, y = %lf\n", x, y);
    x += h;
    y = yn;
  }

  return y;
}

int main() {
  double x0, y0, h, xn;

  printf("This is Runge Kutta method\n");
  printf("Initial condition (x0 y0): ");
  scanf("%lf %lf", &x0, &y0);

  printf("Step size (h): ");
  scanf("%lf", &h);

  printf("Evaluate f at x =  ");
  scanf("%lf", &xn);

  double yn2 = runge_kutta_2nd(x0, y0, h, xn);
  printf("\n");
  double yn4 = runge_kutta_4nd(x0, y0, h, xn);

  printf("Final value of y using 2nd order: %lf at x = %lf\n", yn2, xn);
  printf("Final value of y using 4th order: %lf at x = %lf\n", yn4, xn);

  return 0;
}
