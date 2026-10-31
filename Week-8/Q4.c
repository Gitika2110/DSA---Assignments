
#include <stdio.h>
#include <string.h>

double fulltime(double salary) {
    return salary * 0.10;
}

double parttime(double salary) {
    return salary * 0.05;
}

double intern(double salary) {
    return 2000;
}

int main() {
    int n;
    double salary, bonus, total = 0;
    char type[20], name[30];

    struct Employee {
        char type[20];
        double (*calculate)(double);
    };

    struct Employee e[] = {
        {"FULLTIME", fulltime},
        {"PARTTIME", parttime},
        {"INTERN", intern}
    };

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %s %lf", type, name, &salary);

        for (int j = 0; j < 3; j++) {
            if (strcmp(type, e[j].type) == 0) {
                bonus = e[j].calculate(salary);
                break;
            }
        }

        printf("%s: %.2f\n", name, bonus);
        total = total + bonus;
    }

    printf("Total Bonus: %.2f\n", total);

    return 0;
}
