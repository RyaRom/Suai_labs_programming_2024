#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

typedef double (*Tfun)(double);

double integrall(double, double, int, double, Tfun, double);

double fun1(double x);

double fun2(double x);

double fun3(double x);

double fun4(double x);

double fun5(double x);

double fun6(double x);

double fun7(double x);

double fun8(double x);

double fun9(double x);

double fun10(double x);

int lab3_main() {
    int i = 0;
    int n = 10;
    double x, y;
    double s1, s2, s3, s4, s5;
    double eps = 0.0001;
    double s = 0;

    cout << '\n' << "Enter the coordinates of the point (x, y): ";
    cin >> x >> y;

    if (y > 1 && y < 2 && x > -2 && x < 0 && x * x + (y - 1) * (y - 1) > 1) {
        cout << "The point is in Region M1. " << endl;
        i = 1;
    } else if (x > -1 && x < 1 && y > -1 && y < 1 &&
               (x + 1) * (x + 1) + (y + 1) * (y + 1) > 1 &&
               (x + 1) * (x + 1) + (y - 1) * (y - 1) > 1 &&
               (x - 1) * (x - 1) + (y + 1) * (y + 1) > 1 &&
               (x - 1) * (x - 1) + (y - 1) * (y - 1) > 1) {
        cout << "The point is in Region M2. " << endl;
        i = 2;
    } else if (x > 1 && x < 2 && y > -1 && y < 1 &&
               (x - 1) * (x - 1) + (y + 1) * (y + 1) > 1 &&
               (x - 1) * (x - 1) + (y - 1) * (y - 1) > 1) {
        cout << "The point is in Region M3. " << endl;
        i = 3;
    } else if ((x + 1) * (x + 1) + (y + 1) * (y + 1) < 1 &&
               (x + 1) * (x + 1) + y * y > 1 && x * x + (y + 1) * (y + 1) > 1) {
        cout << "The point is in Region M4. " << endl;
        i = 4;
    } else if ((x - 1) * (x - 1) + y * y > 1 && x * x + y * y > 1 &&
               x * x + (y + 1) * (y + 1) < 1 && (x - 1) * (x - 1) + (y + 1) * (y + 1) < 1) {
        cout << "The point is in Region M5. " << endl;
        i = 5;
    } else {
        cout << "The point is outside the defined regions." << endl;
    }

    cout.precision(4);
    switch (i) {
        case 1:
            cout << "Formula: S1 = " << (s1 = 2 - M_PI / 4) << endl;
            cout << "Integral S1 = " << (s1 = integrall(1, 2, n, eps, fun4, s) - integrall(1, 2, n, eps, fun2, s)) <<
                    endl;
            break;
        case 2:
            cout << "Formula: S2 = " << (s2 = 4 - M_PI) << endl;
            cout << "Integral S2 = " << (s2 = integrall(-1, 1, n, eps, fun7, s) - integrall(-1, 1, n, eps, fun2, s)) <<
                    endl;
            break;
        case 3:
            cout << "Formula: S3 = " << (s3 = 2 - M_PI / 2) << endl;
            cout << "Integral S3 = " << (s3 = integrall(1, 2, n, eps, fun3, s)) << endl;
            break;
        case 4:
            cout << "Formula: S4 = " << (s4 = M_PI / 4 + 2 * (M_PI / 2 - 2 * (M_PI / 3 - sqrt(3) / 4))) << endl;
            cout << "Integral S4 = " << (s4 = fabs(integrall(-1, 0, n, eps, fun1, s)) - fabs(
                                                  integrall(-1, 0, n, eps, fun3, s))) << endl;
            break;
        case 5:
            cout << "Formula: S5 = " << (s5 = 1 - M_PI / 4) << endl;
            cout << "Integral S5 = " << (s5 = fabs(integrall(-1, 0, n, eps, fun8, s)) - fabs(
                                                  integrall(-1, 0, n, eps, fun5, s))) << endl;
            break;
    }

    return 0;
}

double integrall(double a, double b, int n, double eps, Tfun fun, double s1) {
    double x, h, s = 0;
    int i;
    h = (b - a) / n;
    for (i = 0; i < n; i++) {
        x = a + i * h + h / 2;
        s += fun(x);
    }
    s *= h;
    if (fabs(s - s1) > eps)
        s = integrall(a, b, 2 * n, eps, fun, s);
    return s;
}

double fun1(double x) {
    return sqrt(1 - x * x); //x^2 + y^2 = 1
}

double fun2(double x) {
    return sqrt(2 * x - x * x); //(x - 1)^2 + y^2 = 1
}

double fun3(double x) {
    return sqrt(-2 * x - x * x); //(x + 1)^2 + y^2 = 1
}

double fun4(double x) {
    return 2; //y = 2
}

double fun5(double x) {
    return -1 - sqrt(1 - x * x); //x^2 + (y + 1)^2 = 1
}

double fun6(double x) {
    return sqrt(1 - x * x) - 1; //x^2 + (y + 1)^2 = 1
}

double fun7(double x) {
    return 1; //y = 1
}

double fun8(double x) {
    return -2; //y = -2
}

double fun9(double x) {
    return -sqrt(1 - x * x); //x^2 + y^2 = 1
}

double fun10(double x) {
    return -sqrt(2 * x - x * x); //(x - 1)^2 + y^2 = 1
}
