// Dynamic Programming(?), path ����?
// �ﰢ�� ���� �ִ���(���̵�:��)
// �迭 ���� ���� Ȯ��!

#include <iostream>
#include <vector>
#include <algorithm>// max()

using namespace std;

/*
Time Complexity : O()
Space Complexity : O()
*/

int N;// �˹� ����, 3 <= N <= 500
int M;// �˹� ���۳�, 0 <= M <= 200
int D;// �˹� �Ⱓ, 0 <= D <= 100
int I;// ����, 0 <= I <= 100
int s[501][3];//�˹� ������, M D I
int chck[501] = { 0, };// ������ �˹ٴ� 1�� ǥ��, ����� ���� ���
int day[301] = { 0, };// �˹��ϴ� ��¥, 0 ~ 300
int maxi;
int ret;

// ��ȭ�� : alba(n) = max{ alba(n + 1), alba(n + 1) + s[n][2] }
// ���⵵ O(2^n) <- 10�����������ۿ� ������
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
//	// base : �˹ٹ�ȣ > N �� ��� (������ �� ���캽)
//	if (num > N)
//		return;
//	// base : �˹� �Ⱓ�� ��ġ�� ���, ���� �˹ٹ�ȣ�� ���
//
//
//
//	return chck;
//	// ������ �ִ��� ��쿡, vector<�˹�>�� �����ϴ°� ���?
//	// �ֱٿ� �̷��� Ǫ�°� ��� �ô���...
//}

int main()
{
	// input
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> s[i][0] >> s[i][1] >> s[i][2];// M D I

	// algor
	// �ΰ��� �Լ��� ������ ���ٵ�...
	// �ִ뺸���� ã�� �Լ���, �׶��� �˹� �������� ���ϴ� �Լ�?
	// ��������� �� ������? �˹��ϴ� �Ⱓ, ������� ������ ����(?), ���� �˹ٹ�ȣ
	// �˹ٸ� �����ߴ���, ���������� ����

	//dp(chck, 0);// �˹� 0������ ���

	// alba(n, sum) = ���� �˹� ��ȣ�� n�̰�, ���ݱ����� ������ ���� sum�϶�
	// �˹� ����Ʈ�� �ǵڱ��� ����Ͽ� ���� �� �ִ� �ִ� ���� ���� ��ȯ�Ѵ�.
	ret = alba(0);
	// ��ȭ�� : alba(n, sum) = max{ alba(n+1, sum), alba(n+1, sum+s[n][2]) }
	// �޸������̼� : n(3~500), sum(0~50000) <- �ٵ� �̰� �˹ٸ� ���������� ���°ǵ� �޸������̼��� �Ҽ��� ���µ�


	// output
	cout << endl;
	cout << ret << endl;
	cout << "�˹� ���" << endl;

	return 0;
}