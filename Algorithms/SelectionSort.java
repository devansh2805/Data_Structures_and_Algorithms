import java.util.Scannner;
import java.util.Random;

class SelectionSort
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
			array[i] = rd.nextInt(1000);
		}

		System.out.println("Array is:");
		for(i=0;i<array.length;i++)
		{
			System.out.print(array[i]+" ");
		}
		System.out.println();

		nc = selectionSort(array);
		
		System.out.println("\nSorted Array is:");
		for(i=0;i<array.length;i++)
		{
			System.out.print(array[i]+" ");
		}
		System.out.println("\n\nNo of comparisons is: "+nc);
	}

	public static int selectionSort(int arr[])
  	{
    	int i, n, temp, comparisons=0,swaps=0;
    	n = arr.length;
    	for(i=0;i<n-1;i++)
    	{
      		int minind = i;
      		for(int j=i+1;j<n;j++)
      		{
        		comparisons++;
        		if(arr[j]<arr[minind])
        		{
          			minind = j;
        		}
      		}
      		if(i != minind)
      		{
        		temp = arr[i];
        		arr[i] = arr[minind];
        		arr[minind] = temp;
        		swaps++;
      		}
    	}
    	return comparisons+swaps;
  	}
}