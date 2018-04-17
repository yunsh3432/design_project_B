#include<iostream>
#include"App.h"
#include <string>

using namespace std;

App::App()
{
	um = new UserManager();
	cm = new ComposerManager();
	am = new AlbumManager();

}

App::~App()
{
	delete um;
	delete cm;
	delete am;
}

void App::run()
{
	int selec;
	while(1)
	{
		for(int i = 0; i < 20; i++)
			cout << '-';
		cout << endl;
	
		cout << "1.����� �޴�" << endl;
		cout << "2.������ �޴�" << endl;
		cout << "3.����" << endl; 

		for(int i = 0; i < 20; i++)
			cout << '-';
		cout << endl;
		cin >> selec;

		switch(selec)
		{
		case 1:
			printloginMenu();
			break;
		case 2:
			printManagerMenu();
			break;
		case 3:
			return ;
		default:
			cout << " ���� �޴��� �����ϼ˽��ϴ�." << endl;
			
		}
	}
}

void App::printloginMenu()
{
	int selec;
		while(1)
		{
			for(int i = 0; i < 20; i++)
				cout << '-';
			cout << endl;
			cout << "����� �޴�" << endl;
			cout << "1.ȸ������" << endl;
			cout << "2.�α���" << endl;
			cout << "3.�ǵ��ư���" << endl;
			for(int i = 0; i < 20; i++)
				cout << '-';
			cout << endl;
			cin >> selec;
			switch(selec)
			{
			case 1:
				userRegisteration();
				break;
			case 2:
				if(login() == true)
				{
					printUserMenu();
					break;
				}
				else
				{
					return ;
				}
				break;
			case 3:
				return;
			default:
			cout << " ���� �޴��� �����ϼ˽��ϴ�." << endl;
			}
		}
}

void App::printUserMenu()
{
	int selec;
		while(1)
		{
		for(int i = 0; i < 20; i++)
			cout << '-';
		cout << endl;
		cout << "����� �޴�" << endl;
		cout << "1.���Ǳ���" << endl; 
		cout << "2.������õ�ޱ�" << endl;
		cout << "3.���ų���Ȯ��" << endl;
		cout << "4.�ǵ��ư���" << endl;
		for(int i = 0; i < 20; i++)
			cout << '-';
		cout << endl;
		cin >> selec;

		switch(selec)
		{
		case 1:
			buyAlbum();
			break;
		case 2:
		     recommend();
			break;
		case 3:
			printPurchasedList();
			break;
		case 4:
			return ;
		default:
			cout << " ���� �޴��� �����ϼ˽��ϴ�." << endl;
			
		}
	}
}

void App::printManagerMenu()
{
	int selec;
	while(1)
	{
		for(int i = 0; i < 20; i++)
			cout << '-';
		cout << endl;
		cout << "������ �޴�" << endl;
		cout << "1.���ǰ� �߰�" << endl;
		cout << "2.�ٹ� �߰�" << endl;
		cout << "3.����" << endl; 

		for(int i = 0; i < 20; i++)
			cout << '-';
		cout << endl;
		cin >> selec;

		switch(selec)
		{
		case 1:
			addComposer();
			break;
		case 2:
			addAlbum();
			break;
		case 3:
			return ;
		default:
			cout << " ���� �޴��� �����ϼ˽��ϴ�." << endl;
			
		}
	}
}

void App::userRegisteration()//ȸ������
{
	int id;
	string pw;

	cout << "���̵� �Է��� �ּ���: " ;
	cin >> id;
	cout << "��й�ȣ�� �Է��� �ּ���: " ;
	cin >> pw;

	vector<User> tempList = um->getAllUserList();

	for(int i = 0; i < tempList.size(); i++)
	{
		if(tempList[i].getId() == id)
		{
			cout << "�̹� �ִ� ���̵� �Դϴ�." << endl;
			return ;
		}
	}

	vector<int> PulList;
	User tempUser(id,pw,PulList);
	um->addUserToFile(tempUser);
	return ;
}

