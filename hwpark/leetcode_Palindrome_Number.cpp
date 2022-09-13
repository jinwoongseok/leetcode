
class Solution {
public:
    bool isPalindrome(int x) {
        int temp =x;
        int arr[11];
        int cnt=0;
        int len=0;
        if(x<0){
            return false;
        }
        while(temp!=0){
            arr[len+1]=temp%10;
            temp/=10;
            len+=1;
        }
    
        for(int i=1;i<=len/2;i++){
            if(arr[i]!=arr[len+1-i]){
                return false;
            }
        }
        return true;
    }
        
};
