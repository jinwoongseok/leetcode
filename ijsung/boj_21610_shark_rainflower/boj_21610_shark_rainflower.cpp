#pragma warning (disable:4996)

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define MAX_N 50
#define MAX_M 100
#define MAX_WATER 100

enum _dir { LL = 1, LU, UU, UR, RR, RD, DD, DL };

typedef struct _coord {
	int r, c;
} coord;
typedef struct _cmd {
	_dir d;
	int s;
} cmd;

int N;
int M;
int water_bucket[MAX_N + 2][MAX_N + 2] = { 0, };
cmd command[MAX_M];

vector<coord> clouds;

inline bool chk_edge(int r, int c)
{
	if (r < 1 || r > N || c < 1 || c > N)
		return true;
	else
		return false;
}

inline bool chk_edge(coord co)
{
	return chk_edge(co.r, co.c);
}

void print_bucket()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			printf("[%3d] ", water_bucket[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void print_clouds()
{
	printf("clouds : ");
	for (int i = 0; i < clouds.size(); i++)
	{
		printf("[%2d,%2d] ", clouds[i].r, clouds[i].c);
	}
	printf("\n\n");
}

void init_tc()
{
	//memset(water_bucket, 0x00, sizeof(water_bucket));
	//memset(command, 0x00, sizeof(command));

	scanf("%d %d", &N, &M);

	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= N + 1; j++)
		{
			if (chk_edge(i, j))
				water_bucket[i][j] = -1;
			else
				scanf("%d", &water_bucket[i][j]);
		}
	}

	for (int i = 0; i < M; i++)
	{
		int d, s;
		scanf("%d %d", &d, &s);
		command[i].d = (_dir)d;
		command[i].s = s;
	}

	clouds.push_back({ N,1 });
	clouds.push_back({ N,2 });
	clouds.push_back({ N - 1,1 });
	clouds.push_back({ N - 1,2 });
}

void move(coord &co, cmd cmd)
{
	switch (cmd.d)
	{
	case LL:
		co.c = co.c - cmd.s;
		while (co.c < 1)
			co.c = co.c + N;
		break;
	case LU:
		co.r = co.r - cmd.s;
		co.c = co.c - cmd.s;
		while (co.r < 1)
			co.r = co.r + N;
		while (co.c < 1)
			co.c = co.c + N;
		break;
	case UU:
		co.r = co.r - cmd.s;
		while (co.r < 1)
			co.r = co.r + N;
		break;
	case UR:
		co.r = co.r - cmd.s;
		co.c = co.c + cmd.s;
		while (co.r < 1)
			co.r = co.r + N;
		while (co.c > N)
			co.c = co.c - N;
		break;
	case RR:
		co.c = co.c + cmd.s;
		while (co.c > N)
			co.c = co.c - N;
		break;
	case RD:
		co.r = co.r + cmd.s;
		co.c = co.c + cmd.s;
		while (co.r > N)
			co.r = co.r - N;
		while (co.c > N)
			co.c = co.c - N;
		break;
	case DD:
		co.r = co.r + cmd.s;
		while (co.r > N)
			co.r = co.r - N;
		break;
	case DL:
		co.r = co.r + cmd.s;
		co.c = co.c - cmd.s;
		while (co.r > N)
			co.r = co.r - N;
		while (co.c < 1)
			co.c = co.c + N;
		break;
	}

	if (co.r < 1 || co.c < 1 || co.r > N || co.c > N)
	{
		printf("here\n");
	}
}

void step1_move_cloud(cmd cmd)
{
	for (int i = 0; i < clouds.size(); i++)
	{
		move(clouds[i], cmd);
	}
}

void step2_increase_water()
{
	for (int i = 0; i < clouds.size(); i++)
	{
		water_bucket[clouds[i].r][clouds[i].c]++;
	}
}

int get_adjacent_water(coord co)
{
	int ret = 0;
	if (water_bucket[co.r - 1][co.c - 1] > 0)
		ret++;
	if (water_bucket[co.r - 1][co.c + 1] > 0)
		ret++;
	if (water_bucket[co.r + 1][co.c - 1] > 0)
		ret++;
	if (water_bucket[co.r + 1][co.c + 1] > 0)
		ret++;

	return ret;
}

typedef struct _water_copy {
	coord co;
	int amount;
} water_copy;

void step3_water_copy()
{
	vector<water_copy> vec_copy;
	for (int i = 0; i < clouds.size(); i++)
	{
		int amount = get_adjacent_water(clouds[i]);
		vec_copy.push_back({ clouds[i], amount });
	}

	for (int i = 0; i < vec_copy.size(); i++)
	{
		water_bucket[vec_copy[i].co.r][vec_copy[i].co.c] += vec_copy[i].amount;
	}
}

void step4_gen_clouds()
{
	bool past_clouds[MAX_N + 2][MAX_N + 2] = { false, };
	for (int i = 0; i < clouds.size(); i++)
	{
		past_clouds[clouds[i].r][clouds[i].c] = true;
	}
	clouds.clear();

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!past_clouds[i][j] && water_bucket[i][j] >= 2) {
				water_bucket[i][j] -= 2;
				clouds.push_back({ i,j });
			}
		}
	}
}

int solve()
{
	int total = 0;
	for (int i = 0; i < M; i++)
	{
		step1_move_cloud(command[i]);
	/*	printf("after step1\n");
		print_bucket();
		print_clouds();
		printf("after step2\n");*/
		step2_increase_water();
		/*print_bucket();
		print_clouds();
		printf("after step3\n");*/
		step3_water_copy();
		/*print_bucket();
		print_clouds();
		printf("after step4\n");*/
		step4_gen_clouds();
		/*print_bucket();
		print_clouds();*/

		//printf("\n\n");
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			total += water_bucket[i][j];
		}
	}

	return total;
}

int main()
{
	/*int T;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		int ret;
		init_tc();
		ret = solve();

		printf("%d\n", ret);
	}*/

	int ret;
	init_tc();
	ret = solve();

	printf("%d\n", ret);

	return 0;
}