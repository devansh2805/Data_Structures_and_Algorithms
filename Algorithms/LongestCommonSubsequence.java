import java.util.Scanner;
class LongestCommonSubsequence
{
	static LinkedList list = new LinkedList();
	public static void main(String[] args) 
	{
		String seq1 = "", seq2 = "";
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter First String Sequence: ");
		seq1 = sc.next();
		seq1 = seq1.toLowerCase();
		System.out.print("Enter Second String Sequence: ");
		seq2 = sc.next();
		seq2 = seq2.toLowerCase();
		lcsComputation(seq1,seq2);
		sc.close();
	}

	static void lcsComputation(String str1, String str2)
	{
		int sl1, sl2, i, j;
		sl1 = str1.length();
		sl2 = str2.length();
		int lcstable[][] = new int[sl1+1][sl2+1];
		for(i=0;i<sl1+1;i++)
		{
			for(j=0;j<sl2+1;j++)
			{
				if(i==0||j==0)
					lcstable[i][j] = 0;
				else if(str1.charAt(i-1)==str2.charAt(j-1))
					lcstable[i][j] = lcstable[i-1][j-1]+1;
				else
				{
					if(lcstable[i-1][j] > lcstable[i][j-1])
						lcstable[i][j] = lcstable[i-1][j];
					else
						lcstable[i][j] = lcstable[i][j-1];
				}
			}
		}
		System.out.println("\n");
		System.out.println("Longest Common Subsequence Computation Table:");
		for(i=0;i<sl1+3;i++)
		{
			for(j=0;j<sl2+3;j++)
			{
				if(i==0)
				{
					if(j==0||j==1)
						System.out.print(padLeft("",3));
					else
						System.out.print(padLeft(((Integer)(j-2)).toString(),3));
				}
				else if(i==1)
				{
					if(j==0||j==1||j==2)
						System.out.print(padLeft("",3));
					else
						System.out.print(padLeft(Character.toString(str2.charAt(j-3)),3));
				}
				else
				{
					if(i==2)
					{
						if(j==0)
							System.out.print(padLeft(((Integer)(i-2)).toString(),3));
						else if(j==1)
							System.out.print(padLeft("",3));
						else
							System.out.print(padLeft(((Integer)(lcstable[i-2][j-2])).toString(),3));
					}
					else
					{
						if(j==0)
							System.out.print(padLeft(((Integer)(i-2)).toString(),3));
						else if(j==1)
							System.out.print(padLeft(Character.toString(str1.charAt(i-3)),3));
						else
							System.out.print(padLeft(((Integer)(lcstable[i-2][j-2])).toString(),3));					}
				}
			}
			System.out.println();
		}
		System.out.println("\nLength of Longest Common Subsequence is: "+lcstable[sl1][sl2]);
		backTrackLcs(lcstable,"",str1,str2,sl1,sl2,lcstable[sl1][sl2]-1);
		System.out.print("\nAll Possible Longest Common Subsequences are: ");
		list.printList();
		System.out.println("\n\n");
	}

	static void backTrackLcs(int lcs[][], String rev, String s1, String s2, int x, int y, int z)
	{
		if(z<0)
		{
			String flcs = "";
			for(int i=rev.length()-1;i>=0;i--)
			{
				flcs = flcs + rev.charAt(i);
			}
			
			if(list.exists(flcs))
			{
				return;
			}
			else
			{
				list.append(flcs);
				return;
			}
		}
		else
		{
			if(s1.charAt(x-1)==s2.charAt(y-1))
			{
				rev = rev + s1.charAt(x-1);
				backTrackLcs(lcs,rev,s1,s2,x-1,y-1,z-1);
				rev = rev.substring(0,rev.length()-1).trim();
			}
			else if(lcs[x-1][y] > lcs[x][y-1])
			{
				backTrackLcs(lcs,rev,s1,s2,x-1,y,z);
			}
			else if(lcs[x-1][y] < lcs[x][y-1])
			{
				backTrackLcs(lcs,rev,s1,s2,x,y-1,z);
			}
			else if(lcs[x-1][y] == lcs[x][y-1])
			{
				backTrackLcs(lcs,rev,s1,s2,x-1,y,z);
				backTrackLcs(lcs,rev,s1,s2,x,y-1,z);
			}
		}
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
		String data;
		Node link;
		Node()
		{
			data = "";
			link = null;
		}
	}

	Node head;
	LinkedList()
	{
		head = null;
	}

	void append(String s)
	{
		Node temp;
		Node newnode = new Node();
		newnode.data = s;

		if(this.head == null)
		{
			this.head = newnode;
			newnode.link = null;
		}
		else
		{
			temp = this.head;
			while(temp.link != null)
				temp = temp.link;	
			temp.link = newnode;
			newnode.link = null;
		}
	}

	void printList()
	{
		Node temp = this.head;
		while(temp != null)
		{
			System.out.print(temp.data+" ");
			temp = temp.link;
		}
	}

	boolean exists(String s1)
	{
		Node temp = this.head;
		while(temp != null)
		{
			String x = temp.data;
			if(s1.equals(x))
			{
				return true;
			}
			temp = temp.link;
		}
		return false;
	}
}