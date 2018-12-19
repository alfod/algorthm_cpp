//
// Created by Administrator on 2018/12/19.
//

#include <iostream>

using namespace std;

int sheepCount();

int palindrome();


int main() {
//    sheepCount();
    palindrome();
}

int palindrome() {
    int n;
    cin >> n;
    string str;
    bool isPalin;
    int maxLength;
    while (n-- > 0) {
        cin >> str;
        maxLength = 0;
        for (int i = 0; i < str.length(); i++) {
            for (int j = i + 1; j < str.length(); j++) {
                isPalin = true;
                for (int k = 0; k < (j - i) / 2; k++) {
                    if (str[i + k] != str[j - k]) {
                        isPalin = false;
                        break;
                    }
                }
                if (isPalin && maxLength < (j - i + 1)) {
                    maxLength = j - i + 1;
                }
            }
        }
        cout << maxLength << endl;
    }
}

int sheepCount() {
    int n;
    cin >> n;
    int wordNum, sheepCount = 0;
    string words;
    const string sheep = "sheep";
    int loopIndex = 0;
    while (loopIndex++ < n) {
        cin >> wordNum;
        sheepCount = 0;
        while (wordNum-- > 0) {
            cin >> words;
            if (words.length() != sheep.length()) {
                continue;
            }
            for (int i = 0; i < sheep.length(); i++) {
                if (words[i] != sheep[i]) {
                    continue;
                }
            }
            sheepCount++;
        }
        cout << "case:" << loopIndex << ":" << "this list contains " << sheepCount << " sheep" << endl;
    }
}