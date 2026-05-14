#include <stdio.h>
#include <limits.h>

int mySqrt(int x){
    float x_n1 = 1, x_n = 1;
    int temp = 0;
    while (temp != x) {
        x_n1 = x_n + ((x_n*x_n)/(2*x_n));
        temp = (int)x_n1*x_n1;
    }
    return x_n1;
}

void run_test(int x, int expected, int testNum) {
    int result = mySqrt(x);
    if (result == expected) {
        printf("Test %d Passed: sqrt(%d) = %d\n", testNum, x, result);
    } else {
        printf("Test %d Failed: sqrt(%d) Expected %d, Got %d\n", testNum, x, expected, result);
    }
}

int main() {
    run_test(0, 0, 1);
    run_test(1, 1, 2);
    run_test(2, 1, 3);
    run_test(3, 1, 4);
    run_test(4, 2, 5);
    run_test(8, 2, 6);
    run_test(9, 3, 7);
    run_test(15, 3, 8);
    run_test(16, 4, 9);
    run_test(46339, 215, 10);
    run_test(46340 * 46340, 46340, 11);
    run_test(2147395599, 46339, 12);
    run_test(2147395600, 46340, 13);
    run_test(INT_MAX, 46340, 14);
    run_test(100000000, 10000, 15);
    run_test(1073741824, 32768, 16);

    return 0;
}
