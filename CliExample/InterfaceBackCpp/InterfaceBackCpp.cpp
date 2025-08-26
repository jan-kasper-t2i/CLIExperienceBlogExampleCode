#include "pch.h"

#include <msclr/marshal_cppstd.h>

#include <iostream>

#include "InterfaceBackCpp.h"
#include "CalledFromCSharp.h"

namespace InterfaceBackCpp {
	void InterfaceForCSharp::SendTextToCpp(String^ text)
	{
		std::cout << "InterfaceForCSharp::SendTextToCpp reached! \n";
		CalledFromCSharp nativeCppLibClass;
		auto unmanagedString = msclr::interop::marshal_as<std::wstring>(text);
		nativeCppLibClass.ReceivedTextFromCSharp(unmanagedString);
	}
}