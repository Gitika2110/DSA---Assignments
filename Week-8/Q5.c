
#include <stdio.h>
#include <string.h>

int basic() {
    return 30;
}

int standard() {
    return 90;
}

int premium() {
    return 365;
}

int leapYear(int year) {
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

int daysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31};

    if (month == 2 && leapYear(year))
        return 29;

    return days[month - 1];
}

void addDays(int *year, int *month, int *day, int days) {
    while (days > 0) {
        (*day)++;
        
        if (*day > daysInMonth(*month, *year)) {
            *day = 1;
            (*month)++;

            if (*month > 12) {
                *month = 1;
                (*year)++;
            }
        }

        days--;
    }
}

int main() {
    int n, year, month, day, validity;
    char type[20], name[30];

    struct Plan {
        char name[20];
        int (*validity)();
    };

    struct Plan p[] = {
        {"BASIC", basic},
        {"STANDARD", standard},
        {"PREMIUM", premium}
    };

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %s %d-%d-%d",
              type, name, &year, &month, &day);

        for (int j = 0; j < 3; j++) {
            if (strcmp(type, p[j].name) == 0) {
                validity = p[j].validity();
                break;
            }
        }

        addDays(&year, &month, &day, validity);

        printf("%s: %04d-%02d-%02d\n",
               name, year, month, day);
    }

    return 0;
}
