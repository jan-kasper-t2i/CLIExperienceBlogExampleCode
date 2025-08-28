using Interface;
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
        
        public void ReceiveTreasure(ITreasure treasure)
        {
            Console.WriteLine("CSharpLib::ReceiveTreasure was reached!");
            Console.WriteLine("Treasure contains: " +string.Join(", ", treasure.Contents.Select(i => i.Name)));
            Console.WriteLine("Treasure is worth: " + treasure.OverallValue());
            
            InterfaceForCSharp callToCpp = new InterfaceForCSharp();
            callToCpp.SendTreasureToCpp(treasure);
        }

        //needs unsafe
        public void ReceivePointer(char* pByte)
        {
            Console.WriteLine("CSharpLib::ReceivePointer was reached!");
            
            var s = new string(pByte);
            Console.WriteLine(s);
        }
    }

    //TODO JP Treasure results in nameing conflicts
    public class ManagedTreasure: ITreasure
    {
        public ManagedTreasure(IReadOnlyList<IValuableItem> contents)
        {
            Contents = contents;
        }
        public IReadOnlyList<IValuableItem> Contents { get;} 
    
        public int OverallValue()
        {
            return Contents.Sum(valuable => valuable.Value);
        }
    }
    
    public class ManagedValuableItem: IValuableItem
    {
        public ManagedValuableItem(string name, int value)
        {
            Name = name;
            Value = value;
        }
        public string Name { get; }
        public int Value { get; }
    }
}
