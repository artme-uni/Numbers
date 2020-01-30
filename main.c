#include "conversion.h"

int main(int argc, char *argv[]) {
    int b1 = atoi(argv[1]);
    int b2 = atoi(argv[2]);

    char *num = argv[3];

    char end[M];

    double D = func1(b1, num);
    func2(b2, D, end);

//    printf("%s -> %d -> ", num, (int)D);
//    printf("%s\n", end);

    puts(end);

    return 0;
}