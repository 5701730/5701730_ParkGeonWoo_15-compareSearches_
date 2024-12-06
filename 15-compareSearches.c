#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000 

int compareCount = 0; // 비교 횟수르 저장하기위한 변수

void generateRandomArray(int* array) {
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000; // 0~999 사이의 랜덤 숫자
    }
}

// 순차 탐색
int linearSearch(int* array, int target) {
    for (int i = 0; i < SIZE; i++) {
        compareCount++;
        if (array[i] == target) return i;
    }
    return -1;
}

// 퀵 정렬
void quickSort(int* array, int left, int right) {
    if (left >= right) return;

    int pivot = array[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        compareCount++;
        if (array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[right];
    array[right] = temp;

    quickSort(array, left, i);
    quickSort(array, i + 2, right);
}

// 이진 탐색
int binarySearch(int* array, int target, int size) {
    int left = 0, right = size - 1;

    while (left <= right) {
        compareCount++;
        int mid = left + (right - left) / 2;

        if (array[mid] == target) return mid;
        if (array[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// 순차 탐색 평균 비교 횟수
float getAverageLinearSearchCompareCount(int* array) {
    compareCount = 0;
    for (int i = 0; i < 100; i++) {
        int target = array[rand() % SIZE]; // 항상 존재하는 데이터에ㅣ 대한 탐색하기 위함
        linearSearch(array, target);
    }
    return compareCount / 100.0;
}

// 퀵 정렬 비교 횟수
int getQuickSortCompareCount(int* array) {
    compareCount = 0;
    quickSort(array, 0, SIZE - 1);
    return compareCount;
}

// 이진 탐색 평균 비교 횟수
float getAverageBinarySearchCompareCount(int* array) {
    compareCount = 0;
    for (int i = 0; i < 100; i++) {
        int target = array[rand() % SIZE]; 
        binarySearch(array, target, SIZE);
    }
    return compareCount / 100.0;
}

// 배열 출력
void printArray(int* array) {
    printf("Array Sorting Result:\n");
    for (int i = 0; i < 20; i++) {
        printf("%3d ", array[i]);
    }
    printf("\n");
    for (int i = SIZE - 20; i < SIZE; i++) {
        printf("%3d ", array[i]);
    }
    printf("\n");
}


int main() {
    srand(time(NULL)); 

    for (int i = 0; i < 3; i++) { // 3번연속 출력
        int array[SIZE];
        generateRandomArray(array);

        printf("Average Linear Search Compare Count: %.2f\n", getAverageLinearSearchCompareCount(array));

        int quickSortComparisons = getQuickSortCompareCount(array);
        printf("Quick Sort Compare Count: %d\n", quickSortComparisons);

        printf("Average Binary Search Compare Count: %.2f\n", getAverageBinarySearchCompareCount(array));

        printArray(array);

        printf("\n");
    }

    return 0;
}


