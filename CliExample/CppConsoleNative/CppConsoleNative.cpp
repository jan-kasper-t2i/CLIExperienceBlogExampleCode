// CppConsoleNative.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "InterfaceCLI.h"

int main()
{
    std::cout << "Programm started\n";

    CppCliWrapper cliWrapper;

    // Prepare the string to send to C# (you can replace this with your actual data)
    std::wstring dataToSend = L"Hello from C++!";

    // Call the function in the C++/CLI wrapper to send data to C#
   cliWrapper.SendDataToCSharp(dataToSend);

    wchar_t sendP[] = L"Sending a pointer success!";
    
    cliWrapper.SendPointer(sendP);
    std::cout << "Pogramm finished\n";
}
