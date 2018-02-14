#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdio.h>  
#include <time.h> 

using namespace std;
const int Reader=100;	//����������	
const int Maxb=100;		//����鼮����
const int Bor=5;		//��������

class Student
{
private:
	int tag;             //��־��0,���ڣ�1������
	
	char number[30];	//����id
	char name[30];		//��������
	int flag;			//�Ƿ����
	
	char borbook[Bor][10];	//����״̬
public:
	
	Student()						//���캯����ʼ��
	{
		char *s="0";
		for(int i=0;i<Bor;i++)
		{
			strcpy(borbook[i],s);
		}
	}
	
	char *getname()		//����֮��ȡֵ
	{
		return name;
	}
	
	int gettag()		//��־��0,���ڣ�1������
	{
		return tag;
	}
	int getflag()		//��־��0,�ڼܣ�1�ڽ�
	{
		return flag;
	}
	char *getnumber()	//����id
	{
		return number;
	}
	
	void setname(char *na)//��������
	{
		strcpy(name,na);		
	}

	void setnumber(char *num)
	{
		strcpy(number,num);		
	}
	
	void delbook()
	{
		tag=1;
	}
	
	void addStudent(char *n,char *na)//��Ӷ���
	{
		flag=0;
		char *num=n;
		strcpy(number,num);
		char *nas=na;
		strcpy(name,nas);
		
		//for(int i=0;i<Bor;i++)
		//{
	//		borbook[i]=NULL;	   //����0��Ϊ�ڼ�״̬
		//}
	}
	
	void borrowbook(char *bookid)//�������
	{
		for(int i=0;i<Bor;i++)
		{			
			if (borbook[i][0]=='0')			
			{  
				flag=1;
				strcpy(borbook[i],bookid);
				return;
			}
		}
		
	}
	int retbook(char *bookid)//�������
	{		
		char *s="0";
		for(int i=0;i<Bor;i++)
		{	
			if(strcmp(borbook[i],bookid)==0)
			{
				flag=0;
				strcpy(borbook[i],s);		//����0��Ϊ�ڼ�״̬
				return 1;	
			}
		}
		return 0;
	}
	void output(int op)
	{

		//����̨����������Ϣ
		if(op==1)
		{
			cout <<"����ID��"<<setw(10)<<number<<setw(6)<<"  ����������"<<setw(10)<<name<<setw(8)<<"  �����ţ�[";		//number��name֮��10���ո��ڿ���̨��ʾ����
													 			
			for(int i=0;i<Bor;i++)														
				if(borbook[i][0]!='0')
					cout << borbook[i] << "|";
				
				cout << "]"<<endl;
		}
		
		//��־д�������Ϣ
		if(op==0)
		{
			fstream file("E://���ݽṹ����ҵ//ͼ�����ϵͳplus//User.txt",ios::app|ios::out);
			file <<"����ID��"<<setw(10)<<number<<setw(6)<<"  ����������"<<setw(10)<<name<<setw(8)<<"  �����ţ�[";		//ֻ���˳�����Ż���User.txt��¼�����־
			
			for(int j=0;j<Bor;j++)
				if(borbook[j][0]!='0')
					
				file << borbook[j] << "|";
				
				file << "]"<<endl;
				
			file.close();
		}
	}

};
Student read[Reader];
class RData
{
private:
	int top; //���߼�¼ָ�룬-1��ն��ߣ�����һ������+1

public:
	
	RData() //���캯������User.txt����read[]��
	{
		top=-1;		//top��ʼ��-1
	}
	
	int gettop()
	{
		return top;
	}
	
	void clear()
	{
		top=-1;
	}
	
