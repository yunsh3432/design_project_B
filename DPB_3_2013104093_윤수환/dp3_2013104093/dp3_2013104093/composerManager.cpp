#include"composerManager.h"
#include<string>
#include<iostream>

using namespace std;

ComposerManager::ComposerManager()
{
	ifstream fsIn("Composer.dat",ios::binary|ios::in);

	fsIn.seekg(0, ios::end);
	int filesize = fsIn.tellg();
	fsIn.seekg(0 , ios::beg);

	while(1)
	{
		int data = 0;
		fsIn.read((char*)&data,sizeof(int));
		int namesize = 0;
		fsIn.read((char*)&namesize,sizeof(int));
		string name  = "";
		name.resize(namesize);
		fsIn.read(&name[0],namesize);
		
		Composer tempComposer(data, name);
		composerList.push_back(tempComposer);

		if(fsIn.tellg() >= filesize)
		{
			break;
		}
	}
	fsIn.close();
}

ComposerManager::~ComposerManager()
{
	
}

bool ComposerManager::addComposerToFile(Composer addedComposer)
{
	composerList.push_back(addedComposer);

	ofstream fsOut("composer.dat",ios::binary|ios::in);

	int tempid = addedComposer.getid();
	string tempname = addedComposer.getname();
	int tempnamesize = tempname.size();
	

	fsOut.seekp(0,ios::end);
	

	fsOut.write((char*)&tempid,sizeof(int));
	fsOut.write((char*)&tempnamesize,sizeof(int));
	fsOut.write(tempname.c_str(),tempname.size());
	

	fsOut.close();

	return true;
}

Composer ComposerManager::searchComposerByName(string _name)
{
	for( int i = 0; i < composerList.size(); i++)
	{
		if(composerList[i].getname() == _name)
		{
			return composerList[i];
		}
		else
		{
			cout << "없는 이름입니다." << endl;

		}
	}
}

Composer ComposerManager::searchComposerById(int _id)
{
	for( int i = 0; i < composerList.size(); i++)
	{
		if(composerList[i].getid() == _id)
		{
			return composerList[i];
		}
		else
		{
			cout << "없는 아이디입니다." << endl;
			
		}
	}
}

vector<Composer> ComposerManager::getAllComposerList()
{
	return composerList;
}