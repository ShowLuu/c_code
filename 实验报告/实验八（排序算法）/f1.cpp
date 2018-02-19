#include <iostream.h>
int const     n=5;				//n为表的最大长度
typedef struct    node
{char no[10];
char name[10];
int score;			//key为关键字，类型设定为elemtype
}NODE;


void Bubblesort(node R[],int n)
{
  int flag=1;  //当flag为0则停止排序
  for(int i=1; i<n; i++)
  {  //i表示趟数，最多n-1趟
    flag=0;//开始时元素未交换
    for (int j=n-1; j>=i; j--)  
      if (R[j].score<R[j-1].score)
         { //发生逆序   
            node t=R[j];
                    R[j]=R[j-1];
                    R[j-1]=t;flag=1;  //交换，并标记发生了交换
          }
       if(flag==0)return;
      }} 



void selectsort(node R[],int n) //直接选择排序
{
  int i, j,m; node t;
  for(i=1;i<n-1;i++)
  {
    m=i;
    for(j=i+1;j<n;j++) 
      if(R[j].score>R[m].score)  m=j;
    if (m!=i)
      {
       t=R[i];
       R[i]=R[m];
       R[m]=t;
     }
    }
  }



void insertsort(NODE R[],int n)//直接插入排序
{
  for ( int i=1; i<n; i++)   			//i表示插入次数，共进行n-1次插入
   {
	NODE temp=R[i]; 				//把待排序元素赋给temp
    int j=i-1; 
    while ((j>=0)&& (temp.score<R[j].score))
 {
      R[j+1]=R[j]; j--; 			//顺序比较和移动
      }
    R[j+1]=temp;
}
}
 void main()
 {

    NODE s1[5];
	for(int i=1;i<5;i++)
	{
		cout<<"请输入第"<<i<<"个学生信息"<<endl;
		cout<<"学号:";	cin>>s1[i].no;
		cout<<"姓名:"; cin>>s1[i].name;
		cout<<"成绩:"; cin>>s1[i].score;
	}
	cout<<"按序号显示学生信息:"<<endl;
	for( i=1;i<5;i++)
		 cout<<s1[i].no<<' '<<s1[i].name<<' '<<s1[i].score<<' '<<endl;
	cout<<"利用冒泡排序实现成绩从小到大排序："<<endl;
	Bubblesort(s1,5);
	for( i=1;i<5;i++)
		 cout<<s1[i].no<<' '<<s1[i].name<<' '<<s1[i].score<<' '<<endl;
	cout<<"利用直接选择排序实现成绩从大到小排序："<<endl;
	selectsort(s1,5);
	for( i=1;i<5;i++)
		 cout<<s1[i].no<<' '<<s1[i].name<<' '<<s1[i].score<<' '<<endl;
	cout<<"利用直接插入排序实现成绩从小到大排序："<<endl;
	insertsort(s1,5);
	for( i=1;i<5;i++)
		 cout<<s1[i].no<<' '<<s1[i].name<<' '<<s1[i].score<<' '<<endl;

 }
