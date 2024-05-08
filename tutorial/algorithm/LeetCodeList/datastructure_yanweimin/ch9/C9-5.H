 /* c9-5.h Trie�������� */
 #define MAXKEYLEN 16 /* �ؼ��ֵ���󳤶ȣ�ͬc9-4.h */
 typedef struct
 {
   char ch[MAXKEYLEN]; /* �ؼ��� */
   int num; /* �ؼ��ֳ��� */
 }KeysType; /* �ؼ������ͣ�ͬc9-4.h */

 typedef struct
 {
   KeysType key; /* �ؼ��� */
   Others others; /* ��������(�����̶���) */
 }Record; /* ��¼���ͣ�ͬc9-4.h */

 typedef enum{LEAF,BRANCH}NodeKind; /* �������:{Ҷ��,��֧}��ͬc9-4.h */

 typedef struct TrieNode /* Trie�������� */
 {
   NodeKind kind;
   union
   {
     struct /* Ҷ�ӽ�� */
     {
       KeysType K;
       Record *infoptr;
     }lf;
     struct /* ��֧��� */
     {
       struct TrieNode *ptr[LENGTH]; /* LENGTHΪ��������+1,�����̶��� */
     /*  int num; �� */
     }bh;
   }a;
 }TrieNode,*TrieTree;

 /* �������ַ����͹ؼ��ֵıȽ�Լ��Ϊ���µĺ궨�� */
 #define EQ(a,b) (!strcmp((a),(b)))
 #define LT(a,b) (strcmp((a),(b))<0)
 #define LQ(a,b) (strcmp((a),(b))<=0)