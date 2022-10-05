#pragma warning(disable : 4996)
#include<iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define LEFT_LIMIT 3
#define MAX_DIGIT 100000

struct num_info {
	int msd[LEFT_LIMIT];
	int pow;
};

int get_num_info(char* num, struct num_info &out_info)
{
	if (!num)
		return -1;
	out_info.pow = strlen(num) -1;
	char tmp[2] = { 0,0 };

	tmp[0] = num[0];
	out_info.msd[0] = atoi(tmp);
	tmp[0] = num[1];
	out_info.msd[1] = atoi(tmp);
	tmp[0] = num[2];
	out_info.msd[2] = atoi(tmp);
	return 0;
}

void round_msd3(struct num_info &out_info)
{
	if (5 > out_info.msd[2])
		return;
	
	out_info.msd[1]++;

	if (5 > out_info.msd[1])
		return;

	if (10 <= out_info.msd[1])
	{
		out_info.msd[1] -= 10;
		out_info.msd[0]++;
	}

	if (10 <= out_info.msd[0])
	{
		out_info.msd[1] = out_info.msd[0] - 10;
		out_info.msd[0] = 1;
		out_info.pow++;
	}
	
	return;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ret = 0;

		char str_num[MAX_DIGIT + 1] = { 0x00, };
		struct num_info n_info = { 0x00, };
		scanf("%s", str_num);

		ret = get_num_info( str_num, n_info );
		if (ret)
		{
			printf("#%d Failed to get struct num_info\n", test_case);
			continue;
		}		
		round_msd3(n_info);
		printf("#%d %d.%d*10^%d\n", test_case, n_info.msd[0], n_info.msd[1], n_info.pow);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}