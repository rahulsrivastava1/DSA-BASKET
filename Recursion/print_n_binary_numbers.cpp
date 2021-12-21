// Print N-bit binary numbers having more 1s than 0s

void solve(int n,int ones,int zeroes,string op,vector<string>& ans){
        if(n==0){
            ans.push_back(op);
            return;
        }
        string op1=op;
        op1.push_back('1');
        solve(n-1,ones+1,zeroes,op1,ans);
        if(ones>zeroes){
            string op2=op;
            op2.push_back('0');
            solve(n-1,ones,zeroes+1,op2,ans);
        }
    }
vector<string> NBitBinary(int N)
{
  vector<string> ans;
	int ones=0;
	int zeroes=0;
	string op="";
	solve(N,ones,zeroes,op,ans);
	return ans;
}
