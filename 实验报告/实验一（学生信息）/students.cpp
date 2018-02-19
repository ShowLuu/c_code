#include <iostream.h>
#include <string>

class Student{
private:
	int age,num;
	char *name;
public:
	Student(char *name1,int age1,int num1);
    ~Student();
	void display();
};
Student::Student(char *name1,int age1,int num1)

{   name=new char[strlen(name1)+1];
    strcpy(name,name1);
	age=age1;
	num=num1;
}
void Student::display()
{   
	cout<<"输出学生信息: "<<endl;
	cout<<"name: "<<name<<endl;
    cout<<"age: "<<age<<endl;
	cout<<"num: "<<num<<endl;
}
Student::~Student()
{  
	//delete []name;
}
void main()
{   
	Student s1("lu",20,49);
    s1.display();
}