#include "pch.h"
#include <msclr\marshal_cppstd.h>
#include "TreasureConverter.h"

using namespace System;
using namespace CSharpWorld;
using namespace Interface;
TreasureConverter::TreasureConverter(Interface::ITreasure^ treasure)
{
    
}
TreasureConverter::TreasureConverter(Treasure& treasure)
{

}

ITreasure^ TreasureConverter::ToITreasure(Treasure& treasure)
{
    std::vector<ValuableItem>& items = treasure.GetContents();
    String^ item1Name = msclr::interop::marshal_as<String^>(items[0].GetName());
    int item1Value = items[0].GetValue();
    String^ item2Name = msclr::interop::marshal_as<String^>(items[1].GetName());
    int item2Value = items[1].GetValue();
    String^ item3Name = msclr::interop::marshal_as<String^>(items[2].GetName());
    int item3Value = items[2].GetValue();

    ManagedValuableItem^ item1 = gcnew ManagedValuableItem(item1Name, item1Value);
    ManagedValuableItem^ item2 = gcnew ManagedValuableItem(item2Name, item2Value);
    ManagedValuableItem^ item3 = gcnew ManagedValuableItem(item3Name, item3Value);
    
    Collections::Generic::List<IValuableItem^>^ managedValuableItemList = gcnew Collections::Generic::List<IValuableItem^>();
    managedValuableItemList->Add(item1);
    managedValuableItemList->Add(item2);
    managedValuableItemList->Add(item3);
    ManagedTreasure^ managedTreasure = gcnew ManagedTreasure(managedValuableItemList);
    
    return managedTreasure;
}
