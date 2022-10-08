#pragma warning(disable:4996)
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
using namespace std;
#define MAX_TC 157
#define MAX_STR 100000

int cards[MAX_STR+2] = { 0x00, };
char str[MAX_STR] = { 0x00, };
int N;
vector<string> vec_no;
vector<string> vec_yes;

inline void init_tc()
{
	scanf("%s", str);
	N = strlen(str);
	for (int i = 1; i < N+1; i++)
	{
		cards[i] = str[i-1] - '0';
	}
}

void preprocess()
{
	vec_no.push_back("0");
	vec_yes.push_back("1");

	vec_no.push_back("00");
	vec_no.push_back("11");

	vec_yes.push_back("01");
	vec_yes.push_back("10");
	   
	vec_no.push_back("000");
	vec_no.push_back("011");
	vec_no.push_back("101");
	vec_no.push_back("110");

	vec_yes.push_back("001");
	vec_yes.push_back("010");
	vec_yes.push_back("100");
	vec_yes.push_back("111");

	vec_no.push_back("0000");
	vec_no.push_back("0011");
	vec_no.push_back("0101");
	vec_no.push_back("0110");
	vec_no.push_back("1001");
	vec_no.push_back("1010");
	vec_no.push_back("1100");
	vec_no.push_back("1111");
	
	vec_yes.push_back("0001");
	vec_yes.push_back("0010");
	vec_yes.push_back("0100");
	vec_yes.push_back("0111");
	vec_yes.push_back("1000");
	vec_yes.push_back("1011");
	vec_yes.push_back("1101");
	vec_yes.push_back("1110");
}

int solve()
{
	int zero_cnt = 0;
	int one_cnt = 0;

	for (int i = 0; i < N; i++)
	{
		if (str[i] == '0')
			zero_cnt++;
		else
			one_cnt++;
	}
	return one_cnt % 2 == 1;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	clock_t start = clock();
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	//preprocess();
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ret = 0;
		init_tc();
		ret = solve();
		printf("#%d %s\n", test_case, ret ? "yes" : "no");
	}
	printf("Elapsed time : %dms\n", clock() - start);
	return 0;
}