#include<iostream>
 
using namespace std;
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
     
    cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string s;
        cin >> s;
        int sequence=0;
        int cnt =0;
        for(int i=0;i<s.length();i++){
            if( s[i]-'a'==sequence || s[i]-'A'==sequence){
                sequence+=1;
                cnt+=1;
            }else break;
        }
        cout<<"#"<<test_case<<" ";
        if(sequence==0) cout << 0<<"\n";
        else cout<<cnt<<"\n";
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
