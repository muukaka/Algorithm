#include <iostream>
#include <string.h>

using namespace std;

int ret;
int N, M, K;// 5 ≤ N ≤ 100, 1 ≤ M ≤ 1,000, 5 ≤ K ≤ 1,000
//상하좌우 4방향 중 한 방향을 가진다. (상: 1, 하: 2, 좌: 3, 우: 4)
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, -1, 1, 0, 0 };
int maxcnt[100][100] = { 0 };
int map[100][100] = { 0 };
int dmap[100][100] = { 0 };

struct Micro {
	int x;
	int y;
	int cnt;
	int dir;
};

Micro micro[1000];

void mov()
{
	// 미생물 이동
	for (int k = 0; k < K; k++)
	{
		int d = micro[k].dir;
		micro[k].x += dx[d];
		micro[k].y += dy[d];
		// 경계에 들어간 경우
		if (micro[k].x == 0 || micro[k].x == N - 1 || micro[k].y == 0 || micro[k].y == N - 1)
		{
			micro[k].cnt = micro[k].cnt / 2;
			if (d == 1 || d == 3) micro[k].dir++;
			if (d == 2 || d == 4) micro[k].dir--;
		}
	}

	memset(maxcnt, 0, sizeof(maxcnt));
	memset(map, 0, sizeof(map));
	memset(dmap, 0, sizeof(dmap));
	// map[y][x]에 각 칸의 max count가 몇인지 저장
	for (int k = 0; k < K; k++)
	{
		int xx = micro[k].x;
		int yy = micro[k].y;
		int cnt = micro[k].cnt;
		map[yy][xx] += cnt;
		if (maxcnt[yy][xx] == 0)
		{
			maxcnt[yy][xx] = cnt;
			dmap[yy][xx] = micro[k].dir;
		}
		else if (maxcnt[yy][xx] < cnt)
		{
			maxcnt[yy][xx] = cnt;
			dmap[yy][xx] = micro[k].dir;
		}
		else if (maxcnt[yy][xx] > cnt)
		{
			micro[k].cnt = 0;// 흡수됨
		}
	}

	for (int k = 0; k < K; k++)
	{
		int xx = micro[k].x;
		int yy = micro[k].y;
		micro[k].cnt = map[yy][xx];
		micro[k].dir = dmap[yy][xx];
	}

	// maxcount 미생물에게 흡수
	//for (int i = 0; i < K; i++)
	//{
	//	for (int j = i + 1; j < K; j++)
	//	{
	//		int xi = micro[i].x;
	//		int yi = micro[i].y;
	//		if (xi == micro[j].x && yi == micro[j].y)
	//		{
	//			if (maxcnt[yi][xi] == micro[i].cnt)
	//			{
	//				micro[i].cnt += micro[j].cnt;
	//				micro[j].cnt = 0;
	//			}
	//			else if (maxcnt[yi][xi] == micro[j].cnt)
	//			{
	//				micro[j].cnt += micro[i].cnt;
	//				micro[i].cnt = 0;
	//			}
	//			else// 둘다 max가 아닌경우
	//			{
	//				micro[j].cnt += micro[i].cnt;
	//				micro[i].cnt = 0;
	//			}
	//		}
	//	}
	//}
}

void solve()
{
	for (int m = 0; m < M; m++)
	{
		mov();
	}

	// 미생물 전체 수
	for (int k = 0; k < K; k++)
	{
		ret += micro[k].cnt;
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		// input
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++)
		{
			cin >> micro[i].y >> micro[i].x;
			cin >> micro[i].cnt >> micro[i].dir;
		}

		// algo
		ret = 0;
		solve();

		// output
		cout << "#" << t << " " << ret << endl;
	}
	return 0;
}