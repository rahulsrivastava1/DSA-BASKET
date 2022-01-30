// Minimum Window Substring

string minWindow(string s, string t) {
        int i=0,j=0,MinL=INT_MAX,start=0;
        unordered_map<char,int> mp;
        for(auto it:t)
            mp[it]++;
        int count=mp.size();
        
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0)
                count--;
        }
        
        while(j<s.length()){
            if(count>0){
                j++;
                if(mp.find(s[j])!=mp.end()){
                    mp[s[j]]--;
                    if(mp[s[j]]==0)
                    count--;
                }
            }
            else if(count==0){
                // MinL=min(MinL,j-i+1);
                if(MinL>j-i+1){
                    MinL=j-i+1;
                    start=i;
                }
                while(count==0){
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1){
                            count++;
                            // MinL=min(MinL,j-i+1);
                             if(MinL>j-i+1){
                                MinL=j-i+1;
                                start=i;
                            } 
                        }
                        i++;
                    }
                    else
                        i++;
                }
            }
        }
        string str="";
        if(MinL!=INT_MAX)
            return str.append(s.substr(start,MinL));
        else
            return str;
    }
