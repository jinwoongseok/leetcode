class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i;j<nums.size();j++){
                if(nums[i]+nums[j]==target) v.push_back({nums[i],nums[j]});
                    
                    return  v[0];
                
            }
        }
