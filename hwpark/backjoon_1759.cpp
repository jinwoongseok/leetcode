#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>

using namespace std;
#define MAX_N 16

int L,C ;
vector<char> v;
int visited[MAX_N];
char value[MAX_N];
map<char,int> m;
void input(){
    m.insert({'a',0});
    m.insert({'e',1});
    m.insert({'i',2});
    m.insert({'o',3});
    m.insert({'u',4});

    cin >> L >> C;
    for(int i=0;i<C;i++){
        char in;
        cin >> in;
        v.push_back(in);
    }
    sort(v.begin(),v.end());
}
void solve( int cnt ){
    if(cnt == L ){
        string s;
        int von=0; //모음
        int con=0; //자음
        for(int i=0;i<L;i++){
            if(m.find(value[i])!=m.end()){
                von+=1;
            }else{
                con+=1;
            }
            s+=value[i];
        }
        if(von>=1 && con>=2){
            cout<<s<<"\n";
        }
        return;
    }// a c i s t w
    
    for(int i=0;i<C;i++){
        if(visited[i]==0 && (int)value[cnt-1] < (int)v[i] ){
            visited[i]=1;
            value[cnt]=v[i];
            solve(cnt+1);
            visited[i]=0;
        }
        
    }
}
void solution(){
    input();
    solve(0);
}
int main(){
    solution();
    return 0;
}



