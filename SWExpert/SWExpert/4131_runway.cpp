#include <iostream>

using namespace std;

int ret;//활주로를 건설할 수 있는 경우의 수
int N, X;// 6<=N<=20, 2<=X<=4
int map[20][20];
int slide[20][20];

void solve()
{
	// 가로 활주로 확인
	for (int i = 0; i < N; i++)
	{
		bool possible = true;
		for (int j = 0; j < N - 1; j++)
		{
			if (map[i][j] == map[i][j + 1])
				continue;
			else// map[i][j] != map[i][j+1]
			{
				if (abs(map[i][j] - map[i][j + 1]) > 1)
					possible = false;
				else if (map[i][j] > map[i][j+1])
				{
					for (int k = 1; k < X; k++)
					{
						if ((j + 1 + k) > N)
						{
							possible = false;
							continue;
						}
						if (map[i][j + k] != map[i][j + k + 1])
							possible = false;
					}
				}
				else// (map[i][j] < map[i][j+1])
				{
					for (int k = 1; k < X; k++)
					{
						if ((j - k - 1) < 0)
						{
							possible = false;
							continue;
						}
						if (map[i][j - k] != map[i][j - k - 1])
							possible = false;
					}
				}
			}
		}
		if (possible)
			ret++;
	}

	// 세로 활주로 확인
	for (int j = 0; j < N; j++)
	{
		bool possible = true;
		for (int i = 0; i < N - 1; i++)
		{
			if (map[i][j] == map[i + 1][j])
				continue;
			else// map[i][j] != map[i][j+1]
			{
				if (abs(map[i][j] - map[i + 1][j]) > 1)
					possible = false;
				else if (map[i][j] > map[i + 1][j])
				{
					for (int k = 1; k < X; k++)
					{
						if ((i + 1 + k) > N)
						{
							possible = false;
							continue;
						}
						if (map[i + k][j] != map[i + k + 1][j])
							possible = false;
					}
				}
				else// (map[i][j] < map[i][j+1])
				{
					for (int k = 1; k < X; k++)
					{
						if ((i - k - 1) < 0)
						{
							possible = false;
							continue;
						}
						if (map[i - k][j] != map[i - k - 1][j])
							possible = false;
					}
				}
			}
		}
		if (possible)
			ret++;
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
		cin >> N >> X;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		// algo
		ret = 0;//경우의수
		solve();

		//output
		cout << "#" << t << " " << ret << endl;
	}

	return 0;
}