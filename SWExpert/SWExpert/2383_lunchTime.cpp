#include <iostream>
#include <algorithm>

using namespace std;

int ret;//�̵��� �Ϸ�Ǵ� �ּ��� �ð��� ���
int N;// �Ѻ��� ����
int P;// ����� ��
int S;// ����� ��
int map[10][10];// ����
int match[10];// �� ����� �̿��� ����� index ����

typedef struct Point {
	int x, y;
} point;

point person[10], stair[2];

// ����� ��ġ�� ����� ��ġ �ľ�
void initialize()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1)
			{
				person[P].y = i;
				person[P].x = j;
				P++;
			}
			else if (map[i][j] > 1)
			{
				stair[S].y = i;
				stair[S].x = j;
				S++;
			}
		}
	}
}

// ��� index�� ��� index ������ ����ź �Ÿ�
int dist(int p_index, int s_index)
{
	int dx = abs(person[p_index].x - stair[s_index].x);
	int dy = abs(person[p_index].y - stair[s_index].y);
	return dx + dy;
}

// ��� �̿��ϴµ� �ɸ��� �ð��� ����ϴ� �Լ�
void update()
{
	int tot_time;// ��� ������� ����� �������µ� �ʿ��� �ּҽð�

	// �� ����� ���� �������̹Ƿ� ������ ���ؼ� ���
	for (int s_index = 0; s_index < S; s_index++)
	{
		point& now_stair = stair[s_index];
		int arrival_time[20] = { 0, };// �ð� t�϶� ��ܿ� �����ϴ� ����� ��
		int current_stair[20] = { 0, };
		for (int p_index = 0; p_index < P; p_index++)
		{
			if (match[p_index] == s_index)
			{
				arrival_time[dist(p_index, s_index) + 1]++;
			}
		}

		int now_min_time = 0;// s_index ����� ��� �������� ���� �ּ� �ð�
		for (int time = 1; time <= 20; time++)
		{
			// time�� ������ ����� �ִٸ�
			while (arrival_time[time] > 0)
			{
				arrival_time[time]--;
				int remain_time = map[now_stair.y][now_stair.x];// �ش� ����� �������µ� �ɸ��� �ð�
				// ��ܿ� ������ �������� ��� 3���� ���ÿ� �������� ���� ���� �� 1ĭ�� ������
				for (int walk_time = time; walk_time < 20; walk_time++)
				{
					if (current_stair[walk_time] < 3)
					{
						current_stair[walk_time]++;
						remain_time--;

						// ����� �� ���������� now_min_time ����
						if (remain_time == 0)
						{
							now_min_time = max(now_min_time, walk_time + 1);
							break;
						}
					}
				}
			}
		}
		tot_time = max(tot_time, now_min_time);
	}
	ret = min(ret, tot_time);
}

void solve(int p_index)
{
	// base : ��� ����� ����� �� ������ ���
	if (p_index == P)
	{
		update();// �ش� ���¿��� �ʿ��� �ð��� ����ϰ� ���� ����
		return;
	}
	// p_index ����� s_index�� ����, ���
	for (int s_index = 0; s_index < S; s_index++)
	{
		match[p_index] = s_index;
		solve(p_index + 1);
	}
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

		// algo
		ret = 987654321;
		initialize();
		solve(0);

		// output
		cout << "#" << t << " " << ret << endl;
	}

	return 0;
}