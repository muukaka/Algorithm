#include <stdio.h>
// �� ���� ����ü
typedef struct {
	int k;//����ȣ
	int t;//ó���ð�
} cus;
// ���� â�� ��� ť ���� ����ü
typedef struct {
	int idx;//���� �̿��� ���� â�� ��ȣ
	int k;//����ȣ
	int t;//ť�� ���Ե� �ð�
} prc;

const int MAXS = 9;// ���� â���� ���� â�� �ִ� ����
const int MAXK = 1000;// �ִ� ��
int a[MAXS + 1];// ���� â������ ���� ������ �ɸ��� �ð�
int b[MAXS + 1];// ���� â������ ���� ���� �ɸ��� �ð�

cus rec[MAXS + 1];// ���� ���� â�� �̿� �� ����
cus rep[MAXS + 1];// ���� ���� â�� �̿� �� ����
cus recq[MAXK];// ���� â�� ��� ť
prc repq[MAXK];// ���� â�� ��� ť

int crp;// ���� â�� ��� ť�� ���� �ε���
int pwp, prp;//���� ���� ��� ť�� ����, ���� �ε���

int tc, T;// �׽�Ʈ ���̽�

int N, M, K, A, B;

//������ ���� â�� ��� ���� ����
void _sort(cus arr[], int from, int to)
{

}

//�׽�Ʈ ���̽��� Ǭ��
int solve()
{

}