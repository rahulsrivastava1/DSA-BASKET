// Fractional Knapsack

// structure
struct Item{
    int value;
    int weight;
};

// function

// utility-function
bool comp(Item a,Item b){
  double r1=(double)a.value/(double)a.weight;
  double r2=(double)b.value/(double)b.weight;
  return r1>r2;
}

// main function
double fractionalKnapSack(int W,Item arr[],int n){
  if(n==0 || W==0)
    return 0;
  // descending order
  sort(arr,arr+n,comp);
  double curr_weight=0;
  double ans;
  for(int i=0;i<n;i++){
    if(curr_weight+arr[i].weight<=W){
      curr_weight+=arr[i].weight;
      ans+=arr[i].value;
    }else{
      double temp=W-curr_weight;
      ans+=arr[i].value*(r/(double)arr[i].weight);
      break;
    }
  }
  return ans;
}

