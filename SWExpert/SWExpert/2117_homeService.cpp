#include <iostream>
//#include <math.h>
#include <algorithm>
using namespace std;

int ret;//손해를 보지 않으면서 홈방범 서비스를 받는 가장 많은 집의 개수
int N, M;
int K;
int map[20][20];

// map[i][j]로 부터 k범위의 가구의 수를 구하는 함수
int range(int ii, int jj, int k)
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (abs(i - ii) + abs(j - jj) < k && map[i][j])
				cnt++;
		}
	}
	return cnt;
}

// 운영 비용 = K * K + (K - 1) * (K - 1)
void solve()
{
	for (int k = N + 1; k > 0; k--)// 큰 범위부터 시작해서 찾고
	{
		int cost = k * k + (k - 1) * (k - 1);
		if (cost < ret)
			return;
		for (int i = 0; i < N; i++)// 중심점 (0,0)에서 시작
		{
			for (int j = 0; j < N; j++)
			{
				int cnt = range(i, j, k);
				if (M * cnt - cost >= 0)// 손해를 보지않는 선, 이익이 0이어도 됨
				{
					ret = max(ret, cnt);
				}
			}
		}
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
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];
		//K = (N + 1) / 2;

		// algo
		ret = -1;
		solve();

		// output
		cout << "#" << t << " " << ret << endl;
	}

	return 0;
}