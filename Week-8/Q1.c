
#include <stdio.h>
#include <string.h>

double student(double amount) {
    return amount * 0.90;
}

double staff(double amount) {
    return amount * 0.95;
}

double guest(double amount) {
    return amount + 10;
}

int main() {
    int n;
    double amount, total = 0, finalAmount;
    char type[20];

    struct Customer {
        char name[20];
        double (*calculate)(double);
    };

    struct Customer c[] = {
        {"STUDENT", student},
        {"STAFF", staff},
        {"GUEST", guest}
    };

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %lf", type, &amount);

        for (int j = 0; j < 3; j++) {
            if (strcmp(type, c[j].name) == 0) {
                finalAmount = c[j].calculate(amount);
                break;
            }
        }

        printf("%s: %.2f\n", type, finalAmount);
        total = total + finalAmount;
    }

    printf("Total: %.2f\n", total);

    return 0;
}
