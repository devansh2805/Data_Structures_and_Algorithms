import java.util.Scanner;

class SingleSourceShortestPath
{
	public static void main(String[] args) 
	{
		int n, i, d;
		char c = 'A', x;
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter number of vertices: ");
		n = sc.nextInt();
		System.out.println();

		LinkedList.Node harr[] = new LinkedList.Node[n];
		LinkedList adj = new LinkedList();

		for(i=0;i<n;i++)
		{
			while(true)
			{
				System.out.print("Enter Adjacent node of "+(char)(c+i)+" [Press 0 if no more adjacent]: ");
				x = sc.next().charAt(0);
				if(x != '0')
				{
					System.out.print("Enter Distance between "+(char)(c+i)+" and "+x+": ");
					d = sc.nextInt();
					adj.append(x,((int)(x))-65,d);
				}
				else
				{
					harr[i] = adj.head;
					adj.head = null;
					break;
				}
			}
			System.out.println();
		}

		System.out.println("Graps is: (Adjacency List) {in form of (Vertex,EdgeLength)}");
		for(i=0;i<n;i++)
		{
			System.out.print((char)(65+i)+": ");
			LinkedList.display(harr[i]);
			System.out.println();
		}

		System.out.print("\nEnter Starting Vertex: ");
		x = sc.next().charAt(0);
		System.out.println();
		singleSourceShortestPath(x,harr);
		sc.close();
	}

	static void singleSourceShortestPath(char v, LinkedList.Node graph[])
	{
		int n = graph.length, i, j=0;
		LinkedList.Node temp;
		boolean visited[] = new boolean[n];
		int distance[][] = new int[n-1][n+1];
		char paths[][] = new char[n][n];
		for(i=0;i<n;i++)
		{
			temp = graph[(int)(v)-65];
			if(LinkedList.presence(temp,i) == true)
				distance[j][i] = LinkedList.edgeDistance(temp,i);
			else
				distance[j][i] = Integer.MAX_VALUE;
			visited[i] = false;
		}

		distance[j][n] = (int)(v)-65+1;
		distance[j][(int)(v)-65] = 0;
		visited[(int)(v)-65] = true;

		for(i=1;i<n-1;i++)
		{
			int minind;
			
			minind = findMinVertex(distance[j],visited);
			visited[minind] = true;
			temp = graph[minind];

			for(int k=0;k<n;k++)
				distance[j+1][k] = distance[j][k];
			distance[j+1][n] = minind+1;

			while(temp != null)
			{
				if(visited[temp.vindex]==false)
				{
					int newdist;
					newdist = distance[j+1][minind] + temp.edist;
					if(newdist < distance[j+1][temp.vindex])
						distance[j+1][temp.vindex] = newdist;
				}
				temp = temp.link;
			}
			j++;
		}
		System.out.println("Calculation Table: ");
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n+1;j++)
			{
				if(distance[i][j] != Integer.MAX_VALUE)
					System.out.print(padLeft(((Integer)distance[i][j]).toString(),12)+" ");
				else
					System.out.print(padLeft("Infinity",12)+" ");
			}
			System.out.println();
		}
		System.out.println();

		for(i=0;i<n;i++)
			findPath(paths,distance,i,n);

		for(i=0;i<n;i++)
		{
			if(distance[n-2][i] != Integer.MAX_VALUE)
			{
				System.out.print("Shortest Distance of "+v+" to "+(char)(65+i)+" is: "+distance[n-2][i]);
				System.out.print(" Path is: "+v+" -> ");
				for(j=n-1;j>=0;j--)
				{
					if(j != 0)
					{
						if(paths[i][j]!='\0')
							System.out.print(paths[i][j]+" -> ");
					}
					else
						System.out.println(paths[i][j]);
				}
			}
			else
			{
				System.out.print("Shortest Distance of "+v+" to "+(char)(65+i)+" is: Infinity");
				System.out.println("Vertex "+(char)(65+i)+" unreachable from "+v);	
			}
		}
	}

	public static String padLeft(String s, int n) 
	{
    	return String.format("%"+n+"s",s);  
	}

	static void findPath(char path[][],int dist[][], int vertex, int n)
	{
		int i, j=1, k, v = vertex;
		path[v][0] = (char)(vertex+65);
		for(i=n-2;i>0;i--)
		{
			k = dist[i][vertex];
			if(k < dist[i-1][vertex])
			{
				path[v][j] = (char)(dist[i][n]+65-1);
				j++;
				vertex = dist[i][n]-1;
			}
		}
		for(k=j;k<n;k++)
			path[vertex][k] = '\0';
	}

	static int findMinVertex(int dist[],boolean v[])
	{
		int i;
		int minvertex = -1;
		for(i=0;i<dist.length-1;i++)
		{
			if(v[i]==false && (minvertex == -1 || dist[i] < dist[minvertex]))
				minvertex = i;
		}
		return minvertex;
	} 
}

class LinkedList
{
	class Node
	{
		char vname;
		int vindex;
		int edist;
		Node link;

		Node()
		{
			vname = '\0';
			vindex = 0;
			edist = 0;
			link = null;
		}
	}

	Node head;
	LinkedList()
	{
		head = null;
	}

	void append(char v, int i, int e)
	{
		Node temp;
		Node newnode = new Node();
		newnode.vname = v;
		newnode.vindex = i;
		newnode.edist = e;

		if(head == null)
		{
			head = newnode;
		}
		else
		{
			temp = head;
			while(temp.link != null)
				temp = temp.link;	
			temp.link = newnode;
		}
	}

	static void display(Node h)
	{
		Node temp;
		temp = h;
		if(temp == null)
			System.out.print("NULL");
		while(temp != null) 
		{
			if(temp.link != null)
				System.out.print("("+temp.vname+","+temp.edist+") -> ");
			else
				System.out.print("("+temp.vname+","+temp.edist+") -> NULL");	
			temp = temp.link;	
		}
	}

	static boolean presence(Node h, int a)
	{
		Node temp = h;
		while(temp != null)
		{
			if(temp.vindex == a)
				return true;
			temp = temp.link;
		}
		return false;
	}

	static int edgeDistance(Node h, int a)
	{
		Node temp = h;
		while(temp != null)
		{
			if(temp.vindex == a)
				return temp.edist;
			temp = temp.link;
		}
		return -1;
	}
}