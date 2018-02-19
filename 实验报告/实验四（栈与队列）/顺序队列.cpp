#include <iostream.h>
typedef int elemtype;

const int  maxsize= 60;   

class seqqueue
{
public:
elemtype  queue[maxsize]; 			//��������Ԫ�ض�Ϊ�����ͣ�Ԫ������Ϊelemtype
int   front;             			//��ͷָ��
int   rear;             			//��βָ��
void     INIQUEUE(seqqueue &Q);			//������Q���ó�һ���ն���
void     ENQUEUE (seqqueue  &Q,int y);		//��Ԫ��X���뵽��β�У�Ҳ�ơ����ӡ��������롱
void     DLQUEUE(seqqueue &Q);			//������Q�Ķ�ͷԪ��ɾ����Ҳ�ơ��˶ӡ�����ɾ����
elemtype GETHEAD(seqqueue Q );			//�õ�����Q�Ķ�ͷԪ��ֵ֮
bool   EMPTY(seqqueue Q );	
void print(seqqueue Q);			//�ж϶���Q�Ƿ�Ϊ�գ���Ϊ�շ����棬���򷵻ؼ�
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
			  cout<<"������Ҫ��ӵ�Ԫ��: ";
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
	 cout<<"����1Ϊ���г�ʼ��"<<endl;
	 cout<<"����2Ϊ����в���Ԫ��"<<endl;
	 cout<<"����3Ϊɾ����ͷԪ��"<<endl;
	 cout<<"����4Ϊ�õ����ж�ͷԪ�ص�ֵ"<<endl;
	 cout<<"����5Ϊ�ж����Ƿ�Ϊ��"<<endl;
	 cout<<"����6Ϊ�鿴����"<<endl;
	 int q;
	 cin>>q;
	 while(q!=0)
	 {
		switch(q)
		{
		case 1: {s1.INIQUEUE(s1);}break;
		case 2: {
			int x;
			cout<<"��ѡ�����Ԫ�ظ���: ";
			cin>>x;
			s1.ENQUEUE(s1,x);}break;
		case 3: {s1.DLQUEUE(s1);}break;
		case 4: {
			cout<<"��ͷԪ��Ϊ: "<<s1.GETHEAD(s1)<<endl;}break;
		case 5: {if(s1.EMPTY(s1)==true)
					cout<<"����Ϊ��"<<endl;
				else
					cout<<"���в�Ϊ��"<<endl;}break;
		case 6: {s1.print(s1);}break;
		 default:cout<<"�������λ������"<<endl;
		}
		 cout<<"����������: ";
	     cin>>q;
	 }	

}

