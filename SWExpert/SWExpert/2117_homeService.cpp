#include <iostream>
//#include <math.h>
#include <algorithm>
using namespace std;

int ret;//���ظ� ���� �����鼭 Ȩ��� ���񽺸� �޴� ���� ���� ���� ����
int N, M;
int K;
int map[20][20];

// map[i][j]�� ���� k������ ������ ���� ���ϴ� �Լ�
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

// � ��� = K * K + (K - 1) * (K - 1)
void solve()
{
	for (int k = N + 1; k > 0; k--)// ū �������� �����ؼ� ã��
	{
		int cost = k * k + (k - 1) * (k - 1);
		if (cost < ret)
			return;
		for (int i = 0; i < N; i++)// �߽��� (0,0)���� ����
		{
			for (int j = 0; j < N; j++)
			{
				int cnt = range(i, j, k);
				if (M * cnt - cost >= 0)// ���ظ� �����ʴ� ��, ������ 0�̾ ��
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