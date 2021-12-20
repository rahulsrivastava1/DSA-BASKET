// command line argument in C++

// How to execute a cpp file from commmand line:-
// g++ programName.cpp (To compile program)
// a (To execute program)
// g++ programName.cpp -o newName (To compile as a newName)

#include<iostream>
using namespace std;

int main(int argc,char* argv[]){
	cout<<"argv = "<<argc<<endl;
	int i=0;
	while(i<argc){
		cout<<"argv["<<i<<"]="<<argv[i]<<endl;
		i++;
	}
	return 0;
}
