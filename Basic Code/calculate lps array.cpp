// longest proper prefix

vector<int> calculatelps(string s){
    int n=s.size();
    int len=0;
    vector<int> lps(n);
    lps[0]=0;
    int i=1;
    while(i<n){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len!=0){
                len=lps[len-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

