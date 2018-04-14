#include <iostream>

using namespace std;

int ret;// 결과값 중 최댓값과 최솟값의 차이
int N;
int op[4];// +, -, *, /
int num[12];
int maxi;
int mini;

void solve(int idx, int op0, int op1, int op2, int op3, int sum)
{
	// base : 모든 연산자를 다 사용한 경우
	if (op0 == op[0] && op1 == op[1] && op2 == op[2] && op3 == op[3])
	{
		if (sum < mini) mini = sum;
		if (sum > maxi) maxi = sum;
		return;
	}
	if (idx >= N - 1 || op0 > op[0] || op1 > op[1] || op2 > op[2] || op3 > op[3])
	{
		return;
	}

	solve(idx + 1, op0 + 1, op1, op2, op3, sum + num[idx + 1]);
	solve(idx + 1, op0, op1 + 1, op2, op3, sum - num[idx + 1]);
	solve(idx + 1, op0, op1, op2 + 1, op3, sum * num[idx + 1]);
	solve(idx + 1, op0, op1, op2, op3 + 1, sum / num[idx + 1]);
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
		for (int i = 0; i < 4; i++)
			cin >> op[i];
		for (int i = 0; i < N; i++)
			cin >> num[i];

		// algo
		maxi = -987654321;
		mini = 987654321;
		solve(0, 0,0,0,0, num[0]);
		ret = maxi - mini;

		// output
		cout << "#" << t << " " << ret << endl;
	}

	return 0;
}