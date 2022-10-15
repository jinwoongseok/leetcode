//#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define MAX_N 100

typedef unsigned long long ull;

ull scores[MAX_N];
int N;
vector<int> possible_sum;
bool possible_score[MAX_N*MAX_N] = { 0x00, };

inline void init_tc()
{
	possible_sum.clear();
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &scores[i]);

	possible_sum.push_back(0);
	possible_sum.push_back(scores[0]);
}

void get_partial_sum(int prob)
{
	vector<int> new_sum;
	int size_save = possible_sum.size();

	memset(possible_score, 0x00, N*N);

	for (int i = 0; i < size_save; i++)
	{
		if (!possible_score[possible_sum[i]])
		{
			possible_score[possible_sum[i]] = true;
		}
	}
	for (int i = 0; i < size_save; i++)
	{
		if (!possible_score[possible_sum[i] + scores[prob]])
		{
			possible_score[possible_sum[i] + scores[prob]] = true;
			possible_sum.push_back(possible_sum[i] + scores[prob]);
		}
	}
}

inline int solve()
{
	for (int i = 1; i < N; i++)
		get_partial_sum(i);

	return possible_sum.size();
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ret = 0;
		init_tc();
		ret = solve();
		printf("#%d %d\n", test_case, ret);
	}
	return 0;
}