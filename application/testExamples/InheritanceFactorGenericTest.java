// Test for Inheritance Method Factor for Generics.
// Builds a full binary tree of inheritance of classes.
// Root is generic and his left successor - A2 - is too.
// Each class has one method and a constructor.
// Constructors should not be inhereted, but methods are inhereted by all inheritors.
// That is why A4 - root - inherites nothing, 
// A2 and A6, that have A4 as parent, inherite 1 method each
// and other classes inherite 2 methods. 0 + 1 + 1 + 2 + 2 + 2 + 2 = 10
// Total number of methods is 7 + 7 (method + constructor for each class).
// There we should have 10 / 14 = 0.714286 IMF.
public class InheritanceFactorGenericTest
{
	public class A4<T>
	{
		public A4() {}
		public void m4(T a) {}
	}

	public class A2<T> extends A4<T>
	{
		public A2() {}
		public void m2(T a) {}
	}
	
	public class A6 extends A4<Object>
	{
		public A6() {}
		public void m6(Object a) {}
	}
	
	public class A1 extends A2<Object>
	{
		public A1() {}
		public void m1(Object a) {}
	}
	
	public class A3 extends A2<Object>
	{
		public A3() {}
		public void m3(Object a) {}
	}
	
	public class A5 extends A6
	{
		public A5() {}
		public void m5(Object a) {}
	}
	
	public class A7 extends A6
	{
		public A7() {}
		public void m7(Object a) {}
	}
}