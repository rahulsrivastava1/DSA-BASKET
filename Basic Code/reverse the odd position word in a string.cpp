// reverse the odd position word in a string

#include<iostream>
#include<vector>
using namespace std;

string reverse(string input){
    int n=input.size();
    for(int i=0;i<n/2;i++){
        swap(input[i],input[n-i-1]);
    }
    return input;
}

int main(){
	string s;
	getline(cin,s);
	vector<string> str;
	string word="";
	for(auto it:s){
		if(it==' '){
			str.push_back(word);
			word="";
		}else
			word+=it;
	}
	str.push_back(word);
	string ans="";
	for(int i=0;i<str.size();i++){
	    if(i%2!=0)
	        ans+=reverse(str[i]);
	    else
	        ans+=str[i];
	    ans+=" ";
	}
	for(int i=0;i<ans.size();i++)
	    cout<<ans[i];
	return 0;
}
