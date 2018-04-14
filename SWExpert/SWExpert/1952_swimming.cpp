#include <iostream>

using namespace std;

int ret;//가장 적은 비용으로 수영장을 이용할 수 있는 방법을 찾고 그 비용을 정답으로 출력
int fee[4];// 1일, 1개월, 3개월, 1년 요금
int plan[12];// 연간 이용계획, 각 월별로 이용할 날짜

// 백트래킹으로 찾을 함수
void search(int month, int cost)
{
	// 계산 중 12월이 지나갈 경우 재귀를 멈춤
	if (month >= 12)
	{
		if (cost < ret)
			ret = cost;
		return;
	}
	// 현재 달에 1일 이용권 사용하는 경우
	search(month + 1, cost + fee[0] * plan[month]);
	// 현재 달에 1달 이용권 사용하는 경우
	search(month + 1, cost + fee[1]);
	// 현재 달에 3달 이용권 사용하는 경우
	search(month + 3, cost + fee[2]);
	// 현재 달에 1년 이용권 사용하는 경우
	search(month + 12, cost + fee[3]);
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		// input
		for (int i = 0; i < 4; i++)
			cin >> fee[i];
		for (int i = 0; i < 12; i++)
			cin >> plan[i];
			
		// algo
		ret = fee[3];// 1년간 요금, 이것보다 클수 없음
		search(0, 0);

		// output
		cout << "#" << t << " " << ret << endl;
	}

	return 0;
}