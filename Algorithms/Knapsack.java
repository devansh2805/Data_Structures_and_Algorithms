import java.util.Scanner;

class Knapsack 
{
    static int comparisons = 0, swaps = 0, computations = 0;
    public static void main(String[] args)
    {
        int i, n, j, w, p, capacity, count = 0;
        float profit = 0.0f;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Number of Items: ");
        n = sc.nextInt();
        System.out.print("Enter Capacity of Knapsack: ");
        capacity = sc.nextInt();

        Item it[] = new Item[n+1];
        float ans[] = new float[n];
        System.out.print("\n\n");
        
        for(i=0;i<n;i++)
        {
            System.out.print("Enter Profit of Item "+(i+1)+" : ");
            p = sc.nextInt();
            System.out.print("Enter Weight of Item "+(i+1)+" : ");
            w = sc.nextInt();
            float x = (float)p/(float)w;
            it[i] = new Item(w,p,i+1,x);
        }
        System.out.println();
        for(i=0;i<n;i++)
        {
            System.out.println("Item Name: "+it[i].name);
            System.out.println("Weight of "+it[i].name+": "+it[i].weight);
            System.out.println("Profit of "+it[i].name+": "+it[i].profit);
            System.out.println("Profit/Weight of "+it[i].name+": "+it[i].pbyw);
        }
        System.out.println("\n");
        it[n] = new Item(0,0,0,100000);
        quickSort(it, 0, n);

        System.out.print("Item Names Sorted in Increaing order of Profit/Weight ratio: ");
        System.out.print("(");
        for(i=n-1;i>=0;i--)
        {
            if(i!=0)
                System.out.print(it[i].name+", ");
            else
                System.out.println(it[i].name+")");
        }

        for(i=n-1;i>=0;i--)
        {
            if(capacity != 0)
            {
                computations += 1;
                if(it[i].weight <= capacity)
                {
                    ans[it[i].name-1] = 1.0f;
                    profit += it[i].profit;
                    capacity -= it[i].weight;   
                }
                else
                {
                    ans[it[i].name-1] = (float)capacity/it[i].weight;
                    profit += ans[it[i].name-1]*it[i].profit;
                    capacity = 0;
                }
            }
            else
            {
                break;
            }
        }

        System.out.print("Answer: Fraction of - (");
        for(i=0;i<n;i++)
        {
            if(i != n-1)
                System.out.print((i+1)+", ");
            else
                System.out.print((i+1)+"): (");
        }
        for(i=0;i<n;i++)
        {
            if(i != n-1)
                System.out.print(ans[i]+", ");
            else
                System.out.print(ans[i]+")");
        }
        System.out.println("\nProfit: "+profit);
        sc.close();
    }

    public static void quickSort(Item arr[],int p,int q)
    {
        int j;
        if(p<q)
        {
            j = partition(arr,p,q+1);
            quickSort(arr, p, j-1);
            quickSort(arr,j+1,q);
        }
    }

    public static int partition(Item arr[],int m, int n)
    {
        int i ,j;
        float pivot;
        Item temp;
        pivot = arr[m].pbyw;
        i = m;
        j = n;
        
        do
        {
            do
            {
                comparisons += 1;
                i += 1;
            }while(arr[i].pbyw < pivot);

            do
            {
                comparisons += 1;
                j -= 1;
            }while(arr[j].pbyw > pivot);
            comparisons -= 2;

            if(i < j)
            {
                swaps += 1;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

        }while(i < j);
    
        temp = arr[m];
        arr[m] = arr[j];
        arr[j] = temp;

        return j;
    }
}

class Item
{
    int weight;
    int profit;
    int name;
    float pbyw;

    Item(int w, int p, int n, float pb)
    {
        weight = w;
        profit = p;
        name = n;
        pbyw = pb;
    }
}
