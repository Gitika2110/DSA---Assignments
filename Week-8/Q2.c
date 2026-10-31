
#include <stdio.h>
#include <string.h>

double bike(int hours) {
    return hours * 10;
}

double car(int hours) {
    return 30 + (hours - 1) * 20;
}

double truck(int hours) {
    double charge = hours * 50;

    if (charge < 100)
        charge = 100;

    return charge;
}

int main() {
    int n, hours;
    double charge, total = 0;
    char type[20];

    struct Vehicle {
        char name[20];
        double (*calculate)(int);
    };

    struct Vehicle v[] = {
        {"BIKE", bike},
        {"CAR", car},
        {"TRUCK", truck}
    };

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d", type, &hours);

        for (int j = 0; j < 3; j++) {
            if (strcmp(type, v[j].name) == 0) {
                charge = v[j].calculate(hours);
                break;
            }
        }

        printf("%s: %.2f\n", type, charge);
        total = total + charge;
    }

    printf("Total: %.2f\n", total);

    return 0;
}
