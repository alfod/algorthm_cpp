//
// Created by Administrator on 2018/12/20.
//


#include <iostream>

using namespace std;


class AA {
private:
    int a;

public:
    AA(const AA &a) {
        this->a = a.a;
        cout << "copy" << endl;
    }

    AA() {
        this->a = 3;
        cout << "contructed " << endl;
    }

    AA(int i) {
        this->a = i;
        cout << i << endl;
    }


    void print() {
        cout << "print  " << this->a << endl;
    }
};

int numRoot();

int countNum(int n);

void rever(char s[], int start, int end);

int wordReversal();

int main() {
//    AA c;
//    AA a(1);
//    AA b = a;
//    b.print();

    // numRoot();

    wordReversal();
}

void rever(char s[], int start, int end) {
    if (end - start < 1)return;
    char c;
    while (s[start] == ' ') start++;
    while (s[end] == ' ') end--;

    if (end - start < 1)return;
    while (end > start) {
        c = s[start];
        s[start] = s[end];
        s[end] = c;
        start++;
        end--;
    }
}

int wordReversal() {
    char s[100];
    int n;
    cin >> n;
    cin.get();
    int start, end, length;
    while (n-- > 0) {
        cin.getline(s, 100);
        start = 0;
        length = strlen(s);
        for (int i = 0; i < length; i++) {
            if (s[i] == ' ') {
                end = i;
                rever(s, start, end);
                start = i;
            }
        }
        rever(s, start, length - 1);
        cout << s << endl;
    }
}

int countNum(int n) {
    int result = 0;
    while (n > 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int numRoot() {
    int n, result, tmp;
    while (cin >> n) {
        if (n == 0)
            return 0;
        result = countNum(n);
        while (result > 9) {
            result = countNum(result);
        }
        cout << result << endl;
    }
}

