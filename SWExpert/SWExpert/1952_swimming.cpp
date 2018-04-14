#include <iostream>

using namespace std;

int ret;//���� ���� ������� �������� �̿��� �� �ִ� ����� ã�� �� ����� �������� ���
int fee[4];// 1��, 1����, 3����, 1�� ���
int plan[12];// ���� �̿��ȹ, �� ������ �̿��� ��¥

// ��Ʈ��ŷ���� ã�� �Լ�
void search(int month, int cost)
{
	// ��� �� 12���� ������ ��� ��͸� ����
	if (month >= 12)
	{
		if (cost < ret)
			ret = cost;
		return;
	}
	// ���� �޿� 1�� �̿�� ����ϴ� ���
	search(month + 1, cost + fee[0] * plan[month]);
	// ���� �޿� 1�� �̿�� ����ϴ� ���
	search(month + 1, cost + fee[1]);
	// ���� �޿� 3�� �̿�� ����ϴ� ���
	search(month + 3, cost + fee[2]);
	// ���� �޿� 1�� �̿�� ����ϴ� ���
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
		ret = fee[3];// 1�Ⱓ ���, �̰ͺ��� Ŭ�� ����
		search(0, 0);

		// output
		cout << "#" << t << " " << ret << endl;
	}

	return 0;
}