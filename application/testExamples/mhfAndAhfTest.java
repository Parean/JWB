/**
	MhfAndAhfTest has 0 methods, 0 of which is private.
	Class has 5 methods, 2 of which is private.
	GenericClass has 3 methods, 1 of which is private.
	Interface has 3 methods, 1 of which is private.
	GenericInterface has 2 methods, 1 of which is private.
	MhfAndAhfTest has 0 attributes, 0 of which is private.
	Class has 3 attributes, 1 of which is private.
	GenericClass has 2 attributes, 1 of which is private.

	MHF 0.384615
	AHF 0.4
*/

public class MhfAndAhfTest
{
	private class Class
	{
		private static final int attribute1;
		public static double attribute2;
		int attribute3 = 0;

		private Class()
		{
			int i = 0;
		}

		public boolean method1(){
			return attribute3 < attribute2;
		}

		private int method2()
		{
			return attribute1;
		}

		public void method3(Object x){}
		public Object method4(int pos){}
	}

	public class GenericClass<T>
	{
		public int attribute1 = 0;
		private T attribute2;

		private GenericClass(T t){}

		public T method1()
		{
			return this.t;
		}

		public void method2(T t1)
		{
			this.t=t1;
		}
	}

	public interface Interface
	{
		private int method1(Direction direction);
		public int method2(Direction direction);
		int method3(Direction direction);
	}

	public interface GenericInterface<T>
	{
		public <T> boolean method1(GenericInterface<T> a);
		private <T> int method2(GenericInterface<T> b);
	}
}
