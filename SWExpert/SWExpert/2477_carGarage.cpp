/*
[�������]
1. �ð����� : �ִ� 50�� �׽�Ʈ ���̽��� ��� ����ϴµ�, C/C++/Java ��� 3��
2. ���� â���� ���� N�� ���� â���� ���� M�� 1 �̻� 9 ������ �����̴�. (1 �� N, M �� 9)
3. ���� â�� i���� ������ �����ϴ� ó�� �ð� ai�� 1 �̻� 20 ������ �����̴�. (1 �� ai �� 20)
4. ���� â�� j���� ������ �����ϴ� ó�� �ð� bj�� 1 �̻� 20 ������ �����̴�. (1 �� bj �� 20)
5. ���� ����Ҹ� �湮�� ���� �� K�� 2 �̻� 1,000 ������ �����̴�. (2 �� K �� 1,000)
6. �� k�� ���� �ð� tk�� 0 �̻� 1,000 ������ �����̴�. (0 �� tk �� 1,000)
7. ������ �ΰ� �� ���� �̿��� ���� â����ȣ A�� 1 �̻� N ������ �����̴�. (1 �� A �� N)
8. ������ �ΰ� �� ���� �̿��� ���� â����ȣ B�� 1 �̻� M ������ �����̴�. (1 �� B �� M)
9. â����ȣ�� ����ȣ�� 1���� �����Ѵ�.

[�Է�]
�Է��� �� ù �ٿ��� �� �׽�Ʈ ���̽��� ���� T�� �־�����, �� ���� �ٺ��� T���� �׽�Ʈ ���̽��� �־�����.
�� �׽�Ʈ ���̽��� ù ��° �ٿ��� ���� â���� ���� N, ���� â���� ���� M, ���� ����Ҹ� �湮�� ���� �� K, ������ �ΰ� �� ���� �̿��� ���� â����ȣ A�� ���� â����ȣ B�� �־�����.
�� ��° �ٿ��� i��° ���� â���� ������ �����ϴ� �� �ɸ��� �ð� ai�� N�� �־�����.
�� ��° �ٿ��� j��° ���� â���� ������ �����ϴ� �� �ɸ��� �ð� bj�� M�� �־�����.
�� ��° �ٿ��� k��° ���� ���� ����Ҹ� �湮�ϴ� �ð� tk�� ������� K�� �־�����.

[���]
�׽�Ʈ ���̽��� ������ŭ T�ٿ� T���� �׽�Ʈ ���̽� ������ ���� ���� ����Ѵ�.
�� ���� "#x"�� �����ϰ� ������ �ϳ� �� ���� ������ ����Ѵ�. (x�� 1���� �����ϴ� �׽�Ʈ ���̽��� ��ȣ�̴�)
����ؾ� �� ������ ������ �ΰ� �� ���� ���� ���� â�� A�� ���� ���� â�� B�� �̿��� ������ ����ȣ�� ���̴�. ���� �׷� ���� ���� ��� �������� -1�� ����Ѵ�.
*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int ret;
int N, M, K, A, B;
int Ta[10];// ����â������ ���� ó���ϴ� �ð�
int Tb[10];// ����â������ ���� ó���ϴ� �ð�
int Tk[1001];// ���� �����ð�
int Adesk[10];// A ����ũ�� ���� �ϰ� ������ ����ȣ, or -1
int Bdesk[10];// B ����ũ�� ���� �ϰ� ������ ����ȣ, or -1

class Customer {// �� ����
public:
	int k;	// �� ��ȣ
	int tk, ta, tb;	// ó�� �ð�
	int a, b;// ����â��, ����â��
};

Customer customer[1001];
vector<Customer> queueA;// A ����ũ�� ����ϴ� ��
vector<Customer> queueB;// B ����ũ�� ����ϴ� ��

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
	sort(queueA.begin(), queueA.end());// �����ϱ� ���� ��ü�� ���ؼ� �ѹ���

	// run
	int cnt = 0;// ������� ���� ���� ��
	for (int time = 0; cnt <= K; time++)
	{
		// ����â��
		for (int n = 1; n <= N; n++)
		{
			if (Adesk[n] == 0 && !queueA.empty())// ����ũ�� ����ٸ� ä��
			{
				int k = queueA.front().k;
				customer[k].a = n;
				customer[k].ta = Ta[n];
				Adesk[n] = k;
				queueA.erase(queueA.begin());
			}
			else if (Adesk[n] > 0 )// ����ũ ���ð� ���� ���
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
			// �׿ܴ� �״��
		}

		// ����â��
		if (!queueB.empty())
			sort(queueB.begin(), queueB.end());// ���� â������ �׻� �����������
		for (int m = 1; m <= M; m++)
		{
			if (Bdesk[m] == 0 && !queueB.empty())// ����ũ�� ����ٸ� ä��
			{
				int k = queueB.front().k;
				customer[k].b = m;
				customer[k].tb = Tb[m];
				Bdesk[m] = k;
				queueB.erase(queueB.begin());
			}
			else if (Bdesk[m] > 0)// ����ũ ���ð� ���� ���
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
			// �׿ܴ� �״��
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
		// ����â��N, ����â��M, ��ü�� K, �̿��� ���� â����ȣ A�� ���� â����ȣ B
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