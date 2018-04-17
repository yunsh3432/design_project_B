#pragma once
#include <string>
using namespace std;

class Composer
{
public:
	Composer();
	~Composer();
	Composer(int _id,string _name);

	int getid(){return id;}
	string getname(){return name;}

private:
	int id;
	string name;
};

