import java.util.Scanner;
import java.util.Random;

class InsertionSort
{
	public static void main(String args[])
	{
		int n, i, nc;
		Random rd = new Random();
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Number of Entries: ");
		n = sc.nextInt();
		int[] array = new int[n];
		for(i=0;i<array.length;i++)
		{
			array[i] = rd.nextInt(100);
		}

		System.out.println("Array is:");
		for(i=0;i<array.length;i++)
		{
			System.out.print(array[i]+" ");
		}
		System.out.println();

		nc = insertionSort(array,n);

		System.out.println("\nSorted Array is:");
		for(i=0;i<array.length;i++)
		{
			System.out.print(array[i]+" ");
		}
		System.out.println("\n\nNo of Comparisons is: "+nc);
	}

	public static int insertionSort(int arr[], int n1)
	{
		int i, j, temp, count = 0;
		for(i=1;i<n1;i++)
		{
			j=i-1;
			temp = arr[i];
			count++;
			while(j>=0 && arr[j]>temp)
			{
				arr[j+1] = arr[j];
				j--;
				count++;
			}
			arr[j+1] = temp;
		}
		return count;
	}
}