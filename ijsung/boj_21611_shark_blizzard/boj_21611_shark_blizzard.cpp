#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <time.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

enum _dir { UU = 1, DD, LL, RR };

typedef struct _st_cmd {
	int d, s;
} st_cmd;

typedef struct _coord {
	int r, c;
} coord;

typedef struct _st_board {
	int num;
	int r, c;
	int marble;
} st_board;

#define MAX_N 49
#define MAX_M 100

int N;
int M;
st_board board[MAX_N + 2][MAX_N + 2] = { 0x00, };
st_cmd cmd[MAX_M] = { 0x00, };
coord shark;
st_board *num_to_board[MAX_N*MAX_N + 1] = { 0x00, };

int max_num = 0;

void print_board_num()
{
	printf("[%s]\n", __func__);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			printf("[%3d] ", board[i][j].num);
		printf("\n");
	}
	printf("\n\n");
}

void print_board_marble()
{
	printf("[%s]\n", __func__);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (board[i][j].marble == 0)
				printf("[   ] ");
			else
				printf("[%3d] ", board[i][j].marble);
		}
		printf("\n");
	}
	printf("\n\n");
}

inline bool chk_edge(int r, int c)
{
	if (r < 1 || r> N || c<1 || c>N)
		return true;
	else
		return false;
}

inline bool chk_edge(coord co)
{
	return chk_edge(co.r, co.c);
}

void set_num_to_board(coord start, int max_num)
{
	int s_r = start.r;
	int s_c = start.c;
	int num = max_num;

	int lst_r, lst_c;

	if (max_num == 0)
		return;

	// 윗행 채우기 (좌->우)
	for (int i = s_c; i <= N; i++)
	{
		if (board[s_r][i].num == -1)
		{
			board[s_r][i].num = num;
			num_to_board[num] = &board[s_r][i];
			num--;
			lst_c = i;
		}
		else
			break;
	}

	// 우측열 채우기 (상->하)
	for (int j = s_r + 1; j <= N; j++)
	{
		if (board[j][lst_c].num == -1)
		{
			board[j][lst_c].num = num;
			num_to_board[num] = &board[j][lst_c];
			num--;
			lst_r = j;
		}
		else {
			break;
		}

	}
	// 아랫행 채우기 (우->좌)
	for (int i = lst_c - 1; i > 0; i--)
	{
		if (board[lst_r][i].num == -1)
		{
			board[lst_r][i].num = num;
			num_to_board[num] = &board[lst_r][i];
			num--;
			lst_c = i;
		}
		else
			break;
	}
	// 왼쪽열 채우기 (하->상)
	for (int j = lst_r - 1; j > 0; j--)
	{
		if (board[j][lst_c].num == -1)
		{
			board[j][lst_c].num = num;
			num_to_board[num] = &board[j][lst_c];
			num--;
			lst_r = j;
		}
		else {
			break;
		}
	}
	start.r = lst_r;
	start.c = lst_c + 1;
	return set_num_to_board(start, num);
}

void init_tc()
{
	N = 0, M = 0;
	memset(board, 0x00, sizeof(board));
	memset(cmd, 0x00, sizeof(cmd));
	memset(num_to_board, 0x00, sizeof(num_to_board));
	shark = { 0,0 };

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N + 2; i++)
	{
		for (int j = 0; j < N + 2; j++)
		{
			if (chk_edge(i, j)) {
				board[i][j].marble = -1;
				board[i][j].r = -1;
				board[i][j].c = -1;
				board[i][j].num = -1;
			}
			else {
				scanf("%d", &board[i][j].marble);
				board[i][j].r = i;
				board[i][j].c = j;
				board[i][j].num = -1;
			}

		}
	}

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &cmd[i].d, &cmd[i].s);
	}

	shark.r = (N + 1) / 2;
	shark.c = (N + 1) / 2;
	max_num = N * N - 1;
	set_num_to_board({ 1,1 }, max_num);
	//print_board_num();
}

void move_marble_compact(int start_num)
{
	int flag_end = 0;
	int blank_cnt = 1;

	for (int i = start_num; i <= max_num; i++)
	{
		if (num_to_board[i]->marble == 0)
		{
			for (int j = blank_cnt; i + j <= max_num + 1; j++)
			{
				if (i + j == max_num + 1)
				{
					flag_end = 1;
					break;
				}
				else
				{
					if (num_to_board[i + j]->marble != 0)
					{
						num_to_board[i]->marble = num_to_board[i + j]->marble;
						num_to_board[i + j]->marble = 0;
						flag_end = 1;
						break;
					}
					else
						blank_cnt++;
				}
			}
		}
	}
	//print_board_marble();
}

