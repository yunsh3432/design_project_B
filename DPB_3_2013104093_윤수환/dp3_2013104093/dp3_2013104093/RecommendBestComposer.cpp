#include<vector>
#include<iostream>
#include<algorithm>
#include"RecommendBestComposer.h"

using namespace std;

struct Composerinfo
{
	int ComposerID;
	string ComposerName;
	int purchasedCnt;
};

RecommendBestComposer::RecommendBestComposer()
{
	am = new AlbumManager();
	um = new UserManager();
	cm = new ComposerManager();
}

RecommendBestComposer::~RecommendBestComposer()
{
}

void RecommendBestComposer::recommend()
{
	vector<Composer> tempComposerList = cm->getAllComposerList();
	vector<MusicAlbum> tempAlbumManagerList = am->getAllAlbumList();
	vector<Composerinfo> composerinfoList;
	Composerinfo tempComposer;


	for(int i = 0; i < tempComposerList.size() ; i++)
	{
		for(int j = 0; j < tempAlbumManagerList.size(); j++)
		{
			if(tempComposerList[i].getid() == tempAlbumManagerList[j].getcomposerId())
			{
				tempComposer.ComposerID = tempComposerList[i].getid();
				tempComposer.ComposerName = tempComposerList[i].getname();
				tempComposer.purchasedCnt = tempAlbumManagerList[j].getpurchasedCount();

				composerinfoList.push_back(tempComposer);
			}
		}
	}

	Composerinfo MaxPurComposer = composerinfoList[0];

	for(int i = 0; i < composerinfoList.size(); i++)
	{
		if(MaxPurComposer.purchasedCnt < composerinfoList[i].purchasedCnt)
			MaxPurComposer = composerinfoList[i];
	}

	for(int i = 0; i < tempAlbumManagerList.size(); i++)
	{
		if(tempAlbumManagerList[i].getcomposerId() == MaxPurComposer.ComposerID)
		{
			cout <<"-------------------"<<endl;
			cout <<"¾Ù¹ü ¾ÆÀÌµð: "<< tempAlbumManagerList[i].getid() << endl;
			cout <<"¾Ù¹ü ÀÌ¸§: "<< tempAlbumManagerList[i].getname() << endl;
			cout <<"À½¾Ç°¡ ¾ÆÀÌµð: "<< tempAlbumManagerList[i].getcomposerId() << endl;
			cout <<"±¸¸ÅÈ½¼ö: "<< tempAlbumManagerList[i].getpurchasedCount() << endl;
			cout <<"------------------"<<endl;
		}
	}
}