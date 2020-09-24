import java.util.Scanner;

class MatrixChain
{
	static char mname = 'A';
	public static void main(String[] args)
	{
		int i, n;
		Scanner sc = new Scanner(System.in);
		System.out.print("\nEnter Number of Matrices to multiply: ");
		n = sc.nextInt();
		int inparr[] = new int[n+1];
		int calarr[][] = new int[n+1][n+1];
		System.out.print("Enter Order of matrix Sequentially: ");
		for(i=0;i<inparr.length;i++)
			inparr[i] = sc.nextInt();

		int c = matrixOrder(inparr,calarr,1,n);
		printTable(calarr,n);
		System.out.print("\n\nOrder of Multiplication is: ");
		printOrder(calarr,1,n);
		System.out.println("\nMinimum number of Computations for multiplication are: "+c);
		sc.close();	
	}

	static int matrixOrder(int inp[], int val[][], int i, int j)
	{
		if(i==j)
		{
			val[i][j] = 0;
			val[j][i] = 0;
			return 0;
		}
		int k, min, temp;
		min = Integer.MAX_VALUE;

		for(k=i;k<j;k++)
		{
			temp = matrixOrder(inp,val,i,k)+matrixOrder(inp,val,k+1,j)+inp[i-1]*inp[k]*inp[j];
			if(temp < min)
			{
				min = temp;
				val[i][j] = min;
				val[j][i] = k;
			}
		}
		return min;
	}

	static void printTable(int val[][], int n)
	{
		System.out.println("\nM-Value Table:");
		int l;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
				System.out.print(padLeft(" ",4));
			l = n-i+1;
			for(int k=1;k<=i;k++)
			{
				System.out.print(padLeft(((Integer)val[k][l]).toString(),4));
				System.out.print(padLeft(" ",4));
				l++;
			}
			System.out.println();
		}

		System.out.println("\nK-Value Table:");
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
				System.out.print(padLeft(" ",4));
			l = n-i+1;
			for(int k=1;k<=i;k++)
			{
				System.out.print(padLeft(((Integer)val[l][k]).toString(),4));
				System.out.print(padLeft(" ",4));
				l++;
			}
			System.out.println();
		}
	}

	static void printOrder(int val[][],int i, int j)
	{
		if(i==j)
		{
			System.out.print(mname);
			mname++;
			return;
		}
		System.out.print("(");
		printOrder(val,i,val[j][i]);
		printOrder(val,val[j][i]+1,j);
		System.out.print(")");
	}

	public static String padLeft(String s, int n) 
	{
    	return String.format("%"+n+"s",s);  
	}	
}