#include <iostream.h>
typedef int elemtype; 

class  link                      		//���嵥������������
    { public:
    elemtype  data;
    link  *next;
  };
class  linkqueue                   		//������������������
  { public:
link *front,*rear;             			//����ͷָ���βָ��
void   iniqueue(linkqueue  &s);
void  enqueue(linkqueue &s, elemtype  x);
bool  empty(linkqueue  s);
elemtype  gethead(linkqueue s);
void dlqueue(linkqueue &Q);
void print(linkqueue &Q);
};

void   linkqueue::iniqueue(linkqueue  &s)
{
   link  *p;
   p=new  link;
   p->next=NULL;
   s.front=p; 
   s.rear=p;
}

void  linkqueue::enqueue(linkqueue &s, elemtype  x)
{
 link   *p;
 p=new  link;
 p->data=x; 
p->next=s.rear->next;
s.rear->next=p; 
s.rear=p;
}

bool  linkqueue::empty(linkqueue  s)
{
 if (s.front==s.rear) return true; 
else return false;
}

elemtype  linkqueue::gethead(linkqueue s)
{ 
if (s.front==s.rear)  return  NULL;
else  return  s.front->next->data;
}

void linkqueue::dlqueue(linkqueue &s)
{   link *p;
	p=s.front->next;
	if(p->next==NULL)
	 {s.front->next=NULL;s.front=s.rear;}
	else s.front->next=p->next;
	delete p;
}


void linkqueue::print(linkqueue &Q)
{
link *p;
// QElemType e;
p=Q.front->next;
// e=p->data;
while(p)
{
// printf("%d",e);
cout<<p->data<<" ";
p=p->next;
}
cout<<endl;
} 

void main()
{
	 linkqueue s1;
	 s1.iniqueue(s1);
	 cout<<"����1Ϊ���г�ʼ��"<<endl;
	 cout<<"����2Ϊ����в���Ԫ��"<<endl;
	 cout<<"����3Ϊɾ����ͷԪ��"<<endl;
	 cout<<"����4Ϊ�õ����ж�ͷԪ�ص�ֵ"<<endl;
	 cout<<"����5Ϊ�ж����Ƿ�Ϊ��"<<endl;
	 cout<<"����6Ϊ�鿴����"<<endl;
	 int q;
	 cin>>q;
	 while(q!=0)
	 {
		switch(q)
		{
		case 1: {s1.iniqueue(s1);}break;
		case 2: {
			int x;
			cout<<"��ѡ�����Ԫ�ظ���: ";
			cin>>x;
			s1.enqueue(s1,x);}break;
		case 3: {s1.dlqueue(s1);}break;
		case 4: {
			cout<<"��ͷԪ��Ϊ: "<<s1.gethead(s1)<<endl;}break;
		case 5: {if(s1.empty(s1)==true)
					cout<<"����Ϊ��"<<endl;
				else
					cout<<"���в�Ϊ��"<<endl;}break;
		case 6: {s1.print(s1);}break;
		 default:cout<<"�������λ������"<<endl;
		}
		 cout<<"����������: ";
	     cin>>q;
	 }	

}

