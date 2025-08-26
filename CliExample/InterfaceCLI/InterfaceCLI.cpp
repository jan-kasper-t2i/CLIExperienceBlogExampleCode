#include "pch.h"

//Leaned: This gets to the top, otherwise strange compiler errors can (but do not have to) arise!
#include <msclr\auto_gcroot.h>
#include <msclr\marshal_cppstd.h>

#include "InterfaceCLI.h"

#include <iostream>



using namespace System;
using namespace CSharpWorld;

class CSharpInterface
{
public:
	msclr::auto_gcroot<CSharpLib^> CSharpLib;
};

CppCliWrapper::CppCliWrapper()
{
	_managedState = new CSharpInterface();
	_managedState->CSharpLib = gcnew CSharpLib();
}

CppCliWrapper::~CppCliWrapper()
{
	delete _managedState;
}

void CppCliWrapper::SendDataToCSharp(std::wstring text)
{
	std::cout << "SendDataToCSharp called, Wrapper reached! \n";

	String^ managedString = msclr::interop::marshal_as<String^>(text);
	_managedState->CSharpLib->ReceiveDataFromCpp(managedString);
}


void CppCliWrapper::SendPointer(wchar_t* bytearray)
{
	_managedState->CSharpLib->ReceivePointer(bytearray);
}

