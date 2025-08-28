// CppConsoleNative.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "InterfaceCLI.h"
#include "Treasure.h"


int main()
{
    std::cout << "Programm started\n";

    CppCliWrapper cliWrapper;


    ValuableItem item1 = ValuableItem(L"Gold Dukaten", 512);
    ValuableItem item2 = ValuableItem(L"Handtuch", 42);
    ValuableItem item3 = ValuableItem(L"Ringe", 69);
    
    Treasure myTreasure = Treasure(item1, item2, item3);

    cliWrapper.SendTreasure(myTreasure);

    // Prepare the string to send to C# (you can replace this with your actual data)
   //  std::wstring dataToSend = L"Hello from C++!";
   //
   //  // Call the function in the C++/CLI wrapper to send data to C#
   // cliWrapper.SendDataToCSharp(dataToSend);
   //
   //  wchar_t sendP[] = L"Sending a pointer success!";
   //  
   //  cliWrapper.SendPointer(sendP);
   //  std::cout << "Pogramm finished\n";
}
