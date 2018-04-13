/*
[제약사항]
1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는데, C/C++/Java 모두 3초
2. 접수 창구의 개수 N과 정비 창구의 개수 M은 1 이상 9 이하의 정수이다. (1 ≤ N, M ≤ 9)
3. 접수 창구 i에서 고장을 접수하는 처리 시간 ai는 1 이상 20 이하의 정수이다. (1 ≤ ai ≤ 20)
4. 정비 창구 j에서 차량을 정비하는 처리 시간 bj는 1 이상 20 이하의 정수이다. (1 ≤ bj ≤ 20)
5. 차량 정비소를 방문한 고객의 수 K는 2 이상 1,000 이하의 정수이다. (2 ≤ K ≤ 1,000)
6. 고객 k의 도착 시간 tk는 0 이상 1,000 이하의 정수이다. (0 ≤ tk ≤ 1,000)
7. 지갑을 두고 간 고객이 이용한 접수 창구번호 A는 1 이상 N 이하의 정수이다. (1 ≤ A ≤ N)
8. 지갑을 두고 간 고객이 이용한 정비 창구번호 B는 1 이상 M 이하의 정수이다. (1 ≤ B ≤ M)
9. 창구번호와 고객번호는 1부터 시작한다.

[입력]
입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T가 주어지고, 그 다음 줄부터 T개의 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 접수 창구의 개수 N, 정비 창구의 개수 M, 차량 정비소를 방문한 고객의 수 K, 지갑을 두고 간 고객이 이용한 접수 창구번호 A와 정비 창구번호 B가 주어진다.
두 번째 줄에는 i번째 접수 창구가 고장을 접수하는 데 걸리는 시간 ai가 N개 주어진다.
세 번째 줄에는 j번째 정비 창구가 차량을 정비하는 데 걸리는 시간 bj가 M개 주어진다.
네 번째 줄에는 k번째 고객이 차량 정비소를 방문하는 시간 tk가 순서대로 K개 주어진다.

[출력]
테스트 케이스의 개수만큼 T줄에 T개의 테스트 케이스 각각에 대한 답을 출력한다.
각 줄은 "#x"로 시작하고 공백을 하나 둔 다음 정답을 출력한다. (x는 1부터 시작하는 테스트 케이스의 번호이다)
출력해야 할 정답은 지갑을 두고 간 고객과 같은 접수 창구 A와 같은 정비 창구 B를 이용한 고객들의 고객번호의 합이다. 만약 그런 고객이 없는 경우 정답으로 -1을 출력한다.
*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int ret;
int N, M, K, A, B;
int Ta[10];// 접수창구에서 일을 처리하는 시간
int Tb[10];// 정비창구에서 일을 처리하는 시간
int Tk[1001];// 고객의 도착시간
int Adesk[10];// A 데스크가 일을 하고 있으면 고객번호, or -1
int Bdesk[10];// B 데스크가 일을 하고 있으면 고객번호, or -1

class Customer {// 고객 정보
public:
	int k;	// 고객 번호
	int tk, ta, tb;	// 처리 시간
	int a, b;// 접수창구, 정비창구
};

Customer customer[1001];
vector<Customer> queueA;// A 데스크를 대기하는 고객
vector<Customer> queueB;// B 데스크를 대기하는 고객

bool operator<(Customer c1, Customer c2) {
	return ((c1.tk < c2.tk) || (c1.tk == c2.tk && c1.k < c2.k)) ? true : false;
}

void solve()
{
	// initialize
	int i;
	memset(Adesk, 0, sizeof(Adesk));
	memset(Bdesk, 0, sizeof(Bdesk));
	for (i = 1; i <= K; i++)
	{
		customer[i].k = i;
		customer[i].tk = Tk[i];
		Customer temp;
		temp.k = i; temp.tk = Tk[i];
		queueA.push_back(temp);
	}
	sort(queueA.begin(), queueA.end());// 시작하기 전에 전체에 대해서 한번만

	// run
	int cnt = 0;// 정비까지 끝낸 고객의 수
	for (int time = 0; cnt <= K; time++)
	{
		// 접수창구
		for (int n = 1; n <= N; n++)
		{
			if (Adesk[n] == 0 && !queueA.empty())// 데스크가 비었다면 채움
			{
				int k = queueA.front().k;
				customer[k].a = n;
				customer[k].ta = Ta[n];
				Adesk[n] = k;
				queueA.erase(queueA.begin());
			}
			else if (Adesk[n] > 0 )// 데스크 상담시간 끝난 경우
			{
				int k = Adesk[n];
				customer[k].ta -= 1;
				if (customer[k].ta == 0)
				{
					Customer temp;
					temp.k = k;
					temp.tk = time;
					queueB.push_back(temp);
					Adesk[n] = 0;
				}
			}
			// 그외는 그대로
		}

		// 정비창구
		if (!queueB.empty())
			sort(queueB.begin(), queueB.end());// 정비 창구에서 항상 정렬해줘야함
		for (int m = 1; m <= M; m++)
		{
			if (Bdesk[m] == 0 && !queueB.empty())// 데스크가 비었다면 채움
			{
				int k = queueB.front().k;
				customer[k].b = m;
				customer[k].tb = Tb[m];
				Bdesk[m] = k;
				queueB.erase(queueB.begin());
			}
			else if (Bdesk[m] > 0)// 데스크 상담시간 끝난 경우
			{
				int k = Bdesk[m];
				customer[k].tb -= 1;
				if (customer[k].tb == 0)
				{
					Bdesk[m] = 0;
					cnt++;//
					if (customer[k].a == A && customer[k].b == B)
						ret += k;
				}
			}
			// 그외는 그대로
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
		// 접수창구N, 정비창구M, 전체고객 K, 이용한 접수 창구번호 A와 정비 창구번호 B
		cin >> N >> M >> K >> A >> B;
		for (int i = 1; i <= A; i++)
			cin >> Ta[i];
		for (int i = 1; i <= B; i++)
			cin >> Tb[i];
		for (int i = 1; i <= K; i++)
			cin >> Tk[i];
		
		// algo
		ret = 0;
		solve();

		// output
		cout << "#" << t << " " << ret << endl;
	}
	return 0;
}