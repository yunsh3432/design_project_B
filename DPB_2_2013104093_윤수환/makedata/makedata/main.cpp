#include<fstream>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct MusicAlbum
{
	int id;
	string name;
	int composerId;
	int purchasedCount;
};

struct composer
{
	int id;
	string name;
};

struct User
{
	int id;
	string password;
	int size;
	vector<int> purcahsedList;
	
};


int main()
{
	//user
	ofstream fsOut("User.dat",ios::binary | ios::out);
	User* user;
	user = new User;
	User* curuser = user;
	
	curuser->id = 1;
	curuser->password = "user1";
	int pwsize = (curuser->password).size();
	curuser->size = 0;
	
	fsOut.write((char*)&(curuser->id),sizeof(int));
	fsOut.write((char*)&pwsize,sizeof(int));
	fsOut.write((curuser->password).c_str(),(curuser->password).size());
	fsOut.write((char*)&(curuser->size),sizeof(int));//user1 �� ���� �����Է�

	curuser->id = 2;
	curuser->password = "user2";
	pwsize = (curuser->password).size();
	curuser->size = 1;
	(curuser->purcahsedList).clear();
	(curuser->purcahsedList).push_back(1);
	
	fsOut.write((char*)&(curuser->id),sizeof(int));
	fsOut.write((char*)&pwsize,sizeof(int));
	fsOut.write((curuser->password).c_str(),(curuser->password).size());
	fsOut.write((char*)&(curuser->size),sizeof(int));
	for(int i = 0;i < (curuser->purcahsedList).size(); i++)
	{
		fsOut.write((char*)&(curuser->purcahsedList[i]),sizeof(int));
	}//user2 �� ���� �����Է�


	curuser->id = 3;
	curuser->password = "user3";
	pwsize = (curuser->password).size();
	curuser->size = 5;
	(curuser->purcahsedList).clear();
	(curuser->purcahsedList).push_back(1);
	(curuser->purcahsedList).push_back(3);
	(curuser->purcahsedList).push_back(4);
	(curuser->purcahsedList).push_back(2);
	(curuser->purcahsedList).push_back(5);
	
		fsOut.write((char*)&(curuser->id),sizeof(int));
	fsOut.write((char*)&pwsize,sizeof(int));
	fsOut.write((curuser->password).c_str(),(curuser->password).size());
	fsOut.write((char*)&(curuser->size),sizeof(int));
	for(int i = 0;i < (curuser->purcahsedList).size(); i++)
	{
		fsOut.write((char*)&(curuser->purcahsedList[i]),sizeof(int));
	}//user3 �� ���� �����Է�


	curuser->id = 4;
	curuser->password = "user4";
	pwsize = (curuser->password).size();
	curuser->size = 2;
	(curuser->purcahsedList).clear();
	(curuser->purcahsedList).push_back(1);
	(curuser->purcahsedList).push_back(3);

	fsOut.write((char*)&(curuser->id),sizeof(int));
	fsOut.write((char*)&pwsize,sizeof(int));
	fsOut.write((curuser->password).c_str(),(curuser->password).size());
	fsOut.write((char*)&(curuser->size),sizeof(int));
	for(int i = 0;i < (curuser->purcahsedList).size(); i++)
	{
		fsOut.write((char*)&(curuser->purcahsedList[i]),sizeof(int));
	}//user4 �� ���� �����Է�


	curuser->id = 5;
	curuser->password = "user5";
	pwsize = (curuser->password).size();
	curuser->size = 3;
	(curuser->purcahsedList).clear();
	(curuser->purcahsedList).push_back(1);
	(curuser->purcahsedList).push_back(3);
	(curuser->purcahsedList).push_back(5);
	
	fsOut.write((char*)&(curuser->id),sizeof(int));
	fsOut.write((char*)&pwsize,sizeof(int));
	fsOut.write((curuser->password).c_str(),(curuser->password).size());
	fsOut.write((char*)&(curuser->size),sizeof(int));
	for(int i = 0;i < (curuser->purcahsedList).size(); i++)
	{
		fsOut.write((char*)&(curuser->purcahsedList[i]),sizeof(int));
	}//user5 �� ���� �����Է�

	fsOut.close();

	//composer
	ofstream fsOut1("composer.dat",ios::binary | ios::out);
	composer com;

	com.id = 1;
	com.name = "����";
	int namesize = (com.name).size();
	fsOut1.write((char*)&(com.id),sizeof(int));
	fsOut1.write((char*)&namesize,sizeof(int));
	fsOut1.write((com.name).c_str(),(com.name).size());//composer1 �����Է�
	
	com.id = 2;
	com.name = "������";
	namesize = (com.name).size();
	fsOut1.write((char*)&(com.id),sizeof(int));
	fsOut1.write((char*)&namesize,sizeof(int));
	fsOut1.write((com.name).c_str(),(com.name).size());//composer2 �����Է�
	
	com.id = 3;
	com.name = "I.O.I";
	namesize = (com.name).size();
	fsOut1.write((char*)&(com.id),sizeof(int));
	fsOut1.write((char*)&namesize,sizeof(int));
	fsOut1.write((com.name).c_str(),(com.name).size());//composer3 �����Է�
	
	com.id = 4;
	com.name = "������";
	namesize = (com.name).size();
	fsOut1.write((char*)&(com.id),sizeof(int));
	fsOut1.write((char*)&namesize,sizeof(int));
	fsOut1.write((com.name).c_str(),(com.name).size());//composer4 �����Է�
	
	com.id = 5;
	com.name = "The one";
	namesize = (com.name).size();
	fsOut1.write((char*)&(com.id),sizeof(int));
	fsOut1.write((char*)&namesize,sizeof(int));
	fsOut1.write((com.name).c_str(),(com.name).size());//composer5 �����Է�

	fsOut1.close();

	//MusicAlbum
	ofstream fsOut2("MusicAlbum.dat", ios::binary | ios::out);
	
	MusicAlbum MA;

	MA.id = 1;
	MA.name = "���Ѱ���";
	int Anamesize = (MA.name).size();
	MA.composerId = 1;
	MA.purchasedCount = 4;
	fsOut2.write((char*)&(MA.id),sizeof(int));
	fsOut2.write((char*)&Anamesize,sizeof(int));
	fsOut2.write((MA.name).c_str(),Anamesize);
	fsOut2.write((char*)&(MA.composerId),sizeof(int));
	fsOut2.write((char*)&(MA.purchasedCount),sizeof(int));

	MA.id = 2;
	MA.name = "���ϸ��ϱ�ٷ�";
	Anamesize = (MA.name).size();
	MA.composerId = 2;
	MA.purchasedCount = 1;
	fsOut2.write((char*)&(MA.id),sizeof(int));
	fsOut2.write((char*)&Anamesize,sizeof(int));
	fsOut2.write((MA.name).c_str(),Anamesize);
	fsOut2.write((char*)&(MA.composerId),sizeof(int));
	fsOut2.write((char*)&(MA.purchasedCount),sizeof(int));

	MA.id = 3;
	MA.name = "�ʹ��ʹ��ʹ�";
	Anamesize = (MA.name).size();
	MA.composerId = 3;
	MA.purchasedCount = 3;
	fsOut2.write((char*)&(MA.id),sizeof(int));
	fsOut2.write((char*)&Anamesize,sizeof(int));
	fsOut2.write((MA.name).c_str(),Anamesize);
	fsOut2.write((char*)&(MA.composerId),sizeof(int));
	fsOut2.write((char*)&(MA.purchasedCount),sizeof(int));

	MA.id = 4;
	MA.name = "���³���";
	Anamesize = (MA.name).size();
	MA.composerId = 4;
	MA.purchasedCount = 1;
	fsOut2.write((char*)&(MA.id),sizeof(int));
	fsOut2.write((char*)&Anamesize,sizeof(int));
	fsOut2.write((MA.name).c_str(),Anamesize);
	fsOut2.write((char*)&(MA.composerId),sizeof(int));
	fsOut2.write((char*)&(MA.purchasedCount),sizeof(int));

	MA.id = 5;
	MA.name = "����";
	Anamesize = (MA.name).size();
	MA.composerId = 5;
	MA.purchasedCount = 2;
	fsOut2.write((char*)&(MA.id),sizeof(int));
	fsOut2.write((char*)&Anamesize,sizeof(int));
	fsOut2.write((MA.name).c_str(),Anamesize);
	fsOut2.write((char*)&(MA.composerId),sizeof(int));
	fsOut2.write((char*)&(MA.purchasedCount),sizeof(int));

	fsOut2.close();
}