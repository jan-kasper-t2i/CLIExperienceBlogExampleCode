#pragma once

using namespace System;

namespace InterfaceBackCpp {
    public ref class InterfaceForCSharp {
    public:
        InterfaceForCSharp() {}

        void SendTextToCpp(String^ text);
    };
}
