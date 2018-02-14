#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdio.h>  
#include <time.h> 

using namespace std;
const int Reader=100;	//最大读者数量	
const int Maxb=100;		//最大书籍数量
const int Bor=5;		//最大借阅量

class Student
{
private:
	int tag;             //标志：0,存在，1不存在
	
	char number[30];	//读者id
	char name[30];		//读者姓名
	int flag;			//是否借书
	
	char borbook[Bor][10];	//借阅状态
public:
	
	Student()						//构造函数初始化
	{
		char *s="0";
		for(int i=0;i<Bor;i++)
		{
			strcpy(borbook[i],s);
		}
	}
	
	char *getname()		//方便之后取值
	{
		return name;
	}
	
	int gettag()		//标志：0,存在，1不存在
	{
		return tag;
	}
	int getflag()		//标志：0,在架，1在借
	{
		return flag;
	}
	char *getnumber()	//读者id
	{
		return number;
	}
	
	void setname(char *na)//读者姓名
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
	
	void addStudent(char *n,char *na)//添加读者
	{
		flag=0;
		char *num=n;
		strcpy(number,num);
		char *nas=na;
		strcpy(name,nas);
		
		//for(int i=0;i<Bor;i++)
		//{
	//		borbook[i]=NULL;	   //等于0则为在架状态
		//}
	}
	
