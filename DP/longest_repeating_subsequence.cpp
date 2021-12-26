// Longest Repeating Subsequence

int LongestRepeatingSubsequence(string str){
		    // Code here
		    string a = str;
		    int n = str.size();
		    int t[n+1][n+1];
		    
		    for(int i=0;i<=n;i++){
		        for(int j=0;j<=n;j++){
		            if(i==0 || j==0){
		                t[i][j] = 0;
		            }
		            else if(str[i-1] == a[j-1] && i!=j){
		                t[i][j] = 1 + t[i-1][j-1];
		            }
		            else t[i][j] = max(t[i-1][j],t[i][j-1]);
		        }
		    }
		    return t[n][n];
		
		}
