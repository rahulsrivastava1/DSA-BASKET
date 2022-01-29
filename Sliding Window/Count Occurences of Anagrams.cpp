// Count Occurences of Anagrams

//function
int search(string pat, string txt) {
	    map<char,int> mp;
	    int ans=0;
	    int i=0;
	    int j=0;
	    for(int k=0;k<pat.size();k++)
	        mp[pat[k]]++;
	    int count=mp.size();
	    while(j<txt.size()){
	        if(mp.find(txt[j])!=mp.end()){
	            mp[txt[j]]--;
	            if(mp[txt[j]]==0)
	                count--;
	        }
	        if(j-i+1<pat.size())
	            j++;
	        else if(j-i+1==pat.size()){
	            if(count==0)
	                ans++;
	            if(mp.find(txt[i])!=mp.end()){
	                mp[txt[i]]++;
	                if(mp[txt[i]]==1)
	                    count++;
	            }
	            i++;
	            j++;
	        }
	    }
	    return ans;
	}
