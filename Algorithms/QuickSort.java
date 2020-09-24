import java.util.Random;
import java.util.Scanner;

class QuickSort
{
    static int comparisons = 0, swaps = 0;
    public static void main(String args[])
    {
        int n, i, x;
        Random rd = new Random();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Number of Entries: ");
        n = sc.nextInt();
        int[] array = new int[n+1];
        for(i=0;i<array.length-1;i++)
        {
            array[i] = /*i;*/rd.nextInt(1000);
        }
        array[n] = 1001;

        System.out.println("Array is:");
        for(i=0;i<array.length-1;i++)
        {
            System.out.print(array[i]+" ");
        }
        System.out.println();

        x = quickSort(array,0,array.length-1);

        System.out.println("\nSorted Array is:");
        for(i=0;i<array.length-1;i++)
        {
            System.out.print(array[i]+" ");
        }
        System.out.println("\nNo. of Comparisons: "+(comparisons+swaps));
        System.out.println("nlogn = "+(n*log(n)));
        //System.out.println("n^2 = "+(n*n));
    }

    public static int quickSort(int arr[],int p,int q)
    {
        int j;
        if(p<q)
        {
            j = partition(arr,p,q+1);
            quickSort(arr, p, j-1);
            quickSort(arr,j+1,q);
        }
        return 0;
    }

    public static int partition(int arr[],int m, int n)
    {
        int pivot, i ,j, temp;
        pivot = arr[m];
        i = m;
        j = n;
        do
        {
            do
            {
                comparisons += 1;
                i += 1;
            }while(arr[i] < pivot);

            do
            {
                comparisons += 1;
                j -= 1;
            }while(arr[j] > pivot);
            comparisons -= 2;

            if(i < j)
            {
                swaps += 1;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }while(i < j);
        
        arr[m] = arr[j];
        arr[j] = pivot;
        return j;
    }

    public static int log(int x)
    {
        return (int)(Math.log(x)/Math.log(2));
    }
}