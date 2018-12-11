//
// Created by Administrator on 2018/12/11.
//

#include <iostream>
#include <stdio.h>

using namespace std;

struct Date {
    int year, month, day;
};

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int getDays(Date *date) {
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    for (int i = 2000; i < date->year; i++) {
        if (isLeapYear(i)) {
            days += 366;
        } else {
            days += 365;
        }
    }
    const bool isLeap = isLeapYear(date->year);
    for (int i = 0; i < date->month - 1; i++) {
        if (isLeap && i == 1) {
            days += 29;
        } else {
            days += monthDays[i];
        }
    }
    days += date->day;
    return days;
}

int main() {
    Date *start = new Date();
    Date *end = new Date();
    cout << "please enter start year, format 2018,1,1" << endl;
    scanf("%d,%d,%d", &start->year, &start->month, &start->day);
    cout << "please enter end year, format 2018,2,1" << endl;
    scanf("%d,%d,%d", &end->year, &end->month, &end->day);
    int startDays = getDays(start);
    int endDays = getDays(end);
    int index = (endDays - startDays) % 5;
    if (index < 3) {
        cout << "打鱼" << endl;
    }else{
        cout << "晒网" << endl;
    }
}

