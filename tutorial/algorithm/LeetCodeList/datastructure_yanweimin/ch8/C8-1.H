 /* c8-1.h �߽��ʶ�������ÿռ���Ľ��ṹ */
 /* head��foot�ֱ��ǿ����ÿռ���н��ĵ�һ���ֺ����һ����(WORD) */

 typedef struct WORD /* ������ */
 {
   union
   {
     struct WORD *llink; /* ͷ����ָ��ǰ����� */
     struct WORD *uplink; /* �ײ���ָ�򱾽��ͷ�� */
   }a;
   int tag; /* ���־��0�����У�1��ռ�ã�ͷ����β������ */
   int size; /* ͷ���򣬿��С */
   struct WORD *rlink; /* ͷ����ָ���̽�� */
 }WORD,head,foot,*Space; /* *Space�������ÿռ�ָ������ */

 #define FootLoc(p) (p)+(p)->size-1 /* �������ĺ궨�壬ָ��p��ָ���ĵײ�(���һ����) */