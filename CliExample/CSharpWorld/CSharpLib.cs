using InterfaceBackCpp;

namespace CSharpWorld
{
    public unsafe class CSharpLib
    {
        //Lesson leard: for the way c# communicates with c++, the project has to be set to target windows and the processor specifically!
        public void ReceiveDataFromCpp(string textToPrint)
        {
            Console.WriteLine("CSharpLib::ReceiveDataFromCpp was reached!");
            Console.WriteLine(textToPrint);

            string sendBack = "Hello to you too, from C#!";
            InterfaceForCSharp callToCpp = new InterfaceForCSharp();
            callToCpp.SendTextToCpp(sendBack);
        }

        public void ReceivePointer(char* pByte)
        {
            Console.WriteLine("CSharpLib::ReceivePointer was reached!");
            
            var s = new string(pByte);
            Console.WriteLine(s);
        }
    }
}
