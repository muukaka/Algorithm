#include <iostream>
#include <algorithm>

using namespace std;

int ret;//이동이 완료되는 최소의 시간을 출력
int N;// 한변의 길이
int P;// 사람의 수
int S;// 계단의 수
int map[10][10];// 지도
int match[10];// 각 사람이 이용할 계단의 index 저장

typedef struct Point {
	int x, y;
} point;

point person[10], stair[2];

// 사람의 위치와 계단의 위치 파악
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

// 사람 index와 계단 index 사이의 맨하탄 거리
int dist(int p_index, int s_index)
{
	int dx = abs(person[p_index].x - stair[s_index].x);
	int dy = abs(person[p_index].y - stair[s_index].y);
	return dx + dy;
}

// 계단 이용하는데 걸리는 시간을 계산하는 함수
void update()
{
	int tot_time;// 모든 사람들이 계단을 내려가는데 필요한 최소시간

	// 두 계단은 서로 독립적이므로 각각에 대해서 계산
	for (int s_index = 0; s_index < S; s_index++)
	{
		point& now_stair = stair[s_index];
		int arrival_time[20] = { 0, };// 시간 t일때 계단에 도착하는 사람의 수
		int current_stair[20] = { 0, };
		for (int p_index = 0; p_index < P; p_index++)
		{
			if (match[p_index] == s_index)
			{
				arrival_time[dist(p_index, s_index) + 1]++;
			}
		}

		int now_min_time = 0;// s_index 계단을 모두 내려가기 위한 최소 시간
		for (int time = 1; time <= 20; time++)
		{
			// time에 도착한 사람이 있다면
			while (arrival_time[time] > 0)
			{
				arrival_time[time]--;
				int remain_time = map[now_stair.y][now_stair.x];// 해당 계단을 내려가는데 걸리는 시간
				// 계단에 도착한 시점부터 사람 3명이 동시에 내려가고 있지 않을 때 1칸씩 밑으로
				for (int walk_time = time; walk_time < 20; walk_time++)
				{
					if (current_stair[walk_time] < 3)
					{
						current_stair[walk_time]++;
						remain_time--;

						// 계단을 다 내려갔으면 now_min_time 갱신
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
	// base : 모든 사람이 계단을 다 정했을 경우
	if (p_index == P)
	{
		update();// 해당 상태에서 필요한 시간을 계산하고 정답 갱신
		return;
	}
	// p_index 사람이 s_index를 선택, 재귀
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