#include <math.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int x1, y1, x2, y2;
} line;

bool checkIntersection(line a, line b){
    // a must be a line parallel to x-axis and b must be a line parallel to y-axis
    if(a.x1 > b.x1 && a.x2 < b.x2){
        if(a.y1 < b.y1 && a.y2 > b.y2){
            return true;
        }
    }
    return false;
}

int main(){
    line a = {.x1 = 5, .y1 = 0, .x2 = 5, .y2 = 10};
    line b = {.x1 = 6, .y1 = 5, .x2 = 10, .y2 = 5};
    printf("%d\n", checkIntersection(a, b));
    return 0;
}
