#include <stdio.h>
// 고객 정보 구조체
typedef struct {
	int k;//고객번호
	int t;//처리시간
} cus;
// 정비 창구 대기 큐 원소 구조체
typedef struct {
	int idx;//고객이 이용한 접수 창구 번호
	int k;//고객번호
	int t;//큐에 삽입된 시간
} prc;

const int MAXS = 9;// 접수 창구와 정비 창구 최대 갯수
const int MAXK = 1000;// 최대 고객
int a[MAXS + 1];// 접수 창구에서 고장 접수에 걸리는 시간
int b[MAXS + 1];// 정비 창구에서 차량 정비에 걸리는 시간

cus rec[MAXS + 1];// 현재 접수 창구 이용 고객 정보
cus rep[MAXS + 1];// 현재 정비 창구 이용 고객 정보
cus recq[MAXK];// 접수 창구 대기 큐
prc repq[MAXK];// 정비 창구 대기 큐

int crp;// 접수 창구 대기 큐의 추출 인덱스
int pwp, prp;//정비 차구 대기 큐의 삽입, 추출 인덱스

int tc, T;// 테스트 케이스

int N, M, K, A, B;

//고객들의 접수 창구 대기 순서 정렬
void _sort(cus arr[], int from, int to)
{

}

//테스트 케이스를 푼다
int solve()
{

}