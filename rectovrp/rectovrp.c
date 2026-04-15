#include <endian.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} coord;

typedef struct {
    int x1, y1, x2, y2;
} line;

bool checkIntersectionLines(line a, line b){
    // a x-axis ge ||el irbeku matthe b y-axis ge ||el irbeku
    if(a.x1 > b.x1 && a.x2 < b.x2){
        if(a.y1 < b.y1 && a.y2 > b.y2){
            return true;
        }
    }
    return false;
}

line* getLines(coord* points){
    if(!points){
        return NULL;
    }
    line* lines = (line*)malloc(sizeof(line)*4);
    lines[0].x1 = points[0].x; lines[0].y1 = points[0].y;
    lines[0].x2 = points[1].x; lines[0].y2 = points[1].y;
    lines[1].x1 = points[1].x; lines[1].y1 = points[1].y;
    lines[1].x2 = points[2].x; lines[1].y2 = points[2].y;
    lines[2].x1 = points[3].x; lines[2].y1 = points[3].y;
    lines[2].x2 = points[2].x; lines[2].y2 = points[2].y;
    lines[3].x1 = points[0].x; lines[3].y1 = points[0].y;
    lines[3].x2 = points[3].x; lines[3].y2 = points[3].y;
    return lines;
}

coord* getCoords(int* rec){
    if(!rec){
        return NULL;
    }
    coord* points = (coord*)malloc(sizeof(coord)*4);
    points[0].x = rec[0]; points[0].y = rec[1];
    points[1].x = rec[2]; points[1].y = rec[1];
    points[2].x = rec[2]; points[2].y = rec[3];
    points[3].x = rec[0]; points[3].y = rec[3];
    return points;
}

bool pointWithinRect(coord* a, int* b){
    if(a->x > b[0] && a->x < b[2] && a->y > b[1] && a->y < b[3]){
        return true;
    }
    return false;
}

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {
    if( rec1Size != 4 || rec2Size != 4 || !rec1 || !rec2 ) {
        return false;
    }

    // 2 rects equal agidre
    bool eql = true;
    for(int i=0; i<rec1Size; i++){
        if(rec1[i]!=rec2[i]){
            eql = false;
            break;
        }
    }
    if(eql) { return true; }

    coord* rec1Points = getCoords(rec1);
    coord* rec2Points = getCoords(rec2);

    // one rect na ond point inond rect olagade idre
    for(int i=0; i<4; i++){
        if(pointWithinRect(&rec1Points[i], rec2)){
            return true;
        }
    }
    for(int i=0; i<4; i++){
        if(pointWithinRect(&rec2Points[i], rec1)){
            return true;
        }
    }

    // one rect na ond line inond rect na yavdadru line jothe intersect agtha idre
    line* rec1Lines = getLines(rec1Points);
    line* rec2Lines = getLines(rec2Points);
    if(checkIntersectionLines(rec1Lines[3], rec2Lines[0]) || checkIntersectionLines(rec1Lines[3], rec2Lines[2]) ){
        return true;
    }
    if(checkIntersectionLines(rec1Lines[1], rec2Lines[0]) || checkIntersectionLines(rec1Lines[1], rec2Lines[2]) ){
        return true;
    }
    if(checkIntersectionLines(rec2Lines[3], rec1Lines[0]) || checkIntersectionLines(rec2Lines[3], rec1Lines[2]) ){
        return true;
    }
    if(checkIntersectionLines(rec2Lines[1], rec1Lines[0]) || checkIntersectionLines(rec2Lines[1], rec1Lines[2]) ){
        return true;
    }

    return false;
}

void test(int id, int r1[4], int r2[4], bool expected) {
    bool result = isRectangleOverlap(r1, 4, r2, 4);
    if (result == expected) {
        printf("Test %02d: PASSED\n", id);
    } else {
        printf("Test %02d: FAILED | Expected %s, Got %s\n", 
               id, expected ? "true" : "false", result ? "true" : "false");
    }
}

int main() {
    int cases[][9] = {
        {0, 0, 2, 2, 1, 1, 3, 3, 1}, 
        {0, 0, 1, 1, 1, 0, 2, 1, 0}, 
        {0, 0, 1, 1, 0, 1, 1, 2, 0}, 
        {0, 0, 1, 1, 1, 1, 2, 2, 0}, 
        {0, 0, 10, 10, 2, 2, 5, 5, 1}, 
        {2, 2, 5, 5, 0, 0, 10, 10, 1}, 
        {0, 0, 2, 2, 0, 0, 2, 2, 1}, 
        {-1, -1, 1, 1, -2, -2, 2, 2, 1}, 
        {0, 0, 1, 1, 0, 0, 1, 0, 0}, 
        {0, 0, 1, 1, 2, 2, 3, 3, 0}, 
        {7, 8, 13, 15, 10, 8, 12, 20, 1},
        {-1000000000, -1000000000, 0, 0, -1, -1, 1000000000, 1000000000, 1},
        {0, 0, 10, 10, 10, 0, 20, 10, 0},
        {0, 0, 10, 10, 0, 10, 10, 20, 0},
        {-5, -5, -1, -1, -2, -2, 2, 2, 1},
        {2, 17, 6, 20, 3, 8, 6, 20, 1}
    };

    int num_cases = sizeof(cases) / sizeof(cases[0]);
    for (int i = 0; i < num_cases; i++) {
        int r1[] = {cases[i][0], cases[i][1], cases[i][2], cases[i][3]};
        int r2[] = {cases[i][4], cases[i][5], cases[i][6], cases[i][7]};
        test(i + 1, r1, r2, (bool)cases[i][8]);
    }

    return 0;
}
