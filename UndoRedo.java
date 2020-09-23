// Importing Various Packages Required
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.applet.*;

// Class having Main Thread
class UndoRedo
{
	public static void main(String[] args) 
	{
		MyEditor myedit = new MyEditor();
		myedit.texteditor();
	}
}

// This class defines the layot of the Text Editor
class MyEditor extends JFrame implements ActionListener, KeyListener
{
	public static final Color C1 = new Color(44,62,80);
	public static final Color C2 = new Color(248,148,6);
	LinkedList mylist = new LinkedList();
	Container mycontentpane = getContentPane();
	SpringLayout mylayout = new SpringLayout();
	JLabel mylabel = new JLabel("Input: ");
	JLabel mylabel1 = new JLabel("Output: ");
	JTextField mytextfield = new JTextField("",30);
	JTextField mytextfield1 = new JTextField("",30);
	JButton mybutton2 = new JButton("Undo");
	JButton mybutton3 = new JButton("Redo");
	Font myfont = new Font("SansSerif",Font.BOLD|Font.ITALIC,50);
	boolean ctrlon;

	void texteditor()
	{

		setTitle("Text Editor Using Double Linked List");
		setSize(1600,800);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		mycontentpane.setBackground(C1);
		mytextfield.setBackground(Color.WHITE);
		mytextfield1.setBackground(Color.WHITE);
		mybutton2.setBackground(C2);
		mybutton3.setBackground(C2);
		mycontentpane.setLayout(mylayout);

		mytextfield.setFont(myfont);
		mytextfield1.setFont(myfont);
		mylabel.setFont(myfont);
		mylabel1.setFont(myfont);
		mylabel.setForeground(Color.WHITE);
		mylabel1.setForeground(Color.WHITE);
		mybutton2.setFont(myfont);
		mybutton3.setFont(myfont);

		add(mylabel);
		add(mylabel1);
		add(mytextfield);
		add(mytextfield1);
		add(mybutton2);
		add(mybutton3);

		mylayout.putConstraint(SpringLayout.WEST,mylabel,10,SpringLayout.WEST,mycontentpane);
		mylayout.putConstraint(SpringLayout.NORTH,mylabel,10,SpringLayout.NORTH,mycontentpane);

		mylayout.putConstraint(SpringLayout.WEST,mytextfield,5,SpringLayout.EAST,mylabel);
		mylayout.putConstraint(SpringLayout.NORTH,mytextfield,5,SpringLayout.NORTH,mycontentpane);

		mylayout.putConstraint(SpringLayout.WEST,mylabel1,10,SpringLayout.WEST,mycontentpane);
		mylayout.putConstraint(SpringLayout.NORTH,mylabel1,200,SpringLayout.NORTH,mycontentpane);

		mylayout.putConstraint(SpringLayout.WEST,mytextfield1,10,SpringLayout.EAST,mylabel1);
		mylayout.putConstraint(SpringLayout.NORTH,mytextfield1,200,SpringLayout.NORTH,mycontentpane);
		
		mylayout.putConstraint(SpringLayout.WEST,mybutton2,0,SpringLayout.WEST,mycontentpane);
		mylayout.putConstraint(SpringLayout.SOUTH,mybutton2,-5,SpringLayout.SOUTH,mycontentpane);
		
		mylayout.putConstraint(SpringLayout.EAST,mybutton3,0,SpringLayout.EAST,mycontentpane);
		mylayout.putConstraint(SpringLayout.SOUTH,mybutton3,-5,SpringLayout.SOUTH,mycontentpane);

		mytextfield.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e1)
			{
				String mytext;
				mytext = mytextfield.getText();
				mytextfield.setText("");
				mylist.insertdll(mytext);
				mytextfield1.setText(mylist.currentref.data);		
			}
		});

		mytextfield1.addKeyListener(new KeyListener()
		{
			public void keyPressed(KeyEvent ke)
			{
				if(ke.getKeyCode() == KeyEvent.VK_CONTROL)
				{
					ctrlon = true;
				}
				if(ke.getKeyCode() == KeyEvent.VK_Z && ctrlon)
				{
					if(mylist.currentref.prev != null)
					{
						mylist.undo();
						mytextfield1.setText(mylist.currentref.data);
					}
					else
					{
						mylist.undo();
						mytextfield1.setText("");
					}
				}
				if(ke.getKeyCode() == KeyEvent.VK_Y && ctrlon)
				{
					mytextfield1.setText(mylist.currentref.data);
					mylist.redo();	
				}
			}
			public void keyReleased(KeyEvent ke)
			{
				return;
			}
			public void keyTyped(KeyEvent ke)
			{
				return;
			}
		});

		mybutton2.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e2)
			{
				if(mylist.currentref.prev != null)
				{
					mylist.undo();
					mytextfield1.setText(mylist.currentref.data);
				}
				else
				{
					mylist.undo();
					mytextfield1.setText("");
				}
			}
		});

		mybutton3.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e2)
			{
				
				mytextfield1.setText(mylist.currentref.data);
				mylist.redo();		
			}
		});

		setVisible(true);
	}

	public void actionPerformed(ActionEvent ae)
	{
		return;
	}
	public void keyPressed(KeyEvent ke)
	{
		return;
	}
	public void keyReleased(KeyEvent ke)
	{
		return;
	}
	public void keyTyped(KeyEvent ke)
	{
		return;
	}

}

// Class Defining the structure of LinkedList Nodes used for text editor
class Node
{
	Node prev;
	String data;
	Node next;

	Node()
	{
		data = "";
		next = null;
		prev = null;
	}
}

// Class Defining Attributes and Methods for Linked List in a Text Editor
class LinkedList
{
	public Node currentref = null; // This reference variable is what than can be accessed by other classes 
	public int status_flag = 0;
	void insertdll(String st)
	{
		Node mynode = new Node();
		mynode.next = null;
		mynode.prev = null;

		if(currentref == null)
		{
			mynode.data = st;
			currentref = mynode;
		}
		else
		{
			if(status_flag == 0)
			{
				mynode.data = currentref.data + " " + st;
				mynode.prev = currentref; 
				currentref.next = mynode;
				currentref = mynode;
			}
			else
			{
				status_flag = 0;
				mynode.data = st;
				mynode.prev = currentref; 
				currentref.next = mynode;
				currentref = mynode;
			}
		}
	}

	void undo()
	{
		if(currentref.prev == null)
		{
			status_flag = 1; //This is done so as to not concatenate previous data with existing one
			return;
		}
		else
		{
			currentref = currentref.prev;
		}
	}

	void redo()
	{
		if(currentref.next == null)
		{
			return;
		}
		else
		{
			currentref = currentref.next;
		}
	}
}