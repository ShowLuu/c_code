#include <iostream.h>
typedef int elemtype;

class link
{  
public:
	elemtype data; 				//元素类型
	link     *next;   			//指针类型，存放下一个元素的地址
public:
	void length(link  *head);             		//求链表的长度
	void Insert(link  *head , elemtype  x , elemtype  y);	//将元素x插入到第i个位置
	void link::dele(link  *head , elemtype  x);      		//删除第i个位置的元素
	void setnull( );//置空表
	link *Locate(link  *head ,elemtype x); //定位，查找元素x的位置
	link *get(link  *head ,  int  i);			//取第i个位置的元素
	elemtype prior(elemtype x ); 	//求元素x的前驱
	elemtype succ(elemtype x ); 	//求元素x的后继
	link *hcreat1(int n );
	link *hcreat2(int n );//头插法建立单链表
	link *rcreat1( int n);  
	link *rcreat2( int n);//尾插法建立单链表
	void  print(link  *head);
};

link *link::rcreat1(int n )
{ 
	link *s,*r,*p;
    int i;
    p=NULL;
    for(i=1;i<=n;i++)
    {
		s=new link;
		cin>>s->data;
		if(p==NULL)  p=s;
		else r->next=s;
		r=s;
	}
		r->next=NULL;
		return p;
}

link *link::rcreat2(int n )
{ 
	link *s,*r,*p;
    int i;
    p=r=new link;
    p->next=NULL;
	cout<<"创建单链表： ";
    for(i=1;i<=n;i++)
    {
		s=new link;
		cin>>s->data;
		r->next=s;
		r=s;
	}
	r->next=NULL;
	return p;
}

link *link::hcreat1(int n )
{ 
	link *s,*p;
    int i;
    p=new link;
    p->next=NULL;
    for(i=1;i<=n;i++)
    {
	 s=new link;
     cin>>s->data;
     s->next=p->next;
     p->next=s;
    }
	return p;
}

link *link::hcreat2(int n )
{ 
	link *s,*p;
	int i;
    p=new link;
    p->next=NULL;
    for(i=1;i<=n;i++)
    {
		 s=new link;
		 cin>>s->data;
		 s->next=p->next;
		 p->next=s;
    }
	return p;
}

void link::length(link  *head )
{
    link *p;
    p=head->next;
	int count=1;
    while(p->next!=NULL)
  { 
		p=p->next;
     count++;
  }  				
  cout<<"单链表的长度为:"<<count<<endl;
}

link *link::Locate(link  *head ,elemtype  x)
 {
	
	 link *p;
	 p=head->next;
	 if(p!=NULL){
	 while(p->data!=x)
		p=p->next;
	 }
	 else
	 {
		 cout<<"次元素不存在"<<endl;
		 return NULL;
	 }
	 return p;
 }
 

link  *link::get(link  *head ,  int  i)
 {
   int j;
   link *p;
   j=1;
   p=head->next;
   if(p!=NULL){
   while(j<i)
   { 
     j++;
     p=p->next;
   }
   }
   else
	 {
		 cout<<"次元素不存在"<<endl;
		 return NULL;
	 }
  return p;
  }


void  link::Insert(link  *head , elemtype  x , elemtype  y)
{
  link *p,*s;
  s=new link;
  s->data=x;
  if(head->next==NULL)  		//链表为空
  {
	head->next=s;
	 s->next=NULL;
  }
	 p=Locate(head,y) ;      		//调用查找算法
	if(p==NULL)
		cout<<"插入位置非法";
    else
    {  s->next=p->next;
       p->next=s;
    }

}

void  link::dele(link  *head , elemtype  x)
{
	link *p,*q;
	q=head;
    p=head->next;
   while((p!=NULL)&&(p->data!=x))
   {
     q=p;
     p=p->next;
   }
   if(p==NULL)  cout<<"要删除的结点不存在";
   else
   {  
    q->next=p->next;
    delete(p);
   }
}

void  link::print(link  *head)
 {  
    link *p;
    p=head->next;
    while(p->next!=NULL)
  { 
    cout<<p->data<<"->";			//输出表中非最后一个元素
    p=p->next;
  }
  cout<<p->data;   				//输出表中最后一个元素
  cout<<endl;
}

void main()
{
	link rj1,*p,*p1;
	//int m,x,y;
	//cout<<"请输入链表的节点数：";
//	cin>>m;
	//p=rj1.rcreat2(m);
	//p=rj1.hcreat2(m);

	//rj1.print(p);
	

	//cout<<"请输入想要查找的元素： ";
	//cin>>m;

//	cout<<"请输入插入元素的值： ";
//	cin>>m;
//	cout<<"请输入待插入的元素： ";
//	cin>>m;

//	rj1.Insert(p,m,m);
//	rj1.print(p);


//	cout<<"请输入删除元素的值： ";
//	cin>>m;
//	rj1.dele(p,m);
//	rj1.print(p);
	
	cout<<"*************输入数字1为创建单链表：***********************"<<endl;
	cout<<"*************输入数字2为显示线性表的长度：*****************"<<endl;
	cout<<"*************输入数字3为插入一个元素到线性表：*************"<<endl;
	cout<<"*************输入数字4为删除一个元素到线性表：*************"<<endl;
	cout<<"*************输入数字5为查找线性表中某个元素的位置：*******"<<endl;
	cout<<"*************输入数字6为取出一个位置的元素：*************"<<endl;
//	cout<<"*************输入数字9为置表空***************************"<<endl;
	cout<<"*************输入数字7为查看单链表*************************"<<endl;
    cout<<"*************输入数字0为结束操作***************************"<<endl;
	cout<<"请输入操作数：";
	int t;
	cin>>t;

   while(t!=0)
   {
	   switch(t)
	   {case 1:
	   	
		  int m;
		cout<<"请输入链表的节点数：";
		cin>>m;
		p=rj1.rcreat2(m);
		rj1.print(p);	   
			break;

	   case 2:
		   { 	rj1.length(p);}// 求单链表表的长度
           	break;
	   case 3:
		   { 
			    int m,n;
			    cout<<"请输入插入元素的值： ";
				cin>>m;
				cout<<"请输入待插入的元素： ";
				cin>>m;
				rj1.Insert(p,m,n);
				rj1.print(p);}
           break;
	   case 4:
		   { int j;
			 cout<<"请输入删除的位置: ";
			 cin>>j;
			 rj1.dele(p,j);}
             break;
	   case 5:
		   {

			   cout<<"请输入查找某一元素的位置： ";
				cin>>m;
				p1=rj1.Locate(p,m);
		        cout<<p1->next<<endl;}
			 break;
	   case 6:
		   {	cout<<"请输入查找位置的元素： ";
				cin>>m;
				p1=rj1.get(p,m);
		        cout<<p1->data<<endl;}
			 break;
	  
		case 7:
			{
				cout<<"查看结果: "<<endl;
				rj1.print(p);
			}
			break;
		  
	   default:return ;
		       
	   }
	   cout<<"请输入数字：";
	   cin>>t;
   }

}