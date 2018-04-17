#pragma once
#include <string>
using namespace std;

class MusicAlbum
{
public:
	MusicAlbum();
	~MusicAlbum();
	MusicAlbum(int _id, string _name, int _Cid, int _purchasedCount);

	int getid(){return id;}
	string getname(){return name;}
	int getcomposerId(){return composerId;}
	int getpurchasedCount(){return purchasedCount;}

	void addPurchasedCount(){purchasedCount++; return;}
private:
	int id;
	string name;
	int composerId;
	int purchasedCount;
};

