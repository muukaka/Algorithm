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

// 각 테스트 케이스의 생각하는 수를 추측해서 맞추는 함수 또는 메소드
void doUserImplementation(int guess[]) {
	// Implement a user's implementation function
	// The array of guess[] is a return array that
	// is your guess for what digits[] would be.

	Result temp;
	//int digit[10];
	int loc[10][2];// 0~9까지 숫자와 그 위치[0,1,2,3]
	for (int i = 0; i < N; i++)
		guess[i] = i;
	memset(loc, 0, sizeof(loc));
	//query()를 사용해서 Result 구조체의 strike가 4일때 정답
	while (1) {
		temp = query(guess);
		if (temp.strike == N)
			break;
		else if (temp.strike + temp.ball == N)
		{
			for (int i = 0; i < 24; i++)//순열
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