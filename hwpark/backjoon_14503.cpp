

//1. 현재 위치 청소
//2. 왼쪽방향으로 청소가능한지 안한지 찾기.
//3. 만약 왼쪽 방향 청소가 가능하면 -> 왼쪽으로 회전하고 이동 ( 즉 청소되어지지 않은 칸으로 이동)
//4. 청소 불가능 하면 -> 그 방향으로 회전하고 다시 탐색.
//5. 네 방향 청소완료 or 벽 -> 바라보는 바향 유지 한칸 후진 후 다시 탐색
//6. 네 방향 청소완료 or 벽 or 뒤쪽 방향 벽이라 후진 못하면 스톱.

// 0 1 2 3
// 북 동 남 서


#include<iostream>
#include<queue>
using namespace std;
#define MAX_N 51
int N,M;            // Map의 크기
int vacuumX,vacuumY,direction;
int map[MAX_N][MAX_N];
int x_dir[4]={-1,0,1,0};        //북 동 남 서 순서
int y_dir[4]={0,1,0,-1};
int back_dir[4]={2,3,0,1};
queue<pair<int,int>> q;
void input(){
    cin >> N >> M;
    cin >> vacuumX >> vacuumY >> direction;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
}
void findSpace(){
    int result=1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int cnt =0;
        q.pop();
        while(1){
            if(direction==0) direction=3;                //방향이 북쪽(=0)이면 다음방향은 3이다
            else direction-=1;                           //0->3->2->1 순서이므로
            int nx = x + x_dir[direction];
            int ny = y + y_dir[direction];
            
            if(nx>=0 && ny>=0 && nx<N && ny<M ){
                if(map[nx][ny]==0 ){
                    map[nx][ny]=2;
                    result+=1;
                    q.push({nx,ny});
                    break;                      //청소할 수 있으면 그 부분부터 바로 다시 탐색 방향은 바뀐방향에서 왼쪽으로 회전하므로 dirtection 전역변수 사용
                }else{
                    cnt+=1;
                    if(4==cnt){         //4방향 모두 이미 청소가 되었거나 벽일 경우에
                        int nx = x + x_dir[back_dir[direction]];
                        int ny = y + y_dir[back_dir[direction]];
                        if(nx>=0 && ny>=0 && nx<N && ny<M ){
                        if(map[nx][ny]==1) break;                      //벽이면
                        q.push({nx,ny});
                        break;
                        }
                    }
                }
            }
            
        }
        
    }
    cout<<result<<"\n";

}
void solve(){
    q.push({vacuumX,vacuumY});
    map[vacuumX][vacuumY]=2;
    findSpace();
}
void solution(){
    input();
    solve();
}
int main(){
    solution();
    return 0;
}
