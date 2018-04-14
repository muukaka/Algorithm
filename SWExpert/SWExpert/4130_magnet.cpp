#include <iostream>

using namespace std;

int ret;
int K;//1 ≤ K ≤ 20
int map[4][8];
int mov[20][2];// 번호, 방향 //시계방향 1, 반시계방향 -1 
int score[4] = { 1, 2, 4, 8 };
int pointing[4] = { 0,0,0,0 };

void rotate(int idx, int dir)
{
	if (dir == 1)
	{
		pointing[idx] = (pointing[idx] + 1) % 8;
	}
	else if (dir == -1)
	{
		pointing[idx] = (pointing[idx] - 1) % 8;
	}
}

void rotate_left(int idx, int dir)
{
	// base : 자석 범위 확인
	if (idx < 0)
		return;
	if (map[idx][(pointing[idx] + 2) % 8] != map[idx + 1][(pointing[idx] + 6) % 8])
	{
		rotate_left(idx - 1, dir * -1);
		rotate(idx, dir);
	}
}
void rotate_right(int idx, int dir)
{
	// base : 자석 범위 확인
	if (idx >= 4)
		return;
	if (map[idx - 1][(pointing[idx] + 2) % 8] != map[idx][(pointing[idx] + 6) % 8])
	{
		rotate_right(idx + 1, dir * -1);
		rotate(idx, dir);
	}
}

void solve()
{
	for (int k = 0; k < K; k++)
	{
		int idx = mov[k][0] - 1;
		int dir = mov[k][1];
		rotate_left(idx - 1, dir * -1);
		rotate_right(idx + 1, dir * -1);
		rotate(idx, dir);
	}

	for (int i = 0; i < 4; i++)
	{
		if (map[i][pointing[i]] == 1)
			ret += score[i];
	}
	return;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		// input
		cin >> K;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 8; j++)
				cin >> map[i][j];
		for (int i = 0; i < K; i++)
			cin >> mov[i][0] >> mov[i][1];
		
		// algo
		ret = 0;
		solve();

		// output
		cout << "#" << t << " " << ret << endl;
	}
	return 0;
}