	void borrowbook(char *bookid)//借书操作
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
	int retbook(char *bookid)//还书操作
	{		
		char *s="0";
		for(int i=0;i<Bor;i++)
		{	
			if(strcmp(borbook[i],bookid)==0)
			{
				flag=0;
				strcpy(borbook[i],s);		//等于0则为在架状态
				return 1;	
			}
		}
		return 0;
	}
	void output(int op)
	{

		//控制台读出读者信息
		if(op==1)
		{
			cout <<"读者ID："<<setw(10)<<number<<setw(6)<<"  读者姓名："<<setw(10)<<name<<setw(8)<<"  借书编号：[";		//number与name之间10个空格，在控制台显示数据
													 			
			for(int i=0;i<Bor;i++)														
				if(borbook[i][0]!='0')
					cout << borbook[i] << "|";
				
				cout << "]"<<endl;
		}
		
		//日志写入读者信息
		if(op==0)
		{
			fstream file("E://数据结构大作业//图书管理系统plus//User.txt",ios::app|ios::out);
			file <<"读者ID："<<setw(10)<<number<<setw(6)<<"  读者姓名："<<setw(10)<<name<<setw(8)<<"  借书编号：[";		//只有退出程序才会向User.txt记录结果日志
			
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
	int top; //读者记录指针，-1清空读者，新增一个读者+1

public:
	
	RData() //构造函数，将User.txt读到read[]中
	{
		top=-1;		//top初始化-1
	}
	
	int gettop()
	{
		return top;
	}
	
	void clear()
	{
		top=-1;
	}
	
	int addStudent(char *n,char *na)	//添加读者									
	{
		Student *p=equalById(n);//查找是否存在
		if (p==NULL)
		{
			top++;
			read[top].addStudent(n,na);		//真正的添加读者
			return 1;
		}
		return 0;
	}
	Student *equal(char *Studentid)		
	{
		for (int i=0;i<=top;i++)
		{	
			if ((strcmp(read[i].getnumber(),Studentid)==0) && read[i].gettag()==0)	//判断书库里是否存在读者编号,两者相等则表示存在此读者编号;
			{																		//判断书库里是否存在读者,tag==0表示该读者存在,tag==1表示读者不存在	
				return &read[i];
			}
		}	
		return NULL;		
	}
	
	Student *equalById(char *Studentid)		
	{
		for (int i=0;i<=top;i++)
		{
			if (read[i].gettag()==1)			//tag==1说明读者不存在或已删除，当删除一个读者时，使得可以再次添加相同的读者编号有效
			{
				return NULL;
			}
			if (strcmp(read[i].getnumber(),Studentid)==0)	//判断读者库里是否存在读者编号,两者相等则表示存在此读者编号
			{
				return &read[i];
			}
		}	
		return NULL;		
	}
	
	//输出时调用
	void output(int op)
	{	
		//程序输入0退出时调用，汇总所有有意义的信息，记录日志
		if(op==0)
		{
			fstream file("E://数据结构大作业//图书管理系统plus//User.txt",ios::app|ios::out);
			file<<"----------结果："<<endl;				
			for (int i=0;i<=top;i++)
			{
				
				if(read[i].gettag()==0)
				{
					read[i].output(0);		//执行op==0的方法，记录结果日志
				}	
			}
			time_t t = time(0); 
			char tmp[64]; 
			strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A",localtime(&t) ); 
			file<<"退 出 时 间：";
			file.width(3);
			file<<"<"<<tmp<<">"<<endl;
			file.close();
		}
		else
		{
			//在控制台打印，即查看操作
			for (int j=0;j<=top;j++)
			{
				if(read[j].gettag()==0)
				{
					read[j].output(1);		//不执行op==0的方法
				}	
			}
		}
		
	}
	
	void Studentdata(int op);//读者库维护
	
	void writeData(char *n,char *na,int op);	//写入日志

	int test(char *input)				//过滤输入读者编号时的中文
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

void RData::writeData(char *n,char *na,int op)	//写入日志具体方法实现
{	 
	fstream file("E://数据结构大作业//图书管理系统plus//User.txt",ios::app|ios::out);
	file<<"读者号：";
	file.width(5);
	file<<n;
	file.width(15);
	file<<"读者：";
	file.width(5);
	file<<na;
	file.width(30);
	time_t t = time(0); 
	char tmp[64]; 
	strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A",localtime(&t) ); 
	switch(op)
	{
	case 1:{file<<"新 增 时 间：";};break;
	case 2:{file<<"更 改 时 间：";};break;
	case 3:{file<<"删 除 时 间：";};break;
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
		cout<<"                     ┏━━━━━━━━━━━━━┓\n";
		cout<<"                     ┃      读 者 维 护         ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";
		cout<<"                     ┃1.新 增                   ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";
		cout<<"                     ┃2.更 改                   ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";
		cout<<"                     ┃3.删 除                   ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";
		cout<<"                     ┃4.查 找                   ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";
		cout<<"                     ┃5.显 示                   ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";
		cout<<"                     ┃6.全 删                   ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";
		cout<<"                     ┃0.退出                    ┃\n";
		cout<<"                     ┗━━━━━━━━━━━━━┛\n";
		cout<<"请输入操作数："<<endl;
		cin >> choice;
		
	if(op==0)
	{
		output(0);			//程序退出时记录结果日志，方便后续维护
	}
	else{

		switch (choice)		
		{
		case '1':
			cout << "输入读者编号:";				//读者编号唯一，读者名称可以是不唯一的，读者编号只能是数字和字母		
			cin >>Studentid;
			n=qwe.test(Studentid);
			if(n==0)
			{
				cout<<"编号不能是汉字！"<<endl;
				break;
			}
			r=equalById(Studentid);
			if(r!=NULL)
			{
				cout<<"存在此读者编号！"<<endl;
				break;
			}
			r=equal(Studentid);
			if (r!=NULL)
			{
				cout << " 存在该读者！ "<<endl;
				break;
			} 
			cout << "输入读者姓名:";
			cin >> rname;
			if(strlen(rname)>10)					//判断输入姓名长度不能大于10字节
			{
				cout<<" 读者姓名过长！"<<endl;
				break;
			}	
			addStudent (Studentid,rname);
			qwe.writeData(Studentid,rname,1);
			cout<<" 新增读者成功！"<<endl;
			break;
			
		case '2':
			cout << "输入读者编号:";
			cin >> Studentid;
			n=qwe.test(Studentid);
			if(n==0)
			{
				cout<<"编号不能是汉字！"<<endl;
				break;
			}
			r=equal(Studentid);
			
			if (r==NULL)
			{
				cout << " 该读者不存在 "<<endl;
				break;
			} 
			cout << " 输入新的姓名: ";
			cin >> rname;
			if(strlen(rname)>10)
			{
				cout<<" 读者姓名过长！"<<endl;
				break;
			}
			r->setname(rname);
			qwe.writeData(Studentid,rname,2);
			break;
			
		case '3':
			cout << " 输入读者编号:";
			cin >> Studentid;
			n=qwe.test(Studentid);
			if(n==0)
			{
				cout<<"编号不能是汉字！"<<endl;
				break;
			}
			r=equal(Studentid);
			
			if (r==NULL)
			{
				cout <<" 该读者不存在！" << endl;
				break;
			}
			if(r->getflag()==1)
			{
				cout<<"不能删！"<<endl;
				break;
			}
			r->delbook();
			cout<<" 删除成功！"<<endl;
			qwe.writeData(Studentid,rname,3);
			break;
			
		case '4':
			cout << "读入读者编号:";
			cin >> Studentid;
			r=equal(Studentid);
			if (r==NULL) 
			{
				cout <<"该读者不存在"<< endl;
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
			cout<<"退出：\n";system("cls");break;		//返回主界面
		}		
	}
	}
}

class Book
{
private:
	int tag;			//等于1不存在该书籍,等于0存在该书籍
	
	char number[20];			//图书编号
	
	char name[64];		//图书名称

	char author[64];	//作者

	char location[64];	//出版社

	char cTime[64];		//出版时间
	
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
		tag=1;			//等于1不存在该书籍
	}
	void addbook(char *n,char *na,char *au,char *loca,char *Time)		//添加图书信息
	{
		tag=0;			//等于0存在该书籍
		
		strcpy(number,n);

		strcpy(name,na);

		strcpy(author,au);

		strcpy(location,loca);
		
		strcpy(cTime,Time);
		
		onshelf=1;		//等于1为在架状态
	}
	
	int borrowbook()	//借书操作
	{
		if (onshelf==1)
		{
			onshelf=0;	//等于0为已借状态
			return 1;
		}		
		return 0;
	}
	
	void retbook()		//还书操作
	{
		onshelf=1;
	}
	
	void output(int op)		//输出图书
	{
		//在控制台输出图书信息，即查看图书信息
		if(op==1)
		{
			cout << setw(6) <<"图书编号："<<setw(10)<<number<<setw(6)<<"  图书名称："<<setw(20)<<setw(20)<<name<<setw(6)
			<<"  作者："<<setw(10)<<author<<setw(6)<<"  出版社："<<setw(10)<<location<<setw(6)<<"  出版时间："<<setw(20)<<cTime<<setw(6)
			<<(onshelf==1? "  在架":"  已借") <<endl;
		}
		
		//程序输入0退出时调用，汇总所有有意义的信息，记录日志
		if(op==0)
		{
			fstream file("E://数据结构大作业//图书管理系统plus//Book.txt",ios::app|ios::out);
			file<<setw(6) <<"图书编号："<<setw(10)<<number<<setw(6)<<"  图书名称："<<setw(20)<<name<<setw(6)
			<<"  作者："<<setw(10)<<author<<setw(6)<<"  出版社："<<setw(10)<<location<<setw(6)<<"  出版时间："<<setw(20)<<cTime<<setw(6)
			<<(onshelf==1? "在架":"已借") <<endl;
			
			file.close();
		}
	}
};

class BDatabase
{
private:
	
	int top;		 //图书数量记录
	Book book[Maxb]; //图书记录
	
public:
	BDatabase()		//构造函数，将Book.txt读到book[]中
	{
		top=-1;	
	}
	void clear()		//清除所有图书信息
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
	
	int addbook(char *n,char *na,char *au,char *loca,char *cTime)		//添加图书信息
	{
		if(top>Maxb)				//限制最大书籍不得超过规定Maxb
		{
			cout<<"馆藏已满！"<<endl;
			return 0;
		}
		Book *p=equal(n);			//判断是否有该书籍
		if (NULL==p)
		{
			top++;	
			book[top].addbook(n,na,au,loca,cTime);	//实现添加操作
			return 1;
		}	
		return 0;
	}
	
	Book *equal(char *bookid)			//根据图书编号判断是否有该书籍
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
	
	Book *equalById(char *bookid)			//判断是否有唯一的书籍编号
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

Book *opBook(char *bookid)			//当图书处于在借状态时不能删除
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
		//将结果写入日志
		if(op==0)
		{
			fstream file("E://数据结构大作业//图书管理系统plus//Book.txt",ios::app|ios::out);
			file<<"----------结果："<<endl;				
			for (int i=0;i<=top;i++)
			{
				if(book[i].gettag()==0)
				{
					book[i].output(0);		//执行op==0的方法，记录结果日志
				}	
			}
			time_t t = time(0); 
			char tmp[64]; 
			strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A",localtime(&t) ); 
			file<<"退 出 时 间：";
			file.width(3);
			file<<"<"<<tmp<<">"<<endl;
			file.close();
		}
		else
		{
			//在控制台显示图书信息，即查询操作
			for (int j=0;j<=top;j++)
			{
				if(book[j].gettag()==0)
				{
					book[j].output(1);		//不执行op==0的方法
				}	
			}
		}
	}

	void writeData(char *n,char *na,int op,char *au,char *loca,char *cTime);	//将文件从写入日志时调用的方法

	int test(char *input)			//过滤掉输入图书编号时候的中文
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

void BDatabase::writeData(char *n,char *na,int op,char *au,char *loca,char *cTime)		//写入日志
{
	fstream file("E://数据结构大作业//图书管理系统plus//Book.txt",ios::app|ios::out);
	file<<"图书编号：";
	file.width(15);
	file<<n;
	file.width(5);
    file<<"图书名称：";
    file.width(15);
	file<<"《"<<na<<"》";
	file.width(5);
	file<<"作者：";
	file.width(15);
	file<<au;
	file.width(5);
	file<<"出版社：";
	file.width(15);
	file<<loca;
	file.width(5);
	file<<"出版时间：";
	file.width(15);
	file<<cTime;
	file.width(5);
	file<<"在架";
	file.width(30);
	time_t t = time(0); 
	char tmp[64]; 
	strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A",localtime(&t) ); 
	switch(op)
	{
	case 1:{file<<"新 增 时 间：";};break;
	case 2:{file<<"更 改 时 间：";};break;
	case 3:{file<<"删 除 时 间：";};break;
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
		cout<<"                     ┏━━━━━━━━━━━━━┓\n";
		cout<<"                     ┃      图书 维 护          ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n"; 
		cout<<"                     ┃1.新 增                   ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";
		cout<<"                     ┃2.更 改                   ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";
		cout<<"                     ┃3.删 除                   ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";
		cout<<"                     ┃4.查 找                   ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";
		cout<<"                     ┃5.显 示                   ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";
		cout<<"                     ┃6.全 删                   ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";
		cout<<"                     ┃0.退出                    ┃\n";
		cout<<"                     ┗━━━━━━━━━━━━━┛\n";
		cout<<"请输入操作数："<<endl;
		cin >> choice;

	if(op==0)
	{
		output(0);			//程序退出时记录结果日志，方便后续维护
	}
	else
	{

		switch (choice)
		{			
		case '1':											//图书编号唯一，图书可以是不唯一的
			cout << " 输入图书编号: "<<endl;
			cin >> bookid;
			n=qwe.test(bookid);
			if(n==0)
			{
				cout<<"编号不能是汉字！"<<endl;
				break;
			}
			b=equalById(bookid);							//图书编号唯一
			if (b!=NULL)
			{
				cout<<" 存在此图书编号！"<<endl;
				break;
			}
			b=equal(bookid);
			if (b!=NULL)
			{
				cout << " 存在该图书！ "<<endl;
				break;
			}
			cout << " 输入图书书名: "<<endl;
			cin >> bname;
			if(strlen(bname)>64)							//限制书名长度
			{
				cout<<" 图书名称过长！"<<endl;
				break;
			}
			cout << " 输入图书作者: "<<endl;
			cin >> bauthor;
			if(strlen(bauthor)>64)							//限制书名长度
			{
				cout<<" 作者姓名过长！"<<endl;
				break;
			}

			cout << " 输入图书出版社: "<<endl;
			cin >> blocation;
			if(strlen(blocation)>64)							//限制书名长度
			{
				cout<<" 出版社名称过长！"<<endl;
				break;
			}

			cout << " 输入图书出版时间: "<<endl;
			cin >> bcTime;
			 
			addbook(bookid,bname,bauthor,blocation,bcTime);
			writeData(bookid,bname,1,bauthor,blocation,bcTime);
			cout<<"新增成功！"<<endl;
			//output(1);
			break;
			
		case '2':			
			cout << "输入图书编号:"<<endl;
			cin >> bookid;
			n=qwe.test(bookid);
			if(n==0)
			{
				cout<<"编号不能是汉字！"<<endl;
				break;
			}
			b=equal(bookid);
			if (b==NULL)
			{
				cout << " 该图书不存在 "<<endl;
				break;
			}

			b=opBook(bookid);
			if(b==NULL)
			{
				cout <<" 该图书处于在借状态，不能修改！" <<endl;
				break;
			}
			
			cout << "输入新的书名:"<<endl;
			cin >> bname;
			if(strlen(bname)>40)
			{
				cout<<"读者姓名过长！"<<endl;
				break;
			}
			b->setname(bname);
			cout << "输入新的作者:"<<endl;
			cin >> bauthor;
			if(strlen(bauthor)>10)
			{
				cout<<"作者姓名过长！"<<endl;
				break;
			}
			b->setauthor(bauthor);
			cout << "输入新的出版社:"<<endl;
			cin >> blocation;
			if(strlen(blocation)>64)
			{
				cout<<"出版社名称过长！"<<endl;
				break;
			}
			b->setlocation(blocation);
			cout << "输入新的出版时间:"<<endl;
			cin >> bcTime;
			b->setcTime(bcTime);
			qwe.writeData(bookid,bname,2,bauthor,blocation,bcTime);
			break;
			
		case '3':	
			cout <<" 读入图书编号:"<<endl;
			cin >> bookid;
			n=qwe.test(bookid);
			if(n==0)
			{
				cout<<"编号不能是汉字！"<<endl;
				break;
			}
			b=equal(bookid);
		
			if (b==NULL)
			{
				cout <<" 该图书不存在" <<endl;
				break;
			}	
			b=opBook(bookid);
			if(b==NULL)
			{
				cout <<" 该图书处于在借状态，不能删除！" <<endl;
				break;
			}
			else
			{
				b->delbook();
				cout<<" 删除成功！"<<endl;
				qwe.writeData(bookid,bname,3,bauthor,blocation,bcTime);
				break;
			}
			
			
		case '4':
			/*
			cout<<"输入1按图书编号精确查找"<<endl;
			cout<<"输入2按图书名称查找"<<endl;
			cout<<"输入3按作者查找"<<endl;
			int op;
			cout<<"请输入操作数："<<endl;
			cin>>op;
			qwe.findBook(op);
			*/
			cout <<" 读入图书编号:"<<endl;
			cin >> bookid;
			n=qwe.test(bookid);
			if(n==0)
			{
				cout<<"编号不能是汉字！"<<endl;
				break;
			}
			b=equal(bookid);
		
			if (b==NULL)
			{
				cout <<" 该图书不存在" <<endl;
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
			cout<<"退出\n"; system("cls"); break;
		}
	}	
	}
}

void main()			//主方法，调用以上所有
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
		
		cout<<"                     ┏━━━━━━━━━━━━━┓\n";
		cout<<"                     ┃      图 书 管 理 系 统   ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";
		cout<<"                     ┃1.借书                    ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";
		cout<<"                     ┃2.还书                    ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";
		cout<<"                     ┃3.图书维护                ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";
		cout<<"                     ┃4.读者维护                ┃\n";
		cout<<"                     ┃━━━━━━━━━━━━━┃\n";    
		cout<<"                     ┃0.退出                    ┃\n";
		cout<<"                     ┗━━━━━━━━━━━━━┛\n";
		
		cout<<"请输入操作数："<<endl;
		cin >> choice;
		
		switch (choice)
			
		{
			
		case '1': system("cls");
			cout <<" 借书\n 读者编号:";
			cin >>Studentid;
			r=StudentDB.equal(Studentid);//按编号查找
			if (NULL==r)
			{
				cout <<" 不存在该读者，不能借书"<< endl;
				break;
			}
			cout <<" 图书编号： ";
			cin >>bookid;
			b=BookDB.equal(bookid); 
			
			if (b==NULL)		
			{	
				cout <<" 不存在该图书，不能借书"<< endl;
				break;
			}
			
			if (b->borrowbook()==0)
			{	
				cout << " 该图书已借出，不能借书"<< endl;
				break;
			}
			
			r->borrowbook(b->getnumber());
			system("cls");
			break;
			
		case '2':
			system("cls");
			
			cout<<" 还书\n 读者编号:";
		
			r=StudentDB.equal(Studentid);
			
			cin >>Studentid;
			
			if (r==NULL)
			{
				cout <<" 不存在该读者，不能还书" << endl;
				break;
			}
			cout << " 图书编号:";
			
			cin >>bookid;
			
			b=BookDB.equal(bookid);
			
			if (b==NULL)	
			{
				cout <<" 不存在该图书，不能还书" <<endl;
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
			cout<<"退出\n";		
		}
}
}
