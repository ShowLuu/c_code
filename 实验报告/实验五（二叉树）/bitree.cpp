#include<iostream.h>
typedef char elemtype;
 int jieDian=0;
class  bitree
{  public:
  
   elemtype data;
   bitree *lchild,*rchild;
   bitree *creat();
   void preorder(bitree  *root);
   void preorder1(bitree  *root);
   void inorder(bitree  *root);
   void inorder1(bitree  *root);
   void postorder(bitree *root);
   void postorder1(bitree *root);
   int LeafNodes(bitree *b);
   int depth(bitree  *root);
};
bitree *bitree::creat()
{  
   bitree *q[100]; 	//����q������Ϊ���У���Ŷ��������еĽ�㣬100Ϊ�������
   bitree *s;   			//���������еĽ��
   bitree *root ;   		//��������ĸ�ָ�� 
   int front=1,rear=0;     	//������е�ͷ��βָ��
   char ch;            	//����data��ֵ
   root=NULL;  
   cin>>ch;
   while(ch!='#')     	//����ֵΪ#�ţ��㷨����
   { s=NULL;
    if(ch!=',')       		//�������ݲ�Ϊ���ţ���ʾ��Ϊ���㣬����Ϊ����
      { s=new bitree;
         s->data=ch;
         s->lchild=NULL;
         s->rchild=NULL;      }
      rear++;      q[rear]=s;    			
      if(rear==1) root=s;      else
      { if((s!=NULL)&&(q[front]!=NULL))	
               {  if(rear%2==0)  q[front]->lchild=s;  	
                  else q[front]->rchild=s;}            
       if(rear%2==1) front++;                			
      }      cin>>ch;}
	return root;
}

void bitree::preorder(bitree  *root)
{   
  bitree  *p;
  p=root;
  if(p!=NULL)
{cout<<p->data<<"  ";
  preorder(p->lchild);
  preorder (p->rchild);
  jieDian++;
}
  
}

void bitree::preorder1(bitree *root)
{ bitree *p,*s[100];   
  int top=0; 	
  p=root;
  while((p!=NULL)||(top>0))
  {       while(p!=NULL)
            {cout<<p->data<<"  ";
             s[++top]=p;           
             p=p->lchild;           
            }
    p=s[top--];                  		
    p=p->rchild;                	
  } 
}

void bitree::inorder(bitree  *root)
{   bitree   *p;
  p=root;
  if (p!=NULL)
{   inorder(p->lchild);
    cout<<p->data<<"  ";
    inorder(p->rchild);
}
}

void bitree::inorder1( bitree *root)
{ bitree *p,*s[100];    			//sΪһ��ջ��topΪջ��ָ��
  int top=0;
  p=root;
  while((p!=NULL)||(top>0)) 
  {   
	  while(p!=NULL)
  {
	  s[++top]=p;          			//��ջ
      p=p->lchild;}         			//����������
  {
	  p=s[top--];             		//��ջ
      cout<<p->data<<"  ";
      p=p->rchild;             		//����������
  }
  }
}

void bitree::postorder(bitree *root)
{
	bitree *p;
	p=root;
	if(p!=NULL)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		cout<<p->data<<"  ";
	}
}
 
void bitree::postorder1(bitree *root)
{
	bitree *p,*s1[100];
	int s2[100],top=0,b;
	p=root;
	do
	{
		while(p!=NULL)
		{
			s1[top]=p;
			s2[top++]=0;
			p=p->lchild;
		}
		if(top>0)
		{
			b=s2[--top];
			p=s1[top];
			if(b==0)
			{
				s1[top]=p;
				s2[top++]=1;
				p=p->rchild;
			}
			else
			{
				cout<<p->data<<"  ";
				p=NULL;
			}
		}
	}
	while(top>0);
}

int bitree::LeafNodes(bitree *b)
{
	int num1,num2;
	if(b==NULL)
		return 0;
	else if(b->lchild==NULL&&b->rchild==NULL)
		return 1;
	else
	{
		num1=LeafNodes(b->lchild);
		num2=LeafNodes(b->rchild);
		return (num1+num2);
	}

}

int bitree::depth(bitree  *root)
{
	if(root==NULL)
		return 0;
	else
	{
		int dep1=depth(root->lchild);
		int dep2=depth(root->rchild);
		if(dep1>dep2)
			return dep1+1;
		else
			return dep2+1;
	}
}

void main()
{
	bitree b,*res;

	cout<<"����������: ";
	res=b.creat();
	
	cout<<"ǰ�������Ľ��Ϊ: ";
	b.preorder(res);
	cout<<'\n';
	cout<<"����"<<jieDian<<"�����"<<endl;
	cout<<"Ҷ�ӽ����Ϊ: "<<b.LeafNodes(res)<<endl;
	cout<<"Ҷ�����Ϊ: "<<b.depth(res)<<endl;
	

	cout<<"ǰ���ǵݹ�����Ľ��Ϊ: ";
	b.preorder1(res);
	cout<<'\n';

	cout<<"�и������Ľ��Ϊ: ";
	b.inorder(res);
	cout<<'\n';

	cout<<"�и��ǵݹ�����Ľ��Ϊ: ";
	b.inorder1(res);
	cout<<'\n';

	cout<<"��������Ľ��Ϊ: ";
	b.postorder(res);
	cout<<'\n';

	cout<<"����ǵݹ�����Ľ��Ϊ: ";
	b.postorder1(res);
	cout<<'\n';

}