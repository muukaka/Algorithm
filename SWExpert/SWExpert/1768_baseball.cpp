#include <iostream>
#include <string>

using namespace std;

#define N 4
typedef struct {
	int strike;
	int ball;
} Result;

// API
extern Result query(int guess[]);

// �� �׽�Ʈ ���̽��� �����ϴ� ���� �����ؼ� ���ߴ� �Լ� �Ǵ� �޼ҵ�
void doUserImplementation(int guess[]) {
	// Implement a user's implementation function
	// The array of guess[] is a return array that
	// is your guess for what digits[] would be.

	Result temp;
	//int digit[10];
	int loc[10][2];// 0~9���� ���ڿ� �� ��ġ[0,1,2,3]
	for (int i = 0; i < N; i++)
		guess[i] = i;
	memset(loc, 0, sizeof(loc));
	//query()�� ����ؼ� Result ����ü�� strike�� 4�϶� ����
	while (1) {
		temp = query(guess);
		if (temp.strike == N)
			break;
		else if (temp.strike + temp.ball == N)
		{
			for (int i = 0; i < 24; i++)//����
			{

			}
		}
		else if (temp.strike > 0 && temp.ball > 0)
		{

		}
		else if (temp.strike == 0 && temp.ball > 0)
		{

		}
		else if (temp.strike > 0 && temp.ball > 0)
		{

		}
		else if (temp.strike == 0 && temp.ball == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				loc[guess[i]][0] -= 1;
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (loc[j][0] >= 0)
					{
						guess[i] = j;
						break;
					}
				}
			}
		}


	
	}


}