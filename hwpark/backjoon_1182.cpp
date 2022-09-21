
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define MAX_N 21

using namespace std;

int N,M;
int result[MAX_N];
int visited[MAX_N];
int num[MAX_N];
vector<int> v;
int cycle;
int sum;
int total;
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
    if(cnt == cycle ){
      //  for(int i=0;i<cnt;i++) cout<<num[i]<<" " ;
        if(sum == M){
             total+=1;
          }
        return ;
    }
    for(int i=0;i<v.size();i++){
        if(visited[i]==0){
            if(cnt>0){
                if(num[cnt-1]<i){
                    num[cnt]=i;
                    sum+=v[i];
                    solve(cnt+1);
                    sum-=v[i];
                }
            }
            else{
                sum+=v[i];
                num[cnt]=i;
                solve(cnt+1);
                sum-=v[i];
            }
        }
    }
}
void solution(){
    input();
    for(int i=1;i<=v.size();i++){
        cycle=i;
        sum=0;
        memset(visited,0,sizeof(visited));
        solve(0);

    }
    cout<<total<<"\n";
    
}
int main(){
    solution();
return 0;
}

