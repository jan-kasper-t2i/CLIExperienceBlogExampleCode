#include "pch.h"
#include "Treasure.h"


ValuableItem::ValuableItem(std::wstring name, int value){_name = name; _value = value;}
std::wstring ValuableItem::GetName() { return _name;}
int ValuableItem::GetValue() { return _value; }

Treasure::Treasure(ValuableItem& item1, ValuableItem& item2,ValuableItem& item3)
{
    contents.push_back(item1);
    contents.push_back(item2);
    contents.push_back(item3);
}
std::vector<ValuableItem>& Treasure::GetContents(){return contents;}