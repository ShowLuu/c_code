#include <iostream.h>
const  int  maxsize=10;
typedef int elemtype;

class  sequenlist
{
 public:
   elemtype  a[maxsize];    	//��ʾ���Ա�(a1,a2,��,an,aMaxlen), elemtype��ʾĳ�־�����������
   int       len;            			//len��ʾ���Ա��ʵ�ʳ���  
 public:
   int length(sequenlist L );   			//��˳���L�ĳ���
   void Insert(sequenlist &L,elemtype x,int i);//��Ԫ��x����˳���L��i��λ��
   void Dele(sequenlist &L , int  i) ; //ɾ��˳���L��i��λ�õ�Ԫ��
   void setnull(sequenlist &L );      //˳���L�ÿձ�
   int Locate(sequenlist  L , elemtype  x) ; //��λ��˳���L�в���Ԫ��x��λ��
   elemtype Get(sequenlist  L , int i);      //ȡ˳���L�е�i��λ�õ�Ԫ��
   elemtype prior(sequenlist  L , elemtype  x );	   //˳���L����Ԫ��x��ǰ��
   elemtype next(sequenlist  L , elemtype  x );    //˳���L����Ԫ��x�ĺ��
   void prin(sequenlist  L);//������Ա��е�Ԫ��
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
                      L.a[j-1]=L.a[j];                            	//Ԫ��ǰ��
               L.len--;                                   	//���ȼ�1
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

void sequenlist ::prin(sequenlist  L)//��ʾ�����Ա����Ԫ��
{
	cout<<"���Ա��Ԫ��Ϊ��";
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
				L.a[j+1]=L.a[j];          		//Ԫ�غ���
			 L.a[i]=x;               		//����Ԫ��
			 L.len++;               		//��������1
		}
}

void main()
{
	int i;
	sequenlist rj1;
    rj1.setnull(rj1);
	int t;
	cout<<"*************��������1Ϊ����˳���***********************"<<endl;
	cout<<"*************��������2Ϊ��ʾ���Ա�ĳ��ȣ�*****************"<<endl;
	cout<<"*************��������3Ϊ����һ��Ԫ�ص����Ա�*************"<<endl;
	cout<<"*************��������4Ϊɾ��һ��Ԫ�ص����Ա�*************"<<endl;
	cout<<"*************��������5Ϊ�������Ա���ĳ��Ԫ�ص�λ�ã�*******"<<endl;
	cout<<"*************��������6Ϊȡ��һ��λ�õ�Ԫ�أ�*************"<<endl;
	cout<<"*************��������7Ϊ�鿴ĳ��Ԫ�ص�ǰ����*******"<<endl;
	cout<<"*************��������8Ϊ�鿴ĳ��Ԫ�صĺ�̣�*******"<<endl;
	cout<<"*************��������9Ϊ�ñ��***************************"<<endl;
    cout<<"*************��������0Ϊ��������***************************"<<endl;
	cout<<"�������������";
	cin>>t;

   while(t!=0)
   {
	   switch(t)
	   {case 1:
	   {	
		   int x;
		   cout<<"���뼸������: "<<endl;
		   cin>>x;
		   for( i=1;i<=x;i++)//Ϊ���ݸ�Ԫ�أ�
			{
				cout<<"�������: "<<i<<"��Ԫ�أ�";
				cin>>rj1.a[i];
				rj1.len++;
				cout<<endl;
			}
				rj1.prin(rj1);
	   }//������Ա�
			break;

	   case 2:
		   { cout<<"���Ա�ĳ���Ϊ: "<<rj1.length(rj1) <<endl;}// 3����˳���ĳ���
           	break;
	   case 3:
		   { int x,j;
			 cout<<"���������Ԫ�ص�ֵ: ";
			 cin>>x;
			 cout<<"����������λ��: ";
			 cin>>j;
			 rj1.Insert(rj1,x,j); 
			 rj1.prin(rj1);}
             break;
	   case 4:
		   { int j;
			   cout<<"������ɾ����λ��: ";
			cin>>j;
			rj1.Dele(rj1,j);
			rj1.prin(rj1);}
            break;
	   case 5:
		   {int x;
			   cout<<"������Ҫ���ҵ�Ԫ�ص�ֵ: ";
			 cin>>x;
			 cout<<"�����ҵ�Ԫ�ص�λ����: "<<rj1.Locate(rj1, x)<<endl; }
			 break;
	   case 6:
		   { int x;
			 cout<<"������ȡ��Ԫ�ص�λ��: ";
			 cin>>x;
			 cout<<"Ԫ����: "<<rj1.Get(rj1,x)<<endl;}
             break;
		case 7:
		   { int x;
			 cout<<"������鿴�ĸ�Ԫ�ص�ǰ��: ";
			 cin>>x;
			 cout<<"��Ԫ�ص�ǰ��Ϊ: "<<rj1.prior(rj1,x)<<endl;}
             break;
		case 8:
		   { int x;
			 cout<<"������鿴�ĸ�Ԫ�صĺ�̣�";
			 cin>>x;
			 cout<<"��Ԫ�صĺ��Ϊ: "<<rj1.next(rj1,x)<<endl;}
             break;
		case 9:
		   { 
			 cout<<"�ñ��---";
			 rj1.setnull(rj1);}
             break;
		  
	   default:cout<<"�������λ������";
		       
	   }
	   cout<<"���������֣�";
	   cin>>t;
   }
                                 



}