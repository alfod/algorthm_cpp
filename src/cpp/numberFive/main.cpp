//
// Created by Administrator on 2018/12/15.
//
#include <iostream>
#include <list>
#include <math.h>
#include<cstring>

using namespace std;

int getNumber(char numchar[], int start, int end) {
    int num = 0;
    for (int j = start; j <= end; j++) {
        num = num * 10 + (numchar[j] - '0');
    }
    return num;
}

void dueNumber(char numchar[], int numbers[], int &numberLength) {
    int length = strlen(numchar);
    numberLength = 0;
    int start = 0;
    char c;
    for (int i = 0; i < length; i++) {
        c = numchar[i];
        if (c == '5') {
            if (i - start > 0) {
                numbers[numberLength++] = getNumber(numchar, start, i - 1);
            }
            start = i + 1;
        }
    }
    numbers[numberLength++] = getNumber(numchar, start, length - 1);
}

void quickSort(int array[], int start, int end, int result[]) {
    if (end - start < 1) {
        return;
    }
    if (end - start == 1) {
        if (array[start] > array[end]) {
            result[start] = array[end];
            array[end] = array[start];
            array[start] = result[start];
        }
    }
    if (end - start > 1) {
        int aix = array[start];
        int rightIndex = end, leftIndex = start;
        for (int i = start; i <= end; i++) {
            if (array[i] > aix) {
                result[rightIndex--] = array[i];
            } else if (array[i] < aix) {
                result[leftIndex++] = array[i];
            }
        }
        for (int i = leftIndex; i <= rightIndex; i++) {
            result[i] = aix;
        }
        for (int i = start; i <= end; i++) {
            array[i] = result[i];
        }
        quickSort(array, start, leftIndex - 1, result);
        quickSort(array, rightIndex + 1, end, result);
    }

}

void gracefulQuickSort(int array[], int start, int end) {
    if (start >= end) {
        return;
    }
    int i = start, j = end, pivot = array[i];
    while (i < j) {
        while (i < j && array[j] > pivot) j--;
        if (i < j) array[i++] = array[j];
        while (i < j && array[i] < pivot) i++;
        if (i < j) array[j--] = array[i];
    }
    array[i] = pivot;
    gracefulQuickSort(array, start, i - 1);
    gracefulQuickSort(array, i + 1, end);
}

int main() {
//    int nums[] = {1, 2, 5, 3, 2, 7, 1, 4, 2, 3, 5, 2};
//    int result[20];
//    int length = sizeof(nums) / sizeof(nums[0]);
//    //quickSort(nums, 0, length - 1, result);
//    gracefulQuickSort(nums, 0, length - 1);
//    for (int i = 0; i <= length - 1; i++) {
//        cout << nums[i] << " " << endl;
//    }


    const int LENGTH = 1004;
    int realLength;
    int numberLength = 0;
    while (true) {
        cout << "enter number  " << endl;
        char numberChar[LENGTH];
        cin.getline(numberChar, LENGTH);
        realLength = strlen(numberChar);
        if (realLength == 1 && numberChar[0] == '0') {
            break;
        }
        int numbers[LENGTH];
        dueNumber(numberChar, numbers, numberLength);
        int result[numberLength];
        memcpy(result, numbers, (size_t) numberLength);
        gracefulQuickSort(numbers, 0, numberLength);

        for (int i = 0; i < numberLength; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
    }

}