	int addStudent(char *n,char *na)	//��Ӷ���									
	{
		Student *p=equalById(n);//�����Ƿ����
		if (p==NULL)
		{
			top++;
			read[top].addStudent(n,na);		//��������Ӷ���
			return 1;
		}
		return 0;
	}
	Student *equal(char *Studentid)		
	{
		for (int i=0;i<=top;i++)
		{	
			if ((strcmp(read[i].getnumber(),Studentid)==0) && read[i].gettag()==0)	//�ж�������Ƿ���ڶ��߱��,����������ʾ���ڴ˶��߱��;
			{																		//�ж�������Ƿ���ڶ���,tag==0��ʾ�ö��ߴ���,tag==1��ʾ���߲�����	
				return &read[i];
			}
		}	
		return NULL;		
	}
	
	Student *equalById(char *Studentid)		
	{
		for (int i=0;i<=top;i++)
		{
			if (read[i].gettag()==1)			//tag==1˵�����߲����ڻ���ɾ������ɾ��һ������ʱ��ʹ�ÿ����ٴ������ͬ�Ķ��߱����Ч
			{
				return NULL;
			}
			if (strcmp(read[i].getnumber(),Studentid)==0)	//�ж϶��߿����Ƿ���ڶ��߱��,����������ʾ���ڴ˶��߱��
			{
				return &read[i];
			}
		}	
		return NULL;		
	}
	
	//���ʱ����
	void output(int op)
	{	
		//��������0�˳�ʱ���ã������������������Ϣ����¼��־
		if(op==0)
		{
			fstream file("E://���ݽṹ����ҵ//ͼ�����ϵͳplus//User.txt",ios::app|ios::out);
			file<<"----------�����"<<endl;				
			for (int i=0;i<=top;i++)
			{
				
				if(read[i].gettag()==0)
				{
					read[i].output(0);		//ִ��op==0�ķ�������¼�����־
				}	
			}
			time_t t = time(0); 
			char tmp[64]; 
			strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A",localtime(&t) ); 
			file<<"�� �� ʱ �䣺";
			file.width(3);
			file<<"<"<<tmp<<">"<<endl;
			file.close();
		}
		else
		{
			//�ڿ���̨��ӡ�����鿴����
			for (int j=0;j<=top;j++)
			{
				if(read[j].gettag()==0)
				{
					read[j].output(1);		//��ִ��op==0�ķ���
				}	
			}
		}
		
	}
	
	void Studentdata(int op);//���߿�ά��
	
	void writeData(char *n,char *na,int op);	//д����־

	int test(char *input)				//����������߱��ʱ������
	{

		int len=strlen(input);
		for(int i=0;i<len;i++)
		{
			char c=input[i];
			if((c>=48 && c<=58)||(c>=65 && c<=90)||(c>=97 && c<=122))
			{ 
				if(i==len-1)
				{
					return 1;
				}
				continue;
			}
			break;	
		}
		return 0;
	}
	
};

void RData::writeData(char *n,char *na,int op)	//д����־���巽��ʵ��
{	 
	fstream file("E://���ݽṹ����ҵ//ͼ�����ϵͳplus//User.txt",ios::app|ios::out);
	file<<"���ߺţ�";
	file.width(5);
	file<<n;
	file.width(15);
	file<<"���ߣ�";
	file.width(5);
	file<<na;
	file.width(30);
	time_t t = time(0); 
	char tmp[64]; 
	strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A",localtime(&t) ); 
	switch(op)
	{
	case 1:{file<<"�� �� ʱ �䣺";};break;
	case 2:{file<<"�� �� ʱ �䣺";};break;
	case 3:{file<<"ɾ �� ʱ �䣺";};break;
	}
	file.width(3);
	file<<"<"<<tmp<<">"<<endl;
	file.close();
}

