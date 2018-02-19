#include <iostream.h>
typedef int elemtype;

const int  maxsize= 60;   

class seqqueue
{
public:
elemtype  queue[maxsize]; 			//将队列中元素定为数组型，元素类型为elemtype
int   front;             			//队头指针
int   rear;             			//队尾指针
void     INIQUEUE(seqqueue &Q);			//将队列Q设置成一个空队列
void     ENQUEUE (seqqueue  &Q,int y);		//将元素X插入到队尾中，也称“进队”，“插入”
void     DLQUEUE(seqqueue &Q);			//将队列Q的队头元素删除，也称“退队”、“删除”
elemtype GETHEAD(seqqueue Q );			//得到队列Q的队头元素之值
bool   EMPTY(seqqueue Q );	
void print(seqqueue Q);			//判断队列Q是否为空，若为空返回真，否则返回假
};


 void  seqqueue::INIQUEUE(seqqueue &Q )
 {  
	 Q.front=Q.rear=maxsize-1;
 }

void  seqqueue::ENQUEUE (seqqueue  &Q,int y)
{ 
	for(int i=0;i<y;i++)
	{
       if ((Q.rear+1)%maxsize == Q.front) 
		   cout<<"overflow";
       else  { 
			  elemtype  x;
			  cout<<"请输入要添加的元素: ";
			  cin>>x;
			  Q.rear=(Q.rear+1)%maxsize;
              Q.queue[Q.rear]=x;
             }
	}
}

void  seqqueue::DLQUEUE(seqqueue  &Q )
{
  if (Q.rear==Q.front)  cout<<"underflow";
  else  
    Q.front =(Q.front+1)%maxsize;
}

elemtype  seqqueue::GETHEAD(seqqueue Q )
{ 
         if  (Q.rear==Q.front)  
         { cout<<"underflow";return  NULL;}
         else{ 
			 return Q.queue[(Q.front+1)%maxsize];}
}

bool seqqueue::EMPTY(seqqueue Q )
{ 
        if  (Q.rear==Q.front)
           return true;
        else return false;
}


void seqqueue::print(seqqueue Q)
{
	int i=Q.front;
	for(int j=1;j<=(Q.rear-Q.front+maxsize)%maxsize;j++)
	{
		i=(i+1)%maxsize;
		cout<<Q.queue[i]<<" ";

	}
	cout<<endl;
}

void main()
{
	 seqqueue s1;
	 s1.INIQUEUE(s1);
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
		case 1: {s1.INIQUEUE(s1);}break;
		case 2: {
			int x;
			cout<<"请选择放入元素个数: ";
			cin>>x;
			s1.ENQUEUE(s1,x);}break;
		case 3: {s1.DLQUEUE(s1);}break;
		case 4: {
			cout<<"对头元素为: "<<s1.GETHEAD(s1)<<endl;}break;
		case 5: {if(s1.EMPTY(s1)==true)
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

