#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX_N 100000

int arr[MAX_N];
int A,B;
vector<int> v;
int search(int start,int end, int target){
    if(start>end) return 0;
    int mid = (start+end)/2;
    if(arr[mid]==target) return 1;
    else if(arr[mid]>target) return search(start,mid-1,target);//target이 더 작을 때
        else return search(mid+1,end,target);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> A;
    for(int i=0;i<A;i++){
        cin >> arr[i];
    }
    sort(arr,arr+A);                // sort 기본이 quick 정렬 O(nlog(n))
    cin >> B;
    for(int i=0;i<B;i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    for(int i=0;i<B;i++){               //2분탐색 O(logn)
        cout<<search(0,A-1,v[i])<<"\n";
    }
    return 0;
}
