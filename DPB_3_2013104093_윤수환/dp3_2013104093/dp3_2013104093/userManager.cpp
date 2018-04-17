#include"userManager.h"
#include<fstream>
#include<vector>
#include<iostream>

using namespace std;

UserManager::UserManager()
{
	ifstream fsIn("User.dat",ios::binary | ios::in);

	fsIn.seekg(0, ios::end);
	int filesize = fsIn.tellg();
	fsIn.seekg(0 , ios::beg);

	
	while(1)
	{
		int data = 0;
		fsIn.read((char*)&data,sizeof(int));
		int pwsize = 0;
		fsIn.read((char*)&pwsize,sizeof(int));
		string pw = "";
		pw.resize(pwsize);
		fsIn.read(&pw[0],pwsize);
		int Alsize = 0;
		fsIn.read((char*)&Alsize,sizeof(int));
		vector<int> PulnumList;
		PulnumList.clear();
		for(int i = 0; i < Alsize; i++)
		{
			int Pulnum = 0;
			fsIn.read((char*)&Pulnum,sizeof(int));
			PulnumList.push_back(Pulnum);
		}
		User tempUser(data, pw, PulnumList);
		userList.push_back(tempUser);

		

		if(fsIn.tellg() >= filesize)
		{
			break;
		}
	}
	fsIn.close();
}

UserManager::~UserManager()
{
	
	ofstream fsOut("User.dat",ios::binary | ios::out);
	int _id;
	int _pwsize;
	string _pw;
	int purnum;
	vector<int> temppurcahsedList;

	for(int i = 0; i < userList.size();i++)
	{
		_id = userList[i].getId();
		_pw = userList[i].getpw();
		_pwsize = _pw.size();
		temppurcahsedList = userList[i].getpurcahsedList();
		purnum = temppurcahsedList.size();

		fsOut.write((char*)&_id,sizeof(int));
		fsOut.write((char*)&_pwsize,sizeof(int));
		fsOut.write(_pw.c_str(),_pw.size());
		fsOut.write((char*)&purnum,sizeof(int));
		for(int j = 0; j < purnum; j++)
		{
			fsOut.write((char*)& temppurcahsedList[j],sizeof(int));
		}

	}

	fsOut.close();

	//파괴자에서 user.dat최신화를 위해 다시 write함
}

bool UserManager::addUserToFile(User addedUser)
{
	userList.push_back(addedUser);
	return true;
}

bool UserManager::authenticateUser(int _id, string _pw)
{
	for(int i = 0; i < userList.size(); i++)
	{
		if(userList[i].getId() == _id && userList[i].getpw() == _pw)
		{
			return true;
		}
	}
	return false;
}

vector<int> UserManager::getPurchasedListByUserId(int _id)
{
	for(int i = 0; i < userList.size(); i++)
	{
		if(userList[i].getId() == _id)
		{
			return userList[i].getpurcahsedList();
		}
	}
	cout << "없는 아이디 입니다." << endl;
}

vector<User> UserManager::getAllUserList()
{
	return userList;
}

bool UserManager::addAlbumIdToPurchaseList(int _userId, int _albumId)
{
	for(int i = 0; i < userList.size(); i++)
	{
		if(userList[i].getId() == _userId)
		{
			userList[i].addPurcahsedList(_albumId);
			return true;
		}
	}
	return false;
}