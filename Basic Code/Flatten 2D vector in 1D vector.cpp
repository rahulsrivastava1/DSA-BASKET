// Flatten 2D vector in 1D vector

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int r,c;
    cin>>r>>c;
    int total=r*c;
    vector<vector<int>> matrix;
    vector<int> ans(total,0);
    for(int i=0;i<r;i++){
        vector<int> temp;
        for(int j=0;j<c;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }
    cout<<"Printing 2D vector:"<<endl;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int pos=i*c+j;
            ans[pos]=matrix[i][j];
        }
    }
    cout<<"Printing 1D vector:"<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}