void RData::Studentdata(int op)
{
	RData qwe;
	char choice;
	char rname[30];
	char Studentid[30];
	Student *r;
	int n;
	while (choice!='0')
	{	
		cout<<"                     ������������������������������\n";
		cout<<"                     ��      �� �� ά ��         ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"                     ��1.�� ��                   ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"                     ��2.�� ��                   ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"                     ��3.ɾ ��                   ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"                     ��4.�� ��                   ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"                     ��5.�� ʾ                   ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"                     ��6.ȫ ɾ                   ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"                     ��0.�˳�                    ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"�������������"<<endl;
		cin >> choice;
		
	if(op==0)
	{
		output(0);			//�����˳�ʱ��¼�����־���������ά��
	}
	else{

		switch (choice)		
		{
		case '1':
			cout << "������߱��:";				//���߱��Ψһ���������ƿ����ǲ�Ψһ�ģ����߱��ֻ�������ֺ���ĸ		
			cin >>Studentid;
			n=qwe.test(Studentid);
			if(n==0)
			{
				cout<<"��Ų����Ǻ��֣�"<<endl;
				break;
			}
			r=equalById(Studentid);
			if(r!=NULL)
			{
				cout<<"���ڴ˶��߱�ţ�"<<endl;
				break;
			}
			r=equal(Studentid);
			if (r!=NULL)
			{
				cout << " ���ڸö��ߣ� "<<endl;
				break;
			} 
			cout << "�����������:";
			cin >> rname;
			if(strlen(rname)>10)					//�ж������������Ȳ��ܴ���10�ֽ�
			{
				cout<<" ��������������"<<endl;
				break;
			}	
			addStudent (Studentid,rname);
			qwe.writeData(Studentid,rname,1);
			cout<<" �������߳ɹ���"<<endl;
			break;
			
		case '2':
			cout << "������߱��:";
			cin >> Studentid;
			n=qwe.test(Studentid);
			if(n==0)
			{
				cout<<"��Ų����Ǻ��֣�"<<endl;
				break;
			}
			r=equal(Studentid);
			
			if (r==NULL)
			{
				cout << " �ö��߲����� "<<endl;
				break;
			} 
			cout << " �����µ�����: ";
			cin >> rname;
			if(strlen(rname)>10)
			{
				cout<<" ��������������"<<endl;
				break;
			}
			r->setname(rname);
			qwe.writeData(Studentid,rname,2);
			break;
			
		case '3':
			cout << " ������߱��:";
			cin >> Studentid;
			n=qwe.test(Studentid);
			if(n==0)
			{
				cout<<"��Ų����Ǻ��֣�"<<endl;
				break;
			}
			r=equal(Studentid);
			
			if (r==NULL)
			{
				cout <<" �ö��߲����ڣ�" << endl;
				break;
			}
			if(r->getflag()==1)
			{
				cout<<"����ɾ��"<<endl;
				break;
			}
			r->delbook();
			cout<<" ɾ���ɹ���"<<endl;
			qwe.writeData(Studentid,rname,3);
			break;
			
		case '4':
			cout << "������߱��:";
			cin >> Studentid;
			r=equal(Studentid);
			if (r==NULL) 
			{
				cout <<"�ö��߲�����"<< endl;
				break;
			}
			r->output(1);
			break;
			
		case '5':
			output(1);
			break;
			
		case '6':
			clear();
			break;
		default:							
			cout<<"�˳���\n";system("cls");break;		//����������
		}		
	}
	}
}

class Book
{
private:
	int tag;			//����1�����ڸ��鼮,����0���ڸ��鼮
	
	char number[20];			//ͼ����
	
	char name[64];		//ͼ������

	char author[64];	//����

	char location[64];	//������

	char cTime[64];		//����ʱ��
	
	int onshelf;
	
public:
    Book(){}
	
