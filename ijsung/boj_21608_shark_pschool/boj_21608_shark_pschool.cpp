#pragma warning (disable:4996)

#include <iostream>
#include <math.h>
#include <queue>
#include <string.h>
using namespace std;
#define MAX_N 20
#define MAX_STUDENT MAX_N*MAX_N

int N;

typedef struct _coord {
	int r, c;
} coord;

struct _student {
	int name;
	struct _student* love[4];

	coord loc;
	bool have_seat;
} student[MAX_STUDENT + 1];

int student_order[MAX_STUDENT + 1];

struct _seat {
	coord loc;
	struct _student *st;
} seat[(MAX_N + 2)][(MAX_N + 2)];

typedef struct _cand_seat {
	coord loc;
	_student *st;
} cand_seat;

void print_seat()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			printf("[%3d] ", seat[i][j].st ? seat[i][j].st->name : -1);
		printf("\n");
	}
	printf("\n\n");
}

inline bool chk_near(coord a, coord b)
{
	return((abs(a.r - b.r) + abs(a.c - b.c)) == 1);
}

void init_tc()
{
	memset(student, 0x00, sizeof(student));
	memset(seat, 0x00, sizeof(seat));
	memset(student_order, 0x00, sizeof(student_order));

	scanf("%d", &N);

	int num, lov1, lov2, lov3, lov4;

	for (int i = 1; i <= N * N; i++)
	{
		scanf("%d %d %d %d %d", &num, &lov1, &lov2, &lov3, &lov4);
		student_order[i] = num;
		student[num].name = num;
		student[num].love[0] = &student[lov1];
		student[num].love[1] = &student[lov2];
		student[num].love[2] = &student[lov3];
		student[num].love[3] = &student[lov4];
	}

	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= N + 1; j++)
		{
			if (j == 0 || i == 0 || j == N + 1 || i == N + 1)
			{
				seat[i][j].loc = { -1,-1 };
				seat[i][j].st = NULL;
			}
			else
			{
				seat[i][j].loc = { i,j };
				seat[i][j].st = NULL;
			}
		}
	}
}

int cnt_lover(struct _student *p_st)
{
	int cnt = 0;
	int r = p_st->loc.r, c = p_st->loc.c;
	int l0 = p_st->love[0]->name;
	int l1 = p_st->love[1]->name;
	int l2 = p_st->love[2]->name;
	int l3 = p_st->love[3]->name;

	if (seat[r - 1][c].st)
	{
		if (seat[r - 1][c].st->name == l0 ||
			seat[r - 1][c].st->name == l1 ||
			seat[r - 1][c].st->name == l2 ||
			seat[r - 1][c].st->name == l3)
			cnt++;
	}

	if (seat[r][c - 1].st)
	{
		if (seat[r][c - 1].st->name == l0 ||
			seat[r][c - 1].st->name == l1 ||
			seat[r][c - 1].st->name == l2 ||
			seat[r][c - 1].st->name == l3)
			cnt++;
	}

	if (seat[r][c + 1].st)
	{
		if (seat[r][c + 1].st->name == l0 ||
			seat[r][c + 1].st->name == l1 ||
			seat[r][c + 1].st->name == l2 ||
			seat[r][c + 1].st->name == l3)
			cnt++;
	}

	if (seat[r + 1][c].st)
	{
		if (seat[r + 1][c].st->name == l0 ||
			seat[r + 1][c].st->name == l1 ||
			seat[r + 1][c].st->name == l2 ||
			seat[r + 1][c].st->name == l3)
			cnt++;
	}

	return cnt;
}

