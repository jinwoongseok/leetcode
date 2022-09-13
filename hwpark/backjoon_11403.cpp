#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

#define MAX_N 101

int N;
int visited[MAX_N];
int result[MAX_N][MAX_N];
vector<int> v[MAX_N];
queue<int> q;

void input(){
    cin >> N;
    int input;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> input;
            if(input==1)    v[i].push_back(j);
        }
    }
}
void dfs(int node, int orgin_node){

    for(int i=0;i<v[node].size();i++){
        int next = v[node][i];
        if(visited[next]) continue;
        if(visited[next]==0){
            result[orgin_node][next]=1;
            visited[next]=1;
            dfs(next,orgin_node);
        }
    }
}

void solve(){
    for(int i=1;i<=N;i++){
        memset(visited,0,sizeof(visited));
        dfs(i,i);
    }
}
void print_result(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<< result[i][j]<<" " ;
        }
        cout<<"\n";
    }
}
void solution(){
    input();
    solve();
    print_result();
}
int main(){
    solution();
    return 0;
}