    char *getname()
	{
		return name;
	}
	char *getauthor()
	{
		return author;
	}
	char *getlocation()
	{
		return location;
	}
	char *getcTime()
	{
		return cTime;
	}
    char *getnumber()
	{
		return number;
	}
    int gettag()
	{
		return tag;
	}
	int getonshelf()
	{
		return onshelf;
	}
	void setnumber(char na[])
	{
		strcpy(number,na);
	}
	void setname(char na[])
	{
		strcpy(name,na);
	}
	void setlocation(char na[])
	{
		strcpy(location,na);
	}
	void setauthor(char na[])
	{
		strcpy(author,na);
	}
	void setcTime(char na[])
	{
		strcpy(cTime,na);
	}
	void delbook()
	{
		tag=1;			//����1�����ڸ��鼮
	}
	void addbook(char *n,char *na,char *au,char *loca,char *Time)		//���ͼ����Ϣ
	{
		tag=0;			//����0���ڸ��鼮
		
		strcpy(number,n);

		strcpy(name,na);

		strcpy(author,au);

		strcpy(location,loca);
		
		strcpy(cTime,Time);
		
		onshelf=1;		//����1Ϊ�ڼ�״̬
	}
	
	int borrowbook()	//�������
	{
		if (onshelf==1)
		{
			onshelf=0;	//����0Ϊ�ѽ�״̬
			return 1;
		}		
		return 0;
	}
	
	void retbook()		//�������
	{
		onshelf=1;
	}
	
	void output(int op)		//���ͼ��
	{
		//�ڿ���̨���ͼ����Ϣ�����鿴ͼ����Ϣ
		if(op==1)
		{
			cout << setw(6) <<"ͼ���ţ�"<<setw(10)<<number<<setw(6)<<"  ͼ�����ƣ�"<<setw(20)<<setw(20)<<name<<setw(6)
			<<"  ���ߣ�"<<setw(10)<<author<<setw(6)<<"  �����磺"<<setw(10)<<location<<setw(6)<<"  ����ʱ�䣺"<<setw(20)<<cTime<<setw(6)
			<<(onshelf==1? "  �ڼ�":"  �ѽ�") <<endl;
		}
		
		//��������0�˳�ʱ���ã������������������Ϣ����¼��־
		if(op==0)
		{
			fstream file("E://���ݽṹ����ҵ//ͼ�����ϵͳplus//Book.txt",ios::app|ios::out);
			file<<setw(6) <<"ͼ���ţ�"<<setw(10)<<number<<setw(6)<<"  ͼ�����ƣ�"<<setw(20)<<name<<setw(6)
			<<"  ���ߣ�"<<setw(10)<<author<<setw(6)<<"  �����磺"<<setw(10)<<location<<setw(6)<<"  ����ʱ�䣺"<<setw(20)<<cTime<<setw(6)
			<<(onshelf==1? "�ڼ�":"�ѽ�") <<endl;
			
			file.close();
		}
	}
};

class BDatabase
{
private:
	
	int top;		 //ͼ��������¼
	Book book[Maxb]; //ͼ���¼
	
public:
	BDatabase()		//���캯������Book.txt����book[]��
	{
		top=-1;	
	}
	void clear()		//�������ͼ����Ϣ
	{
		for (int i=0;i<=top;i++)
		{	
			if (book[i].gettag()==0 && book[i].getonshelf()==1)		
			{
				book[i].delbook();
			}
		}
		//top=-1;
	}
	
	int addbook(char *n,char *na,char *au,char *loca,char *cTime)		//���ͼ����Ϣ
	{
		if(top>Maxb)				//��������鼮���ó����涨Maxb
		{
			cout<<"�ݲ�������"<<endl;
			return 0;
		}
		Book *p=equal(n);			//�ж��Ƿ��и��鼮
		if (NULL==p)
		{
			top++;	
			book[top].addbook(n,na,au,loca,cTime);	//ʵ����Ӳ���
			return 1;
		}	
		return 0;
	}
	
	Book *equal(char *bookid)			//����ͼ�����ж��Ƿ��и��鼮
	{
		for (int i=0;i<=top;i++)
		{	
			if ((strcmp(book[i].getnumber(),bookid)==0) && book[i].gettag()==0)
			{
				return &book[i];
			}
		}
		return NULL;
	}
	
