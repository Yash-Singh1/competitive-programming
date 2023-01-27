/*
ID: saiansh1
LANG: C++
TASK: preface
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("preface.in", "r", stdin);
  freopen("preface.out", "w", stdout);

  int n;
	cin >> n;

	map<char, int> dp;
	vector<pair<char,char>> numerals(4);
	numerals[0] = {'I', 'V'}; numerals[1] = {'X', 'L'}; numerals[2] = {'C', 'D'}; 
	numerals[3] = {'M', '#'};
	for (int i{1}; i <= n; ++i) {
		int m{i};
		for (int j{0}; j < 4; ++j) {
			if (m % 5 <= 3) {
				dp[numerals[j].first] += m % 5;
			} else if (m % 5 == 4) {
				if (m % 10 == 9) {
					++dp[numerals[j].first]; ++dp[numerals[j + 1].first];
				} else {
					++dp[numerals[j].first]; ++dp[numerals[j].second];
				}
			}
			if (m % 10 >= 5 && m % 10 < 9) {
				++dp[numerals[j].second];
			}
			m /= 10;
		}
	}

	vector<char> numeral = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	int end{-1};
	for (int i{6}; i >= 0; --i) {
		if (dp[numeral[i]] > 0) {
			end = i;
			break;
		}
	}

	for (int i{0}; i <= end; ++i) {
		cout << numeral[i] << " " << dp[numeral[i]] << "\n";
	}
}
