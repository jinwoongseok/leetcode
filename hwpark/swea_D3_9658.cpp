#include<iostream>
#include<cstring>
using namespace std;

int T;

void solve(string s ,int t){
    int len = s.length();
    int temp = (int)(s[1]-'0');
    int first = (int)(s[0]-'0');
    if((int)(s[2]-'0') > 4){
        temp+=1;
        if(temp>9){
            first+=1;
            if(first>9){
                first=1;
                len+=1;
            }
            temp=0;
        }
    }
    len-=1;
    cout<<"#"<<t<<" "<<first<<"."<<temp<<"*10^"<<len<<"\n";

}

void input(){
    cin >> T;
    for(int i=1;i<=T;i++){
        string s;
        cin >> s;
        solve(s,i);
    }
}
void solution(){
    input();
}
int main(){
    solution();
    return 0;
}

