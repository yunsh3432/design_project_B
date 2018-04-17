#include"User.h"

User::User()
{
}

User::~User()
{
}

User::User(int _id, string _pw, vector<int> _PchL)
{
	id = _id;
	password = _pw;
	purcahsedList = _PchL;
}