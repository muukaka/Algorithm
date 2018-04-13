#include <iostream>
#include <algorithm>
#include <string.h>//memset()

using namespace std;

int ret;// 음식 맛 차이가 최소가 될때의 값
int N;// 4<=N<=16
int S[16][16];// 맛의 시너지
int use[16];//최대 16가지 재료중 A가 사용중인 재료에 1, B재료 0

// 조합의 갯수가 일정하지 않은 경우에 재귀로 풀면 좋음!
void solve(int cnt, int n)// n = N/2
{
	// base : 재료가 범위를 벗어난 경우
	if (cnt >= N) return;
	// base : A가 재료 반을 선택한 경우
	if (n == 0)
	{
		int A = 0, B = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i == j) continue;
				if (use[i] && use[j]) A += S[i][j];
				if (!use[i] && !use[j]) B += S[i][j];
			}
		}
		ret = min(ret, abs(A - B));
		return;
	}
	use[cnt] = 1;
	solve(cnt + 1, n - 1);
	use[cnt] = 0;
	solve(cnt + 1, n);
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		// input
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> S[i][j];

		// algo
		ret = 987654321;
		memset(use, 0, sizeof(use));
		solve(0, N / 2);

		// output
		cout << "#" << t << " " << ret << endl;
	}

	return 0;
}