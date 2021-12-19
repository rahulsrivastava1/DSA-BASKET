// Sort an array

class Solution {
public:
    void insert(vector<int>& nums,int temp){
        if(nums.size()==0 || nums[nums.size()-1]<=temp){
            nums.push_back(temp);
            return;
        }
        int val=nums[nums.size()-1];
        nums.pop_back();
        insert(nums,temp);
        nums.push_back(val);
    }
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()==1)
            return {0};
        int temp=nums[nums.size()-1];
        nums.pop_back();
        sortArray(nums);
        insert(nums,temp);
        return nums;
    }
};
