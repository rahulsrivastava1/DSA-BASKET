// Sort a stack

class Solution {
public:
    void insert(stack<int>&nums,int temp){
        if(nums.size()==0 || nums.top()<=temp){
            nums.push(temp);
            return;
        }
        int val=nums.top();
        nums.pop();
        insert(nums,temp);
        nums.push(val);
    }
    stack<int> sortArray(stack<int>& nums) {
        if(nums.size()==1)
            return {0};
        int temp=nums.top();
        nums.pop();
        sortArray(nums);
        insert(nums,temp);
        return nums;
    }
};
