class Solution {
public:
    string convert(string s, int numRows) {
        bool isReverse= false;
        int reverse = 0;
        string result[numRows];
        string st;
        if(numRows==1){
            return s;
        }
        
        for(int i=0;i<s.length();i++){
            if(isReverse==true){
                result[reverse]+=s[i];
                reverse-=1;
                if(reverse<0){
                  reverse =1;
                  isReverse = false;
                }else if(reverse==0){
                    reverse=0;
                    isReverse = false;
                }
            }else{                         
                result[(reverse)]+=s[i];
                reverse+=1;
                if(reverse%numRows==0){
                    reverse=numRows-2;
                    isReverse=true;
                }                
            }
        }
        
        for(int i=0;i<numRows;i++){
               st+=result[i];
        }
        return st;
    }
};
