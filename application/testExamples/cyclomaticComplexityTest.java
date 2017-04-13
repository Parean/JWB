// Average Cyclomatic Complexity 5
public class CyclomaticComplexityTest
{
	// Cyclomatic Complexity 6
	public static void switchAndIf(String[] args)
	{
		int month = 8;
		String monthString;
		switch (month) {
			case 1:  monthString = "January";
					 break;
			case 2:  monthString = "February";
					 break;
			case 3:  monthString = "March";
					 break;
			default: monthString = "Other month";
					 break;
		}
		System.out.println(monthString);
		if (month == 5)
			System.out.println("May");
		else
			System.out.println("Other month");
	}

	// Cyclomatic Complexity 5
	public void doAndWhile()
	{
		int i = 0;
		int j = 0;
		int k = 0;
		while (i < 10)
		{
			i++;
			while (j < 10);
			{
				j++;
				while (k < 10)
					k++;
			}
		}

		do {
		  system.out.print(i);
		  i++;
	  } while (i < 20);
	}

	// Cyclomatic Complexity 5
	public void catchAndFor()
	{
		try
		{
			System.err.print(" 0");
		}
		catch (RuntimeException e)
		{
			System.err.print(" 2.1");
			try
			{
				System.err.print(" 2.3");
			}
			catch (Throwable t)
			{
				System.err.print(" 2.4");
			}
			System.err.print(" 2.5");
		}
		catch (Error e)
		{
			System.err.print(" 3");
		}
		System.err.println(" 4");

		for (int i = 0; i < 100; i++)
			system.out.print(i);
	}

	// Cyclomatic Complexity 4
	private void ternaryOperator()
	{
		int a = 0;
		int b = 1;
		int c = 2;
		int minVal = (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
	}

	//Cyclomatic Complexity 0
	private class EmptyClass {}
}
