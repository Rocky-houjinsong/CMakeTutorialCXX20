 /* c2-5.h ��ͷ���������������� */
 typedef struct LNode /* ������� */
 {
   ElemType data;
   struct LNode *next;
 }LNode,*Link,*Position;

 typedef struct LinkList /* �������� */
 {
   Link head,tail; /* �ֱ�ָ�����������е�ͷ�������һ����� */
   int len; /* ָʾ��������������Ԫ�صĸ��� */
 }LinkList;