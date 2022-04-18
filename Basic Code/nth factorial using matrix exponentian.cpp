// nth factorial using matrix exponentian

//Time Complexity :- O(logn)

// function

vector<vector<int>> multiply(vector<vector<int>> &a,vector<vector<int>> &b){
	const int mod = 1e9 + 7;
	vector<vector<int>> ans(2,vector<int>(2,0));
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				ans[i][j]=(ans[i][j]+(long long)((long long)a[i][k]*(long long)b[k][j]))%mod;
			}
		}
	}
	return ans;
}

vector<vector<int>> matrix_exponentiation(vector<vector<int>> &coeff,int n){
	if(n==0){
		vector<vector<int>> res(2,vector<int>(2,0));
		for(int i=0;i<2;i++){
			res[i][i]=1;
		}
		return res;
	}
	if(n==1)
		return coeff;
	vector<vector<int>> temp=matrix_exponentiation(coeff,n/2);
	vector<vector<int>> ans=multiply(temp,temp);
	if(n&1)
		ans=multiply(ans,coeff);
	return ans;
}

int fibonacciNumber(int n){
    vector<vector<int>> coeff={{1,1},{1,0}};
	vector<vector<int>> ans=matrix_exponentiation(coeff,n);
	return ans[0][1];
}
