#include <iostream.h>
const  int  maxsize=10;
typedef int elemtype;

class  sequenlist
{
 public:
   elemtype  a[maxsize];    	//表示线性表(a1,a2,…,an,aMaxlen), elemtype表示某种具体数据类型
   int       len;            			//len表示线性表的实际长度  
 public:
   int length(sequenlist L );   			//求顺序表L的长度
   void Insert(sequenlist &L,elemtype x,int i);//将元素x插入顺序表L第i个位置
   void Dele(sequenlist &L , int  i) ; //删除顺序表L第i个位置的元素
   void setnull(sequenlist &L );      //顺序表L置空表
   int Locate(sequenlist  L , elemtype  x) ; //定位，顺序表L中查找元素x的位置
   elemtype Get(sequenlist  L , int i);      //取顺序表L中第i个位置的元素
   elemtype prior(sequenlist  L , elemtype  x );	   //顺序表L中求元素x的前驱
   elemtype next(sequenlist  L , elemtype  x );    //顺序表L中求元素x的后继
   void prin(sequenlist  L);//输出线性表中的元素
 };

elemtype  sequenlist ::Get(sequenlist L,int i)
{ 
    if((i<1)||(i>L.len)) return NULL;
    else  return  L.a[i];
}

elemtype sequenlist :: prior(sequenlist L,elemtype x)
{
	int j=1;
   while((j<=L.len)&&(L.a[j]!=x))
    j++;
    if(j<L.len)  return j-1;
    else return -1;	
}

elemtype sequenlist :: next(sequenlist L,elemtype x)
{
	int j=1;
   while((j<=L.len)&&(L.a[j]!=x))
    j++;
    if(j<L.len)  return j+1;
    else return -1;
}



void  sequenlist ::Dele(sequenlist &L , int i)
{ int j;
      if((i<1)||(i>L.len))
        cout<<" position is not correct!"<<endl;
        else {
               for(j=i+1;j<=L.len;j++)
                      L.a[j-1]=L.a[j];                            	//元素前移
               L.len--;                                   	//表长度减1
            }
}

int  sequenlist::Locate(sequenlist L , elemtype x)
{ int j=1;
   while((j<=L.len)&&(L.a[j]!=x))
    j++;
    if(j<L.len)  return j;
    else return -1;
}


int  sequenlist :: length(sequenlist L )
{
   return  L.len;
}

void  sequenlist ::setnull(sequenlist  &L )
{
 L.len=0;
}

void sequenlist ::prin(sequenlist  L)//显示出线性表里的元素
{
	cout<<"线性表的元素为：";
	for(int i=1;i<=L.len;i++)
		cout<<L.a[i]<<' ';
	cout<<endl;
}


void  sequenlist ::Insert(sequenlist &L,elemtype x,int i)
{ 
	int j;
	if(L.len==maxsize-1) 
        cout<<"overflow"<<endl;
	else if ((i<1)||(i>L.len+1)) 
            cout<<"position is not correct!"<<endl;
		else
		{
			 for(j=L.len;j>=i;j--)
				L.a[j+1]=L.a[j];          		//元素后移
			 L.a[i]=x;               		//插入元素
			 L.len++;               		//表长度增加1
		}
}

void main()
{
	int i;
	sequenlist rj1;
    rj1.setnull(rj1);
	int t;
	cout<<"*************输入数字1为创建顺序表：***********************"<<endl;
	cout<<"*************输入数字2为显示线性表的长度：*****************"<<endl;
	cout<<"*************输入数字3为插入一个元素到线性表：*************"<<endl;
	cout<<"*************输入数字4为删除一个元素到线性表：*************"<<endl;
	cout<<"*************输入数字5为查找线性表中某个元素的位置：*******"<<endl;
	cout<<"*************输入数字6为取出一个位置的元素：*************"<<endl;
	cout<<"*************输入数字7为查看某个元素的前驱：*******"<<endl;
	cout<<"*************输入数字8为查看某个元素的后继：*******"<<endl;
	cout<<"*************输入数字9为置表空***************************"<<endl;
    cout<<"*************输入数字0为结束操作***************************"<<endl;
	cout<<"请输入操作数：";
	cin>>t;

   while(t!=0)
   {
	   switch(t)
	   {case 1:
	   {	
		   int x;
		   cout<<"插入几条数据: "<<endl;
		   cin>>x;
		   for( i=1;i<=x;i++)//为数据赋元素；
			{
				cout<<"请输入第: "<<i<<"个元素：";
				cin>>rj1.a[i];
				rj1.len++;
				cout<<endl;
			}
				rj1.prin(rj1);
	   }//输出线性表
			break;

	   case 2:
		   { cout<<"线性表的长度为: "<<rj1.length(rj1) <<endl;}// 3、求顺序表的长度
           	break;
	   case 3:
		   { int x,j;
			 cout<<"请输入插入元素的值: ";
			 cin>>x;
			 cout<<"请输入插入的位置: ";
			 cin>>j;
			 rj1.Insert(rj1,x,j); 
			 rj1.prin(rj1);}
             break;
	   case 4:
		   { int j;
			   cout<<"请输入删除的位置: ";
			cin>>j;
			rj1.Dele(rj1,j);
			rj1.prin(rj1);}
            break;
	   case 5:
		   {int x;
			   cout<<"请输入要查找的元素的值: ";
			 cin>>x;
			 cout<<"待查找的元素的位置是: "<<rj1.Locate(rj1, x)<<endl; }
			 break;
	   case 6:
		   { int x;
			 cout<<"请输入取出元素的位置: ";
			 cin>>x;
			 cout<<"元素是: "<<rj1.Get(rj1,x)<<endl;}
             break;
		case 7:
		   { int x;
			 cout<<"请输入查看哪个元素的前驱: ";
			 cin>>x;
			 cout<<"此元素的前驱为: "<<rj1.prior(rj1,x)<<endl;}
             break;
		case 8:
		   { int x;
			 cout<<"请输入查看哪个元素的后继：";
			 cin>>x;
			 cout<<"此元素的后继为: "<<rj1.next(rj1,x)<<endl;}
             break;
		case 9:
		   { 
			 cout<<"置表空---";
			 rj1.setnull(rj1);}
             break;
		  
	   default:cout<<"您输入的位置有误！";
		       
	   }
	   cout<<"请输入数字：";
	   cin>>t;
   }
                                 



}