	Book *equalById(char *bookid)			//�ж��Ƿ���Ψһ���鼮���
	{
		for (int i=0;i<=top;i++)
		{	
			if (book[i].gettag()==1)
			{
				return NULL;
			}
			if ((strcmp(book[i].getnumber(),bookid)==0))
			{
				return &book[i];
			}
		}
		return NULL;
	}

void bookdata(int op);

Book *opBook(char *bookid)			//��ͼ�鴦���ڽ�״̬ʱ����ɾ��
	{
		for (int i=0;i<=top;i++)
		{			
			if ((strcmp(book[i].getnumber(),bookid)==0) && book[i].gettag()==0 && book[i].getonshelf()==1)
			{
				return &book[i];
			}
		}
		return NULL;
	}
	
	void output(int op)
	{
		//�����д����־
		if(op==0)
		{
			fstream file("E://���ݽṹ����ҵ//ͼ�����ϵͳplus//Book.txt",ios::app|ios::out);
			file<<"----------�����"<<endl;				
			for (int i=0;i<=top;i++)
			{
				if(book[i].gettag()==0)
				{
					book[i].output(0);		//ִ��op==0�ķ�������¼�����־
				}	
			}
			time_t t = time(0); 
			char tmp[64]; 
			strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A",localtime(&t) ); 
			file<<"�� �� ʱ �䣺";
			file.width(3);
			file<<"<"<<tmp<<">"<<endl;
			file.close();
		}
		else
		{
			//�ڿ���̨��ʾͼ����Ϣ������ѯ����
			for (int j=0;j<=top;j++)
			{
				if(book[j].gettag()==0)
				{
					book[j].output(1);		//��ִ��op==0�ķ���
				}	
			}
		}
	}

	void writeData(char *n,char *na,int op,char *au,char *loca,char *cTime);	//���ļ���д����־ʱ���õķ���

	int test(char *input)			//���˵�����ͼ����ʱ�������
	{
		int len=strlen(input);
		for(int i=0;i<len;i++)
		{
			char c=input[i];
		if((c>=48 && c<=58)||(c>=65 && c<=90)||(c>=97 && c<=122))
		{ 
			if(i==len-1)
			{
				return 1;
			}
			continue;
		}
			break;	
		}
		return 0;
	}
};

void BDatabase::writeData(char *n,char *na,int op,char *au,char *loca,char *cTime)		//д����־
{
	fstream file("E://���ݽṹ����ҵ//ͼ�����ϵͳplus//Book.txt",ios::app|ios::out);
	file<<"ͼ���ţ�";
	file.width(15);
	file<<n;
	file.width(5);
    file<<"ͼ�����ƣ�";
    file.width(15);
	file<<"��"<<na<<"��";
	file.width(5);
	file<<"���ߣ�";
	file.width(15);
	file<<au;
	file.width(5);
	file<<"�����磺";
	file.width(15);
	file<<loca;
	file.width(5);
	file<<"����ʱ�䣺";
	file.width(15);
	file<<cTime;
	file.width(5);
	file<<"�ڼ�";
	file.width(30);
	time_t t = time(0); 
	char tmp[64]; 
	strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A",localtime(&t) ); 
	switch(op)
	{
	case 1:{file<<"�� �� ʱ �䣺";};break;
	case 2:{file<<"�� �� ʱ �䣺";};break;
	case 3:{file<<"ɾ �� ʱ �䣺";};break;
	}
	file.width(3);
	file<<"<"<<tmp<<">"<<endl;
	file.close();
}

