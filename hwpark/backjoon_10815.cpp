#include<iostream>
#include<map>
#include<vector>
using namespace std;

int N,M;
vector<int> card;
vector<int> result;
map<int,int> m;

void input(){
    cin >>  N ;
    for(int i=0;i<N;i++){
        int input;
        cin >> input;
        m.insert({input,input});
    }
    cin >> M;
    for(int j=0;j<M;j++){
        int input;
        cin >> input;
        card.push_back(input);
    }
}
void search(){
    for(int i=0;i<card.size();i++){
        if(m.find(card[i])!=m.end()){
            result.push_back(1);
        }else result.push_back(0);
    }
}
void solve(){
    search();
    for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
}
int main(){
    input();
    solve();
    
    return 0;
}

