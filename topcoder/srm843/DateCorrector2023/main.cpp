#include <bits/stdc++.h>

using namespace std;

bool isNum(char a, bool zero = true) {
    return (zero ? a >= '0' : a > '0') && a <= '9';
}

int mmday[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class DateCorrector2023  {
  public:
    string fix(string token) {
        int monthy;
        int dayy;
        if (token.size() != 10) {
            return token;
        }
        int placeholder;
        bool foundOne{0};
        for (int i{0}; i < 4; ++i) {
            if (!isNum(token[i])) {
                goto skipformat1;
            }
        }
        if (token[4] != '-') goto skipformat1;
        if (!isNum(token[5]) || !isNum(token[6])) goto skipformat1;
        monthy = stoi(string(1, token[5]) + token[6]);
        if (!(monthy >= 1 && monthy <= 12)) goto skipformat1;
        if (token[7] != '-') goto skipformat1;
        if (!isNum(token[8]) || !isNum(token[9])) goto skipformat1;
        dayy = stoi(string(1, token[8]) + token[9]);
        if (!(dayy >= 1 && dayy <= mmday[monthy - 1])) goto skipformat1;
        foundOne = 1;
        skipformat1: placeholder = 1;
        if (!foundOne) {
            if (!isNum(token[0]) || !isNum(token[1])) goto skipformat2;
            if (token[2] != '.') goto skipformat2;
            dayy = stoi(string(1, token[0]) + token[1]);
            if (!isNum(token[3]) || !isNum(token[4])) goto skipformat2;
            monthy = stoi(string(1, token[3]) + token[4]);
            if (!(monthy >= 1 && monthy <= 12)) goto skipformat2;
            if (!(dayy >= 1 && dayy <= mmday[monthy - 1])) goto skipformat2;
            if (token[5] != '.') goto skipformat2;
            for (int i{6}; i < 10; ++i) {
                if (!isNum(token[i])) {
                    goto skipformat2;
                }
            }
            foundOne = 1;
            skipformat2: placeholder = 1;
        }
        if (!foundOne) {
            if (!isNum(token[0]) || !isNum(token[1])) goto skipformat3;
            if (token[2] != '/') goto skipformat3;
            monthy = stoi(string(1, token[0]) + token[1]);
            if (!isNum(token[3]) || !isNum(token[4])) goto skipformat3;
            dayy = stoi(string(1, token[3]) + token[4]);
            if (!(monthy >= 1 && monthy <= 12)) goto skipformat3;
            if (!(dayy >= 1 && dayy <= mmday[monthy - 1])) goto skipformat3;
            if (token[5] != '/') goto skipformat3;
            for (int i{6}; i < 10; ++i) {
                if (!isNum(token[i])) {
                    goto skipformat3;
                }
            }
            foundOne = 1;
            skipformat3: placeholder = 1;
        }
        if (!foundOne) {
            return token;
        }
        int format{-1};
        for (auto &c: token) {
            if (c == '-') {
                format = 0;
            } else if (c == '.') {
                format = 1;
            } else if (c == '/') {
                format = 2;
            } else {
                continue;
            }
            break;
        }
        if (format == 0) {
            if (token[0] == '2' && token[1] == '0' && token[2] == '2' && token[3] == '2') {
                token[3] = '3';
            }
        } else if (format == 1 || format == 2) {
            if (token[6] == '2' && token[7] == '0' && token[8] == '2' && token[9] == '2') {
                token[9] = '3';
            }
        }
        if (format == 3) {
            return to_string(placeholder);
        }
        return token;
    }
};
