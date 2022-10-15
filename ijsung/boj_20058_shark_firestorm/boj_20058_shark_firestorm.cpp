#pragma warning (disable :4996)

#include <iostream>
#include <math.h>
#include <vector>
#include <queue>

#define MAX_N 6
#define MAX_Q 1000
#define MAX_ICE 100

#define MAX_R 64
#define MAX_C 64

using namespace std;

int N;
int Q;

int RC;

int ice[MAX_R + 2][MAX_C + 2] = { 0, };
int arr_L[MAX_Q * 2] = { 0, };

inline bool chk_edge(int r, int c)
{
	if (r < 1 || c < 1 || r > RC || c > RC)
		return true;
	else
		return false;
}

void print_ice()
{
	for (int i = 1; i <= RC; i++)
	{
		for (int j = 1; j <= RC; j++)
		{
			printf("%2d", ice[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void init_tc()
{
	scanf("%d %d", &N, &Q);
	RC = pow(2, N);
	for (int i = 0; i <= RC + 1; i++)
	{
		for (int j = 0; j <= RC + 1; j++)
		{
			if (chk_edge(i, j))
				ice[i][j] = 0;
			else {
				int tmp;
				scanf("%d", &tmp);
				ice[i][j] = tmp;
			}
		}
	}

	arr_L[0] = -1;
	for (int i = 1; i <= Q; i++)
	{
		scanf("%d", &arr_L[i]);
	}
}

typedef struct _split_info
{
	int split_len;
	int split_cnt;
	pair<int, int> start_point[(MAX_R + 2) * (MAX_C + 2)];
	int start_point_cnt;
} split_info;

void get_split_info(int L, split_info *output)
{
	output->split_len = pow(2, L);
	output->split_cnt = RC / output->split_len;

	output->start_point_cnt = 0;

	for (int i = 1; i <= RC; )
	{
		for (int j = 1; j <= RC; )
		{
			output->start_point[output->start_point_cnt].first = i;
			output->start_point[output->start_point_cnt].second = j;
			output->start_point_cnt++;
			j = j + output->split_len;
		}
		i = i + output->split_len;
	}
}

void rotate(split_info *info)
{
	int rc = info->split_len;
	int partial_ice[MAX_R + 2][MAX_C + 2] = { 0, };
	int rotated_ice[MAX_R + 2][MAX_C + 2] = { 0, };

	// [i,j] -> [j,N+1-i]

	for (int repeat = 0; repeat < info->start_point_cnt; repeat++)
	{
		for (int i = 0; i < info->split_len; i++)
		{
			for (int j = 0; j < info->split_len; j++)
			{
				partial_ice[i][j] = ice[info->start_point[repeat].first + i][info->start_point[repeat].second + j];
			}
		}

		for (int i = 0; i < info->split_len; i++)
		{
			for (int j = 0; j < info->split_len; j++)
			{
				rotated_ice[j][info->split_len - i - 1] = partial_ice[i][j];
			}
		}

		for (int i = 0; i < info->split_len; i++)
		{
			for (int j = 0; j < info->split_len; j++)
			{
				ice[info->start_point[repeat].first + i][info->start_point[repeat].second + j] = rotated_ice[i][j];
			}
		}
	}
}

void split_and_rotate(int L)
{
	split_info info;
	get_split_info(L, &info);
	rotate(&info);
}

void reduce_ice()
{
	vector<pair<int, int>> reduce_rc;

	for (int i = 1; i <= RC; i++)
	{
		for (int j = 1; j <= RC; j++)
		{
			if (ice[i][j] > 0)
			{
				int cnt_empty = 0;
				if (ice[i - 1][j] == 0)
					cnt_empty++;
				if (ice[i + 1][j] == 0)
					cnt_empty++;
				if (ice[i][j - 1] == 0)
					cnt_empty++;
				if (ice[i][j + 1] == 0)
					cnt_empty++;

				if (cnt_empty >= 2)
				{
					reduce_rc.push_back({ i,j });
				}
			}
		}
	}

	for (int i = 0; i < reduce_rc.size(); i++)
	{
		ice[reduce_rc[i].first][reduce_rc[i].second]--;
	}
}

int cnt_ice()
{
	int ret = 0;
	for (int i = 1; i <= RC; i++)
	{
		for (int j = 1; j <= RC; j++)
		{
			ret += ice[i][j];
		}
	}
	return ret;
}

int cnt_bulk(int r, int c, bool out_visit[MAX_R + 2][MAX_C + 2])
{
	vector<pair<int, int>> bulk_info;
	bool visited[MAX_R + 2][MAX_C + 2] = { false, };
	queue<pair<int, int>> bfs;
	bfs.push({ r,c });

	while (!bfs.empty())
	{
		pair<int, int> tmp;
		tmp = bfs.front();
		bfs.pop();
		if (!visited[tmp.first][tmp.second])
		{
			visited[tmp.first][tmp.second] = true;
			bulk_info.push_back({ tmp.first, tmp.second });

			if (!visited[tmp.first - 1][tmp.second] && ice[tmp.first - 1][tmp.second] != 0)
				bfs.push({ tmp.first - 1, tmp.second });

			if (!visited[tmp.first + 1][tmp.second] && ice[tmp.first + 1][tmp.second] != 0)
				bfs.push({ tmp.first + 1, tmp.second });

			if (!visited[tmp.first][tmp.second - 1] && ice[tmp.first][tmp.second - 1] != 0)
				bfs.push({ tmp.first, tmp.second - 1 });

			if (!visited[tmp.first][tmp.second + 1] && ice[tmp.first][tmp.second + 1] != 0)
				bfs.push({ tmp.first, tmp.second + 1 });
		}
	}

	for (int i = 0; i < bulk_info.size(); i++)
	{
		out_visit[bulk_info[i].first][bulk_info[i].second] = true;
	}
	return bulk_info.size();
}

int get_max_bulk()
{
	bool visited[MAX_R + 2][MAX_C + 2] = { false, };
	int max = 0;

	for (int i = 1; i <= RC; i++)
	{
		for (int j = 1; j <= RC; j++)
		{
			if (!visited[i][j] && ice[i][j] > 0) {
				int ret = cnt_bulk(i, j, visited);
				max = max < ret ? ret : max;
			}
		}
	}

	return max;
}

pair<int, int> solve()
{
	pair<int, int> ret = { 0, 0 };
	for (int i = 1; i <= Q; i++) {
		split_and_rotate(arr_L[i]);
		reduce_ice();
	}
	ret.first = cnt_ice();
	ret.second = get_max_bulk();
	return ret;
}

int main()
{
	int T;
	//freopen("input.txt", "r", stdin);
	//scanf("%d", &T);

	//for (int tc = 1; tc <= T; tc++)
	//{
	//	pair<int, int> ret;
	//	init_tc();
	//	ret = solve();

	//	printf("%d\n%d\n\n", ret.first, ret.second);
	//}

	pair<int, int> ret;
	init_tc();
	ret = solve();
	printf("%d %d\n", ret.first, ret.second);

	return 0;
}