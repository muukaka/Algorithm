// Dynamic Programming(?), path 저장?
// 삼각형 위의 최대경로(난이도:하)
// 배열 참조 전달 확인!

#include <iostream>
#include <vector>
#include <algorithm>// max()
#include <stack>

using namespace std;

/*
Time Complexity : O()
Space Complexity : O()
*/

int N;// 알바 갯수, 3 <= N <= 500
int M;// 알바 시작날, 0 <= M <= 200
int D;// 알바 기간, 0 <= D <= 100
int I;// 보수, 0 <= I <= 100
int s[501][3];//알바 스케줄, M D I
//int chck[501] = { 0, };// 선택한 알바는 1을 표시, 출력을 위해 사용
int day[301] = { 0, };// 알바하는 날짜, 0 ~ 300
int ret;
vector<int> alist;


// 점화식 : alba(n) = max{ alba(n + 1), alba(n + 1) + s[n][2] }
// 복잡도 O(2^n) <- 10개정도까지밖에 계산못함
int alba(int n)
{
	if (n > N)
		return 0;
	int sum = 0;
	int check = 0;
	for (int i = s[n][0]; i < s[n][0] + s[n][1]; i++)
	{
		if (day[i] == 1)
			check = 1;
	}
	if (check == 1)
		sum = alba(n + 1);
	else
	{
		sum = alba(n + 1);

		for (int i = s[n][0]; i < s[n][0] + s[n][1]; i++)
			day[i] = 1;
		sum = max(sum, alba(n + 1) + s[n][2]);

		for (int i = s[n][0]; i < s[n][0] + s[n][1]; i++)
			day[i] = 0;
	}
	return sum;
}

// 처음부터 알바의 합이 최대값과 같을 때 그 때의 알바 리스트를 출력
// n : 현재 알바 번호, sum : 현재까지 보수의 합, m : 보수의 최대합
void albaList(int n, int sum, int m)
{
	if (n > N)
		return;
	if (sum == m)
	{
		for (int i = 0; i < alist.size(); i++)
			cout << s[alist[i]][0] << " " << s[alist[i]][1] << endl;
		return;
	}

	int check = 0;
	for (int i = s[n][0]; i < s[n][0] + s[n][1]; i++)
		if (day[i] == 1)
			check = 1;

	if (check == 1)
		albaList(n + 1, sum, m);
	else
	{
		for (int i = s[n][0]; i < s[n][0] + s[n][1]; i++)
			day[i] = 1;
		alist.push_back(n);
		albaList(n + 1, sum + s[n][2], m);

		for (int i = s[n][0]; i < s[n][0] + s[n][1]; i++)
			day[i] = 0;
		alist.pop_back();
		albaList(n + 1, sum, m);
	}
	return;
}

int main()
{
	// input
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> s[i][0] >> s[i][1] >> s[i][2];// M D I

	// algor
	// alba(n) = 현재 알바 번호가 n이고, 현재로부터 얻을 수 있는 보수의 최대합을 반환
	// 알바 리스트를 맨뒤까지 고려하여 얻을 수 있는 보수의 최대합을 반환
	ret = alba(0);

	// output
	cout << endl;
	cout << ret << endl;
	//cout << "알바 목록" << endl;
	albaList(0, 0, ret);
	return 0;
}