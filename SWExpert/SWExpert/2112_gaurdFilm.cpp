/*
2112. [모의 SW 역량테스트] 보호 필름
두께 D, 가로 W, 합격기준 K

[제약사항]
1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는데, C/C++/Java 모두 5초
2. 보호 필름의 두께 D는 3이상 13이하의 정수이다. (3≤D≤13)
3. 보호 필름의 가로크기 W는 1이상 20이하의 정수이다. (1≤W≤20)
4. 합격기준 K는 1이상 D이하의 정수이다. (1≤K≤D)
5. 셀이 가질 수 있는 특성은 A, B 두 개만 존재한다.

[입력]
첫 줄에 총 테스트 케이스의 개수 T가 주어진다.
두 번째 줄부터 T개의 테스트 케이스가 차례대로 주어진다.
각 테스트 케이스의 첫 줄에는 보호 필름의 두께 D, 가로크기 W, 합격기준 K가 차례로 주어진다.
그 다음 D줄에 보호 필름 단면의 정보가 주어진다. 각 줄에는 셀들의 특성 W개가 주어진다.
(특성A는 0, 특성B는 1로 표시된다.)

[출력]
테스트 케이스의 개수만큼 T줄에 T개의 테스트 케이스 각각에 대한 답을 출력한다.
각 줄은 “#x”로 시작하고 공백을 하나 둔 다음 정답을 출력한다. (x는 1부터 시작하는 테스트 케이스의 번호이다)
출력해야 할 정답은 성능검사를 통과할 수 있는 약품의 최소 투입 횟수이다.
약품을 투입하지 않고도 성능검사를 통과하는 경우에는 0을 출력한다.
*/

#include <stdio.h>
#include <string.h>// memset()
#include <algorithm>// min()

using namespace std;

int film[13][20];// 필름 상태
int test[20];// 최대 20열의 가로 크기가 있을 수 있음, 테스트 통과시 true
int inject[13];// 투여X:-1, 투여A: 0, 투여B: 1
int D, W, K;// 3 <= D <= 13, 1 <= W <= 20, 1 <= K <= D
int ret;// 최소 약품 투여 횟수

// 필름이 합격기준을 통과하는지 확인하는 함수
// 필름 전체 상태를 보기보다 기준에 안맞으면 바로 리턴해야 시간내에 풀수 있음
bool testCheck()
{
	memset(test, 0, sizeof(test));
	for (int i = 0; i < W; i++)// 열 순서대로 검사
	{
		int cnt = 1;
		for (int j = 0; j < D-1; j++)// 한 열의 여러 장에 대해 검사
		{
			int comp1 = (inject[j] == -1) ? film[j][i] : inject[j];
			int comp2 = (inject[j+1] == -1) ? film[j+1][i] : inject[j+1];
			if (comp1 == comp2)
			{
				cnt++;
				if (cnt >= K)
					break;
			}
			else
				cnt = 1;
		}
		if (cnt < K)
			return false;
	}
	return true;
}

void algo(int idx, int count)
{
	// base : 지금 세고있는 방법이 현재까지 해법보다 약품투여가 더 많다면 중단
	if (count >= ret)
		return;
	// base : 필름의 상태가 기준을 통과한다면 그만
	if (testCheck())
	{
		ret = min(ret, count);
		return;
	}
	else if (idx < D)
	{
		// 투여 A
		inject[idx] = 0;
		algo(idx + 1, count + 1);
		inject[idx] = -1;
		// 투여 B
		inject[idx] = 1;
		algo(idx + 1, count + 1);
		inject[idx] = -1;
		// 투여 X
		algo(idx + 1, count);
	}
	return;
}

int main()
{
	int T;
	scanf("%d", &T);//cin >> T;

	for (int t = 1; t <= T; t++)
	{
		// input
		scanf("%d %d %d", &D, &W, &K);//cin >> D >> W >> K;
		for (int i = 0; i < D; i++)
			for (int j = 0; j < W; j++)
				scanf("%d", &film[i][j]);//cin >> film[i][j];
		
		// algor
		ret = K;// 최대 투여 가능 횟수 K
		for (int i = 0; i < D; i++)
			inject[i] = -1;

		if (K == 1)
			ret = 0;
		else
			algo(0, 0);

		// output
		printf("#%d %d\n", t, ret);//cout << "#" << t << " " << ret;
	}
	return 0;
}