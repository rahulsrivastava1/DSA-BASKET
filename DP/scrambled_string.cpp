// Scrambled String


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
