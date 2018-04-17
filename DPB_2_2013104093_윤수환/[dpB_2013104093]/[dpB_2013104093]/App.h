#pragma once
#include "CounterFacade.h"
#include "ManagerFacade.h"
class App
{
public:
	App(void);
	~App(void);
	void run();
private:
	CounterFacade* cf;
	ManagerFacade* mf;
};

