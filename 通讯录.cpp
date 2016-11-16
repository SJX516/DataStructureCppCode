#include<iostream>
#include<string>
using namespace std;

class personNode
{
public:
	string name;
	string phone;
	string email;
	personNode* next;
	personNode()
	{
		next = NULL;
	}
	void print()
	{
		cout << "name is " << name << endl << "phone is " << phone << endl << "email is " << email << endl << endl;
	}
	~personNode(){}

};

class name{
public:
	char na;
	personNode* head;
	name()
	{
		head = NULL;
	}
	~name(){}
	void print()
	{
		personNode* tmp = head;
		while (tmp != NULL)
		{
			tmp->print();
			tmp = tmp->next;
		}
	}
	void add(string name, string phone, string email)
	{
		personNode* tmp = head;
		if (head == NULL){
			head = new personNode;
			head->name = name;
			head->phone = phone;
			head->email = email;
			return;
		}
		while (tmp->next != NULL){
			//tmp->print();
			tmp = tmp->next;
		}
		tmp->next = new personNode;
		tmp = tmp->next;
		tmp->name = name;
		tmp->phone = phone;
		tmp->email = email;
	}
	void del(string name)
	{
		personNode* tmp = head;
		if (tmp == NULL)
		{
			cout<<"找不到无法删除1";
			return;
		}
        else if (tmp->name == name)
        {
			head = tmp->next;
			return;
		}
		while (tmp->next != NULL)
		{
			if (tmp->next->name == name){
				tmp->next = tmp->next->next;
				return;
			}
			tmp = tmp->next;
		}
		cout << "找不到无法删除2";

	}
	personNode* search(string name)
	{
		personNode* tmp = head;
		while (tmp != NULL){
			if (tmp->name == name){
				return tmp;
			}
			tmp = tmp->next;
		}
		return NULL;
	}

};

class tongxunlu
{
public:
	name  na[26];
	void add()
	{
		string name, phone, email;
		cout << "依次输入姓名 电话 email" << endl;
		cin >> name >> phone >> email;
		na[(name[0] - 'a')].add(name, phone, email);
	}
	void del()
	{
		string name;
		cout << "输入查找姓名 " << endl;
		cin >> name;
		na[(name[0] - 'a')].del(name);
	}
	void printname()
	{
		char c;
		cout << "输入查找的姓 " << endl;
		cin >> c;
		na[c - 'a'].print();
	}
	void print()
	{
		for (int i = 0; i < 26; i++)
		{
			na[i].print();
		}
	}


};

int main(){
	tongxunlu txl;
	int num;
	while (1){
		cout << "1:增加一个人  "<<endl<<endl<<"2:删除一个人  "<<endl<<endl<<"3:按照姓输出人员 "<<endl<<endl<<"4:输出所有信息 "<<endl<<endl<<"5:退出" <<endl<<endl;
		cin >> num;
		if (num == 1)
			txl.add();
		if (num == 2)
			txl.del();
		if (num == 3)
			txl.printname();
		if (num == 4)
			txl.print();
		if (num == 5)
			break;
		cout << endl;
		//system("cls");

	}


}

