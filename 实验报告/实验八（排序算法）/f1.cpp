#include <iostream.h>
int const     n=5;				//nΪ�����󳤶�
typedef struct    node
{char no[10];
char name[10];
int score;			//keyΪ�ؼ��֣������趨Ϊelemtype
}NODE;


void Bubblesort(node R[],int n)
{
  int flag=1;  //��flagΪ0��ֹͣ����
  for(int i=1; i<n; i++)
  {  //i��ʾ���������n-1��
    flag=0;//��ʼʱԪ��δ����
    for (int j=n-1; j>=i; j--)  
      if (R[j].score<R[j-1].score)
         { //��������   
            node t=R[j];
                    R[j]=R[j-1];
                    R[j-1]=t;flag=1;  //����������Ƿ����˽���
          }
       if(flag==0)return;
      }} 



void selectsort(node R[],int n) //ֱ��ѡ������
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



void insertsort(NODE R[],int n)//ֱ�Ӳ�������
{
  for ( int i=1; i<n; i++)   			//i��ʾ���������������n-1�β���
   {
	NODE temp=R[i]; 				//�Ѵ�����Ԫ�ظ���temp
    int j=i-1; 
    while ((j>=0)&& (temp.score<R[j].score))
 {
      R[j+1]=R[j]; j--; 			//˳��ȽϺ��ƶ�
      }
    R[j+1]=temp;
}
}
 void main()
 {

    NODE s1[5];
	for(int i=1;i<5;i++)
	{
		cout<<"�������"<<i<<"��ѧ����Ϣ"<<endl;
		cout<<"ѧ��:";	cin>>s1[i].no;
		cout<<"����:"; cin>>s1[i].name;
		cout<<"�ɼ�:"; cin>>s1[i].score;
	}
	cout<<"�������ʾѧ����Ϣ:"<<endl;
	for( i=1;i<5;i++)
		 cout<<s1[i].no<<' '<<s1[i].name<<' '<<s1[i].score<<' '<<endl;
	cout<<"����ð������ʵ�ֳɼ���С��������"<<endl;
	Bubblesort(s1,5);
	for( i=1;i<5;i++)
		 cout<<s1[i].no<<' '<<s1[i].name<<' '<<s1[i].score<<' '<<endl;
	cout<<"����ֱ��ѡ������ʵ�ֳɼ��Ӵ�С����"<<endl;
	selectsort(s1,5);
	for( i=1;i<5;i++)
		 cout<<s1[i].no<<' '<<s1[i].name<<' '<<s1[i].score<<' '<<endl;
	cout<<"����ֱ�Ӳ�������ʵ�ֳɼ���С��������"<<endl;
	insertsort(s1,5);
	for( i=1;i<5;i++)
		 cout<<s1[i].no<<' '<<s1[i].name<<' '<<s1[i].score<<' '<<endl;

 }
