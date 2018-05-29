#include <iostream>
#include <string>

using namespace std;

int ret;
int K;
int map[4][8];//4�� �ڼ�, 8�� ���
int top[4];// �ڼ��� 12�� ��ġ ����
int com[21][2];// �ڼ���ȣ, ����:: 1:�ð�, -1:�ݽð�
int score[] = {1, 2, 4, 8};
int rot[4];

void right(int n, int d)
{
	if (n > 3)
		return;

	if (map[n - 1][(top[n - 1] + 2) % 8] != map[n][(top[n] + 6) % 8])
	{
		rot[n] = -1 * d;
		right(n + 1, -1 * d);
	}
}

void left(int n, int d)
{
	if (n < 0)
		return;

	if (map[n][(top[n] + 2) % 8] != map[n + 1][(top[n + 1] + 6) % 8])
	{
		rot[n] = -1 * d;
		left(n - 1, -1 * d);
	}
}

void solve()
{
	// K�� ȸ���� ���� ���
	for (int k = 0; k < K; k++)
	{
		memset(rot, 0, sizeof(rot));
		int n = com[k][0] - 1;
		int d = com[k][1];
		rot[n] = d;
		right(n + 1, d);
		left(n - 1, d);

		// ���� ��� ��� ȸ��
		for (int i = 0; i < 4; i++)
		{
			if (rot[i] > 0)
			{
				top[i] = (top[i] - 1) % 8;
			}
			else if (rot[i] < 0)
			{
				top[i] = (top[i] + 1) % 8;
			}
		}
	}

}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		// initial
		memset(map, 0, sizeof(map));
		memset(top, 0, sizeof(top));
		memset(com, 0, sizeof(com));
		// input
		cin >> K;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 8; j++)
				cin >> map[i][j];

		for (int i = 0; i < K; i++)
			cin >> com[i][0] >> com[i][1];

		// algo
		ret = 0;
		solve();

		// output
		for (int i = 0; i < 4; i++)
			ret += score[i] * map[i][top[i]];
		cout << "#" << t << " " << ret << endl;
	}

	return 0;
}