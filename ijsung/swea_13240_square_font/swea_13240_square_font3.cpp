//#pragma warning(disable:4996)
#include<iostream>
#include <string>
#include <string.h>
using namespace std;

#define MAX_HWN 1000
#define MAX_WORDS 1000

int H, W, N;
string words[MAX_WORDS];
int lensum[MAX_HWN][MAX_HWN];

void init_tc()
{
	char buf[MAX_WORDS];
	scanf("%d %d %d", &H, &W, &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", buf);
		words[i] = buf;
		lensum[i][i] = words[i].length();
		for (int j = i; j >= 0; j--)
		{
			lensum[j][i] = lensum[j][i - 1] + lensum[i][i];
		}
	}
}

inline int get_len_sum(int l, int r)
{
	return lensum[l][r] + r - l;
}

int relocate_words(int line)
{
	int font_size = H / line;
	int ret = 0;


	for (int f = font_size; f > 0; f--)
	{
		int idx_newline = 0;
		int w_limit = W / f;

		for (int l = 0; l < line; l++)
		{
			int r;
			int found = false;
			for (r = N - 1; r >= idx_newline; r--)
			{
				int line_len = get_len_sum(idx_newline, r);
				if (w_limit >= line_len)
				{
					idx_newline = r + 1;
					found = true;
					break;
				}
			}

			if (r + 1 >= N)
			{
				ret = f;
				return ret;
			}

			if (!found)
				break;
		}
	}

	return ret;
}


inline int solve()
{
	int font_size = 0;

	for (int line = 1; line <= H; line++)
	{
		int tmp = 0;
		tmp = relocate_words(line);
		if (font_size < tmp)
			font_size = tmp;
	}

	return font_size;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//	freopen("input.txt", "r", stdin);
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