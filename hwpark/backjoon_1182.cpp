
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_N 41
using namespace std;

int N,M,sum,total;
int result[MAX_N];
int num[MAX_N];
vector<int> v;

void input(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        v.push_back(a);

    }
    sort(v.begin(),v.end());
}
void solve( int cnt ){
    if(cnt == N ){
        return ;
    }
    for(int i=0;i<v.size();i++){
            if(cnt>0){
                if(num[cnt-1]<i){
                    if(sum+v[i]==M) total++;
                    num[cnt]=i;
                    sum+=v[i];
                    solve(cnt+1);
                    sum-=v[i];
                }
            }
            else{
                if(sum+v[i]==M) total++;
                num[cnt]=i;
                sum+=v[i];
                solve(cnt+1);
                sum-=v[i];
            }
        }
}
void solution(){
    input();
    solve(0);
    cout<<total<<"\n";
}
int main(){
    solution();
return 0;
}
