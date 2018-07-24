// COM-step-by-step.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <objbase.h>
#include <unknwn.h>

interface IX
{
	virtual void __stdcall Fx1() = 0;
	virtual void __stdcall Fx2() = 0;
};

interface IY
{
	virtual void __stdcall Fy1() = 0;
	virtual void __stdcall Fy2() = 0;
};


class CA : public IX, public IY
{
public:
	//Реализация интерфейса IX
	virtual void __stdcall Fx1() override { std::cout << "CA::Fx()" << std::endl;}
	virtual void __stdcall Fx2() override { std::cout << "CA::Fx()" << std::endl;}

	//Реализация интерфейса IY
	virtual void __stdcall Fy1() override { std::cout << "CA::Fy()" << std::endl;}
	virtual void __stdcall Fy2() override { std::cout << "CA::Fy()" << std::endl;}
};


int not2_main()
{
	CA* pA = new CA;

	IX* pIX = pA;

	pIX->Fx1();
	pIX->Fx2();

	IY* pIY = pA;

	pIY->Fy1();
	pIY->Fy2();

	delete pA;

    return 0;
}

