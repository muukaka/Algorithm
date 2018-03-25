/*
[제약사항]
1. 시간 제한 : 최대 50 개 테스트 케이스를 모두 통과하는 데 C / C++ / Java 모두 3 초
2. 게임 판에 적힌 숫자의 개수 N 은 3 이상 12 이하의 정수이다. ( 3 ≤ N ≤ 12 )
3. 연산자 카드 개수의 총 합은 항상 N - 1 이다.
4. 게임 판에 적힌 숫자는 1 이상 9 이하의 정수이다.
5. 수식을 완성할 때 각 연산자 카드를 모두 사용해야 한다..
6. 숫자와 숫자 사이에는 연산자가 1 개만 들어가야 한다.
7. 완성된 수식을 계산할 때 연산자의 우선 순위는 고려하지 않고, 왼쪽에서 오른쪽으로 차례대로 계산한다.
8. 나눗셈을 계산 할 때 소수점 이하는 버린다.
9. 입력으로 주어지는 숫자의 순서는 변경할 수 없다.
10. 연산 중의 값은 -100,000,000 이상 100,000,000 이하임이 보장된다.

[입력]
입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T 가 주어지고,
그 다음 줄부터 T 개의 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 숫자의 개수 N 이 주어진다.
다음 줄에는 '+', '-', '*', '/' 순서대로 연산자 카드의 개수가 공백을 사이에 두고 주어진다.
다음 줄에는 수식에 들어가는 N 개의 숫자가 순서대로 공백을 사이에 두고 주어진다.

[출력]
테스트 케이스 개수만큼 T 개의 줄에 각각의 테스트 케이스에 대한 답을 출력한다.
각 줄은 "#t" 로 시작하고 공백을 하나 둔 다음 정답을 출력한다. ( t 는 1 부터 시작하는 테스트 케이스의 번호이다. )
정답은 연산자 카드를 사용하여 만들 수 있는 수식으로 얻은 결과값 중 최댓값과 최솟값의 차이이다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num_card(13);// 최대 12개까지
vector<int> op_card(4);// +,-,*,/ 순서대로 사용가능한 연산자 개수
int N;
int ret;
int _min = 0, _max = 0;

void dp(int index, vector<int> op, int sum)
{
	if (index == N)
	{
		if (sum > _max) _max = sum;
		if (sum < _min) _min = sum;
	}

	if (op[0] > 0)
	{
		op[0]--;
		dp(index + 1, op, sum + num_card[index]);
		op[0]++;
	}
	if (op[1] > 0)
	{
		op[1]--;
		dp(index + 1, op, sum - num_card[index]);
		op[1]++;
	}
	if (op[2] > 0)
	{
		op[2]--;
		dp(index + 1, op, sum * num_card[index]);
		op[2]++;
	}
	if (op[3] > 0)
	{
		op[3]--;
		dp(index + 1, op, (int)(sum / num_card[index]));
		op[3]++;
	}
		
}

int main()
{
	int T;
	int i, j;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		// 입력
		for (i = 0; i < 4; i++)
			cin >> op_card[i];
		for (i = 0; i < N; i++)
			cin >> num_card[i];

		// 계산
		_min = 100 * 1000 * 1000 + 1;
		_max = -1 * _min;
		dp(1, op_card, num_card[0]);
		ret = _max - _min;

		// 출력
		cout << "#" << t << " " << ret << endl;
	}


	return 0;
}