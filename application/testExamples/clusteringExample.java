public class Class_A
{
	public static int attributeA1;
	public static int attributeA2;

	public static void mA1()
	{
		attributeA1 = 0;
		mA2();
	}

	public static void mA2()
	{
		attributeA2 = 0;
		attributeA1 = 0;
	}

	public static void mA3()
	{
		attributeA2 = 0;
		attributeA1 = 0;
		mA1();
		mA2();
	}
}

public class Class_B
{
	private static int attributeB1;
	private static int attributeB2;

	public static void mB1()
	{
		Class_A.attributeA1=0;
		Class_A.attributeA2=0;
		Class_A.mA1();
	}

	public static void mB2()
	{
		attributeB1=0;
		attributeB2=0;
	}

	public static void mB3()
	{
		attributeB1=0;
		mB1();
		mB2();
	}
}
