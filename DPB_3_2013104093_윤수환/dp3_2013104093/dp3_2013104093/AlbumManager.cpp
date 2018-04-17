#include"AlbumManager.h"
#include<iostream>
#include<string>

using namespace std;

AlbumManager::AlbumManager()
{
	ifstream fsIn("MusicAlbum.dat",ios::binary|ios::in);

	fsIn.seekg(0, ios::end);
	int filesize = fsIn.tellg();
	fsIn.seekg(0 , ios::beg);

	while(1)
	{
		int id = 0;
		fsIn.read((char*)&id,sizeof(int));
		int namesize = 0;
		fsIn.read((char*)&namesize,sizeof(int));
		string name = "";
		name.resize(namesize);
		fsIn.read(&name[0],namesize);
		int comId = 0;
		fsIn.read((char*)&comId,sizeof(int));
		int Pulcnt = 0;
		fsIn.read((char*)&Pulcnt,sizeof(int));
	
	
		MusicAlbum tempAlbum(id, name, comId, Pulcnt);
		AlbumList.push_back(tempAlbum);

		if(fsIn.tellg() >= filesize)
		{
			break;
		}
	}
	fsIn.close();
}

AlbumManager::~AlbumManager()
{
	
}

bool AlbumManager::addMusicAlbumToFile(MusicAlbum addedMusicAlbum)
{
	AlbumList.push_back(addedMusicAlbum);

	ofstream fsOut("MusicAlbum.dat",ios::binary|ios::in);

	int tempid = addedMusicAlbum.getid();
	string tempname = addedMusicAlbum.getname();
	int tempnamesize = tempname.size();
	int tempComposerID = addedMusicAlbum.getcomposerId();
	int temppurchasedCnt = addedMusicAlbum.getpurchasedCount();
	
	

	fsOut.seekp(0,ios::end);
	

	fsOut.write((char*)&tempid,sizeof(int));
	fsOut.write((char*)&tempnamesize,sizeof(int));
	fsOut.write(tempname.c_str(),tempname.size());
	fsOut.write((char*)&tempComposerID,sizeof(int));
	fsOut.write((char*)&temppurchasedCnt,sizeof(int));

	fsOut.close();

	return true;
}

MusicAlbum AlbumManager::searchMusicAlbumById(int _id)
{
	for(int i = 0 ; i < AlbumList.size(); i++)
	{
		if(AlbumList[i].getid() == _id)
		{
			return AlbumList[i];
		}
	}
	cout << "없는 아이디 입니다." << endl;
	MusicAlbum NoAlbum;
	return NoAlbum;
}

MusicAlbum AlbumManager::searchMusicAlbumByName(string _name)
{
	for(int i = 0 ; i < AlbumList.size(); i++)
	{
		if(AlbumList[i].getname() == _name)
		{
			return AlbumList[i];
		}
	}
	cout << "없는 이름 입니다." << endl;
	MusicAlbum NoAlbum;
	return NoAlbum;
}

bool AlbumManager:: updateMusicAlbumSellCount(int albumId)
{
	for(int i = 0 ; i < AlbumList.size(); i++)
	{
		if(AlbumList[i].getid() == albumId)
		{
			AlbumList[i].addPurchasedCount(); 
			ofstream fsOut("MusicAlbum.dat",ios::binary|ios::in);

			int tempid = AlbumList[i].getid();
			string tempname = AlbumList[i].getname();
			int tempnamesize = tempname.size();
			int tempComposerID = AlbumList[i].getcomposerId();
			int temppurchasedCnt = AlbumList[i].getpurchasedCount();
	
			fsOut.seekp(0,ios::beg);
			for(int j = 0; j < i ; j++)
				fsOut.seekp(16+AlbumList[j].getname().size(),ios::cur);
			

			fsOut.write((char*)&tempid,sizeof(int));
			fsOut.write((char*)&tempnamesize,sizeof(int));
			fsOut.write(tempname.c_str(),tempname.size());
			fsOut.write((char*)&tempComposerID,sizeof(int));
			fsOut.write((char*)&temppurchasedCnt,sizeof(int));

			fsOut.close();
			return true;
		}
	}


	cout << "없는 아이디 입니다." << endl;
	return false;
	
}

vector<MusicAlbum> AlbumManager::getAllAlbumList()
{
	return AlbumList;
}