bool App::login()//�α���
{
	int id;
	string pw;

	cout << "���̵� �Է��� �ּ���: " << endl;
	cin >> id;
	cout << "��й�ȣ�� �Է��� �ּ���: " << endl;
	cin >> pw;

	vector<User> tempList = um->getAllUserList();
	for(int i = 0; i < tempList.size(); i++)
	{
		if(tempList[i].getId() == id && tempList[i].getpw() == pw)
		{
			currentUserId = tempList[i].getId();
			cout << "�α��� �Ǽ˽��ϴ�." << endl;
			return true;
		}
	}
	cout << "�α��ο� ���� �ϼ̽��ϴ�." << endl;
	return false;

}

void App::buyAlbum()//�ٹ�����
{
	while(1)
	{
		for(int i = 0; i <20; i++)
			cout << '-';
		cout << endl;

		cout << "1.�̸����� �˻�" << endl;
		cout << "2.���̵�� �˻�" << endl;
		cout << "3.��ü ���� Ȯ��" << endl;
		cout << "0.���ư���" << endl;
	
		for(int i = 0; i <20; i++)
			cout << '-';
		cout << endl;
		int selec; 
		cin >> selec;

		switch(selec)
		{
			case 1:
			{	
				cout << "�̸��� �Է��� �ּ���: ";
				string tempName;
				cin >> tempName;

				MusicAlbum tempAlbum;
				tempAlbum = am->searchMusicAlbumByName(tempName);
				if(tempAlbum.getname() == "")
				{
					return;
				}
				else
				{
					cout << tempAlbum.getid() << ',' << tempAlbum.getname() << endl;
					cout << "�����Ͻðڽ��ϱ�? <Y/N> :";
					char selec;
					cin >> selec;
					if(selec == 'Y')
					{
						for(int j = 0; j < (um->getAllUserList()).size(); j++)
						{
							if(currentUserId == (um->getAllUserList())[j].getId())
							{
								um->addAlbumIdToPurchaseList(currentUserId, tempAlbum.getid());
							}
						}
						am->updateMusicAlbumSellCount(tempAlbum.getid());
						return ;
					}
					else if(selec == 'N')
					{
						cout << "�ٹ��� �������� �����̽��ϴ�." << endl;
						return ;
					}
					else
					{
						cout  << "�߸� �Է��ϼ̽��ϴ�." << endl;
						return ;
					}
				}
				break ;
			}
			case 2:
				{
					cout << "���̵��� �Է��� �ּ���: ";
					int tempid;
					cin >> tempid;

					MusicAlbum tempAlbum;
					tempAlbum = am->searchMusicAlbumById(tempid);
					if(tempAlbum.getname() == "")
					{
						return;
					}
					else
					{
						cout << tempAlbum.getid() << ',' << tempAlbum.getname() << endl;
						cout << "�����Ͻðڽ��ϱ�? <Y/N> :";
						char selec;
						cin >> selec;
						if(selec == 'Y')
						{
							for(int j = 0; j < (um->getAllUserList()).size(); j++)
							{
								if(currentUserId == (um->getAllUserList())[j].getId())
								{
									um->addAlbumIdToPurchaseList(currentUserId, tempAlbum.getid());
								}
							}
							am->updateMusicAlbumSellCount(tempAlbum.getid());
							return ;
						}
						else if(selec == 'N')
						{
							cout << "�ٹ��� �������� �����̽��ϴ�." << endl;
							return ;
						}
						else
						{
							cout  << "�߸� �Է��ϼ̽��ϴ�." << endl;
							return ;
						}
					}
					break ;
				}
			case 3:
				{
					vector<MusicAlbum> tempList = am->getAllAlbumList();
					for(int i = 0 ; i < tempList.size(); i++)
					{ 
						cout << "------------------------------" << endl;
						cout << "�ٹ� ���̵�: " << tempList[i].getid() << endl;
						cout << "�ٹ� �̸�: "<< tempList[i].getname() << endl;
						cout << "�۰ ���̵�: " << tempList[i].getcomposerId() << endl;
						cout << "�� �ٹ��� ���� Ƚ��: " << tempList[i].getpurchasedCount() << endl;
						cout << "------------------------------" << endl;
					}
					return ;
				}
				break ;
			case 0:
				return ;
			default:
				cout << "�߸��Է��ϼ̽��ϴ�." << endl;
				return ;
		}
	}

}

