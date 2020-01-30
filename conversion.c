#include "conversion.h"

int CharToInt(char ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    } else if (ch >= 'A' && ch <= 'F') {
        return toupper(ch) - 'A' + 10;
    }
    printf("bad input\n");
    exit(1);
}

char IntToChar(int ch) {
    if (ch >= 0 && ch <= 9) {
        return ch + '0';
    } else {
        return ch + 'A' - 10;
    }

}

double func1(int b1, char *st) {

    double D = 0;

    if (b1 >= 2 && b1 <= 16) {
        int p = (int) strlen(st);

        int k = 0;

        if (st[0] == '-') {
            k = 1;
            for (int i = 1; i < p; i++)
                st[i - 1] = st[i];
            st[p - 1] = '\0';
            p--;
        }

        for (unsigned int i = 0; i < strlen(st); i++) {
            if (st[i] == '.' || st[i] == ',') p = i;
        }

        for (int i = 0; i < p; i++) {
            int c = CharToInt(st[i]);

            if (c <= b1) {
                D += c * pow(b1, p - 1 - i);
            } else {
                printf("bad input");
                exit(0);
            }
        }

        for (unsigned int i = p + 1; i < strlen(st); i++) {
            int c = CharToInt(st[i]);

            if (c <= b1) {
                D += c * pow(b1, p - i);
            } else {
                printf("bad input");
                exit(0);
            }
        }

        if (k == 0) {
            return D;
        } else {
            return (-1 * D);
        }

    } else {
        printf("bad input");
        exit(0);
    }
}

int func2(int b2, double D, char *end) {
    int k = 0;

    if (D < 0) {
        k = 1;
        D = D * (-1);
    }

    int d = (int) D;
    char cel[M];

    for (int i = 0; d >= b2; i++) {
        cel[i] = IntToChar(d % b2);
        d = d / b2;

        if (d < b2) {
            cel[i + 1] = IntToChar(d);
            cel[i + 2] = '\0';
        }
    }

    D = D - (int) D;
    char drob[M];

    int n = 0;
    if (D == 0) n = 1;

    for (int i = 0; D != 0 || i < 12; i++) {
        int x = (int) (D * b2);

        drob[i] = IntToChar(x);

        D = D * b2 - (int) (D * b2);

        if (D == 0 || i > 12) {
            drob[i + 1] = '\0';
        }
    }

    if (k == 1)
        end[0] = '-';

    for (int i = strlen(cel) - 1; i >= 0; i--) {
        end[strlen(cel) - 1 - i + k] = cel[i];

    }

    if (n == 0) {
        for (unsigned int i = 0; i < strlen(drob); i++) {
            end[i + strlen(cel) + 1 + k] = drob[i];

            if (i + 1 == strlen(drob)) {
                end[i + strlen(cel) + k] = '\0';

                end[strlen(cel) + k] = '.';
            }
        }
    } else {
        end[strlen(cel) + k] = '\0';
    }

    return 0;
}