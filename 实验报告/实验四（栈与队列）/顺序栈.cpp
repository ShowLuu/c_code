#include <iostream.h>

typedef int elemtype;
 
class  link 
{  
public:
	elemtype data; 				//元素类型
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
	 while(s)            //栈不为空 && 栈中存在数据
    {
        cout<<p->data<<" "<<endl;   //遍历打印栈中数据
        p = p->next;
    }
    cout<<endl;
}

void main()
{
	 link  s1,*p;
	 
	 int x;
	 cout<<"请选择放入元素个数: ";
	 cin>>x;
	 
	 s1.push(p,x);
	 s1.print(p);
	 /*
	 s1.inistack(s1);
	 cout<<"输入1为置栈空"<<endl;
	 cout<<"输入2为向栈插入元素"<<endl;
	 cout<<"输入3为退栈"<<endl;
	 cout<<"输入4为取栈顶元素"<<endl;
	 cout<<"输入5为判栈师是否为空"<<endl;
	 cout<<"输入6为查看栈"<<endl;
	 int q;
	 cin>>q;
	 while(q!=0)
	 {
		switch(q)
		{
		case 1: {s1.inistack(s1);}break;
		case 2: {
			int x;
			cout<<"请选择放入元素个数: ";
			cin>>x;
			s1.push(s1,x);}break;
		case 3: {s1.pop(s1);}break;
		case 4: {cout<<"栈顶元素为: "<<s1.gettop(s1)<<endl;}break;
		case 5: {bool str=s1.empty(s1);
					if(str=true)
						cout<<"  栈不为空"<<endl;
					else
						cout<<"  栈为空"<<endl;}break;
		case 6: {s1.print(s1);}break;
		 default:cout<<"您输入的位置有误！"<<endl;
		}
		 cout<<"请输入数字: ";
	     cin>>q;
	 }
	 */

}