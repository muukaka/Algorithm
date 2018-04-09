// Dynamic Programming(?), path 저장?
// 삼각형 위의 최대경로(난이도:하)
// 배열 참조 전달 확인!

#include <iostream>
#include <vector>
#include <algorithm>// max()

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
int chck[501] = { 0, };// 선택한 알바는 1을 표시, 출력을 위해 사용
int day[301] = { 0, };// 알바하는 날짜, 0 ~ 300
int maxi;
int ret;

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
//int* dp(int* chck, int num)
//{
//	// base : 알바번호 > N 인 경우 (끝까지 다 살펴봄)
//	if (num > N)
//		return;
//	// base : 알바 기간이 겹치는 경우, 다음 알바번호를 고려
//
//
//
//	return chck;
//	// 수입이 최대일 경우에, vector<알바>를 리턴하는건 어떨까?
//	// 최근에 이렇게 푸는거 어디서 봤더라...
//}

int main()
{
	// input
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> s[i][0] >> s[i][1] >> s[i][2];// M D I

	// algor
	// 두가지 함수로 나눠야 할텐데...
	// 최대보수를 찾는 함수와, 그때의 알바 스케줄을 구하는 함수?
	// 전달해줘야 할 정보는? 알바하는 기간, 현재까지 보수의 총합(?), 현재 알바번호
	// 알바를 선택했는지, 보수의합이 얼만지

	//dp(chck, 0);// 알바 0번부터 고려

	// alba(n, sum) = 현재 알바 번호가 n이고, 지금까지의 보수의 합이 sum일때
	// 알바 리스트를 맨뒤까지 고려하여 얻을 수 있는 최대 보수 합을 반환한다.
	ret = alba(0);
	// 점화식 : alba(n, sum) = max{ alba(n+1, sum), alba(n+1, sum+s[n][2]) }
	// 메모이제이션 : n(3~500), sum(0~50000) <- 근데 이거 알바를 순차적으로 도는건데 메모이제이션을 할수가 없는데


	// output
	cout << endl;
	cout << ret << endl;
	cout << "알바 목록" << endl;

	return 0;
}