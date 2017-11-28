/*
������
�����
1 3
0 2 4 6 8
8 6 4 3 2 1 0
*/
#include <iostream>
using namespace std;
const int MinNumber=-1000000;
struct Node
{
	Node(int x)
	{
		value=x;
		next=NULL;
	}
	int value;
	Node* next;
};
Node*  Merge(Node* a,Node *b)
{
	Node *temp;
	Node *p=a,*q=b;
	Node *head = a->value >= b->value?b:a; // ѡ��a b����С��ֵ��Ϊͷ�ڵ�
	while(p!=NULL&&q!=NULL) // a b ֻҪ��һ��������ɣ��Ͳ��ü���ѡ��
	{
		if(p->value < q->value) //p��qС����qָ��p
		{
			temp=p->next;
			p->next=q;
			p=temp;
		}
		else
		{
			temp=q->next;
			q->next=p;
			q=temp;
		}
	}
	return head; // ���ص�head �ǵ�����
}
Node* Reverse(Node* first) // ��������
{
	Node *p=first,*q=p->next;
	first->next=NULL; //�ǵðѵ�һ����next��ֵΪNULL
	while(q!=NULL)
	{
		Node* QNextTemp=q->next;
		q->next=p;
		p=q;
		q=QNextTemp;
	}
	return p;
}
void outputNode(Node* head) // �������
{
    Node *p=head;
    while(p!=NULL)
    {
        cout<<p->value<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
	Node* a=new Node(1);
	Node *p=a;
	for(int i=3;i<=3;i+=2)
	{
		Node * t=new Node(i);
		p->next=t;
		p=t;
	}
	outputNode(a);
	Node* b=new Node(0);
	p=b;
	for(int i=2;i<=8;i+=2)
	{
		Node * t=new Node(i);
		p->next=t;
		p=t;
	}
	outputNode(b);
	Node * head=Merge(a,b);
	head=Reverse(head);
	outputNode(head);
	return 0;
	/***********����**********
	��a�ĳ���Ϊm,b�ĳ���Ϊn,�㷨�ĸ��Ӷ�ΪO(2*(m+n))
	**********************/
}
