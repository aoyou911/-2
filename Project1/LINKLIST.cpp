/*
	9.24��ת���� 
	LINKLIST.cpp 
	�����2003	�μ���	20203983 
*/
#include<stdlib.h>
#include <iostream>
#include"LINKLIST.h"
using namespace std;

LinkList creat1(int n)
{
	printf("������%d��Ԫ���Դ�������(˳����)\n",n);

	LinkList head,tail,p;
	int i;
	ElemType e;
	
	head=(LinkList)malloc(sizeof(LNode));
	tail=head;
	
	for(i=1;i<=n;i++)
	{
		cout << "�������" << i << "��Ԫ��" << endl;
		cin >> e;
		p=(LinkList)malloc(sizeof(LNode));
		p->data=e;
		tail->next=p;
		tail=p;
	}
	
	tail->next=NULL;

	return head;
	
}

LinkList creat2(int n)
{
	printf("������%d��Ԫ���Դ�������(������)\n",n);
	
	LinkList head,p;
	int i;
	ElemType e;
	
	head=(LinkList)malloc(sizeof(LNode));
	head->next=NULL;
	
	for(i=1;i<=n;i++)
	{
		cout << "�������" << i << "��Ԫ��" << endl;
		cin >> e;
		p=(LinkList)malloc(sizeof(LNode));
		p->data=e; 
		p->next=head->next;
		head->next=p;
	}
	
	return head;
}

void printLinkList(LinkList &L)
{
	LinkList p;
	cout << endl;
	for(p=L->next;p!=NULL;p=p->next)
	{
		cout << p->data << "\t";
	}
	cout << endl;
}

Status GetElem(LinkList& L, int i, ElemType &e)
{
	LinkList p = L;
	int j;
	for (j = 1; (j <= i)&&(p); j++)
	{
		p = p -> next;
	}
	if (!p)
	{
		cout << "��" << i << "��Ԫ�ز�����";
		return ERROR;
	}
	else if (i<1)
	{
		cout << "�����ʽ����";
		return ERROR;
	}
	else
	{
		e = p->data;
		return OK;
	}
}

Status ListInsert(LinkList& L, int i, ElemType &e)
{
	LinkList p,s;
	int j = 1;
	for (p = L; (p) && j <= i - 1; j++)
	{
		p = p->next;
	}
	if (!p)
	{
		cout << "�����Ȳ���" << endl;
		return ERROR;
	}
	else if (i < 1)
	{
		cout << "��������" << endl;
		return ERROR;
	}
	else
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return OK;
	}

}

Status ListDelete(LinkList& L, int i, ElemType &e)
{
	LinkList p;
	LinkList temp;
	int j = 1;
	for (p = L; (p->next) && (j <= i - 1); j++)
	{
		p = p->next;
	}
	if (!(p->next)||(i < 1))
	{
		cout << "ɾ��λ�ò�����" << endl;
		return ERROR;
	}
	else
	{
		temp = p->next;
		p->next = temp->next;
		e = temp->data;
		free(temp);
		return OK;
	}
}

LinkList odd_even_arrangement(LinkList& L)
{
	LinkList p,q,r,evenL;
	evenL = (LinkList)malloc(sizeof(LNode));
	q = evenL;
	p = L;
	while (p->next != NULL)
	{
		if ((p->next->data) % 2 == 0)
		{
			q->next = p->next;
			q = p->next;
			p->next = p->next->next;
		}
		else
		{
			p = p->next;
		}
	}
	q->next = NULL;
	
	int i=0,j;
	p = L->next;
	while (p != NULL)
	{
		p = p->next;
		i++;
	}

	for (j = 0; j < i - 1; j++)
	{
		p = L; q = L->next;	r = L->next->next;
		while (r != NULL)
		{
			if (q->data > r->data)
			{
				p->next = r;
				q->next = r->next;
				r->next = q;
				p = r;
				r = q->next;
			}
			else
			{
				p = p->next;
				q = q->next;
				r = r->next;
			}
		}
	}

	p = evenL->next;
	while (p != NULL)
	{
		p = p->next;
		i++;
	}

	for (j = 0; j < i - 1; j++)
	{
		p = evenL; q = evenL->next;	r = evenL->next->next;
		while (r != NULL)
		{
			if (q->data > r->data)
			{
				p->next = r;
				q->next = r->next;
				r->next = q;
				p = r;
				r = q->next;
			}
			else
			{
				p = p->next;
				q = q->next;
				r = r->next;
			}
		}
	}

	return evenL;
}

void MergeList(LinkList& LA, LinkList LB)
{
	LinkList la0 = LA, la1 = LA->next, lb = LB->next;
	while ((la1 != NULL)&&(lb!=NULL))
	{
		if ((lb->data) </*	>	��ʵ�ִӴ�С��*/ (la1->data))
		{
			LB->next = lb->next;
			lb->next = la1;
			la0->next = lb;
			la0 = lb;
			lb = LB->next;
		}
		else if ((lb->data) == (la1->data))
		{
			la0->next = la1->next;
			LB->next = lb->next;
			free(la1);
			//free(lb);	//���п��ްɣ���Ŀ���ϸ�Ҫ��
			la1 = la0->next;
			lb = LB->next;
		}
		else
		{
			la0 = la0->next;
			la1 = la1->next;
		}
	}
	if (la1 == NULL)
	{
		la0->next = LB->next;
	}
	//free(LB);	//���п��ްɣ���Ŀ���ϸ�Ҫ��
}

