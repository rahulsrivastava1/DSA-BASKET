// Job Sequencing with Deadlines
// Approach:-
// Sort profit in descending order
// traverse

// structure
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

// utility function
static bool comp(Job a,Job b){
  return (a.profit>b.profit);
}

// main function
vector<int> jobProfit(Job arr[],int n){
  sort(arr,arr+n,comp);
  int max_upperbound=arr[0].dead;
  for(int i=1;i<n;i++)
    max_upperbound=max(max_upperbound,arr[i].dead);
  int slot[max_upperbound+1];
  for(int i=0;i<=max_upperbound;i++)
    slot[i]=-1;
  int countJobs=0;
  int maxProfit=0;
  for(int i=0;i<n;i++){
    for(int j=arr[i].dead;j>0;j--){
      if(slot[j]==-1){
        slot[j]=i;
        countJobs++;
        jobProfit+=arr[i].profit;
        break;
      }
    }
  }
  return {countJobs,maxProfit};
}
