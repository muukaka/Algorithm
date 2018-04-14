#include <iostream>
#include <string.h>

using namespace std;

int ret;
int N, M;// 지도 세로 가로 //5 ≤ N, M ≤ 50
int R, C;//맨홀 위치 row, col //0 ≤ R ≤ N-1, 0 ≤ C ≤ M-1
int L;//탈출 후 소요 시간 //1 ≤ L ≤ 20
int map[50][50];// 배관 지도
int loc[50][50];// 탈주범이 있을수 있는곳 1
int newloc[50][50];

void mov()
{
	memset(newloc, 0, sizeof(newloc));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (loc[i][j] == 0)
				continue;
			
			newloc[i][j] = 1;
			switch (map[i][j])
			{
			case 1:
				if ((i - 1 >= 0) && (map[i - 1][j] == 1 || map[i - 1][j] == 2 || map[i - 1][j] == 5 || map[i - 1][j] == 6))
					newloc[i - 1][j] = 1;
				if ((i + 1 < N) && (map[i + 1][j] == 1 || map[i + 1][j] == 2 || map[i + 1][j] == 4 || map[i + 1][j] == 7))
					newloc[i + 1][j] = 1;
				if ((j - 1 >= 0) && (map[i][j - 1] == 1 || map[i][j - 1] == 3 || map[i][j - 1] == 4 || map[i][j - 1] == 5))
					newloc[i][j - 1] = 1;
				if ((j + 1 < M) && (map[i][j + 1] == 1 || map[i][j + 1] == 3 || map[i][j + 1] == 6 || map[i][j + 1] == 7))
					newloc[i][j + 1] = 1;
				break;
			case 2:
				if ((i - 1 >= 0) && (map[i - 1][j] == 1 || map[i - 1][j] == 2 || map[i - 1][j] == 5 || map[i - 1][j] == 6))
					newloc[i - 1][j] = 1;
				if ((i + 1 < N) && (map[i + 1][j] == 1 || map[i + 1][j] == 2 || map[i + 1][j] == 4 || map[i + 1][j] == 7))
					newloc[i + 1][j] = 1;
				break;
			case 3:
				if ((j - 1 >= 0) && (map[i][j - 1] == 1 || map[i][j - 1] == 3 || map[i][j - 1] == 4 || map[i][j - 1] == 5))
					newloc[i][j - 1] = 1;
				if ((j + 1 < M) && (map[i][j + 1] == 1 || map[i][j + 1] == 3 || map[i][j + 1] == 6 || map[i][j + 1] == 7))
					newloc[i][j + 1] = 1;
				break;
			case 4:
				if ((i - 1 >= 0) && (map[i - 1][j] == 1 || map[i - 1][j] == 2 || map[i - 1][j] == 5 || map[i - 1][j] == 6))
					newloc[i - 1][j] = 1;
				if ((j + 1 < M) && (map[i][j + 1] == 1 || map[i][j + 1] == 3 || map[i][j + 1] == 6 || map[i][j + 1] == 7))
					newloc[i][j + 1] = 1;
				break;
			case 5:
				if ((i + 1 < N) && (map[i + 1][j] == 1 || map[i + 1][j] == 2 || map[i + 1][j] == 4 || map[i + 1][j] == 7))
					newloc[i + 1][j] = 1;
				if ((j + 1 < M) && (map[i][j + 1] == 1 || map[i][j + 1] == 3 || map[i][j + 1] == 6 || map[i][j + 1] == 7))
					newloc[i][j + 1] = 1;
				break;
			case 6:
				if ((i + 1 < N) && (map[i + 1][j] == 1 || map[i + 1][j] == 2 || map[i + 1][j] == 4 || map[i + 1][j] == 7))
					newloc[i + 1][j] = 1;
				if ((j - 1 >= 0) && (map[i][j - 1] == 1 || map[i][j - 1] == 3 || map[i][j - 1] == 4 || map[i][j - 1] == 5))
					newloc[i][j - 1] = 1;
				break;
			case 7:
				if ((i - 1 >= 0) && (map[i - 1][j] == 1 || map[i - 1][j] == 2 || map[i - 1][j] == 5 || map[i - 1][j] == 6))
					newloc[i - 1][j] = 1;
				if ((j - 1 >= 0) && (map[i][j - 1] == 1 || map[i][j - 1] == 3 || map[i][j - 1] == 4 || map[i][j - 1] == 5))
					newloc[i][j - 1] = 1;
				break;
			default:
				break;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			loc[i][j] = newloc[i][j];
		}
	}
}

void solve()
{
	memset(loc, 0, sizeof(loc));
	loc[R][C] = 1;
	for (int t = 1; t < L; t++)
	{
		mov();
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (loc[i][j] == 1)
				ret++;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		// input
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> map[i][j];
		
		// algo
		ret = 0;
		solve();

		// output
		cout << "#" << t << " " << ret << endl;
	}
	return 0;
}