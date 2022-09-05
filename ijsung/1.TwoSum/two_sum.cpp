#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_NUMLEN 10000
#define MIN_NUMLEN 2

#define MAX_NUM 1000000000
#define MIN_NUM -1000000000

#define MAX_TARGET 1000000000
#define MIN_TARGET -1000000000

struct sort_struct {
    int val;
    int idx;
};

bool comp( struct sort_struct a, struct sort_struct b ) {
    return a.val < b.val;
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> ret = { -1, -1 };
       vector<struct sort_struct> vec_sorted;
       int front_idx, back_idx; 
       int local_sum;

       if( MIN_NUMLEN > nums.size() || MAX_NUMLEN < nums.size() ) 
           return ret;

       if( MIN_TARGET > target || MAX_TARGET < target )
           return ret;
       
       for( int i = 0 ; i < nums.size() ; i++ ) {
           if( MIN_NUM > nums[i] || MAX_NUM < nums[i] )
               return ret;
           else {
                struct sort_struct tmp_sort;
                tmp_sort.val = nums[i];
                tmp_sort.idx = i;

                vec_sorted.push_back( tmp_sort );
           }
       }
             
       sort( vec_sorted.begin(), vec_sorted.end(), comp );
       /* From now, vec_sorted is sorted */ 

       front_idx = 0;
       back_idx = vec_sorted.size()-1;
       while( vec_sorted.size()-1 > front_idx ) {    
           while( vec_sorted.size() > back_idx ) {
               local_sum = vec_sorted[front_idx].val + vec_sorted[back_idx].val;
               if( local_sum == target ) {
                    ret[0] = ( (vec_sorted[front_idx].idx < vec_sorted[back_idx].idx) ? vec_sorted[front_idx].idx : vec_sorted[back_idx].idx );
                    ret[1] = ( (vec_sorted[front_idx].idx >= vec_sorted[back_idx].idx) ? vec_sorted[front_idx].idx : vec_sorted[back_idx].idx );
                    return ret;
               }
               else if( local_sum > target ) {
                   back_idx = back_idx / 2;
                   if( back_idx == front_idx )
                       break;
               }
               else if( local_sum < target ) {
                   back_idx = ( back_idx + ( back_idx * 2 ) ) / 2;
                    if( vec_sorted.size() >= back_idx ) {
                        back_idx = vec_sorted.size() - 1;
                        break;
                    }
               }
           }
           front_idx++;
       }
       return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 2,5,5,11 };
    int target = 10;
    vector<int> result;

    result = solution.twoSum( nums, target ); 
    std::cout << result[0] << ", " << result[1] << std::endl;
    return 0;
}
