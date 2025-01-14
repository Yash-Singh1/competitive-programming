#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'scoreTosses' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER numPlayers
 *  2. STRING_ARRAY tosses
 */

typedef pair<int, pair<int,int>> piii;

bool comp(piii a, piii b) {
    if (a.first == b.first) {
        return a.second.first < b.second.first;
    } else {
        return a.first > b.first;
    }
}

string scoreTosses(int numPlayers, vector<string> tosses) {
    vector<piii> playerScores(numPlayers);
    string result = "";
    for (int i = 0; i < numPlayers; i++) {
        int scoreCur = 0;
        int score = 0;
        int tossesCount = 1;
        for (char ch : ltrim(rtrim(tosses[i]))) {
            if (ch == ' ') {
                score += scoreCur;
                scoreCur = 0;
                tossesCount++;
            } else {
                if (ch == '+') {
                    scoreCur += 2;
                } else {
                    if (scoreCur > 0) scoreCur++;
                    if (ch == 'A' || ch == 'R') {
                        scoreCur++;
                    } else if (ch == 'O' || ch == 'G') {
                        scoreCur += 3;
                    } else if (ch == 'B') {
                        scoreCur += 6;
                    }
                }
            }
        }
        score += scoreCur;
        playerScores[i] = {score, {tossesCount, i}};
    }
    sort(playerScores.begin(), playerScores.end(), comp);
    for (piii score : playerScores) {
        result += to_string(score.second.second + 1) + "-" + to_string(score.first) + " ";
    }
    result.pop_back();
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string numPlayers_temp;
    getline(cin, numPlayers_temp);

    int numPlayers = stoi(ltrim(rtrim(numPlayers_temp)));

    string tosses_count_temp;
    getline(cin, tosses_count_temp);

    int tosses_count = stoi(ltrim(rtrim(tosses_count_temp)));

    vector<string> tosses(tosses_count);

    for (int i = 0; i < tosses_count; i++) {
        string tosses_item;
        getline(cin, tosses_item);

        tosses[i] = tosses_item;
    }

    string result = scoreTosses(numPlayers, tosses);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
