//
// Client1.cpp
// To compile, use: cl Client1.cpp Create.cpp GUIDs.cpp UUID.lib
//
#include <iostream>
#include <objbase.h>
//#include <TCHAR.H>

#include "Iface.h"
#include "Create.h"

//#ifdef _UNICODE
//#define IN() cin >> x
//#else
//typedef char TCHAR;
//#endif


using namespace std;

static void trace(const char* msg) { cout << "Client 1:\t" << msg << endl; }

//
// Client1
//
int main()
{
	HRESULT hr;

	// Get the name of the component to use.
	TCHAR name[40];
	cout << "Enter the filename of a component to use [Cmpnt?.dll]: ";

	#ifdef _UNICODE
		wcin >> name;
	#else
		cin >> name;
	#endif

	cout << endl;
	cout << name << endl;

	// Create component by calling the CreateInstance function in the DLL.
	trace("Get an IUnknown pointer.");
	IUnknown* pIUnknown = CallCreateInstance(name);
	if (pIUnknown == NULL)
	{
		trace("CallCreateInstance Failed.");
		return 1;
	}

	trace("Get interface IX.");

	IX* pIX;
	hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);

	if (SUCCEEDED(hr))
	{
		trace("Succeeded getting IX.");
		pIX->Fx();          // Use interface IX.
		pIX->Release();
	}
	else
	{
		trace("Could not get interface IX.");
	}

	trace("Release IUnknown interface.");
	pIUnknown->Release();

	return 0;
}


