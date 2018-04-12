/*
[�������]
1. �ð����� : �ִ� 50�� �׽�Ʈ ���̽��� ��� ����ϴ� �� C/C++/Java ��� 3��
2. ����Ʈ ī�䰡 ���ִ� ������ �� ���� ���� N�� 4 �̻� 20 ������ �����̴�. (4 �� N �� 20)
3. ����Ʈ ������ ��Ÿ���� ���� 1 �̻� 100 ������ �����̴�.

[�Է�]
�Է��� �� ù �ٿ��� �� �׽�Ʈ ���̽��� ���� T�� �־�����, �� ���� �ٺ��� T���� �׽�Ʈ ���̽��� �־�����.
�� �׽�Ʈ ���̽��� ù ��° �ٿ��� ����Ʈ ī�䰡 ���ִ� ������ �� ���� ���� N�� �־�����.
�� ���� N �ٿ��� N * N ũ���� ����Ʈ ī�信�� �Ȱ� �ִ� ����Ʈ ������ ���� ������ �־�����.

[���]
�׽�Ʈ ���̽� ������ŭ T���� �ٿ� ������ �׽�Ʈ ���̽��� ���� ���� ����Ѵ�.
�� ���� "#t"�� �����ϰ� ������ �ϳ� �� ���� ������ ����Ѵ�. (t�� 1���� �����ϴ� �׽�Ʈ ���̽��� ��ȣ�̴�)
����ؾ� �� ������ ������ ��� �� ����Ʈ�� ���� ���� ���� ���� ����Ʈ �� �̴�.
����, ����Ʈ�� ���� �� ���� ��� ������ -1�̴�.
*/

#include <iostream>

using namespace std;

int N;// 4<= N <= 20
int map[21][21];// ����
int ret;//�ִ�� ���� �ִ� ī�� ����
int visit[101];// ���� ����Ʈ�� ������ 1
int dx[] = { 1, -1, -1, 1};// ��, ��, ��, ��
int dy[] = { 1, 1, -1, -1};// ��, ��, ��, ��

void solve(int i, int j)
{
	// ���� �纯���� ���̴� ���� a, b
	for (int a = 1; a <= N; a++)// �ּ� 1ĭ �̻�
	{
		for (int b = 1; b <= N; b++)// �ּ� 1ĭ �̻�
		{
			if ((j + a >= N) || (j - b < 0) || (i + a + b >= N) || (2 * a + 2 * b < ret))
				continue;
			int y = i;
			int x = j;
			memset(visit, 0, sizeof(visit));
			bool possible = true;
			// 1. ������ �Ʒ� ���� (���� a)
			for (int n = 0; n < a; n++)
			{
				y += dy[0];// i += dy[0];
				x += dx[0];// j += dx[0];
				if (visit[map[y][x]])
				{
					possible = false;
					break;
				}
				else
					visit[map[y][x]] = 1;
			}
			if (!possible) continue;
			// 2. ���� �Ʒ� ���� (���� b)
			for (int n = 0; n < b; n++)
			{
				y += dy[1];
				x += dx[1];
				if (visit[map[y][x]])
				{
					possible = false;
					break;
				}
				else
					visit[map[y][x]] = 1;
			}
			if (!possible) continue;
			// 3. ���� �� ���� (���� a)
			for (int n = 0; n < a; n++)
			{
				y += dy[2];
				x += dx[2];
				if (visit[map[y][x]])
				{
					possible = false;
					break;
				}
				else
					visit[map[y][x]] = 1;
			}
			if (!possible) continue;
			// 4. ������ �� ���� (���� b)
			for (int n = 0; n < b; n++)
			{
				y += dy[3];
				x += dx[3];
				if (visit[map[y][x]])
				{
					possible = false;
					break;
				}
				else
					visit[map[y][x]] = 1;
			}
			if (!possible) continue;
			// �������� ���ƿ� ���, ��� ���� ����
			ret = 2 * (a + b);
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
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		// algor
		ret = -1;// ��ΰ� ���� ��� -1
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				solve(i, j);

		// output
		cout << "#" << t << " " << ret << endl;
	}
	return 0;
}