class Solution {
public:
    int getSum(vector<int> v){
        int total = 0;
        for(int i=0;i<v.size();i++){
            total += v[i];
        }
        return total;
    }
    int pivotIndex(vector<int>& nums) {
        int rightSum = getSum(nums);
        int leftSum = 0;
        for(int i=0;i<nums.size();i++){
            rightSum -=nums[i];
            if(rightSum == leftSum) return i;
            else leftSum+=nums[i];
        }
        return -1;
    }
};
