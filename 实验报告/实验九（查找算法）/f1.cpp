#include <iostream.h>
const   int  n=10;				//n为表的最大长度
typedef struct    node
{
int   key;			//key为关键字，类型设定为elemtype
}NODE;

void Insert(node R[n+1],int x,int i)//将元素x插入顺序表R第i个位置
{ 
	int j;
	if ((i<1)||(i>6)) 
            cout<<"position is not correct!"<<endl;
		else
		{
			 for(j=n;j>=i;j--)
				R[j+1]=R[j];          		//元素后移
			 R[i].key=x;               		//插入元素
			 i++;               		//表长度增加1
		}

}
void Dele(node R[n+1] , int  i) //删除顺序表L第i个位置的元素
{ int j;
   if((i<1)||(i>n))
        cout<<" position is not correct!"<<endl;
        else {
               for(j=i+1;j<=n;j++)
                      R[j-1]=R[j];                            	//元素前移
               
            }
}

/*void Insert(node R[n+1],int x,int i)//将元素x插入顺序表L第i个位置
{ 
	for(int j=n;j>=i;j--)
		R[j+1]=R[j];          		//元素后移
			R[i].=x;               		//插入元素
			 
		}
}

   void Dele(node R[n+1] , int  i) //删除顺序表L第i个位置的元素
{ int j;
   if((i<1)||(i>n))
        cout<<" position is not correct!"<<endl;
        else {
               for(j=i+1;j<=n;j++)
                      R[j-1]=R[j];                            	//元素前移
               
            }
}*/



int  seqsearch (node  R[n+1],int k) //顺序查找	//在表R中查找关键字值为k的元素
{
R[0].key=k; int i=n;             				//从表尾开始向前扫描
while(R[i].key!=k)    i--;
return i;
}

int    binsearch(node    R[n+1],    int   k)//二分查找算法实现
{      int     low=1,     high=n;
 while(low<=high)
{     int  mid=(low +high)/2;          		//取区间中点
if(R[mid].key==k)
   return    mid;      					//查找成功
else if(R[mid].key>k)
        high=mid-1;                 			//在左子区间中查找
        else    low=mid+1;                			//在右子区间中查找
}
return    0;                 				//查找失败
}
void main()
{
NODE s1[5];
for(int i=1;i<5;i++)
{
	cout<<"请输入第"<<i<<"个数"<<endl;
	cin>>s1[i].key;
}
	cout<<"输入的数据为："<<endl;
	for( i=1;i<5;i++)
		 cout<<s1[i].key<<endl;
	cout<<"将40加入到2的位置"<<endl;
Insert(s1,40,2);
for( i=1;i<6;i++)
	cout<<s1[i].key<<endl;
cout<<"将4的位置的数删除"<<endl;
Dele(s1,4);
for( i=1;i<5;i++)
	cout<<s1[i].key<<endl;
cout<<"折半查找90的结果为："<<binsearch(s1,90)<<endl;
cout<<"顺序查找80的结果为："<<seqsearch(s1,80)<<endl;



}