void App::printPurchasedList() 
{
	vector<int> temppurcahsedList;
	for(int i = 0; i < (um->getAllUserList()).size();i++)
	{
		if(um->getAllUserList()[i].getId() == currentUserId)
		{
			temppurcahsedList = um->getAllUserList()[i].getpurcahsedList();
		
	
			vector<MusicAlbum> tempList = am->getAllAlbumList();

			if(temppurcahsedList.size() == 0)
			{
				cout << "������ ���� �����ϴ�." << endl;
				return ;
			}
			else
			{
				for(int k = 0 ; k < temppurcahsedList.size(); k++)
				{ 
					for( int j= 0 ;j < tempList.size(); j++)
					{
						if(temppurcahsedList[k] == tempList[j].getid())
						{
							cout << "------------------------------" << endl;
							cout << "�ٹ� ���̵�: " << tempList[j].getid() << endl;
							cout << "�ٹ� �̸�: "<< tempList[j].getname() << endl;
							cout << "�۰ ���̵�: " << tempList[j].getcomposerId() << endl;
							cout << "�� �ٹ��� ���� Ƚ��: " << tempList[j].getpurchasedCount() << endl;
							cout << "------------------------------" << endl;
						}
					}
				}
			}
			return ;
		}
	}
	return ;

}

void App::recommend()
{
	cout << "� ��õ ����� �����Ͻðڽ��ϱ�? "<< endl;
	cout << "1. ����Ƚ�� Top10" << endl;
	cout << "2. ������� ���� ���� ������ ���ǰ��� �뷡" << endl;
	
	int selec;
	cin >> selec;

	switch(selec)
	{
	case 1:
		rcdAlg = new RecommendTopTen();//vector ranger Error
		rcdAlg->recommend();
		break;
	case 2:
		rcdAlg = new RecommendBestComposer();
		rcdAlg->recommend();
		break;
		
	default:
		cout << "���� ��õ ��� �Դϴ�." << endl;
		break;
	}
}

void App::addComposer()
{
	int id;
	string name;
	cout << "�߰��� ���̵� �Է��� �ּ���: ";
	cin >> id;
	cout << "�߰��� �̸��� �Է��� �ּ���: ";
	cin >> name;
	vector<Composer> tempList = cm->getAllComposerList();

	for(int i = 0; i < tempList.size(); i++)
	{
		if(tempList[i].getid() == id || tempList[i].getname() == name)
		{
			cout << "�̹� �ִ� ���̵��̰ų� �̸��Դϴ�. " << endl;
			return;
		}
		else
		{
			Composer tempComposer(id,name);
			cm->addComposerToFile(tempComposer);
			
		}
	}
}

void App::addAlbum()
{
	int id;
	string name;
	int composerid;
	cout << "�߰��� ���̵� �Է��� �ּ���: ";
	cin >> id;
	cout << "�߰��� �̸��� �Է��� �ּ���: ";
	cin >> name;
	cout << "�۰ ���̵� �Է��� �ּ���: ";
	cin >> composerid;

	vector<MusicAlbum> tempAlbumList = am->getAllAlbumList();
	vector<Composer> tempComposerList = cm->getAllComposerList();
	for(int i = 0; i < tempComposerList.size(); i++)
	{
		if(tempComposerList[i].getid() == composerid )
		{
			MusicAlbum tempAlbum(id,name,composerid,0);
			am->addMusicAlbumToFile(tempAlbum);
			return;
		}
	}
	cout << "���� �۰ ���̵��Դϴ�." << endl;
	return;	
}