void step1_destroy_marble(st_cmd c)
{
	int tmp_dst = 0;
	int tmp_r = shark.r;
	int tmp_c = shark.c;
	int flag_break = 0;

	vector<int> destroyed;

	// 파괴단계
	while (!flag_break)
	{
		switch (c.d)
		{
		case UU:
			tmp_r--;
			if (!chk_edge(tmp_r, tmp_c) && board[tmp_r][tmp_c].marble != 0)
			{
				tmp_dst = abs(tmp_r - shark.r);
				if (tmp_dst <= c.s)
				{
					board[tmp_r][tmp_c].marble = 0;
					destroyed.push_back(board[tmp_r][tmp_c].num);
				}
				else
					flag_break = 1;
			}
			else
				flag_break = 1;
			break;
		case DD:
			tmp_r++;
			if (!chk_edge(tmp_r, tmp_c) && board[tmp_r][tmp_c].marble != 0)
			{
				tmp_dst = abs(tmp_r - shark.r);
				if (tmp_dst <= c.s)
				{
					board[tmp_r][tmp_c].marble = 0;
					destroyed.push_back(board[tmp_r][tmp_c].num);
				}
				else
					flag_break = 1;
			}
			else
				flag_break = 1;
			break;
		case LL:
			tmp_c--;
			if (!chk_edge(tmp_r, tmp_c) && board[tmp_r][tmp_c].marble != 0)
			{
				tmp_dst = abs(tmp_c - shark.c);
				if (tmp_dst <= c.s)
				{
					board[tmp_r][tmp_c].marble = 0;
					destroyed.push_back(board[tmp_r][tmp_c].num);
				}
				else
					flag_break = 1;
			}
			else
				flag_break = 1;
			break;
		case RR:
			tmp_c++;
			if (!chk_edge(tmp_r, tmp_c) && board[tmp_r][tmp_c].marble != 0)
			{
				tmp_dst = abs(tmp_c - shark.c);
				if (tmp_dst <= c.s)
				{
					board[tmp_r][tmp_c].marble = 0;
					destroyed.push_back(board[tmp_r][tmp_c].num);
				}
				else
					flag_break = 1;
			}
			else
				flag_break = 1;
			break;
		}
	}
	//print_board_marble();
	// 이동단계
	if (destroyed.size())
	{
		sort(destroyed.begin(), destroyed.end());
		move_marble_compact(destroyed[0]);
	}
	//print_board_marble();
}

int explosion()
{
	int ret = 0;
	int nxt_num = 2;
	vector<int> destroyed;

	int exp_1 = 0;
	int exp_2 = 0;
	int exp_3 = 0;

	for (int i = 1; i <= max_num; i = nxt_num)
	{
		nxt_num = i + 1;
		while ((num_to_board[i]->marble != 0) && (num_to_board[i]->marble == num_to_board[nxt_num]->marble))
		{
			nxt_num++;
		}

		if (nxt_num - i >= 4)
		{
			for (int j = i; j < nxt_num; j++)
			{
				switch (num_to_board[j]->marble)
				{
				case 1:
					exp_1++;
					break;
				case 2:
					exp_2++;
					break;
				case 3:
					exp_3++;
					break;
				}
				num_to_board[j]->marble = 0;
				destroyed.push_back(j);
			}
		}
	}
	//	print_board_marble();
	if (destroyed.size())
	{
		sort(destroyed.begin(), destroyed.end());
		move_marble_compact(destroyed[0]);
	}

	return 3 * exp_3 + 2 * exp_2 + exp_1;
}
int step2_explosion()
{
	int ret = 0;

	int sub_ret = 0;
	int repeat = 1;
	while (repeat) {
		sub_ret = explosion();
		ret = ret + sub_ret;
		if (!sub_ret)
			repeat = 0;
	}
	return ret;
}

typedef struct _group {
	int A;
	int B;
} group;

void step3_mutation()
{
	int nxt_num = 2;

	vector<group> vec_group;

	for (int i = 1; i <= max_num; i = nxt_num)
	{
		nxt_num = i + 1;
		while ((num_to_board[i]->marble != 0) && (num_to_board[i]->marble == num_to_board[nxt_num]->marble))
		{
			nxt_num++;
		}
		if (num_to_board[i]->marble == 0)
			break;
		vec_group.push_back({ nxt_num - i, num_to_board[i]->marble });
		for (int j = i; j < nxt_num; j++)
		{
			num_to_board[j]->marble = 0;
		}
	}
	//print_board_marble();

	int vec_idx = 0;

	for (int i = 1; i <= max_num && vec_idx < vec_group.size(); i++)
	{
		num_to_board[i]->marble = vec_group[vec_idx].A;
		i++;
		if (i > max_num)
			break;

		num_to_board[i]->marble = vec_group[vec_idx].B;
		vec_idx++;
	}
}

int solve()
{
	int ret = 0;

	int sub_ret = 0;

	for (int i = 0; i < M; i++)
	{
	//	printf("%s\n", __func__);
		step1_destroy_marble(cmd[i]);
	//			print_board_marble();
		sub_ret = step2_explosion();
	//			print_board_marble();
		step3_mutation();
	//	print_board_marble();

		ret += sub_ret;
	//	printf("%s\n", __func__);
		
	}



	return ret;
}

int main()
{
	/*int T;
	freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	for (int i = 1; i <= T; i++)
	{
		int ret = 0;
		init_tc();
		ret = solve();
		printf("TC %d %d\n\n\n\n", i, ret);
	}*/

	int ret = 0;
	init_tc();
	ret = solve();
	printf("%d\n", ret);
	return 0;
}