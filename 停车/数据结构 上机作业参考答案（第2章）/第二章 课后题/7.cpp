#include <iostream>
using namespace std;
const int MinNumber=-1000000;
struct Node
{
	Node(int x)
	{
		value=x;
		before=NULL;
		next=NULL;
	}
	int value;
	Node* before;
	Node* next;
};
void Change(Node* a)
{
	Node *p=a;
	Node *second=a->next;
	Node *q=p->next->next;
	//��1��n,��next·��
	while(q!=a&&q!=a->before)
	{
		p->next=q;
		//q->before=p;���ܸ�before��������Ҫ������
		p=q;
		q=q->next->next;
	}
	if(q==a)//����Ϊż��
	{
		q=a->before;
		p->next=q;
	}
	else//����Ϊ���� 
	{
		p->next=q;
		p=q;
		q=q->before;
		p->next=q;
	}
	//�������ϲ�������֤qΪż��
	//��n��2,��before·��
	if(q!=second)//����Ѿ��ǵ�2���ˣ��Ͳ�������ǰ����
		p=q->before->before;
	else
		p=q;
	while(p!=second)//һ����������
	{
		q->next=p;
		q=p;
		p=p->before->before;
	}
	if(p==second)//����Ϊż��
	{
		q->next=p;//��������
		p->next=a;
	}
	//���������е�before·��
	p=a;
	while(p->next!=a)
	{
		q=p->next;
		q->before=p;
		p=p->next;
	}
	a->before=p;
}

int main()
{
	//����Ŀ�ɵ�n>=3,�Ƚ���˫������
	Node* ha=new Node(1);
	Node *p=ha;
	for(int i=2;i<=11;i++)
	{
		Node * t=new Node(i);
		p->next=t;
		t->before=p;
		p=t;
	}
	p->next=ha;
	ha->before=p;
	Change(ha);
	//�������
	p=ha;
	while(p->next!=ha)
	{
		cout<<p->value<<" ";
		p=p->next;
	}
	cout<<p->value<<endl;
	//�������
	p=ha->before;
	while(p!=ha)
	{
		cout<<p->value<<" ";
		p=p->before;
	}
	cout<<p->value<<endl;
	
}
