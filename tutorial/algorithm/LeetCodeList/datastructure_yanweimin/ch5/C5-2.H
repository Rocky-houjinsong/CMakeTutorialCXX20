 /* c5-2.h ϡ��������Ԫ��˳����洢��ʾ */
 #define MAXSIZE 100 /* ����Ԫ���������ֵ */
 typedef struct
 {
   int i,j; /* ���±�,���±� */
   ElemType e; /* ����Ԫ��ֵ */
 }Triple;
 typedef struct
 {
   Triple data[MAXSIZE+1]; /* ����Ԫ��Ԫ���,data[0]δ�� */
   int mu,nu,tu; /* ����������������ͷ���Ԫ���� */
 }TSMatrix;