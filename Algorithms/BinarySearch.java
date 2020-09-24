import java.util.Random;
import java.util.Scanner;

class BinarySearch 
{
    static int count = 0;
    public static void main(String args[])
    {
        int n, i, x, key;
        Random rd = new Random();
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Number of Entries: ");
        n = sc.nextInt();
        int[] array = new int[n];
        for(i=0;i<array.length;i++)
        {
            array[i] = 2*i;
        }

        System.out.println("Array is:");
        for(i=0;i<array.length;i++)
        {
            System.out.print(array[i]+" ");
        }
        System.out.println();

        System.out.print("Enter Key to be searched: ");
        key = sc.nextInt();

        x = binarysearch(array,0,array.length-1,key);
        if(x==-1)
            System.out.println("Element not Found");
        else
            System.out.println("Element Found at index "+x);
        
        System.out.println("\nNo. of Comparisons: "+count);
        System.out.println("Value of log(n) = "+(Math.log(n)/Math.log(2)));
    }

    public static int binarysearch(int arr[],int n,int m,int key)
    {
        if(n==m)
        {
            if(key == arr[n])
                return n;
            else
                return -1;
        }
        else
        {
            int mid = (n+m)/2;
            if(key == arr[mid])
            {
                count += 1;
                return mid;
            }
            else if(key < arr[mid])
            {
                count += 1;
                return binarysearch(arr, n, mid-1, key);
            }
            else
            {
                count += 1;
                return binarysearch(arr, mid+1, m, key);
            }
        }
    }
}