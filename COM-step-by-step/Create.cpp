//
// Create.cpp 
//
#include <iostream>
#include <unknwn.h>    // Declare IUnknown.

#include "Create.h"
#include <winerror.h>

using namespace std;

typedef IUnknown* (*CREATEFUNCPTR)();

IUnknown* CallCreateInstance(const TCHAR* name)
{
	// Load dynamic link library into process.
	//HINSTANCE hComponent = ::LoadLibrary(L"Component1.dll");
	HINSTANCE hComponent = ::LoadLibrary(name);
	int er = GetLastError();
	if (hComponent == NULL)
	{
		cout << "HINSTANCE:\t" << hComponent << " errNo:\t" << er << endl;
		cout << "CallCreateInstance:\tError: Cannot load component." << endl;
		return NULL;
	}

	// Get address for CreateInstance function.
	CREATEFUNCPTR CreateInstance
		= (CREATEFUNCPTR)::GetProcAddress(hComponent, "CreateInstance");  //IUnknown* (*CREATEFUNCPTR)()
	if (CreateInstance == NULL)
	{
		cout << "CallCreateInstance:\tError: "
			<< "Cannot find CreateInstance function."
			<< endl;
		return NULL;
	}

	return CreateInstance();
}
