#include <iostream.h>
const  int  n=8;			// 图中顶点数  
const  int  e=10;			// 图中边数
typedef int elemtype;
bool visited[n+1];
		
class  graph
{  
public:
elemtype v[n+1]; 	// 存放顶点信息v1,v2,…,vn，不使用v[0]存储空间
int   arcs[n+1][n+1];			// 邻接矩阵
void creatadj1(graph  &g);  //无向图
void creatadj2(graph  &g);  //有向图
void creatadj3(graph  &g);  //无向网
void creatadj4(graph  &g);	//有向网
void dfs (graph g,int i); 
void bfs (graph g,int i); 

void print(graph  &g)     ;             	// 成员函数说明及定义
};

//建立无向图的邻接矩阵
void graph::creatadj1(graph  &g)
{ int i, j,k ;
cout<<"请输入顶点信息";
for(k=1; k<=n; k++){
  cin>>g.v[k];     
}
for (i=1; i<=n;  i++ )
  for (j=1; j<=n; j++)
   g.arcs[i][j]=0;    
  cout<<"请输入顶点对信息" ; 
for (k=1; k<=e; k++)
{  cin>>i>>j;                 		
   g.arcs[i][j]=1;
   g.arcs[j][i]=1;
}
}

//建立有向图的邻接矩阵
void  graph::creatadj2(graph  &g)
{ int i, j,k ;
cout<<"请输入顶点信息";
  for(k=1; k<=n; k++)
  cin>>g.v[k];                        	//输入顶点信息   
for (i=1; i<=n;  i++ )
  for (j=1; j<=n; j++)
   g.arcs[i][j]=0;
  cout<<"请输入顶点对信息" ; 
for (k=1; k<=e; k++)
{ cin>>i>>j;                        	//输入一条弧<i,j> 
   g.arcs[i][j]=1;
}
}

//建立无向网的邻接矩阵
void  graph::creatadj3(graph  &g)
{ int i, j,k ;
   float   w;
   cout<<"请输入顶点信息";
  for(k=1; k<=n; k++)
  cin>>g.v[k];                          	//输入顶点信息   
for (i=1; i<=n;i++ )
  for (j=1; j<=n; j++)
   if (i==j) g.arcs[i][j]=0;
   else      g.arcs[i][j]=8;  	//∞代表顶点i和顶点j无边，上机时可以用一个很大的数代替(8)
 cout<<"请输入顶点对信息" ; 
   for (k=1; k<=e; k++)
{ cin>>i>>j>>w;                  			//输入一条边(i,j) 及权值w 
   g.arcs[i][j]=w;
   g.arcs[j][i]=w;
}
}

//建立有向网的邻接矩阵
void  graph::creatadj4(graph  &g)
{ 
int i, j,k ;
float   w;
cout<<"请输入顶点信息";
for(k=1; k<=n; k++)
cin>>g.v[k];                            	//输入顶点信息   
for (i=1; i<=n;  i++ )
  for (j=1; j<=n; j++)
   if (i==j) g.arcs[i][j]=0;
   else   
   g.arcs[i][j]=8;
 cout<<"请输入顶点对信息" ; 
   for (k=1; k<=e; k++)      				//输入e条边及权值
{
 cin>>i>>j>>w;          				//输入一条弧<i,j> 及权值w
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

void graph::dfs (graph g,int i)     	//从顶点i 出发实现深度优先搜索遍历
     {       
	 int j;       
     cout<<g.v[i]<<' ';            		//输出访问顶点
     visited[i]=true;   		 	//全局数组访问标记置1表示已经访问
     for(j=1; j<=n; j++)
     if ((g.arcs[i][j]==1)&&(!visited[j]))
     dfs(g,j);
    } 

void  graph::bfs(graph g, int  i) 	//从顶点i出发实现图的广度优先搜索遍历
{ int  q[n+1] ;         			//q为队列
  int  f,r,j ;        				//f、r分别为队列头、尾指针
  f=r=0 ;           				//设置空队列
 cout<<g.v[i]<<' ';        			//输出访问顶点
 visited[i]=true ;         			//全局数组标记置true表示已经访问
 r++; q[r]=i ;          			//入队列
 while (f<r)
  { f++; i=q[f] ;       			//出队列
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
	cout<<"深度遍历结果为: ";
	g.dfs(g,1);  
	cout<<endl;
	for(int j=1;j<=n;j++) visited[j]=false;
	cout<<"广度遍历结果为: ";
	g.bfs(g,1);
	cout<<endl;
	g.print(g);
	cout<<endl;

}

