#pragma once
#include <string>
#include <vector>

class  __declspec(dllexport) ValuableItem
{
public:
    ValuableItem(std::wstring name, int value);
    std::wstring GetName();
    int GetValue();

private:
    std::wstring _name;
    int _value;
};


class  __declspec(dllexport) Treasure
{
public:
    Treasure(ValuableItem& item1, ValuableItem& item2,ValuableItem& item3);
    std::vector<ValuableItem>& GetContents();

private:
    std::vector<ValuableItem> contents;
};

