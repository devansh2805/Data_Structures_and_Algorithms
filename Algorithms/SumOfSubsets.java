import java.util.Scanner;
class SumOfSubsets
{
	public static void main(String[] args) 
	{
		int n, m, i;
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Number of Items: ");
		n = sc.nextInt();
		System.out.print("Enter Sum Value: ");
		m = sc.nextInt();

		int[] weights = new int[n];
		int[] values = new int[n];
		System.out.print("Enter "+n+" Weights: ");
		for(i=0;i<n;i++)
		{
			weights[i] = sc.nextInt();
		}
		System.out.print("\nAnswer in form of ");
		for(i=0;i<values.length;i++)
		{
			if(i==0)
				System.out.print("{x"+(i+1)+", ");
			else if(i==values.length-1)
				System.out.print("x"+(i+1)+"}:\n");
			else
				System.out.print("x"+(i+1)+", ");
		}
		subsetSum(weights,values,0,0,m);
		sc.close();	
	}

	static void subsetSum(int w[], int val[], int stindex, int sum, int finalsum)
	{
		if(sum == finalsum)
		{
			for(int i=0;i<val.length;i++)
			{
				if(i==0)
					System.out.print("{"+val[i]+", ");
				else if(i==val.length-1)
					System.out.print(val[i]+"}\n");
				else
					System.out.print(val[i]+", ");
			}
			return;
		}
		else
		{
			for(int i=stindex;i<w.length;i++)
			{
				if(sum > finalsum)
				{
					return;
				}
				else
				{
					val[i] = 1;
					subsetSum(w,val,i+1,sum+w[i],finalsum);
					val[i] = 0;
				}
			}
		}
	}
}