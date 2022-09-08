#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define pairInt pair<int,int>
#define MAX_N 20001
using namespace std;
#define ll long long
typedef struct loc{
    ll cost;
    int node;

    bool operator<(const loc& lo)const{
        return cost > lo.cost;
    }
}loc;


int N,M;
vector<pairInt> v[MAX_N];
vector<int> macdonald;
vector<int> starbucks;
int macMin,starMin;
int house[10001];
ll arr[10002];
int st,mc;
void input(){
    cin >> N >> M;
    int a, b, c;
    for(int j=1;j<=M;j++){
        cin >> a >> b>> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    memset(house,0,sizeof(house));
    int input;
    
    //더미노드를 사용하게 되면 스타벅스끼리의 Cost =0이 되며 모든 집들에 대한 최소 값을 구할 수있게된다.
    cin >> input >> macMin;
    for(int i=0;i<input;i++){
        cin >>a;
        house[a]=1;
        v[0].push_back({a,0});
    }
    //더미노드를 사용 스타벅스용
    cin >> input >> starMin;
    for(int i=0;i<input;i++){
        cin  >> a;
        house[a]=2;
        v[N+1].push_back({a,0});
    }
}
void dijkstra(int startNode){
    for(int i=0;i<=N+1;i++){
        arr[i]=1e12;
    }
    priority_queue<loc> pq;
    pq.push({0,startNode});
    arr[startNode]=0;
    int cur,next;
    ll cost,nextCost;
    while(!pq.empty()){
        cur = pq.top().node;
        cost = pq.top().cost;
        pq.pop();
        if(cost > arr[cur] )continue;
        for(int i=0;i<v[cur].size();i++){
            next =v[cur][i].first;
            nextCost = v[cur][i].second+cost;
            if( nextCost < arr[next]){
                arr[next]=nextCost;
                pq.push({nextCost,next});
            }
        }
    }//end while
}


void solve(){
    ll result=1e12;
    ll dist[N+2];

    dijkstra(0);                //맥날
    for(int i=1;i<=N;i++){
        dist[i] = arr[i];
    }
    dijkstra(N+1);           //스벅
    
    for(int i=1;i<=N;i++){
        if(house[i]!=0)continue;
        else if(dist[i]<=macMin && arr[i]<=starMin){
            if(result > min((dist[i]+arr[i]),result)){
                result=min((dist[i]+arr[i]),result);
            }
        }
    }
    
    if(result>=1e12){
        cout<<"-1\n";
    }else{
        cout<<result<<"\n";
    }
}
void solution(){
    input();
    solve();
}
int main(){
    solution();
return 0;
}