void BDatabase::bookdata(int op)
{
	BDatabase qwe;
	char choice;
	
	char bname[64];

	char bauthor[64];

	char blocation[64];

	char bcTime[64];
	
	char bookid[64];

	int n;
	
	Book *b;
	
	while (choice!='0')
	{	
		cout<<"                     ������������������������������\n";
		cout<<"                     ��      ͼ�� ά ��          ��\n";
		cout<<"                     ������������������������������\n"; 
		cout<<"                     ��1.�� ��                   ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"                     ��2.�� ��                   ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"                     ��3.ɾ ��                   ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"                     ��4.�� ��                   ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"                     ��5.�� ʾ                   ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"                     ��6.ȫ ɾ                   ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"                     ��0.�˳�                    ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"�������������"<<endl;
		cin >> choice;

	if(op==0)
	{
		output(0);			//�����˳�ʱ��¼�����־���������ά��
	}
	else
	{

		switch (choice)
		{			
		case '1':											//ͼ����Ψһ��ͼ������ǲ�Ψһ��
			cout << " ����ͼ����: "<<endl;
			cin >> bookid;
			n=qwe.test(bookid);
			if(n==0)
			{
				cout<<"��Ų����Ǻ��֣�"<<endl;
				break;
			}
			b=equalById(bookid);							//ͼ����Ψһ
			if (b!=NULL)
			{
				cout<<" ���ڴ�ͼ���ţ�"<<endl;
				break;
			}
			b=equal(bookid);
			if (b!=NULL)
			{
				cout << " ���ڸ�ͼ�飡 "<<endl;
				break;
			}
			cout << " ����ͼ������: "<<endl;
			cin >> bname;
			if(strlen(bname)>64)							//������������
			{
				cout<<" ͼ�����ƹ�����"<<endl;
				break;
			}
			cout << " ����ͼ������: "<<endl;
			cin >> bauthor;
			if(strlen(bauthor)>64)							//������������
			{
				cout<<" ��������������"<<endl;
				break;
			}

			cout << " ����ͼ�������: "<<endl;
			cin >> blocation;
			if(strlen(blocation)>64)							//������������
			{
				cout<<" ���������ƹ�����"<<endl;
				break;
			}

			cout << " ����ͼ�����ʱ��: "<<endl;
			cin >> bcTime;
			 
			addbook(bookid,bname,bauthor,blocation,bcTime);
			writeData(bookid,bname,1,bauthor,blocation,bcTime);
			cout<<"�����ɹ���"<<endl;
			//output(1);
			break;
			
		case '2':			
			cout << "����ͼ����:"<<endl;
			cin >> bookid;
			n=qwe.test(bookid);
			if(n==0)
			{
				cout<<"��Ų����Ǻ��֣�"<<endl;
				break;
			}
			b=equal(bookid);
			if (b==NULL)
			{
				cout << " ��ͼ�鲻���� "<<endl;
				break;
			}

			b=opBook(bookid);
			if(b==NULL)
			{
				cout <<" ��ͼ�鴦���ڽ�״̬�������޸ģ�" <<endl;
				break;
			}
			
			cout << "�����µ�����:"<<endl;
			cin >> bname;
			if(strlen(bname)>40)
			{
				cout<<"��������������"<<endl;
				break;
			}
			b->setname(bname);
			cout << "�����µ�����:"<<endl;
			cin >> bauthor;
			if(strlen(bauthor)>10)
			{
				cout<<"��������������"<<endl;
				break;
			}
			b->setauthor(bauthor);
			cout << "�����µĳ�����:"<<endl;
			cin >> blocation;
			if(strlen(blocation)>64)
			{
				cout<<"���������ƹ�����"<<endl;
				break;
			}
			b->setlocation(blocation);
			cout << "�����µĳ���ʱ��:"<<endl;
			cin >> bcTime;
			b->setcTime(bcTime);
			qwe.writeData(bookid,bname,2,bauthor,blocation,bcTime);
			break;
			
		case '3':	
			cout <<" ����ͼ����:"<<endl;
			cin >> bookid;
			n=qwe.test(bookid);
			if(n==0)
			{
				cout<<"��Ų����Ǻ��֣�"<<endl;
				break;
			}
			b=equal(bookid);
		
			if (b==NULL)
			{
				cout <<" ��ͼ�鲻����" <<endl;
				break;
			}	
			b=opBook(bookid);
			if(b==NULL)
			{
				cout <<" ��ͼ�鴦���ڽ�״̬������ɾ����" <<endl;
				break;
			}
			else
			{
				b->delbook();
				cout<<" ɾ���ɹ���"<<endl;
				qwe.writeData(bookid,bname,3,bauthor,blocation,bcTime);
				break;
			}
			
			
		case '4':
			/*
			cout<<"����1��ͼ���ž�ȷ����"<<endl;
			cout<<"����2��ͼ�����Ʋ���"<<endl;
			cout<<"����3�����߲���"<<endl;
			int op;
			cout<<"�������������"<<endl;
			cin>>op;
			qwe.findBook(op);
			*/
			cout <<" ����ͼ����:"<<endl;
			cin >> bookid;
			n=qwe.test(bookid);
			if(n==0)
			{
				cout<<"��Ų����Ǻ��֣�"<<endl;
				break;
			}
			b=equal(bookid);
		
			if (b==NULL)
			{
				cout <<" ��ͼ�鲻����" <<endl;
				break;
			}	
			b->output(1);
			break;
			
		case '5':	
			output(1);
			break;
			
		case '6':
			clear();
			break;	
		default:
			cout<<"�˳�\n"; system("cls"); break;
		}
	}	
	}
}

