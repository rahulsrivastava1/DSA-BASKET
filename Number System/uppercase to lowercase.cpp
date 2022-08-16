// Uppercase to lowercase

#include<bits/stdc++.h>
using namespace std;

int main(){
    string str="RAJA";
    for(int i=0;i<str.size();i++)
        str[i]=str[i] | ' ';
    for(int i=0;i<str.size();i++)
        cout<<str[i];
    return 0;
}
