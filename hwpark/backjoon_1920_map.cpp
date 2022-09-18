#include<iostream>
#include<map>

using namespace std;
map<int,int> m;

void input(){
    int N,M;
    cin >> N;
    for(int i=0;i<N;i++){
        int input;
        cin >> input;
        m.insert({input,input});
    }
    cin >>M;
    for(int i=0;i<M;i++){
        int input;
        cin >> input;
        if(m.find(input)!=m.end()) cout<<"1\n";
        else cout<<"0\n";
    }
}
void solution(){
    input();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
    return 0;
}