void main()			//��������������������
{
	
	char choice;
	
	char bookid[20];

	char Studentid[10];
	
	RData StudentDB;
	
	Student *r;
	
	BDatabase BookDB;
	
	Book *b;
	
	while(choice!='0')
		
	{
		
		cout<<"                     ������������������������������\n";
		cout<<"                     ��      ͼ �� �� �� ϵ ͳ   ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"                     ��1.����                    ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"                     ��2.����                    ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"                     ��3.ͼ��ά��                ��\n";
		cout<<"                     ������������������������������\n";
		cout<<"                     ��4.����ά��                ��\n";
		cout<<"                     ������������������������������\n";    
		cout<<"                     ��0.�˳�                    ��\n";
		cout<<"                     ������������������������������\n";
		
		cout<<"�������������"<<endl;
		cin >> choice;
		
		switch (choice)
			
		{
			
		case '1': system("cls");
			cout <<" ����\n ���߱��:";
			cin >>Studentid;
			r=StudentDB.equal(Studentid);//����Ų���
			if (NULL==r)
			{
				cout <<" �����ڸö��ߣ����ܽ���"<< endl;
				break;
			}
			cout <<" ͼ���ţ� ";
			cin >>bookid;
			b=BookDB.equal(bookid); 
			
			if (b==NULL)		
			{	
				cout <<" �����ڸ�ͼ�飬���ܽ���"<< endl;
				break;
			}
			
			if (b->borrowbook()==0)
			{	
				cout << " ��ͼ���ѽ�������ܽ���"<< endl;
				break;
			}
			
			r->borrowbook(b->getnumber());
			system("cls");
			break;
			
		case '2':
			system("cls");
			
			cout<<" ����\n ���߱��:";
		
			r=StudentDB.equal(Studentid);
			
			cin >>Studentid;
			
			if (r==NULL)
			{
				cout <<" �����ڸö��ߣ����ܻ���" << endl;
				break;
			}
			cout << " ͼ����:";
			
			cin >>bookid;
			
			b=BookDB.equal(bookid);
			
			if (b==NULL)	
			{
				cout <<" �����ڸ�ͼ�飬���ܻ���" <<endl;
				break;
			}
			b->retbook();
			
			r->retbook(b->getnumber());
			break;
			
		case '3':
			system("cls");	
			BookDB.bookdata(1);
			break;
			
		case '4':
			system("cls");
			StudentDB.Studentdata(1);
			break;
			
		default:
			system("cls");
			StudentDB.Studentdata(0);
			system("cls");	
			BookDB.bookdata(0);
			cout<<"�˳�\n";		
		}
}
}
