/* main5-4.c ����bo5-4.c�������� */
#include "../ch1/c1.h"
typedef int ElemType;
#include "c5-4.h"
#include "bo5-4.c"
void main()
{
	CrossList A, B, C;
	InitSMatrix(&A); /* CrossList���͵ı����ڳ���ʹ��֮ǰ�����ʼ�� */
	InitSMatrix(&B);
	printf("��������A: ");
	CreateSMatrix(&A);
	PrintSMatrix(A);
	printf("�ɾ���A���ƾ���B: ");
	CopySMatrix(A, &B);
	PrintSMatrix(B);
	DestroySMatrix(&B); /* CrossList���͵ı������ٴ�ʹ��֮ǰ���������� */
	printf("���پ���B��:\n");
	PrintSMatrix(B);
	printf("��������B2:(�����A���С�������ͬ���С��зֱ�Ϊ%d,%d)\n", A.mu, A.nu);
	CreateSMatrix(&B);
	PrintSMatrix(B);
	printf("����C1(A+B): ");
	AddSMatrix(A, B, &C);
	PrintSMatrix(C);
	DestroySMatrix(&C);
	printf("����C2(A-B): ");
	SubtSMatrix(A, B, &C);
	PrintSMatrix(C);
	DestroySMatrix(&C);
	printf("����C3(A��ת��): ");
	TransposeSMatrix(A, &C);
	PrintSMatrix(C);
	DestroySMatrix(&A);
	DestroySMatrix(&B);
	DestroySMatrix(&C);
	printf("��������A2: ");
	CreateSMatrix(&A);
	PrintSMatrix(A);
	printf("��������B3:(����Ӧ�����A2��������ͬ=%d)\n", A.nu);
	CreateSMatrix(&B);
	PrintSMatrix(B);
	printf("����C5(A*B): ");
	MultSMatrix(A, B, &C);
	PrintSMatrix(C);
	DestroySMatrix(&A);
	DestroySMatrix(&B);
	DestroySMatrix(&C);
}