void AmovB(LinkList La, LinkList& Lb, int i, int len, int j)
{
	int temp;
	LinkList la1=La->next, la2=La, lb=Lb;

	for (temp = 1; (temp < i) && (la1 != NULL); temp++)
	{
		la1 = la1->next;
	}
	if ((la1 == NULL) || (i < 1)) { cout << "����La���Ȳ������iֵ��������" << endl; }

	for (temp = 1, la2 = la1; (temp < len) && (la2 != NULL); temp++)
	{
		la2 = la2->next;
	}
	if ((la2 == NULL) || (len < 1)) { cout << "����La���Ȳ������lenֵ��������" << endl; }

	for (temp = 1; (temp < j) && (lb->next != NULL); temp++)
	{
		lb = lb->next;
	}
	if ((lb->next == NULL) || (j < 1)) { cout << "����Lb���Ȳ������jֵ��������" << endl; }

	la2->next = lb->next;
	lb->next = la1;

}

void negative_positive(LinkList &L)
{
	LinkList p=L->next, q=L->next->next;
	while (q != NULL)
	{
		if ((q->data) < 0)
		{
			p->next = q->next;
			q->next = L->next;
			L->next = q;
			q = p->next;
		}
		else
		{
			p = p->next;
			q = q->next;
		}

	}


}

Status kInvert(LinkList &L,int k)
{
	LinkList p=L->next, q=L->next;
	int i = 1;
	while ((i < k)&&(q!=NULL))
	{
		q = q->next;
		i++;
	}
	if (q == NULL||k < 1)
	{
		//cout << "�����Ȳ����kֵ����ȷ";
		return ERROR;
	}
	else
	{
		while (L->next != q)
		{
			L->next = p->next;
			p->next = q->next;
			q->next = p;
			p = L->next;
		}
		//cout << "\n" << "kֵΪ" << k << endl;
		return OK;
	}
}

void min_first(LinkList &L)
{
	LinkList p = L->next, min = L->next, temp = L;
	while((p->next)!=NULL)
	{
		if((min->data)>(p->next->data))
		{
			min=p->next;
			temp=p;
		}
		p=p->next;
	}
	if (min != L->next)
	{
		temp->next = min->next;
		p = L->next;
		L->next = min;
		min->next = p;
	}
}

/*
* 1	�㷨˼�룺
*
*	����4��ָ�룬p�����ڱ���L��q�����ڸ����γ��µ�����r������ʱ�ĸ���ָ�룻evenL��oddL������Ϊż����Ҳ����������������ͷָ��
*
*	�ȷ���һ��ͷ����������ʹevenLָ���ͷ���
*
*	ʹpָ��Lͷ��㣬qָ��������ͷ���
*
*	��p����һ������Ԫ��ֵΪż������������������q������뵽�������У�q����һ�����ָ��p����һ����㣬qָ��p��q������һ����㣬p����һ����� ��Ϊ ��ǰp����һ��������һ�����
*	��p����һ������Ԫ��ֵ��Ϊż������������pָ�����
*
*	�ظ������жϲ���ֱ��p����һ�����Ϊ�գ���ΪevenL�����һ����㣨qָ��ýڵ㣩��ָ�����Դ����L�е�ĳ��Ԫ�صĵ�ַ���������qʹ�ý�����һ�����Ϊ��
*
*	����������������ͱ���i��k�ĸ�������ȷ������Ľ��ĸ�������p��q��r�ֱ�ָ��ͷ��㡢��Ԫ��㡢�ڶ������ĸ�����
*	��������ð�ݷ��ķ���ʵ�������ڲ�����ָ��Ϊ���ж�ѭ������������������ýڵ����i��kʵ��ѭ���жϣ�
*
*	ͨ�����㷨��ʵ�ֽ������н��ֳ���������ż�������������ݰ���С��������
*
*/

