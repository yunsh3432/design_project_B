#pragma once
#include <string>
#include <vector>
using namespace std;

class User
{
public:
	User();
	~User();
	User(int _id, string _pw, vector<int> _PchL);

	int getId(){return id;}
	string getpw(){return password;}
	vector<int> getpurcahsedList(){return purcahsedList;}

	void addPurcahsedList(int id){purcahsedList.push_back(id);}

private:
	int id;
	string password;
	vector<int> purcahsedList;
};

