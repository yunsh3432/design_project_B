#pragma once
#include "BaseRecommendationAlg.h"
class RecommendTopTen :
	public BaseRecommendationAlg
{
public:
	RecommendTopTen();
	~RecommendTopTen();

	virtual void recommend();
private:	
	AlbumManager* am;
	UserManager* um;
	ComposerManager* cm;
};

