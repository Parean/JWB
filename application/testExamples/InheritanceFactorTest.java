// Test for Inheritance Method Factor.
// Builds a full binary tree of inheritance of classes.
// Each class has one method and a constructor.
// Constructors should not be inhereted, but methods are inhereted by all inheritors.
// That is why A4 - root - inherites nothing, 
// A2 and A6, that have A4 as parent, inherite 1 method each
// and other classes inherite 2 methods. 0 + 1 + 1 + 2 + 2 + 2 + 2 = 10
// Total number of methods is 7 + 7 (method + constructor for each class).
// There we should have 10 / 14 = 0.714286 IMF.
public class InheritanceFactorTest
{
	public class A4
	{
		public A4() {}
		public void m4() {}
	}

	public class A2 extends A4
	{
		public A2() {}
		public void m2() {}
	}
	
	public class A6 extends A4
	{
		public A6() {}
		public void m6() {}
	}
	
	public class A1 extends A2
	{
		public A1() {}
		public void m1() {}
	}
	
	public class A3 extends A2
	{
		public A3() {}
		public void m3() {}
	}
	
	public class A5 extends A6
	{
		public A5() {}
		public void m5() {}
	}
	
	public class A7 extends A6
	{
		public A7() {}
		public void m7() {}
	}
}