import java.util.Scanner;
class GraphColoring
{
	public static void main(String[] args) 
	{
		int n, i, d, m;
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter number of vertices: ");
		n = sc.nextInt();
		System.out.println();

		LinkedList.Node graph[] = new LinkedList.Node[n];
		LinkedList adj = new LinkedList();

		for(i=0;i<n;i++)
		{
			while(true)
			{
				System.out.print("Enter Adjacent node of "+(i+1)+" [Press 0 if no more adjacent]: ");
				d = sc.nextInt();
				if(d != 0)
				{
					adj.append(d);
		 		}
				else
				{
					graph[i] = adj.head;
					adj.head = null;
					break;
				}
			}
			System.out.println();
		}

		System.out.println("Graph is {Adjacency List}:");
		for(i=0;i<n;i++)
		{
			System.out.print((i+1)+": ");
			LinkedList.printList(graph[i]);
			System.out.println();
		}

		m = chromaticNumber(graph,n);
		System.out.println("Chromatic Number for Graph is: "+m);

		int colors[] = new int[n];
		System.out.println("\n Solutions are [in form of {x1,x2,...,xn}]: ");
		graphColor(graph,n,colors,0,m);
		sc.close();
	}

	static int chromaticNumber(LinkedList.Node g[], int n)
	{
		int i, j, k, m=0;
		int colors[] = new int[n];
		for(i=0;i<n;i++)
		{
			colors[i] = 0;
		}
		for(i=0;i<n;i++)
		{
			for(j=1;j<=n;j++)
			{
				colors[i] = j;
				if(LinkedList.colorValidity(g[i],j,colors))
				{
					break;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			if(m<colors[i])
			{
				m = colors[i];
			}
		}
		return m;
	}

	static void graphColor(LinkedList.Node g[], int n, int[] co, int no, int cmno)
	{
		int i;
		if(no == n)
		{
			for(i=0;i<n;i++)
			{
				if(i==0)
					System.out.print("{"+co[i]+", ");
				else if(i==n-1)
					System.out.print(co[i]+"}\n");
				else
					System.out.print(co[i]+", ");
			}
			return;
		}
		for(i=1;i<=cmno;i++)
		{
			if(LinkedList.colorValidity(g[no],i,co))
			{
				co[no] = i;
				graphColor(g,n,co,no+1,cmno);
				co[no] = 0;
			}
			else
			{
				continue;
			}
		}
	}
}

class LinkedList
{
	class Node
	{
		int vindex;
		Node link;

		Node()
		{
			vindex = 0;
			link = null;
		}
	}

	Node head;
	LinkedList()
	{
		head = null;
	}

	void append(int i)
	{
		Node temp;
		Node newnode = new Node();
		newnode.vindex = i;

		if(this.head == null)
		{
			this.head = newnode;
		}
		else
		{
			temp = this.head;
			while(temp.link != null)
				temp = temp.link;	
			temp.link = newnode;
		}
	}

	static void printList(Node h)
	{
		Node temp = h;
		while(temp!=null)
		{
			if(temp.link!=null)
				System.out.print(temp.vindex+"->");
			else
				System.out.print(temp.vindex);
			temp = temp.link;
		}
	}

	static boolean colorValidity(Node h, int c, int[] ca)
	{
		Node temp = h;
		while(temp!=null)
		{
			if(ca[temp.vindex-1]==c)
			{
				return false;
			}
			temp = temp.link;
		}
		return true;
	}
}