// Split a string and store in array

#include<iostream>
#include<vector>
using namespace std;

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
	for(auto x:str)
		cout<<x<<" ";
	return 0;
}
