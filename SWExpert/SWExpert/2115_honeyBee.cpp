#include <iostream>
#include <string.h>

using namespace std;

int ret;//두 일꾼이 꿀을 채취하여 얻을 수 있는 최대 수익
int N, M, C;// 3 ≤ N ≤ 10, 1 ≤ M ≤ 5, 10 ≤ C ≤ 30
int map[10][10];// 꿀 지도
int rev[10][10];// 수익

// (y,x)를 가장 왼쪽 좌표로 두는 벌통에서 최대 수익을 계산하는 재귀 함수
int getPSum(int m, int y, int x, int sum, int psum)
{
	if (m >= M) 
		return psum;
	int nextSum;// 탐색한 경우의 수익을 저장
	int max = 0;// 최대 수익을 저장하는 함수

	for (int i = m; i < M; i++)
	{
		// C값을 넘지 않는 범위라면 (y, x+i) 위치의 용기 채취 가능
		if (sum + map[y][x+i] <= C)
		{
			// (y, x+i) 위치의 용기를 채취할 때 수익을 탐색
			nextSum = getPSum(i + 1, y, x, sum + map[y][x + i], psum + map[y][x + i] * map[y][x + i]);
			// 최대 수익 갱신 가능한 경우 갱신
			if (max < nextSum) max = nextSum;
		}
		// (y,x+i) 위치의 용기를 채취하지 않는 경우도 탐색
		nextSum = getPSum(i + 1, y, x, sum, psum);
		// 최대 수익 갱신 가능한 경우 갱신
		if (max < nextSum) max = nextSum;
	}
	return max;
}

// (y,x)를 가장 왼쪽에 두는 벌통과 동시에 선택가능한 벌통 중 최대 수익을 구하는 함수
int getMaxPair(int y, int x)
{
	int maxR = 0;
	// 일단 같은 행에서 가로로 동시에 선택가능한 벌통 중 최대 수익을 찾는다.
	for (int j = x + M; j <= N - M; j++)
	{
		if (maxR < rev[y][j])
			maxR = rev[y][j];
	}
	// 다른 행에 있는 벌통은 무조건 선택 가능, 모든 수익 확인
	for (int i = y + 1; i < N; i++)
	{
		for (int j = 0; j <= N - M; j++)
		{
			if (maxR < rev[i][j])
				maxR = rev[i][j];
		}
	}
	return maxR;
}

// map에서 벌통의 위치를 지정하는 함수
// 가로로 연속되도록 M개의 벌통을 선택
void solve()
{
	int i, j;// i: 세로순회, j: 가로순회
	int sum;//동시에 선택가능한 두 벌통의 수익 합을 저장

	for (int i = 0; i < N; i++)
	{
		//실제 선택할 수 있는 경우의 수는 N-M+1 가지
		for (int j = 0; j <= N - M; j++)
			rev[i][j] = getPSum(0, i, j, 0, 0);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= N - M; j++)
		{
			// (i,j) 벌통과 동시에 선택가능한 벌통 중 최대 수익을 내는 벌통의 수익
			sum = rev[i][j] + getMaxPair(i, j);
			// 최대 수익이 갱신되는지 확인
			if (ret < sum) ret = sum;
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
		cin >> N >> M >> C;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		// algo
		ret = 0;
		solve();

		// output
		cout << "#" << t << " " << ret << endl;
	}

	return 0;
}