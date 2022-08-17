// Eliminate duplicates

#include <iostream>
using namespace std;

int main() {
	int n,x,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>x;
	    ans^=x;
	}
	cout<<"Element that appears once: "<<ans;
	return 0;
}
