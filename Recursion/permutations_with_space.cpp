// Permutations with Space

void solve(string s,vector<string>& ans,string op){
        if(s.size()==0){
            ans.push_back(op);
            return;
        }
        string op1=op;
        string op2=op;
        op1.push_back(' ');
        op1.push_back(s[0]);
        op2.push_back(s[0]);
        s.erase(s.begin()+0);
        solve(s,ans,op1);
        solve(s,ans,op2);
    }
    vector<string> permutation(string S){
        string op="";
        op.push_back(S[0]);
        S.erase(S.begin()+0);
        vector<string> ans;
        solve(S,ans,op);
        return ans;
    }
