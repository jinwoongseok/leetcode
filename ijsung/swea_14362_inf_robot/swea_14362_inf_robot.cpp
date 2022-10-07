//#pragma warning (disable:4996)
#include<iostream>
#include <string.h>
#include <time.h>
using namespace std;
#define MAX_CMD 2500
typedef long long ll;

char cmd[MAX_CMD + 1] = { 0, };
int cmd_len = 0;

enum direction {
	EAST = 0,
	NORTH,
	WEST,
	SOUTH,
	DIRECTION_END
};

struct point {
	ll x;
	ll y;
	direction dir;
} cur_pos;

inline void init_tc()
{
	scanf("%s", cmd);
	cmd_len = strlen(cmd);

	cur_pos.x = 0;
	cur_pos.y = 0;
	cur_pos.dir = EAST;
}

inline void rotate_L(struct point& p)
{
	switch (p.dir)
	{
	case EAST:
		p.dir = NORTH;
		break;
	case NORTH:
		p.dir = WEST;
		break;
	case WEST:
		p.dir = SOUTH;
		break;
	case SOUTH:
		p.dir = EAST;
		break;
	}
}

inline void rotate_R(struct point& p)
{
	switch (p.dir)
	{
	case EAST:
		p.dir = SOUTH;
		break;
	case NORTH:
		p.dir = EAST;
		break;
	case WEST:
		p.dir = NORTH;
		break;
	case SOUTH:
		p.dir = WEST;
		break;
	}
}

inline void move(struct point& p)
{
	switch (p.dir)
	{
	case EAST:
		p.x++;
		break;
	case NORTH:
		p.y++;
		break;
	case WEST:
		p.x--;
		break;
	case SOUTH:
		p.y--;
		break;
	}
}

inline ll calc_dist(struct point& p)
{
	return p.x*p.x + p.y*p.y;
}

ll run_cmd(int turn)
{
	switch (cmd[turn])
	{
	case 'S':
		move(cur_pos);
		break;
	case 'L':
		rotate_L(cur_pos);
		break;
	case 'R':
		rotate_R(cur_pos);
		break;
	default:
		break;
	}
	return calc_dist(cur_pos);
}

int solve()
{
	ll net_max = -1;
	ll past_net_max = -1;


	for (int i = 0; i < DIRECTION_END * 2; i++)
	{
		ll turn_max = -1;
		for (int j = 0; j < cmd_len; j++)
		{
			ll tmp = run_cmd(j);
			if (tmp > turn_max)
				turn_max = tmp;
		}
		if (turn_max >= net_max)
		{
			past_net_max = net_max;
			net_max = turn_max;
		}
	}

	if (past_net_max < net_max)
		return -1;
	else
		return (int)net_max;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	clock_t start = clock();
	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ans = -1;
		init_tc();
		ans = solve();
		if (0 > ans)
			printf("#%d oo\n", test_case);
		else
			printf("#%d %d\n", test_case, ans);
	}
	printf("elapsed : %dms\n", clock() - start);
	return 0;
}
