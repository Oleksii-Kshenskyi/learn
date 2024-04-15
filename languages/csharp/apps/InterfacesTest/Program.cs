AB ab = new();
((IA)ab).Method();
((IB)ab).Method();
ab.Method();

interface IA {
    void Method();
}

interface IB
{
    void Method();
}

class AB : IA , IB
{
    void IA.Method()
    {
        Console.WriteLine("Method A?..");
    }

    void IB.Method()
    {
        Console.WriteLine("Method B?..");
    }

    public void Method() {
        Console.WriteLine("SOME THIRD METHOD!??!");
    }
}