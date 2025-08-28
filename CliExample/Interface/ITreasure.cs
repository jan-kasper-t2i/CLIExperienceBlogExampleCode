namespace Interface;

public interface ITreasure
{
    IReadOnlyList<IValuableItem> Contents { get; }
    int OverallValue();
}

public interface IValuableItem
{
    string Name { get; }
    int Value { get; }
}