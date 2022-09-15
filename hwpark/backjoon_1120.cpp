//문자열
//22/9/13
#include<iostream>
#include<cstring>
using namespace std;

string A,B;

void input(){
    cin >> A >> B;
}
void solve(){
    int dif = (int)B.length()-(int)A.length();
    int Max =52;
    for(int i=0;i<=dif;i++){
        int cnt = 0;
        for(int j=0;j<A.length();j++){
            if(A[j]!=B[j+i]){
                cnt+=1;
            }
        }
        if(Max>cnt){
            Max = cnt;
        }
    }
    cout<<Max;
}
void solution(){
    input();
    solve();
}
int main(){
    solution();
    return 0;
}
