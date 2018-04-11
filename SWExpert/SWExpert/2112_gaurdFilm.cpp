/*
2112. [���� SW �����׽�Ʈ] ��ȣ �ʸ�
�β� D, ���� W, �հݱ��� K

[�������]
1. �ð����� : �ִ� 50�� �׽�Ʈ ���̽��� ��� ����ϴµ�, C/C++/Java ��� 5��
2. ��ȣ �ʸ��� �β� D�� 3�̻� 13������ �����̴�. (3��D��13)
3. ��ȣ �ʸ��� ����ũ�� W�� 1�̻� 20������ �����̴�. (1��W��20)
4. �հݱ��� K�� 1�̻� D������ �����̴�. (1��K��D)
5. ���� ���� �� �ִ� Ư���� A, B �� ���� �����Ѵ�.

[�Է�]
ù �ٿ� �� �׽�Ʈ ���̽��� ���� T�� �־�����.
�� ��° �ٺ��� T���� �׽�Ʈ ���̽��� ���ʴ�� �־�����.
�� �׽�Ʈ ���̽��� ù �ٿ��� ��ȣ �ʸ��� �β� D, ����ũ�� W, �հݱ��� K�� ���ʷ� �־�����.
�� ���� D�ٿ� ��ȣ �ʸ� �ܸ��� ������ �־�����. �� �ٿ��� ������ Ư�� W���� �־�����.
(Ư��A�� 0, Ư��B�� 1�� ǥ�õȴ�.)

[���]
�׽�Ʈ ���̽��� ������ŭ T�ٿ� T���� �׽�Ʈ ���̽� ������ ���� ���� ����Ѵ�.
�� ���� ��#x���� �����ϰ� ������ �ϳ� �� ���� ������ ����Ѵ�. (x�� 1���� �����ϴ� �׽�Ʈ ���̽��� ��ȣ�̴�)
����ؾ� �� ������ ���ɰ˻縦 ����� �� �ִ� ��ǰ�� �ּ� ���� Ƚ���̴�.
��ǰ�� �������� �ʰ� ���ɰ˻縦 ����ϴ� ��쿡�� 0�� ����Ѵ�.
*/

#include <stdio.h>
#include <string.h>// memset()
#include <algorithm>// min()

using namespace std;

int film[13][20];// �ʸ� ����
int test[20];// �ִ� 20���� ���� ũ�Ⱑ ���� �� ����, �׽�Ʈ ����� true
int inject[13];// ����X:-1, ����A: 0, ����B: 1
int D, W, K;// 3 <= D <= 13, 1 <= W <= 20, 1 <= K <= D
int ret;// �ּ� ��ǰ ���� Ƚ��

// �ʸ��� �հݱ����� ����ϴ��� Ȯ���ϴ� �Լ�
// �ʸ� ��ü ���¸� ���⺸�� ���ؿ� �ȸ����� �ٷ� �����ؾ� �ð����� Ǯ�� ����
bool testCheck()
{
	memset(test, 0, sizeof(test));
	for (int i = 0; i < W; i++)// �� ������� �˻�
	{
		int cnt = 1;
		for (int j = 0; j < D-1; j++)// �� ���� ���� �忡 ���� �˻�
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
	// base : ���� �����ִ� ����� ������� �ع����� ��ǰ������ �� ���ٸ� �ߴ�
	if (count >= ret)
		return;
	// base : �ʸ��� ���°� ������ ����Ѵٸ� �׸�
	if (testCheck())
	{
		ret = min(ret, count);
		return;
	}
	else if (idx < D)
	{
		// ���� A
		inject[idx] = 0;
		algo(idx + 1, count + 1);
		inject[idx] = -1;
		// ���� B
		inject[idx] = 1;
		algo(idx + 1, count + 1);
		inject[idx] = -1;
		// ���� X
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
		ret = K;// �ִ� ���� ���� Ƚ�� K
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