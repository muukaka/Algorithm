/*
[제약사항]
1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는 데 C/C++/Java 모두 3초
2. 디저트 카페가 모여있는 지역의 한 변의 길이 N은 4 이상 20 이하의 정수이다. (4 ≤ N ≤ 20)
3. 디저트 종류를 나타나는 수는 1 이상 100 이하의 정수이다.

[입력]
입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T가 주어지고, 그 다음 줄부터 T개의 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 디저트 카페가 모여있는 지역의 한 변의 길이 N이 주어진다.
그 다음 N 줄에는 N * N 크기의 디저트 카페에서 팔고 있는 디저트 종류에 대한 정보가 주어진다.

[출력]
테스트 케이스 개수만큼 T개의 줄에 각각의 테스트 케이스에 대한 답을 출력한다.
각 줄은 "#t"로 시작하고 공백을 하나 둔 다음 정답을 출력한다. (t는 1부터 시작하는 테스트 케이스의 번호이다)
출력해야 할 정답은 가능한 경우 중 디저트를 가장 많이 먹을 때의 디저트 수 이다.
만약, 디저트를 먹을 수 없는 경우 정답은 -1이다.
*/

#include <iostream>

using namespace std;

int N;// 4<= N <= 20
int map[21][21];// 지도
int ret;//최대로 갈수 있는 카페 갯수
int visit[101];// 먹은 디저트의 종류에 1
int dx[] = { 1, -1, -1, 1};// 오, 왼, 왼, 오
int dy[] = { 1, 1, -1, -1};// 하, 하, 상, 상

void solve(int i, int j)
{
	// 평행 사변형의 길이는 각각 a, b
	for (int a = 1; a <= N; a++)// 최소 1칸 이상
	{
		for (int b = 1; b <= N; b++)// 최소 1칸 이상
		{
			if ((j + a >= N) || (j - b < 0) || (i + a + b >= N) || (2 * a + 2 * b < ret))
				continue;
			int y = i;
			int x = j;
			memset(visit, 0, sizeof(visit));
			bool possible = true;
			// 1. 오른쪽 아래 방향 (길이 a)
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
			// 2. 왼쪽 아래 방향 (길이 b)
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
			// 3. 왼쪽 위 방향 (길이 a)
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
			// 4. 오른쪽 위 방향 (길이 b)
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
			// 원점까지 돌아온 경우, 경로 길이 저장
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
		ret = -1;// 경로가 없을 경우 -1
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				solve(i, j);

		// output
		cout << "#" << t << " " << ret << endl;
	}
	return 0;
}