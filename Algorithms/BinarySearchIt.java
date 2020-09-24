import java.util.Scanner;

class BinarySearchIt
{
	public static void main(String[] args)
	{
		int i, n, k, c;
		System.out.print("Enter number of elements: ");
		Scanner s1 = new Scanner(System.in);
		n = s1.nextInt();
		int arr[] = new int[n];
		for(i=0;i<n;i++)
		{
			arr[i] = i;
		}

		System.out.println("Array is:");
    	for(i=0;i<arr.length;i++)
    	{
 	     	System.out.print(arr[i]+" ");
    	}
    	System.out.println();
		
		System.out.print("Enter the search key: ");
		k = s1.nextInt();
		c = binarySearch(arr,n,k);
		System.out.println("\nNo. of Comparisons: "+c);
        System.out.println("Value of log(n) = "+(Math.log(n)/Math.log(2)));
	}

	static int binarySearch(int arr[], int n, int k)
	{
		int beg = 0, end = n-1, flag = 0, count = 0;

		while (beg <= end)
		{
			int mid = (beg + end)/2;
			if(k == arr[mid])
			{
				count++;
				System.out.println("Search key found at index: " +mid);
				flag = 1;
				break;
			}
			else if(k < arr[mid])
			{
				end = mid-1;
				count++;
			}
			else
			{
				beg = mid+1;
				count++;
			}
		}
		if(flag==0)
		{
			System.out.println("Search key not found");
		}
		return count;
	}
}