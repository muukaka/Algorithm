#include <iostream>
#include <string.h>

using namespace std;

int ret;//�� �ϲ��� ���� ä���Ͽ� ���� �� �ִ� �ִ� ����
int N, M, C;// 3 �� N �� 10, 1 �� M �� 5, 10 �� C �� 30
int map[10][10];// �� ����
int rev[10][10];// ����

// (y,x)�� ���� ���� ��ǥ�� �δ� ���뿡�� �ִ� ������ ����ϴ� ��� �Լ�
int getPSum(int m, int y, int x, int sum, int psum)
{
	if (m >= M) 
		return psum;
	int nextSum;// Ž���� ����� ������ ����
	int max = 0;// �ִ� ������ �����ϴ� �Լ�

	for (int i = m; i < M; i++)
	{
		// C���� ���� �ʴ� ������� (y, x+i) ��ġ�� ��� ä�� ����
		if (sum + map[y][x+i] <= C)
		{
			// (y, x+i) ��ġ�� ��⸦ ä���� �� ������ Ž��
			nextSum = getPSum(i + 1, y, x, sum + map[y][x + i], psum + map[y][x + i] * map[y][x + i]);
			// �ִ� ���� ���� ������ ��� ����
			if (max < nextSum) max = nextSum;
		}
		// (y,x+i) ��ġ�� ��⸦ ä������ �ʴ� ��쵵 Ž��
		nextSum = getPSum(i + 1, y, x, sum, psum);
		// �ִ� ���� ���� ������ ��� ����
		if (max < nextSum) max = nextSum;
	}
	return max;
}

// (y,x)�� ���� ���ʿ� �δ� ����� ���ÿ� ���ð����� ���� �� �ִ� ������ ���ϴ� �Լ�
int getMaxPair(int y, int x)
{
	int maxR = 0;
	// �ϴ� ���� �࿡�� ���η� ���ÿ� ���ð����� ���� �� �ִ� ������ ã�´�.
	for (int j = x + M; j <= N - M; j++)
	{
		if (maxR < rev[y][j])
			maxR = rev[y][j];
	}
	// �ٸ� �࿡ �ִ� ������ ������ ���� ����, ��� ���� Ȯ��
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

// map���� ������ ��ġ�� �����ϴ� �Լ�
// ���η� ���ӵǵ��� M���� ������ ����
void solve()
{
	int i, j;// i: ���μ�ȸ, j: ���μ�ȸ
	int sum;//���ÿ� ���ð����� �� ������ ���� ���� ����

	for (int i = 0; i < N; i++)
	{
		//���� ������ �� �ִ� ����� ���� N-M+1 ����
		for (int j = 0; j <= N - M; j++)
			rev[i][j] = getPSum(0, i, j, 0, 0);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= N - M; j++)
		{
			// (i,j) ����� ���ÿ� ���ð����� ���� �� �ִ� ������ ���� ������ ����
			sum = rev[i][j] + getMaxPair(i, j);
			// �ִ� ������ ���ŵǴ��� Ȯ��
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