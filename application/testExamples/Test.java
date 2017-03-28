public interface A
{
    void A1();
    void A2();
}

public interface B
{
    void B1();
    void B2();

    interface subB
    {
        void subB1();
    }
}

public interface C extends A, B
{
    void C1();
}

public class D implements A
{
    void A1() {}
    void D1() {}
    void D2() {}
}

public class G extends D implements A, C
{
    void A1() {}
    void A2() {}
    void B1() {}
    void B2() {}
    void C1() {}
    void D1() {}
} 