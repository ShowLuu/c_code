#include <iostream.h>
typedef int elemtype; 

class  link                      		//定义单链表数据类型
    { public:
    elemtype  data;
    link  *next;
  };
class  linkqueue                   		//定义链队列数据类型
  { public:
link *front,*rear;             			//定义头指针和尾指针
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
	 cout<<"输入1为队列初始化"<<endl;
	 cout<<"输入2为向队列插入元素"<<endl;
	 cout<<"输入3为删除对头元素"<<endl;
	 cout<<"输入4为得到队列队头元素的值"<<endl;
	 cout<<"输入5为判队列是否为空"<<endl;
	 cout<<"输入6为查看队列"<<endl;
	 int q;
	 cin>>q;
	 while(q!=0)
	 {
		switch(q)
		{
		case 1: {s1.iniqueue(s1);}break;
		case 2: {
			int x;
			cout<<"请选择放入元素个数: ";
			cin>>x;
			s1.enqueue(s1,x);}break;
		case 3: {s1.dlqueue(s1);}break;
		case 4: {
			cout<<"对头元素为: "<<s1.gethead(s1)<<endl;}break;
		case 5: {if(s1.empty(s1)==true)
					cout<<"队列为空"<<endl;
				else
					cout<<"队列不为空"<<endl;}break;
		case 6: {s1.print(s1);}break;
		 default:cout<<"您输入的位置有误！"<<endl;
		}
		 cout<<"请输入数字: ";
	     cin>>q;
	 }	

}

