#include <iostream.h>
const   int  n=10;				//nΪ�����󳤶�
typedef struct    node
{
int   key;			//keyΪ�ؼ��֣������趨Ϊelemtype
}NODE;

void Insert(node R[n+1],int x,int i)//��Ԫ��x����˳���R��i��λ��
{ 
	int j;
	if ((i<1)||(i>6)) 
            cout<<"position is not correct!"<<endl;
		else
		{
			 for(j=n;j>=i;j--)
				R[j+1]=R[j];          		//Ԫ�غ���
			 R[i].key=x;               		//����Ԫ��
			 i++;               		//��������1
		}

}
void Dele(node R[n+1] , int  i) //ɾ��˳���L��i��λ�õ�Ԫ��
{ int j;
   if((i<1)||(i>n))
        cout<<" position is not correct!"<<endl;
        else {
               for(j=i+1;j<=n;j++)
                      R[j-1]=R[j];                            	//Ԫ��ǰ��
               
            }
}

/*void Insert(node R[n+1],int x,int i)//��Ԫ��x����˳���L��i��λ��
{ 
	for(int j=n;j>=i;j--)
		R[j+1]=R[j];          		//Ԫ�غ���
			R[i].=x;               		//����Ԫ��
			 
		}
}

   void Dele(node R[n+1] , int  i) //ɾ��˳���L��i��λ�õ�Ԫ��
{ int j;
   if((i<1)||(i>n))
        cout<<" position is not correct!"<<endl;
        else {
               for(j=i+1;j<=n;j++)
                      R[j-1]=R[j];                            	//Ԫ��ǰ��
               
            }
}*/



int  seqsearch (node  R[n+1],int k) //˳�����	//�ڱ�R�в��ҹؼ���ֵΪk��Ԫ��
{
R[0].key=k; int i=n;             				//�ӱ�β��ʼ��ǰɨ��
while(R[i].key!=k)    i--;
return i;
}

int    binsearch(node    R[n+1],    int   k)//���ֲ����㷨ʵ��
{      int     low=1,     high=n;
 while(low<=high)
{     int  mid=(low +high)/2;          		//ȡ�����е�
if(R[mid].key==k)
   return    mid;      					//���ҳɹ�
else if(R[mid].key>k)
        high=mid-1;                 			//�����������в���
        else    low=mid+1;                			//�����������в���
}
return    0;                 				//����ʧ��
}
void main()
{
NODE s1[5];
for(int i=1;i<5;i++)
{
	cout<<"�������"<<i<<"����"<<endl;
	cin>>s1[i].key;
}
	cout<<"���������Ϊ��"<<endl;
	for( i=1;i<5;i++)
		 cout<<s1[i].key<<endl;
	cout<<"��40���뵽2��λ��"<<endl;
Insert(s1,40,2);
for( i=1;i<6;i++)
	cout<<s1[i].key<<endl;
cout<<"��4��λ�õ���ɾ��"<<endl;
Dele(s1,4);
for( i=1;i<5;i++)
	cout<<s1[i].key<<endl;
cout<<"�۰����90�Ľ��Ϊ��"<<binsearch(s1,90)<<endl;
cout<<"˳�����80�Ľ��Ϊ��"<<seqsearch(s1,80)<<endl;



}