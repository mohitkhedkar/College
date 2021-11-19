// Assignement 2: Solve 8-puzzle problem using A* algorithm. Assume any initial configuration and define goal configuration clearly

package eightpuzzlebfs;

public class EightPuzzleBFS {

    /**
     * @param args the command line arguments
     */
    private int count = 0; // Initialize no. of moves to 0
    private Board start;
    private Board goal;

    public void initStart() // Accept and display start board
    {
        System.out.println("\n\n Enter start Board : ");
        start = new Board();
        start.initBoard();
        System.out.println("\n\nThe given start board is : ");
        start.display();
    }

    public void initGoal() // Accept and display goal board
    {
        System.out.println("\n\n Enter goal Board : ");
        goal = new Board();
        goal.initBoard();
        System.out.println("\n\nThe given goal board is : ");
        goal.display();
    }

    public void solve() // Solve puzzle using A* algorithm
    {
        Board cur = start;
        while (true) {
            System.out.println("\n\nBoard after " + count + " moves : ");
            cur.display();
            if (cur.equals(goal)) // Check if goal is achieved nad return
            {
                System.out.println("\nGoal state achieved.");
                return;
            }

            count++; // Increment count as per moves

            cur = cur.nextMove(goal); // get the board after next move
        }
    }

    public static void main(String[] args) {
        // code application logic here

        EightPuzzleBFS ep = new EightPuzzleBFS(); // Instantiate and solve the puzzle
        ep.initStart();
        ep.initGoal();

        System.out.println("\n\nThe board is solved as : \n");
        ep.solve();

    }
}

/*
 * 
 * 
 * run:
 * 
 * 
 * Enter start Board :
 * 
 * Enter one tile as '-' ie. Blank tile
 * 
 * 
 * 
 * The given start board is : - a c h b d g f e
 * 
 * 
 * Enter goal Board :
 * 
 * Enter one tile as '-' ie. Blank tile
 * 
 * 
 * 
 * The given goal board is : a b c h - d g f e
 * 
 * 
 * The board is solved as :
 * 
 * 
 * 
 * Board after 0 moves : - a c h b d g f e
 * 
 * Possible moves are :
 * 
 * For Fn = 2 : a - c h b d g f e
 * 
 * For Fn = 4 : h a c - b d g f e
 * 
 * 
 * Board after 1 moves : a - c h b d g f e
 * 
 * Possible moves are :
 * 
 * For Fn = 3 : - a c h b d g f e
 * 
 * For Fn = 3 : a c - h b d g f e
 * 
 * For Fn = 0 : a b c h - d g f e
 * 
 * 
 * Board after 2 moves : a b c h - d g f e
 * 
 * Goal state achieved. BUILD SUCCESSFUL (total time: 36 seconds)
 * 
 */