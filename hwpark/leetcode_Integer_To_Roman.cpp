class Solution {
public:
    int getLength(int n){
        int cnt=0;
        while(n!=0){   
            n=n/10;
            cnt++;
        }
        return cnt;
    }
    string intToRoman(int num) {
        map<int,string> m;
        m.insert({1,"I"});
        m.insert({5,"V"});
        m.insert({10,"X"});
        m.insert({50,"L"});
        m.insert({100,"C"});
        m.insert({500,"D"});
        m.insert({1000,"M"});
        m.insert({4,"IV"});
        m.insert({9,"IX"});
        m.insert({40,"XL"});
        m.insert({90,"XC"});
        m.insert({400,"CD"});
        m.insert({900,"CM"});
        int number = num;
        int len = getLength(num)-1;
        string result="";
        while(len!=-1){
            number=num;
            int digit = pow(10,len);      // 10,100,1000
            number/=digit;              //1,2,3,4,5,6,7,8,9 임
            num-=(number*digit);
            if(m.find(number)==m.end()){//없으면
                if(number>5){
                    result+=m[5*digit];
                    number-=5;
                }
                for(int i=0;i<number;i++) {
                    result+=m[digit];
                }
            }else  result+=m[number*digit];
            len--;
      }
      return result;
  }
};
