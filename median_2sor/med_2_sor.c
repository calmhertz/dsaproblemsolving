#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i = nums1Size-1, j = nums2Size-1;
    int totalSize = nums1Size+nums2Size;
    int half = totalSize/2;
    if(!(totalSize&1)) {
        printf("even\n");
        printf("half = %d\n", half);
        for(int k=0; k<half;){
            if(nums1[i]>nums2[j]){
                i--;
                k++;
            }
            else {
                j--;
                k++;
            }
        }
        return (double)(nums1[i]+nums2[j])/2;
    }
    else {
        printf("odd\n");
        printf("half = %d\n", half);
        for(int k=0; k<half;){
            printf("k = %d\n",k);
            int temp = 0;
            if(i>0 && nums1[i]>nums2[j]){
                i--;
            }
            else if(j>0) {
                j--;
                temp = 1;
            }
            k++;
            if(k>=half){
                return (temp==0)?nums1[i]:nums2[j];
            }
        }
    } 
    return 0;
}

void run_test(int* nums1, int n1Size, int* nums2, int n2Size, double expected, int testNum) {
    double result = findMedianSortedArrays(nums1, n1Size, nums2, n2Size);
    if (fabs(result - expected) < 1e-5) {
        printf("Test %d Passed\n", testNum);
    } else {
        printf("Test %d Failed: Expected %f, Got %f\n", testNum, expected, result);
    }
}

int main() {
    int t1_n1[] = {1, 3};
    int t1_n2[] = {2};
    run_test(t1_n1, 2, t1_n2, 1, 2.0, 1);

    int t2_n1[] = {1, 2};
    int t2_n2[] = {3, 4};
    run_test(t2_n1, 2, t2_n2, 2, 2.5, 2);

    int t3_n1[] = {};
    int t3_n2[] = {1};
    run_test(t3_n1, 0, t3_n2, 1, 1.0, 3);

    int t4_n1[] = {2};
    int t4_n2[] = {};
    run_test(t4_n1, 1, t4_n2, 0, 2.0, 4);

    int t5_n1[] = {1000000};
    int t5_n2[] = {1000001};
    run_test(t5_n1, 1, t5_n2, 1, 1000000.5, 5);

    int t6_n1[] = {1, 2};
    int t6_n2[] = {1, 2, 3};
    run_test(t6_n1, 2, t6_n2, 3, 2.0, 6);

    int t7_n1[] = {1, 5, 8};
    int t7_n2[] = {2, 3, 6, 7};
    run_test(t7_n1, 3, t7_n2, 4, 5.0, 7);

    int t8_n1[] = {1, 2, 3, 4, 5};
    int t8_n2[] = {6, 7, 8, 9, 10, 11};
    run_test(t8_n1, 5, t8_n2, 6, 6.0, 8);

    int t9_n1[] = {1, 1, 1, 1};
    int t9_n2[] = {1, 1, 1};
    run_test(t9_n1, 4, t9_n2, 3, 1.0, 9);

    int t10_n1[] = {-10, -5, 0, 5, 10};
    int t10_n2[] = {-15, -12, -8, 2, 4, 20};
    run_test(t10_n1, 5, t10_n2, 6, 0.0, 10);

    int t11_n1[] = {1, 2};
    int t11_n2[] = {-1, 3};
    run_test(t11_n1, 2, t11_n2, 2, 1.5, 11);

    int* t12_n1 = (int*)malloc(1000 * sizeof(int));
    int* t12_n2 = (int*)malloc(1000 * sizeof(int));
    for(int i = 0; i < 1000; i++) {
        t12_n1[i] = i;
        t12_n2[i] = i + 1000;
    }
    run_test(t12_n1, 1000, t12_n2, 1000, 999.5, 12);
    free(t12_n1);
    free(t12_n2);

    return 0;
}
