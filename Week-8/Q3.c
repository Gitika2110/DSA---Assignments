
#include <stdio.h>
#include <string.h>

double single(int units, int occupants) {
    return units * 8;
}

double shared(int units, int occupants) {
    return (units * 6) / occupants;
}

double ac(int units, int occupants) {
    return (units * 10) + 200;
}

int main() {
    int n, units, occupants;
    double bill, total = 0;
    char type[20];

    struct Room {
        char name[20];
        double (*calculate)(int, int);
    };

    struct Room r[] = {
        {"SINGLE", single},
        {"SHARED", shared},
        {"AC", ac}
    };

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d", type, &units);

        occupants = 1;

        if (strcmp(type, "SHARED") == 0) {
            scanf("%d", &occupants);
        }

        for (int j = 0; j < 3; j++) {
            if (strcmp(type, r[j].name) == 0) {
                bill = r[j].calculate(units, occupants);
                break;
            }
        }

        printf("%s: %.2f\n", type, bill);
        total = total + bill;
    }

    printf("Total: %.2f\n", total);

    return 0;
}
