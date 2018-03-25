#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dfs(int x, int y, int k);

int T, N, K;
int ret = 0;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int map[10][10];
int visit[10][10];

int main()
{
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> N >> K;

		int highest = 0;
		ret = 0;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));

		// 지도 입력 & 최대 높이 확인
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> map[i][j];
				if (map[i][j] > highest)
					highest = map[i][j];
			}
		}

		// DFS
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (map[i][j] == highest)
					ret = max(ret, dfs(i, j, K));
			}
		}

		cout << "#" << t << " " << ret << endl;
	}
	return 0;
}

// 등산로를 만드는 재귀함수
int dfs(int x, int y, int k)// Depth First Search
{
	// base case 1: 범위를 벗어나는 경우
	if (x <= 0 || x > N || y <= 0 || y > N) return 0;
	// base case 2: 이미 방문한 경우
	if (visit[x][y]) return 0;

	visit[x][y] = 1;
	int temp = 1;
	// 상하좌우에 대해 길이 있는지 탐색
	for (int i = 0; i < 4; i++)
	{
		// 먼저, 가려는 곳이 더 낮은 곳인지 확인
		if (map[x + dx[i]][y + dy[i]] < map[x][y])
			temp = max(temp, 1 + dfs(x + dx[i], y + dy[i], k));
		// 같거나 높은 곳이라면, 혹시 k만큼 깍아서 길이 있는지
		else if (map[x + dx[i]][y + dy[i]] - k < map[x][y])
		{
			int prev = map[x + dx[i]][y + dy[i]];
			map[x + dx[i]][y + dy[i]] = map[x][y] - 1;
			temp = max(temp, 1 + dfs(x + dx[i], y + dy[i], 0));
			map[x + dx[i]][y + dy[i]] = prev;
		}
	}
	visit[x][y] = 0;
	return temp;
}