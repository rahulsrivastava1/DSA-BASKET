// Scrambled String

// Memoization 

#include <bits/stdc++.h>
using namespace std;

bool isScramble(string S1, string S2)
{
	if (S1.length() != S2.length()) {
		return false;
	}
	int n = S1.length();
	if (n == 0) {
		return true;
	}
	if (S1 == S2) {
		return true;
	}
	string copy_S1 = S1, copy_S2 = S2;

	sort(copy_S1.begin(), copy_S1.end());
	sort(copy_S2.begin(), copy_S2.end());

	if (copy_S1 != copy_S2) {
		return false;
	}

	for (int i = 1; i < n; i++) {
		if (isScramble(S1.substr(0, i), S2.substr(0, i))
			&& isScramble(S1.substr(i, n - i),
						S2.substr(i, n - i))) {
			return true;
		}
		if (isScramble(S1.substr(0, i),
					S2.substr(n - i, i))
			&& isScramble(S1.substr(i, n - i),
						S2.substr(0, n - i))) {
			return true;
		}
	}
	return false;
}

// Driver Code
int main()
{
	string S1 = "coder";
	string S2 = "ocred";

	if (isScramble(S1, S2)) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}


// Bottom up approach
class Solution {
    public:
        /*
             * dp[i][j][l] means whether s2.substr(j,l) is a scrambled string of s1.substr(i,l) or not.
                 */
        bool isScramble(string s1, string s2) {
            int len = s1.size();
            bool dp[len + 1][len + 1][len + 1];
            memset(dp, 0, sizeof(dp));

            for (int i = len - 1; i >= 0; i--) {
                for (int j = len - 1; j >= 0; j--) {
                    dp[i][j][1] = (s1[i] == s2[j]);
                    for (int l = 2; i + l <=len && j + l <= len; l++) {
                        for (int n = 1; n < l; n++) {
                            dp[i][j][l] |= dp[i][j][n] && dp[i+n][j+n][l-n];
                            dp[i][j][l] |= dp[i][j+l-n][n] && dp[i+n][j][l-n];
                        }
                    }
                }
            }
            return dp[0][0][len];
        }
};
