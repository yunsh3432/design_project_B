#include"MusicAlbum.h"

MusicAlbum::MusicAlbum()
{
	name = "";
}

MusicAlbum::~MusicAlbum()
{
}

MusicAlbum::MusicAlbum(int _id, string _name, int _Cid, int _purchasedCount)
{
	id = _id;
	name = _name;
	composerId = _Cid;
	purchasedCount = _purchasedCount;
}