#pragma warning(disable:4996)

#include<iostream>
using namespace std;
#include <math.h>

double LOG_2;

inline double log_2(int val) {
/* function to calculate base 2 log */
	return (log10(val) / LOG_2);
}

inline bool chk_otherside(int n, int v)
{
	while (n >= 4)
		n = n >> 1;
	while (v >= 4)
		v = v >> 1;

	/* if v is on right side 
	 * we don't need to check
	 */
	if (v == 3)
		return false;
	
	return (n == v);
}

int solve(int n, int v) {
	int tree_depth;
	int v_depth;
	int alone_vertex = 0;

	tree_depth = log_2(n);
	v_depth = log_2(v);
	
	if ( 1 < n && chk_otherside( n, v ) )
		alone_vertex = 1;

	return v_depth + tree_depth - alone_vertex;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	LOG_2 = log10(2);
	freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, V;
		scanf("%d %d", &N, &V);
		printf("#%d %d\n", test_case, solve(N, V));
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}