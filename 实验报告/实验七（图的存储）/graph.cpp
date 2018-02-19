#include <iostream.h>
const  int  n=8;			// ͼ�ж�����  
const  int  e=10;			// ͼ�б���
typedef int elemtype;
bool visited[n+1];
		
class  graph
{  
public:
elemtype v[n+1]; 	// ��Ŷ�����Ϣv1,v2,��,vn����ʹ��v[0]�洢�ռ�
int   arcs[n+1][n+1];			// �ڽӾ���
void creatadj1(graph  &g);  //����ͼ
void creatadj2(graph  &g);  //����ͼ
void creatadj3(graph  &g);  //������
void creatadj4(graph  &g);	//������
void dfs (graph g,int i); 
void bfs (graph g,int i); 

void print(graph  &g)     ;             	// ��Ա����˵��������
};

//��������ͼ���ڽӾ���
void graph::creatadj1(graph  &g)
{ int i, j,k ;
cout<<"�����붥����Ϣ";
for(k=1; k<=n; k++){
  cin>>g.v[k];     
}
for (i=1; i<=n;  i++ )
  for (j=1; j<=n; j++)
   g.arcs[i][j]=0;    
  cout<<"�����붥�����Ϣ" ; 
for (k=1; k<=e; k++)
{  cin>>i>>j;                 		
   g.arcs[i][j]=1;
   g.arcs[j][i]=1;
}
}

//��������ͼ���ڽӾ���
void  graph::creatadj2(graph  &g)
{ int i, j,k ;
cout<<"�����붥����Ϣ";
  for(k=1; k<=n; k++)
  cin>>g.v[k];                        	//���붥����Ϣ   
for (i=1; i<=n;  i++ )
  for (j=1; j<=n; j++)
   g.arcs[i][j]=0;
  cout<<"�����붥�����Ϣ" ; 
for (k=1; k<=e; k++)
{ cin>>i>>j;                        	//����һ����<i,j> 
   g.arcs[i][j]=1;
}
}

//�������������ڽӾ���
void  graph::creatadj3(graph  &g)
{ int i, j,k ;
   float   w;
   cout<<"�����붥����Ϣ";
  for(k=1; k<=n; k++)
  cin>>g.v[k];                          	//���붥����Ϣ   
for (i=1; i<=n;i++ )
  for (j=1; j<=n; j++)
   if (i==j) g.arcs[i][j]=0;
   else      g.arcs[i][j]=8;  	//�޴�����i�Ͷ���j�ޱߣ��ϻ�ʱ������һ���ܴ��������(8)
 cout<<"�����붥�����Ϣ" ; 
   for (k=1; k<=e; k++)
{ cin>>i>>j>>w;                  			//����һ����(i,j) ��Ȩֵw 
   g.arcs[i][j]=w;
   g.arcs[j][i]=w;
}
}

//�������������ڽӾ���
void  graph::creatadj4(graph  &g)
{ 
int i, j,k ;
float   w;
cout<<"�����붥����Ϣ";
for(k=1; k<=n; k++)
cin>>g.v[k];                            	//���붥����Ϣ   
for (i=1; i<=n;  i++ )
  for (j=1; j<=n; j++)
   if (i==j) g.arcs[i][j]=0;
   else   
   g.arcs[i][j]=8;
 cout<<"�����붥�����Ϣ" ; 
   for (k=1; k<=e; k++)      				//����e���߼�Ȩֵ
{
 cin>>i>>j>>w;          				//����һ����<i,j> ��Ȩֵw
 g.arcs[i][j]=w;
}
}


void graph::print(graph  &g)
{
	for(int i=1;i<=n;i++)
	{ for(int j=1;j<=n;j++)
		cout<<g.arcs[i][j]<<"  ";
		cout<<endl;
    }

}

void graph::dfs (graph g,int i)     	//�Ӷ���i ����ʵ�����������������
     {       
	 int j;       
     cout<<g.v[i]<<' ';            		//������ʶ���
     visited[i]=true;   		 	//ȫ��������ʱ����1��ʾ�Ѿ�����
     for(j=1; j<=n; j++)
     if ((g.arcs[i][j]==1)&&(!visited[j]))
     dfs(g,j);
    } 

void  graph::bfs(graph g, int  i) 	//�Ӷ���i����ʵ��ͼ�Ĺ��������������
{ int  q[n+1] ;         			//qΪ����
  int  f,r,j ;        				//f��r�ֱ�Ϊ����ͷ��βָ��
  f=r=0 ;           				//���ÿն���
 cout<<g.v[i]<<' ';        			//������ʶ���
 visited[i]=true ;         			//ȫ����������true��ʾ�Ѿ�����
 r++; q[r]=i ;          			//�����
 while (f<r)
  { f++; i=q[f] ;       			//������
for (j=1; j<=n; j++)
 if ((g.arcs[i][j]==1)&&(!visited[j]))
  {  cout<<g.v[j]<<" " ;
     visited[j]=true ;
     r++; q[r]=j ;
}
 }
} 


void main()
{
	graph g;
	g.creatadj3(g);

	for(int i=1;i<=n;i++) visited[i]=false;
	cout<<"��ȱ������Ϊ: ";
	g.dfs(g,1);  
	cout<<endl;
	for(int j=1;j<=n;j++) visited[j]=false;
	cout<<"��ȱ������Ϊ: ";
	g.bfs(g,1);
	cout<<endl;
	g.print(g);
	cout<<endl;

}

