import java.util.Scanner;

class AllPairShortestPath
{
	static LinkedList list = new LinkedList();
	public static void main(String[] args) 
	{
		int i, j, n;
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter Number of Vertices for Graph: ");
		n = sc.nextInt();
		int graph[][] = new int[n][n];
		System.out.println("Enter Adjacency Matrix for Graph: ");
		for(i=0;i<n;i++)
		{
			while(true)
			{
				System.out.print("Enter Adjacent Vertex of Vertex "+(i+1)+" {Enter 0 if no left}: ");
				j = sc.nextInt();
				if(j==0)
					break;
				else
				{
					System.out.print("Enter Weight of Edge from vertex "+(i+1)+" to "+j+": ");
					graph[i][j-1] = sc.nextInt();
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
					continue;
				else if(graph[i][j]==0)
					graph[i][j] = Integer.MAX_VALUE;
			}
		}
		System.out.println("Graph is {A0}: ");
		printGraph(graph,n);
		allPairShortPath(graph,n);
		sc.close();
	}


	static void allPairShortPath(int g[][], int n)
	{
		int i,j,k;
		int a[][] = new int[n][n];
		int path[][] = new int[n][n];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j] = g[i][j];
				path[i][j] = -1;
			}
		}

		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(i==j)
						continue;
					if(k==i||k==j)
						continue;
					if((g[i][k]!=Integer.MAX_VALUE)&&(g[k][j]!=Integer.MAX_VALUE)&&(g[i][j]>g[i][k]+g[k][j]) )
					{
						path[i][j] = k;
						a[i][j] = g[i][k]+g[k][j];
					}
				}
			}
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					g[i][j] = a[i][j];
				}
			}
			System.out.println("\nA"+(k+1)+": ");
			printGraph(g,n);
			System.out.println("\n");
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
				{
					System.out.println((i+1)+" to "+(j+1)+": No path cost=0");
				}
				else if(g[i][j]==Integer.MAX_VALUE)
				{
					System.out.println((i+1)+" to "+(j+1)+": Path Does not exist cost=Infinity");
				}
				else
				{
					System.out.print((i+1)+" to "+(j+1)+": ");
					printPath(path,i,j);
					list.printList();
					System.out.print(" cost="+g[i][j]+"\n");
					list.head = null;
				}
			}
		}
	}

	static void printPath(int p[][], int i, int j)
	{
		if(p[i][j]==-1)
		{
			if(!list.exists(i+1))
				list.append(i+1);
			if(!list.exists(j+1))
				list.append(j+1);
		}
		else
		{
			printPath(p,i,p[i][j]);
			printPath(p,p[i][j],j);
		}
	}

	static void printGraph(int x[][], int n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(x[i][j]==Integer.MAX_VALUE)
				{
					System.out.print(padLeft("Infinity",9));
					System.out.print(padLeft(" ",2));
				}
				else
				{
					System.out.print(padLeft(((Integer)x[i][j]).toString(),9));
					System.out.print(padLeft(" ",2));
				}			
			}
			System.out.println();
		}
		System.out.println();
	}

	public static String padLeft(String s, int n) 
	{
    	return String.format("%"+n+"s",s);  
	}
}

class LinkedList
{
	class Node
	{
		int data;
		Node link;
		Node()
		{
			data = 0;
			link = null;
		}
	}

	Node head;
	LinkedList()
	{
		head = null;
	}

	void append(int x)
	{
		Node temp = this.head;
		Node newnode = new Node();
		newnode.data = x;
		newnode.link = null;
		if(this.head==null)
		{
			this.head = newnode;
			temp = head;
		}
		else
		{
			while(temp.link!=null)
			{
				temp = temp.link;
			}
			temp.link = newnode;
			temp = temp.link;
		}
	}

	void printList()
	{
		Node temp = this.head;
		while(temp != null)
		{
			if(temp.link != null)
				System.out.print(temp.data+"->");
			else
				System.out.print(temp.data);
			temp = temp.link;
		}
	}

	boolean exists(int x)
	{
		Node temp = this.head;
		while(temp != null)
		{
			if(temp.data==x)
			{
				return true;
			}
			temp = temp.link;
		}
		return false;
	}
}