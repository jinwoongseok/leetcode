class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        //hashmap사용하기
        for(int i=0;i<nums.size();i++){
            int gap = target-nums[i];
            map<int,int>::iterator iter;
            iter = m.find(gap);
            if(iter != m.end()){//만약 존재하면
                return {i,m[gap]};
            }else{
                m.insert({nums[i],i});
            }
        }
        return {};
    }  //end func 
    
};



//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        vector<pair<int,int>> v;
//        for(int i=0;i<nums.size()-1;i++){
//            for(int j=i;j<nums.size();j++){
//                if(nums[i]+nums[j]==target) v.push_back({nums[i],nums[j]});
//                    
//                    return  v[0];
//                
//            }
//        }
