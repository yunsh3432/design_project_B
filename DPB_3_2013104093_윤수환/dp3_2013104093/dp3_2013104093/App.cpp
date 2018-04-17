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
	
		cout << "1.사용자 메뉴" << endl;
		cout << "2.관리자 메뉴" << endl;
		cout << "3.종료" << endl; 

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
			cout << " 없는 메뉴를 선택하셧습니다." << endl;
			
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
			cout << "사용자 메뉴" << endl;
			cout << "1.회원가입" << endl;
			cout << "2.로그인" << endl;
			cout << "3.되돌아가기" << endl;
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
			cout << " 없는 메뉴를 선택하셧습니다." << endl;
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
		cout << "사용자 메뉴" << endl;
		cout << "1.음악구매" << endl; 
		cout << "2.음악추천받기" << endl;
		cout << "3.구매내역확인" << endl;
		cout << "4.되돌아가기" << endl;
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
			cout << " 없는 메뉴를 선택하셧습니다." << endl;
			
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
		cout << "관리자 메뉴" << endl;
		cout << "1.음악가 추가" << endl;
		cout << "2.앨범 추가" << endl;
		cout << "3.종료" << endl; 

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
			cout << " 없는 메뉴를 선택하셧습니다." << endl;
			
		}
	}
}

void App::userRegisteration()//회원가입
{
	int id;
	string pw;

	cout << "아이디를 입력해 주세요: " ;
	cin >> id;
	cout << "비밀번호를 입력해 주세요: " ;
	cin >> pw;

	vector<User> tempList = um->getAllUserList();

	for(int i = 0; i < tempList.size(); i++)
	{
		if(tempList[i].getId() == id)
		{
			cout << "이미 있는 아이디 입니다." << endl;
			return ;
		}
	}

	vector<int> PulList;
	User tempUser(id,pw,PulList);
	um->addUserToFile(tempUser);
	return ;
}

bool App::login()//로그인
{
	int id;
	string pw;

	cout << "아이디를 입력해 주세요: " << endl;
	cin >> id;
	cout << "비밀번호를 입력해 주세요: " << endl;
	cin >> pw;

	vector<User> tempList = um->getAllUserList();
	for(int i = 0; i < tempList.size(); i++)
	{
		if(tempList[i].getId() == id && tempList[i].getpw() == pw)
		{
			currentUserId = tempList[i].getId();
			cout << "로그인 되셧습니다." << endl;
			return true;
		}
	}
	cout << "로그인에 실패 하셨습니다." << endl;
	return false;

}

void App::buyAlbum()//앨범구매
{
	while(1)
	{
		for(int i = 0; i <20; i++)
			cout << '-';
		cout << endl;

		cout << "1.이름으로 검색" << endl;
		cout << "2.아이디로 검색" << endl;
		cout << "3.전체 엘범 확인" << endl;
		cout << "0.돌아가기" << endl;
	
		for(int i = 0; i <20; i++)
			cout << '-';
		cout << endl;
		int selec; 
		cin >> selec;

		switch(selec)
		{
			case 1:
			{	
				cout << "이름을 입력해 주세요: ";
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
					cout << "구매하시겠습니까? <Y/N> :";
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
						cout << "앨범을 구매하지 않으셨습니다." << endl;
						return ;
					}
					else
					{
						cout  << "잘못 입력하셨습니다." << endl;
						return ;
					}
				}
				break ;
			}
			case 2:
				{
					cout << "아이디을 입력해 주세요: ";
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
						cout << "구매하시겠습니까? <Y/N> :";
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
							cout << "앨범을 구매하지 않으셨습니다." << endl;
							return ;
						}
						else
						{
							cout  << "잘못 입력하셨습니다." << endl;
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
						cout << "앨범 아이디: " << tempList[i].getid() << endl;
						cout << "앨범 이름: "<< tempList[i].getname() << endl;
						cout << "작곡가 아이디: " << tempList[i].getcomposerId() << endl;
						cout << "이 앨범의 구매 횟수: " << tempList[i].getpurchasedCount() << endl;
						cout << "------------------------------" << endl;
					}
					return ;
				}
				break ;
			case 0:
				return ;
			default:
				cout << "잘못입력하셨습니다." << endl;
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
				cout << "구매한 곡이 없습니다." << endl;
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
							cout << "앨범 아이디: " << tempList[j].getid() << endl;
							cout << "앨범 이름: "<< tempList[j].getname() << endl;
							cout << "작곡가 아이디: " << tempList[j].getcomposerId() << endl;
							cout << "이 앨범의 구매 횟수: " << tempList[j].getpurchasedCount() << endl;
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
	cout << "어떤 추천 방식을 선택하시겠습니까? "<< endl;
	cout << "1. 구매횟수 Top10" << endl;
	cout << "2. 사람들이 가장 많이 좋아한 음악가의 노래" << endl;
	
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
		cout << "없는 추천 방식 입니다." << endl;
		break;
	}
}

void App::addComposer()
{
	int id;
	string name;
	cout << "추가할 아이디를 입력해 주세요: ";
	cin >> id;
	cout << "추가할 이름을 입력해 주세요: ";
	cin >> name;
	vector<Composer> tempList = cm->getAllComposerList();

	for(int i = 0; i < tempList.size(); i++)
	{
		if(tempList[i].getid() == id || tempList[i].getname() == name)
		{
			cout << "이미 있는 아이디이거나 이름입니다. " << endl;
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
	cout << "추가할 아이디를 입력해 주세요: ";
	cin >> id;
	cout << "추가할 이름을 입력해 주세요: ";
	cin >> name;
	cout << "작곡가 아이디를 입력해 주세요: ";
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
	cout << "없는 작곡가 아이디입니다." << endl;
	return;	
}
