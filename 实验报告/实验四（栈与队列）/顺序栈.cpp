#include <iostream.h>

typedef int elemtype;
 
class  link 
{  
public:
	elemtype data; 				//Ԫ������
	link     *next; 
 public:
	void  inistack(link  *top);
	void  push(link *top,int x);
	void  pop(link *top);
	
	
	elemtype gettop(link *top);
	bool   empty(link *top);      
	void print(link *s);
};


void link::inistack(link  *top)
{ 
  top->next=NULL;
}

void link::push(link *top,int x)
{
 link *s;
 s=new link;
 s->data=x;
 s->next=top->next;
 top->next=s;
 }

void link::pop(link *top)
{
      link *s;
      s=top->next;
      if(s!=NULL)
     {
      top->next=s->next;
      delete(s);}
}

elemtype link::gettop(link *top)
{
 if(top->next!=NULL)
 return  top->next->data;
 else
 return  NULL;
}

bool  link::empty(link *top)
{
 if(top->next==NULL)
 return(true);
 else
 return(false);
}

void link::print(link *s)
{
	link *p;
	 while(s)            //ջ��Ϊ�� && ջ�д�������
    {
        cout<<p->data<<" "<<endl;   //������ӡջ������
        p = p->next;
    }
    cout<<endl;
}

void main()
{
	 link  s1,*p;
	 
	 int x;
	 cout<<"��ѡ�����Ԫ�ظ���: ";
	 cin>>x;
	 
	 s1.push(p,x);
	 s1.print(p);
	 /*
	 s1.inistack(s1);
	 cout<<"����1Ϊ��ջ��"<<endl;
	 cout<<"����2Ϊ��ջ����Ԫ��"<<endl;
	 cout<<"����3Ϊ��ջ"<<endl;
	 cout<<"����4Ϊȡջ��Ԫ��"<<endl;
	 cout<<"����5Ϊ��ջʦ�Ƿ�Ϊ��"<<endl;
	 cout<<"����6Ϊ�鿴ջ"<<endl;
	 int q;
	 cin>>q;
	 while(q!=0)
	 {
		switch(q)
		{
		case 1: {s1.inistack(s1);}break;
		case 2: {
			int x;
			cout<<"��ѡ�����Ԫ�ظ���: ";
			cin>>x;
			s1.push(s1,x);}break;
		case 3: {s1.pop(s1);}break;
		case 4: {cout<<"ջ��Ԫ��Ϊ: "<<s1.gettop(s1)<<endl;}break;
		case 5: {bool str=s1.empty(s1);
					if(str=true)
						cout<<"  ջ��Ϊ��"<<endl;
					else
						cout<<"  ջΪ��"<<endl;}break;
		case 6: {s1.print(s1);}break;
		 default:cout<<"�������λ������"<<endl;
		}
		 cout<<"����������: ";
	     cin>>q;
	 }
	 */

}