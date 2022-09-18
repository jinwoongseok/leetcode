class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx=0;
        for(int find=0;find<nums.size();find++){
                if(nums[find]!=0){          //숫자라면 idx바꿔줘야할 위치랑 바꿔주기
                    nums[idx]=nums[find];   
                    idx++;              
                }
        }
        for(int i=idx;i<nums.size();i++){
            nums[i]=0;
        }
    }
};
