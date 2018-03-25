#include <stdio.h>
int T, N, K, map[10][10], maxhigh, max, xx[4] = { 0,0,1,-1 }, yy[4] = { 1,-1,0,0 }, test_case, chk[10][10];
void dfs(int x, int y, int lastk, int L) {
	int i, t;
	if (x>N || y>N || x <= 0 || y <= 0) return;
	chk[x][y] = 1;
	if (L>max) max = L;
	for (i = 0; i<4; i++) {
		if (chk[x + xx[i]][y + yy[i]]) continue;
		if (map[x + xx[i]][y + yy[i]]<map[x][y]) dfs(x + xx[i], y + yy[i], lastk, L + 1);
		else if (map[x + xx[i]][y + yy[i]] - lastk<map[x][y]) {
			t = map[x + xx[i]][y + yy[i]];
			map[x + xx[i]][y + yy[i]] = map[x][y] - 1;
			dfs(x + xx[i], y + yy[i], 0, L + 1);
			map[x + xx[i]][y + yy[i]] = t;
		}
	}
	chk[x][y] = 0;
}
int main() {
	int i, j;
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		maxhigh = max = 0;
		scanf("%d%d", &N, &K);
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				scanf("%d", &map[i][j]);
				if (maxhigh<map[i][j]) maxhigh = map[i][j];
			}
		}
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (maxhigh == map[i][j]) dfs(i, j, K, 1);
			}
		}
		printf("#%d %d\n", test_case, max);
	}
}
//
//#include <stdio.h>
//
//int n, k, ax, ay, res;
//int map[9][9];
//unsigned short visited[9];
//int dx[] = { 1,-1,0,0 };
//int dy[] = { 0,0,1,-1 };
//
//void dfs(int x, int y, int k, bool flag, int pre, int cnt) {
//	visited[x] = visited[x] | (1 << y);
//
//	if (res < cnt) {
//		res = cnt;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		ax = x + dx[i];
//		ay = y + dy[i];
//		if (ax > 0 && ay > 0 && ax <= n && ay <= n) {
//			if (!flag) {
//				//깍지 않았을때
//				if (map[x][y] > map[ax][ay] && !(visited[ax] & (1 << ay))) {
//					dfs(ax, ay, k, flag, map[x][y], cnt + 1);
//				}
//				else {
//					if (map[x][y] > map[ax][ay] - k && !(visited[ax] & (1 << ay))) {
//						dfs(ax, ay, k, true, map[x][y] - 1, cnt + 1);
//					}
//				}
//			}
//			else {
//				//깍기 했을때
//				if (pre > map[ax][ay] && !(visited[ax] & (1 << ay))) {
//					dfs(ax, ay, k, flag, map[ax][ay], cnt + 1);
//				}
//			}
//		}
//	}
//	visited[x] = visited[x] & ~(1 << y);
//}
//
//int main() {
//	int t;
//	scanf("%d", &t);
//	for (int tc = 1; tc <= t; tc++) {
//		scanf("%d %d", &n, &k);
//
//		res = 0;
//		int start = 0;
//
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				scanf("%d", &map[i][j]);
//				if (start < map[i][j]) start = map[i][j];
//			}
//		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				if (map[i][j] == start) {
//					dfs(i, j, k, false, 20, 1);
//				}
//			}
//		}
//
//		printf("#%d %d\n", tc, res);
//	}
//}