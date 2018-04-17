#include"RecommendTopTen.h"
#include<algorithm>

using namespace std;

RecommendTopTen::RecommendTopTen()
{
	am = new AlbumManager();
	um = new UserManager();
	cm = new ComposerManager();
}

RecommendTopTen::~RecommendTopTen()
{
}

void RecommendTopTen ::recommend()
{
	vector<MusicAlbum> temp;
	vector<MusicAlbum> tempAlbumList = am->getAllAlbumList();
	vector<User> tempUserList= um->getAllUserList();
	vector<Composer> tempComposerList = cm->getAllComposerList();
	vector<int> unsortedList;
	vector<int> sortedList;
	int size;
	bool type = true;

	for(int i = 0; i < tempAlbumList.size(); i++)
		unsortedList.push_back(tempAlbumList[i].getpurchasedCount());

	sort(unsortedList.begin(),unsortedList.end(),greater<int>());
	
	for(int i = 0; i < unsortedList.size(); i++)
		sortedList.push_back(unsortedList[i]);
	
	for(int i = 0; i < sortedList.size(); i++)
	{
		
		for(int j = 0; j < tempAlbumList.size(); j++)
		{
			if(sortedList[i] == tempAlbumList[j].getpurchasedCount())
			{
				size = temp.size();
				if(size == 0)
					temp.push_back(tempAlbumList[j]);
				else
				{
					type = true;
					
					for(int k = 0;k < size; k++)
					{
						if(temp[k].getid() == tempAlbumList[j].getid())
						{
							type =false;
						}
					}
					
					if(type == true)
					{
						temp.push_back(tempAlbumList[j]);
					}

					else
					{
						continue;
					}
				}
			}
		}
	}



	if(temp.size() < 10)
	{
		for(int i = 0; i < temp.size(); i++)
		{
			cout <<"-------------------"<<endl;
			cout <<"¾Ù¹ü ¾ÆÀÌµð: "<< temp[i].getid() << endl;
			cout <<"¾Ù¹ü ÀÌ¸§: "<< temp[i].getname() << endl;
			cout <<"À½¾Ç°¡ ¾ÆÀÌµð: "<< temp[i].getcomposerId() << endl;
			cout <<"±¸¸ÅÈ½¼ö: "<< temp[i].getpurchasedCount() << endl;
			cout <<"------------------"<<endl;
		}
	}
	else
	{
		for(int i = 0; i < 10; i++)
		{
			cout <<"-------------------"<<endl;
			cout <<"¾Ù¹ü ¾ÆÀÌµð: "<< temp[i].getid() << endl;
			cout <<"¾Ù¹ü ÀÌ¸§: "<< temp[i].getname() << endl;
			cout <<"À½¾Ç°¡ ¾ÆÀÌµð: "<< temp[i].getcomposerId() << endl;
			cout <<"±¸¸ÅÈ½¼ö: "<< temp[i].getpurchasedCount() << endl;
			cout <<"------------------"<<endl;
		}
	}
	return ;
}

