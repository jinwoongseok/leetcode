#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int a,b;
        cin >> a >> b;
        int range = (b*2)+1;
        int remain = a%range;
        int result=0;
        if( remain == 0){
        	result = a/range;
        }else{
            result =( a / range ) +1;
        }
        cout<< "#"<<test_case << " "<<result<<"\n";
	}
   
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