/*
*2	�㷨˼�룺
*
*	����3��ָ��
*	la0�����ڸ���ʵ�ֲ��������ָ��la1����һ����㣻
*	la1���ڱ���LA����Ѱ��LB���н����ʵĲ���λ�ã�
*	lb����ָ��LB�е�ǰ�����ɻ����н�㣨����������Ԫ�ؾ���������LA�����е�Ԫ�����Ƚ�
*
*	la0ָ��LAͷ��㣬la1ָ��LA��Ԫ��㣬lbָ��LB����Ԫ���
*
*	���lbָ�����ֵС��la1ָ�����ֵ��
*	ʹlb����һ������Ϊ�µ�LB��Ԫ��㣬
*	������la0�������Ѵ�ʱlb�����뵽la0��la1���֮�䣬
*	��la0ָ��lb��ȷ��la0Ϊla1����һ����㣩����ʹlbָ��LB������Ԫ���
*
*	���lbָ�����ֵ����la1ָ�����ֵ��
*	ʹ la0����һ����� Ϊ la1����һ����� ���ͷ�la1ָ����
*	ʹla1����ָ��ǰla0����һ����㣨ȷ��la0Ϊla1����һ����㣩
*	ʹ LB����Ԫ��� Ϊ lb����һ����� ������ѡ���ͷ�lbָ����
*	ʹlb����ָ��LB����Ԫ���
*
*	���lbָ�����ֵ����la1ָ�����ֵ��
*	la0��la1��ָ���Ӧ����һ����㣬��Ѱ�ҷ��������������������
*
*	�ظ�����ѭ����3���жϣ�ֱ��la1����lbָ���
*
*	��la1ָ��յ�ַ��˵��lb����Ԫ�أ���ЩԪ�ؾ�����LA�е����Ԫ�أ�Ϊ���뵽LA�У���ʹla0���¸����ָ��ǰLB����Ԫ���
*	��lbָ��յ�ַ��˵��LB������Ԫ�ؾ��Ѳ��뵽LA��
*
*	����ѡ���ͷ�LB��ͷ���
*
*	ͨ�����㷨��ʵ�ִ������LA��ɾ���������LB��Ԫ����ͬ�Ľ�㣬������LB�������
*/

/*
*3	�㷨˼�룺
*
*	��������ָ�룺la1����ָ��La��i����㣻la2����ָ��La��i+len-1����㣻lb����ָ��Lb��k-1�����
*
*	ͨ������ʹla1ָ��La��i����㣬���ڴ�la1ָ����λ�ó�����ʹla2ָ���i+len-1�����
*	ͨ������ʹlbָ��Lb��k-1�����	������������ѭ������temp�ĸ��������
*
*	ʹla2ָ��lb����һ����㣨Lb�ĵ�k����㣩
*	ʹlb����һ�����Ϊla1
*
*	ͨ�����㷨�ܽ�La�Ե�i��Ԫ�����len��Ԫ���Ƶ�B�ĵ�j��Ԫ��֮ǰ
*
*/

/*
*4	�㷨˼�룺
*
*	����2��ָ�룺	q ����ȷ����������λ��		p q��һ�����λ��,���ڸ���ʵ������˳��ĸı�
*
*	pָ����Ԫ��㣬qָ��p����һ�����		(��Ԫ�����Բ����ж�������Χ�ڣ���Ϊ������Ϊ�������ս������������������)
*	��qָ����Ԫ��Ϊ����ʱ��ʹp���¸����Ϊq����һ����㣬ʹq����һ�����Ϊ��ʱ����Ԫ��㣨L->next������ʹͷ������һ�����Ϊq����ʱq��Ϊ��Ԫ��㣬��ʹqָ��ǰp����һ������Լ�������
*	��qָ����Ԫ�ز�Ϊ����ʱ��p��qָ�������
*
*	�ظ������жϲ���ֱ��qָ���
*
*	ͨ�����㷨�ܰ����и���Ԫ���Ƶ�����Ԫ��ǰ��		��������ʱ������
*/

/*
*5	�㷨˼�룺
*
*	����������㣺p������ָ����Ԫ��㲢����ʵ������˳��ĸı䣻q������Ѱ�ҵ�k�����
*
*	p��q��ָ����Ԫ���
*	����ѭ������i��ʹqָ���k����㣬ͬʱ��֤q��Ϊ��ָ�루��Ϊ��ָ�����˳�ѭ��������ERROR��
*
*	qָ���k������ʹ��ǰ��Ԫ��㣨p������������뵽q������һ�����֮�䣬ֱ��qΪ��Ԫ���
*	�������Ϊ��
*	ʹ��ǰp����һ������Ϊ��Ԫ���
*	p����һ�����ָ��q����һ�����	��ʵ��������룩
*	q����һ�����ָ��q			��ʵ��������룩
*	p����ָ���µ���Ԫ���
*	���ظ���������ֱ��qΪ��Ԫ��㣩
*
*	ͨ�����㷨ʵ��ǰk����㵹��
*/

/*
*6	�㷨˼�룺
*
*	����3��ָ�룺p���ڱ�����min����ָ����С��㣬temp���ڸ����ı�����˳���ʵ��
*	
*	����p��minָ����Ԫ��㣬
*	��p����һ������ֵС��min����ֵ����minָ��p����һ����㣬ͬʱtempָ��p���
*	��p����һ������ֵ��С��min����ֵ���򲻽����κβ���
*	pָ����� 
*	
*	�ظ���������ֱ��p���¸����Ϊ��
*	
*	��ʱminָ��ֵ��С��㣬tempָ����ǰһ����㣬���ڸ����ı�����˳��
*	��min��Ϊ��Ԫ���ʱ����temp����һ�����Ϊmin����һ�����
*	��pָ����Ԫ����ʹmin��Ϊ�µ���Ԫ��㣬ͬʱmin����һ�����Ϊp
*	
*	ͨ�����㷨�ܽ�������ֵ��С��һ������Ƶ��������ǰ�� 
*/
