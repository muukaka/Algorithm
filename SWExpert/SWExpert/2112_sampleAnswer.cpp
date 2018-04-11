//#include <stdio.h>
//#define A 0
//#define B 1
//#define min(a,b) ((a)>(b)?(b):(a))
//int inject[13];
//bool globalMap[13][20];
//
//bool isPass(bool map[13][20], int d, int w, int k) {
//	for (int j = 0; j < w; j++)
//	{
//		int cnt = 1;
//		int s = inject[0] != -1 ? inject[0] : map[0][j];
//		for (int i = 1; i < d; i++) 
//		{
//			int nowS = inject[i] != -1 ? inject[i] : map[i][j];
//			if (s == nowS)
//			{
//				cnt++;
//				if (cnt == k) 
//					break;
//			}
//			else
//			{
//				cnt = 1;
//				s = nowS;
//			}
//		}
//
//		if (cnt < k)
//			return false;
//	}
//	return true;
//}
//
//bool isPossible(int row, int d, int w, int k, int dep, int depMax, int taget) {
//	if (dep == depMax) {
//		return isPass(globalMap, d, w, k);
//	}
//	else  if (row >= d) {
//		return false;
//	}
//
//	if (isPossible(row + 1, d, w, k, dep, depMax, taget)) {
//		return true;
//	}
//
//	inject[row] = taget;
//	bool result = isPossible(row + 1, d, w, k, dep + 1, depMax, taget);
//	inject[row] = -1;
//
//	return result;
//}
//
//int solve(int d, int w, int k, int l, int r, int target) {
//	int ans = d - 1;
//	if (target == B) {
//		if (isPossible(0, d, w, k, 0, r, target)) {
//			ans = r;
//			r = (l + r) / 2 - 1;
//		}
//		else {
//			return ans;
//		}
//	}
//
//	while (l <= r) {
//		int mid = (l + r) / 2;
//		if (isPossible(0, d, w, k, 0, mid, target)) {
//			if (ans > mid) {
//				ans = mid;
//			}
//			r = mid - 1;
//		}
//		else {
//			l = mid + 1;
//		}
//	}
//
//	return ans;
//}
//
//int main() {
//	int t;
//	scanf("%d", &t);
//
//	for (int tc = 1; tc <= t; tc++) {
//		int d, w, k;
//		scanf("%d %d %d", &d, &w, &k);
//
//		for (int i = 0; i < d; i++) {
//			inject[i] = -1;
//			for (int j = 0; j < w; j++) {
//				scanf("%d", &globalMap[i][j]);
//			}
//		}
//
//
//		int ansA = solve(d, w, k, 0, d - 1, A);
//		int ans = min(ansA, solve(d, w, k, 0, ansA - 1, B));
//
//		printf("#%d %d\n", tc, ans);
//	}
//	return 0;
//}


#include<stdio.h>
int H, W, K, A[13][20], B[13], ans;
void f(int idx, int count) 
{
	int i, j, a, a2, b;
	if (count >= ans) return;
	for (j = 0; j < W; j++)
	{
		a = (B[0] == 2) ? A[0][j] : B[0];
		for (i = b = 1; i < H; i++)
		{
			a2 = ((i<idx && B[i] == 2) || i >= idx) ? A[i][j] : B[i];
			if (a == a2)
			{
				b++;
				if (b >= K)
					break;
			}
			else
				a = a2, b = 1;
		}
		if (b < K) 
			break;
	}
	if (j == W)
	{
		ans = count;
		return;
	}
	else if (idx < H) 
	{
		B[idx] = 2; f(idx + 1, count);
		B[idx] = 0; f(idx + 1, count + 1);
		B[idx] = 1; f(idx + 1, count + 1);
	}
}
int main() {
	int T, t, i, j;
	scanf("%d", &t);
	for (T = 1; T <= t; T++)
	{
		scanf("%d%d%d\n", &H, &W, &K); 
		ans = H;
		
		for (i = 0; i < H; i++) 
			for (j = 0; j < W; j++) 
				scanf("%d", &A[i][j]);
		printf("#%d ", T);
		if (K == 1)
		{
			printf("0\n");
			continue;
		}
		B[0] = 2; f(1, 0);
		B[0] = 0; f(1, 1);
		B[0] = 1; f(1, 1);
		printf("%d\n", ans);
	}
}

