// Assignement 2:	Solve 8-puzzle problem using A* algorithm. Assume any initial configuration and define goal configuration clearly


package eightpuzzlebfs;

import java.util.Scanner;
import javax.swing.JOptionPane;


                                                                                    //board class for eight puzzle matrix
public class Board {
    
    private String board[][];
    private  int blankX,blankY;                                                     // co-ordinates for blank tile
    
    public Board()
    {
        this.board = new String[3][3];       
    }
    
    public Board(Board b)                                                           //constructor to initialise Board
    {
        this.board = b.board;
        this.blankX = b.blankX;
        this.blankY = b.blankY;
    }
    
    public void initBoard()                                                         //initialize the board
    {
        Scanner inp = new Scanner(System.in);
        System.out.println("\nEnter one tile as '-' ie. Blank tile\n");
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                board[i][j] = JOptionPane.showInputDialog("Enter the value of tile ["+i+"]["+(j)+"] : ");
                
                if(board[i][j].equals("-"))                                         //store the location of blank symbol
                {
                    blankX=i;
                    blankY=j;
                }
            }
        }
    }
            
    public String[][] getBoard()
    {
        return board;
    }

    public void setBoard(String[][] board)                                          // Set the board puzzle matrix                                  
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                this.board[i][j] = board[i][j];
            }
        }
    }
    
    
    
    public int getBlankX()
    {
        return blankX;
    }
    
     public int getBlankY()
    {
        return blankY;
    }
     
     public void setBlankX(int x)
    {
        blankX = x;
    }
    
     public void setBlankY(int y)
    {
        blankY = y;
    }
    
    public void display()
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                System.out.print("\t"+board[i][j]);
            }
            System.out.println();
        }
    }
    
    public Board nextMove(Board goal)                                     //method to check possible moves and select optimum 
    {
        Board temp = new Board();
        Board next = new Board();
        int minFn = 999;
        System.out.println("\nPossible moves are : ");
        if(blankY>0)                                                      // Condition for possible left move
        {
            temp.setBoard(board);
            temp.swap(blankX, blankY, blankX, blankY-1);                  // Swap blank tile
            int fn =  (temp.getHn(goal));                                 // Calculate fn = hn
            System.out.println("\nFor Fn = "+fn+" : ");
            temp.display();
            if(fn < minFn)                                                // Check for minimum fn and set the next board accordingly
            {
                minFn = fn;
                next.setBoard(temp.board);
                next.setBlankX(blankX);                             
                next.setBlankY(blankY-1);
            }
            
        }
        if(blankY<2)                                                      // Condition for possible right move         
        {
            temp.setBoard(board);
            temp.swap(blankX, blankY, blankX, blankY+1);
            int fn =  (temp.getHn(goal));
            System.out.println("\nFor Fn = "+fn+" : ");
            temp.display();
            if(fn < minFn)
            {
                minFn = fn;
                next.setBoard(temp.board);
                next.setBlankX(blankX);
                next.setBlankY(blankY+1);
            }
            
        }
        if(blankX>0)                                                      // Condition for possible up move
        {
            temp.setBoard(board);
            temp.swap(blankX, blankY, blankX-1, blankY);
            int fn =  (temp.getHn(goal));
            System.out.println("\nFor Fn = "+fn+" : ");
            temp.display();
            if(fn < minFn)
            {
                minFn = fn;
                next.setBoard(temp.board);
                next.setBlankX(blankX-1);
                next.setBlankY(blankY);
            }
            
        }
        if(blankX<2)                                                      // Condition for possible down move
        {
            temp.setBoard(board);
            temp.swap(blankX, blankY, blankX+1, blankY);
            int fn =  (temp.getHn(goal));
            System.out.println("\nFor Fn = "+fn+" : ");
            temp.display();
            if(fn < minFn)
            {
                minFn = fn;
                next.setBoard(temp.board);
                next.setBlankX(blankX+1);
                next.setBlankY(blankY);
            }
            
        }
        return next;                                                      // return board with min fn
    }
    
   
    public void swap(int i1, int j1, int i2, int j2)                      // Swap tile values
    {
        String temp = board[i1][j1];
        board[i1][j1] = board[i2][j2];
        board[i2][j2] = temp;
        
    }
   
    public boolean equals(Board b)                                        // check for board equality
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(!this.board[i][j].equals(b.board[i][j]))
                {
                    return false;
                }
            }
            
        }
        return true;
            
    }
    
    public int getHn(Board goal)                                          // get hn by Hamming method
    {
        int hn = 0;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(!this.board[i][j].equals(goal.board[i][j]))
                {
                    hn++;
                }
            }
            
        }
        return hn;
    }
}
