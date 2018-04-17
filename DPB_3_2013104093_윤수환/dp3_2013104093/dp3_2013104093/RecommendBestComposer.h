#pragma once
#include"BaseRecommendationAlg.h"

class RecommendBestComposer:
	public BaseRecommendationAlg
{
public:
	RecommendBestComposer();
	~RecommendBestComposer();

	virtual void recommend();
private:
	AlbumManager* am;
	UserManager* um;
	ComposerManager* cm;
};