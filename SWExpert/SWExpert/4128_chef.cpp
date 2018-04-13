#include <iostream>
#include <algorithm>
#include <string.h>//memset()

using namespace std;

int ret;// ���� �� ���̰� �ּҰ� �ɶ��� ��
int N;// 4<=N<=16
int S[16][16];// ���� �ó���
int use[16];//�ִ� 16���� ����� A�� ������� ��ῡ 1, B��� 0

// ������ ������ �������� ���� ��쿡 ��ͷ� Ǯ�� ����!
void solve(int cnt, int n)// n = N/2
{
	// base : ��ᰡ ������ ��� ���
	if (cnt >= N) return;
	// base : A�� ��� ���� ������ ���
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