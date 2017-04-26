// Test for Inheritance Factor.
// Builds a full binary tree of inheritance of classes.
// Firstly, let me introduce Method Inheritance Factor:
// 		Each class has one method and a constructor.
// 		Constructors should not be inhereted, but methods are inhereted by all inheritors.
// 		If method was overriden, its last state is inhereted.
// 		That is why A4 - root - inherites nothing, 
// 		A2 and A6, that have A4 as parent, override one method each
// 		and other classes inherite 1 method and override 1. 0 + 0 + 0 + 1 + 1 + 1 + 1 = 4
// 		Total number of methods is 7 (method; constructors are not counted).
// 		So we should have 4 / 7 = 0.571429 IMF.
// 		As for Polymorphism Factor, 0 + 1 + 1 + 1 + 1 + 1 + 1 = 6 and 6 / 7 = 0.857143.
// Secondly, let me give a talk of Attribute Inheritance Factor.
// 		All classes have 1 int field, that is inhereted.
// 		Inherited: 0 + 1 + 1 + 2 + 2 + 2 + 2 = 10; Own: 1 * 7 = 7.
// 		So we should have the result of 10 / 7 = 1.42857
// 		Generally speaking, AIF is way less complicated, cause attributes cannot be overriden.
public class InheritanceFactorTest
{
	public class A4
	{
		public A4() {}
		public void m4() {}

		public int a4;
	}

	public class A2 extends A4
	{
		public A2() {}
		public void m2() {}
		public void m4() {}

		public int a2;
	}
	
	public class A6 extends A4
	{
		public A6() {}
		public void m6() {}
		public void m4() {}

		public int a6;
	}
	
	public class A1 extends A2
	{
		public A1() {}
		public void m1() {}
		public void m2() {}

		public int a1;
	}
	
	public class A3 extends A2
	{
		public A3() {}
		public void m3() {}
		public void m2() {}

		public int a3;
	}
	
	public class A5 extends A6
	{
		public A5() {}
		public void m5() {}
		public void m6() {}

		public int a5;
	}
	
	public class A7 extends A6
	{
		public A7() {}
		public void m7() {}
		public void m6() {}

		public int a7;
	}
}