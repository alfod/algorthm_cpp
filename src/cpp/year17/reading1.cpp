//
// Created by Administrator on 2018/12/19.
//
#include <iostream>
#include <math.h>

using namespace std;

int reading1();

bool isPrime(int n);

bool isExist(const int array[], int length, int n);

int evenSplit();

int passwordCheck();

class AA {
public:
    AA(char s[]) {
        strcpy(name, s);
        cout << "start " << name << endl;
    }

    ~AA() {
        cout << "end  " << name << endl;
    }

    char name[];
};

void test() {
    AA a("local");
    static AA b("static");
}

int main() {
    // reading1();
    //evenSplit();
    test();
    cout<<"main "<<endl;
//    passwordCheck();
}

int passwordCheck() {
    int n;
    cin >> n;
    char **passwords = new char *[n];
    int pwdLength = 0;
    char *pwd;
    while (n-- > 0) {
        pwd = new char[50];
        cin >> pwd;
        passwords[pwdLength++] = pwd;
    }
    int suitSum, charLength;
    bool hasLower, hasUpper, hasNum, hasSpecial;
    char c;
    for (int i = 0; i < pwdLength; i++) {
        pwd = passwords[i];
        suitSum = 0;
        charLength = strlen(pwd);
        if (charLength < 8 || charLength > 16) {
            cout << "NO" << endl;
            continue;
        }
        hasLower = false, hasUpper = false, hasNum = false, hasSpecial = false;
        for (int j = 0; j < charLength; j++) {
            c = pwd[j];
            if (!hasUpper && c >= 'A' && c <= 'Z') {
                hasUpper = true;
                suitSum++;
            }
            if (!hasLower && c >= 'a' && c <= 'z') {
                hasLower = true;
                suitSum++;
            }
            if (!hasNum && c >= '0' && c <= '9') {
                hasNum = true;
                suitSum++;
            }
            if (!hasSpecial && (c == '`' || c <= '!' || c == '@' || c == '#' || c == '$' || c == '^')) {
                hasSpecial = true;
                suitSum++;
            }
        }
        if (suitSum >= 3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
}

bool isPrime(int n) {
    if (n == 2) {
        return true;
    }
    if (n < 2 || n % 2 == 0) {
        return false;
    }
    int topLimit = (int) (sqrt(n) + 1);
    for (int i = 3; i < topLimit; i += 2) {
        if (n % i == 0) return false;
    }
    return true;

}

bool isExist(const int array[], const int length, int n) {
    int left = 0, right = length - 1, index;
    while (true) {
        if (right - left < 2) return false;
        index = (left + right) / 2;
        if (n > array[index]) left = index;
        if (n < array[index]) right = index;
        if (n == array[index]) return true;
    }
}

int evenSplit() {
    int inputNums[500];
    int primes[3000];
    int num, inputNumsLength = 0, primesLength = 0;
    while (true) {
        cin >> num;
        if (num == 0) break;
        inputNums[inputNumsLength++] = num;
    }

    int sum;
    for (int i = 0; i < inputNumsLength; i++) {
        num = inputNums[i];
        for (int j = primes[primesLength]; j < num; j++) {
            if (isPrime(j)) primes[primesLength++] = j;
        }

        sum = 0;
        int half = num / 2;
        for (int j = 1; primes[j] < half; j++) {
            if (isExist(primes, primesLength, num - primes[j])) {
                sum++;
            }
        }
        cout << sum << endl;
    }

}


int reading1() {
    int a, b, c, k;
    a = 1, b = -1, c = 5;
    k = ++b && c++;
    cout << a << " " << b << " " << c << " " << k << endl;
}