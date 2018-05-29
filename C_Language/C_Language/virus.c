/*
백신은 매우 위험한 알파 성분을 내포하고 있기 때문에 사람의 피부 민감도에 따라 알파성분의 배합을 달리해야 한다. 
즉 각 사람마다 알파 성분이 일정량 미만이면 전혀 백신의 효능이 없고 일정량을 초과하면 건강에 치명적인 해를 끼치게 된다. 
우선 메르스 바이러스가 가장 급속도록 확산되고있는 지역에 일차로 생산된 백신을 모두 보냈다.
그 지역에는 모두 N명이 거주하고 있으며 일차로 보낸 백신은 모두 M병이다. 
일단 이 백신으로 몇 명에게 투여가 가능한지 알아야 추가로 생산할 백신의 알파성분 함량을 조절할 수 있다. 
해당 지역에 거주하는 사람들에 대한 정보와 일차로 보낸 백신에 대한 정보를 입력받아 
백신을 투여할 수 있는 최대 인원이 몇 명인지 구하는 프로그램을 작성하시오. 소스 파일명은 gg.cpp(또는 gg.c) 로 한다.

입력형식
첫 번째 줄에 공백으로 구분된 두 개의 정수 N과 M이 입력된다. (1 ≤ N, M ≤ 2500)
이후 N개의 줄에 걸쳐 i번째 사람에게 투여가 가능한 백신의 알파성분의 최소량과 최대량을 나타내는
두 개의 정수(1 이상 1,000 이하)가 공백으로 구분되어 주어진다. 
이후 M개의 줄에 걸쳐 i번째 백신의 알파성분 함량
과 최대 투여가능한 사람수를 나타내는 두 개의 정수(1 이상 1,000 이하)가 공백으로 구분되어 주어진다.

출력형식
백신을 투여할 수 있는 최대 인원수를 출력한다.
입력 예
3 2
3 9
2 5
3 5
6 2
4 1

출력 예
2
*/

#include <stdio.h>

int ret;
int N, M;
int tot;

typedef struct {
	int mini;
	int maxi;
} person;

typedef struct {
	int alpha;
	int pill;
} medi;

person p[2501];
medi m[2501];
int u[2501];

void solve(int p_idx, int m_idx, int use, int cnt)
{
	if (p_idx == N || m_idx == M)
	{

	}
	if (p_idx >= N || m_idx >= M || cnt > tot)
		return;

	if (use < m[m_idx].pill)
	{
		solve(p_idx + 1, m_idx, use + 1, cnt + 1);
	}
	else if (use == m[m_idx].pill)
	{
		solve(p_idx, m_idx + 1, 0, cnt);
	}
		
}

int main()
{
	//int i, j;
	// input
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &p[i].mini, &p[i].maxi);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &m[i].alpha, &m[i].pill);
		tot += m[i].pill;
	}
		
	
	// algo
	ret = 0;
	solve();

	// output
	printf("%d\n", ret);
	return 0;
}