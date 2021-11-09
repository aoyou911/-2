/*
	9.24��ת���� 
	LINKLIST.h
	�����2003	�μ���	20203983 
*/
#ifndef LINKLIST
#define LINKLIST 


#define TRUE 1
#define FALSE 0

#define OK 1
#define ERROR 0

#define INFEASIBLE -1	//����ִ�� 
#define OVERFLOW -2	//���
typedef int Status;	//�������� 
typedef int ElemType; 	//����Ԫ������ 

typedef  struct LNode
{
     ElemType data;
     struct LNode *next;
} LNode ,*LinkList;	//������������ݶ���Ĺ��� 


LinkList creat1(int n);	//˳���������� 
LinkList creat2(int n);	//������������ 

void printLinkList(LinkList &L);	//������������˳���ӡ��������Ԫ�أ������������ 
Status GetElem(LinkList &L,int i,ElemType &e);	//�������� ����������ĳ��λ�õ�Ԫ�أ���������e�� 
Status ListInsert(LinkList &L,int i,ElemType &e);	//�������� ���������i��λ��ǰ����Ԫ��e 
Status ListDelete(LinkList &L,int i,ElemType &e);	//�������� ��ɾ�������i��λ�õ�Ԫ�أ���������e�� 

//������Ŀ
LinkList odd_even_arrangement(LinkList &L);	//����ż������ 
void MergeList(LinkList &LA, LinkList LB);	//�ϲ�������ͬԪ��
void AmovB(LinkList La,LinkList &Lb,int i,int len,int j);	//��i��Ԫ����Ĺ�len��Ԫ���Ƶ�������B�ĵ�j��Ԫ��֮ǰ
void negative_positive(LinkList &L);	//����������֮ǰ
Status kInvert(LinkList &L,int k);	//ǰk����㵹��
void min_first(LinkList &L);//��С��һ������Ƶ���ǰ��

#endif	//LINKLIST	9.24


