//
// Created by Administrator on 2018/12/20.
//

#include <iostream>

using namespace std;

int &func1(int &a) {
    a += a;
    return a;
};

int &func2(int &b) {
    b += b;
    return b;
};

int xy();

int substring();

int main() {
//    int x = 10;
//    int &a = x;
//    int &y = func1(x);
//    int z = func2(y);
//    cout << a << " " << x << " " << y << " " << z << endl;

//    xy();
    substring();
}

int substring() {

    int n;
    cin >> n;
    cin.get();

    char s[100], t[100];
    int sLen, tLen, tmp;
    bool hasWord, isSub;
    while (n--) {
        cin >> s;
        cin >> t;
        sLen = strlen(s);
        tLen = strlen(t);
        isSub = true;
        tmp = 0;
        for (int i = 0; i < sLen;) {
            hasWord = false;
            for (int j = tmp; j < tLen; j++) {
                if (s[i] == t[j]) {
                    i++;
                    tmp = j + 1;
                    hasWord = true;
                    break;
                }
            }
            if (!hasWord) {
                cout << "NO" << endl;
                isSub = false;
                break;
            }
        }
        if (isSub) {
            cout << "YES" << endl;
        }
    }
}

int xy() {
    int n;
    cin >> n;
    cin.get();

    int A, B, x, y;
    while (n--) {
        cin >> A;
        cin >> B;

        x = (A + B) / 2;
        y = (A - B) / 2;
        cout << x << " " << y << endl;
    }
}