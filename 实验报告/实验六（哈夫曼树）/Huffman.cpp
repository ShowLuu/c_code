#include <iostream.h>

const  int     n=8;      		    		//n��ʾҶ����Ŀ
const  int    m= 2*n-1 ;  
  			//mΪɭ�������Ŀ���
class  tree
{ public:
float weight;      					//Ȩֵ
int  parent;       					//˫��
int  lch,rch;      					//���Һ���
void creathuffmantree( );
}; 
tree  hftree[m+1]; 

void tree::creathuffmantree( )
{ int  i,j ,p1,p2;
float s1,s2;
for(i=1;i<=m;i++)
{hftree[i].parent=0;
hftree[i].lch=0;
hftree[i].rch=0;
hftree[i].weight-=0;
}
cout<<"����Ȩֵ: "<<endl;
for(i=1;i<=n;i++)
cin>>hftree[i].weight;  				//����Ȩֵ
for(i=n+1;i<=m;i++)      				//����n-1�κϲ�
{ 
p1=p2=0;             				// p1,p2�ֱ�ָ������Ȩ��С��ֵ��λ��
s1=s2=32767;             			// s1,s2 ����������СȨֵ
for(j=1;j<=i-1;j++)          			//ѡ������Сֵ
if(hftree[j].parent==0)        			//��Ȩֵ��û�б�ѡ��
if(hftree[j].weight<s1)
{s2=s1;
s1=hftree[j].weight;
p2=p1;
p1=j;
}
else
if(hftree[j].weight<s2)
{s2=hftree[j].weight;
p2=j;
}
hftree[p1].parent=i;
hftree[p2].parent=i;
hftree[i].lch=p1;
hftree[i].rch=p2;
hftree[i].weight=hftree[p1].weight+hftree[p2].weight;
}

cout<<"����ϲ���Ľ��: "<<endl;
for(i=1;i<=m;i++){
if(i==m)
{
	cout<<"��������Ϊ: "<<" "<<hftree[i].weight<<" "<<hftree[i].parent<<" "<<hftree[i].lch<<" "<<hftree[i].rch<<endl;
	break;
}  					//����ϲ���Ľ��
cout<<"��"<<i<<"��: "<<" "<<hftree[i].weight<<" "<<hftree[i].parent<<" "<<hftree[i].lch<<" "<<hftree[i].rch<<endl;
}
}



void main()
{  tree t;
  


	cout<<"          ��ӭ���ԣ�������   "<<endl;
	cout<<"----------���Կ�ʼ-----------"<<endl;
	cout<<"���ȵ��ù�����������ĺ�����huffman"<<endl;
	cout<<"���±�˳������Ҷ�ӵ�Ȩ��:"<<endl;
	cout<<" 0  1  2  3  4  5  6  7  "<<endl;
	t.creathuffmantree();
	


}
