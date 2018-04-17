#pragma once
//#include "BaseRecommendationAlg.h"
#include "RecommendTopTen.h"
#include "RecommendBestComposer.h"
class App
{
public:
	App();
	~App();

	void run();
	
private:
	void printUserMenu();
	void printloginMenu();
	void printManagerMenu();

	void userRegisteration();
	bool login();
	void buyAlbum();
	void printPurchasedList();
	void recommend();

	void addComposer();
	void addAlbum();

private:
	BaseRecommendationAlg* rcdAlg;
	UserManager* um;
	ComposerManager* cm;
	AlbumManager* am;
	int currentUserId;
};

