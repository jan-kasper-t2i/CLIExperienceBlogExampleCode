#pragma once
#include "Treasure.h"

class TreasureConverter
{
public:
    TreasureConverter(Interface::ITreasure^ treasure);
    TreasureConverter(Treasure& treasure);
    static Interface::ITreasure^ ToITreasure(Treasure& treasure);
};
