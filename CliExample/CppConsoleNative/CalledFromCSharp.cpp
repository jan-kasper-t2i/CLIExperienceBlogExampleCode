#include "pch.h"

#include "CalledFromCSharp.h"
#include <iostream>


void CalledFromCSharp::ReceivedTextFromCSharp(std::wstring text)
{
	//lessons learned: Currently changing this file need multiple builds, until effects ripple through. 
	std::cout << "CalledFromCSharp::ReceivedTextFromCSharp reached! \n";
	std::wcout << text;
	std::cout << "\n\n";
}
