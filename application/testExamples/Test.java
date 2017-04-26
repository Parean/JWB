public class Test
{
    public static void Main() {};

    public interface A
    {
        public void A1();
        public void A2();
    }

    public interface B
    {
        public void B1();
        public void B2();

        interface subB
        {
            public void subB1();
        }
    }

    public interface C extends A, B
    {
        public void C1();
    }

    public class D implements A
    {
        public void A1() {}
        public void A2() {}
        private void D1() {}
        public void D2() {}

        public void foo(int a) {};
        private void foo(int a, int b) {};
        public void foo(int a, String b) {};
    }

    public class G extends D implements A, C
    {
        public void A1() {}
        public void A2() {}
        public void B1() {}
        public void B2() {}
        public void C1() {}
        public void D1() {}
    } 

    public class E extends D
    {
    } 

    public interface GenericInterface<T>
    {
        public <T> boolean method1(GenericInterface<T> a);
        public <T> int method2(GenericInterface<T> b);
    }

    public class GenericClass<T> implements GenericInterface<T>
    {
        public int attribute1 = 0;
        private T attribute2;

        public <T> boolean method1(GenericInterface<T> a) { return true; }
        public <T> int method2(GenericInterface<T> b) { return 1; }
    }

    public interface NGInterface<T>
    {
        public T method1();
    }

    public class NGClass implements NGInterface<D>
    {
        public D method1() { return new D(); }

        int method3(Object direction) { return 1; }
    }

    public interface GenericInterfaceA<T>
    {
        public <T> boolean method1(GenericInterface<T> a);
        public <T> int method2(GenericInterface<T> b);
    }

    public class GenericClassA<T> implements GenericInterface<T>
    {
        public int attribute1 = 0;
        private T attribute2;

        public <T> boolean method1(GenericInterface<T> a) { return true; }
        public <T> int method2(GenericInterface<T> b) { return 1; }
    }

    public class GenericClassADer<T> extends GenericClass<Object>
    {
        public int attribute1 = 0;
        private T attribute2;
    }
}