int cnt_lover(struct _student *p_st, int r, int c)
{
	int cnt = 0;
	int l0 = p_st->love[0]->name;
	int l1 = p_st->love[1]->name;
	int l2 = p_st->love[2]->name;
	int l3 = p_st->love[3]->name;

	if (seat[r - 1][c].st)
	{
		if (seat[r - 1][c].st->name == l0 ||
			seat[r - 1][c].st->name == l1 ||
			seat[r - 1][c].st->name == l2 ||
			seat[r - 1][c].st->name == l3)
			cnt++;
	}

	if (seat[r][c - 1].st)
	{
		if (seat[r][c - 1].st->name == l0 ||
			seat[r][c - 1].st->name == l1 ||
			seat[r][c - 1].st->name == l2 ||
			seat[r][c - 1].st->name == l3)
			cnt++;
	}

	if (seat[r][c + 1].st)
	{
		if (seat[r][c + 1].st->name == l0 ||
			seat[r][c + 1].st->name == l1 ||
			seat[r][c + 1].st->name == l2 ||
			seat[r][c + 1].st->name == l3)
			cnt++;
	}

	if (seat[r + 1][c].st)
	{
		if (seat[r + 1][c].st->name == l0 ||
			seat[r + 1][c].st->name == l1 ||
			seat[r + 1][c].st->name == l2 ||
			seat[r + 1][c].st->name == l3)
			cnt++;
	}

	return cnt;
}

inline bool chk_edge(int r, int c)
{
	if (r == 0 || r == N + 1 || c == 0 || c == N + 1)
		return true;
	else return false;
}

int cnt_empty(coord co)
{
	int ret = 0;

	if (seat[co.r - 1][co.c].st == NULL &&
		chk_edge(co.r - 1, co.c) == false)
		ret++;

	if (seat[co.r][co.c - 1].st == NULL &&
		chk_edge(co.r, co.c - 1) == false)
		ret++;

	if (seat[co.r][co.c + 1].st == NULL &&
		chk_edge(co.r, co.c + 1) == false)
		ret++;

	if (seat[co.r + 1][co.c].st == NULL &&
		chk_edge(co.r + 1, co.c) == false)
		ret++;

	return ret;
}

struct comp
{
public:
	bool operator() (cand_seat a, cand_seat b)
	{
		int a_lover_cnt;
		int b_lover_cnt;
		int a_empty;
		int b_empty;

		a_lover_cnt = cnt_lover(a.st, a.loc.r, a.loc.c);
		b_lover_cnt = cnt_lover(b.st, b.loc.r, b.loc.c);
		//1차 : 좋아하는 학생수 비교
		if (a_lover_cnt < b_lover_cnt)
			return true;
		else if (a_lover_cnt > b_lover_cnt)
			return false;

		//2차 : 빈자리 비교
		a_empty = cnt_empty(a.loc);
		b_empty = cnt_empty(b.loc);

		if (a_empty < b_empty)
			return true;
		else if (a_empty > b_empty)
			return false;

		//3차 : r비교
		if (a.loc.r > b.loc.r)
			return true;
		else if (a.loc.r < b.loc.r)
			return false;
		else
		{
			if (a.loc.c > b.loc.c)
				return true;
			else
				return false;
		}
	}
};

coord best_seat(struct _student *pst)
{
	coord ret;
	priority_queue<cand_seat, vector<cand_seat>, comp> pq;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (!seat[i][j].st)
			{
				cand_seat cand = { {i,j}, pst };
				pq.push(cand);
			}
		}
	}

	ret = pq.top().loc;

	return ret;
}

void take_seat()
{
	for (int i = 1; i <= N * N; i++)
	{
		coord co;
		co = best_seat(&student[student_order[i]]);
		seat[co.r][co.c].st = &student[student_order[i]];

		student[student_order[i]].loc = co;
		student[student_order[i]].have_seat = true;
	}
}

int calc_satisfaction()
{
	int satis = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int lover = cnt_lover(seat[i][j].st);
			switch (lover)
			{
			case 0:
				break;
			case 1:
				satis += 1;
				break;
			case 2:
				satis += 10;
				break;
			case 3:
				satis += 100;
				break;
			case 4:
				satis += 1000;
				break;
			default:
				printf("ERROR[%d][%d]\n", i, j);
			}
		}
	}

	return satis;
}

int solve()
{
	take_seat();
	return calc_satisfaction();
}

int main()
{
	int tc = 0;
	/*freopen("input.txt", "r", stdin);
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++)
	{
		int ret = 0;
		init_tc();
		ret = solve();
		printf("%d %d\n", t, ret);
	}*/

	init_tc();
	printf("%d\n", solve());
}