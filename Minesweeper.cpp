#include<bits/stdc++.h>
#include"settings.cpp"
#include"leaderboard.cpp"

using namespace std;

/**
Description:    Function for displaying the Minesweeper board
Arguments:
dboard          an array with data type char that prints current gameplay board
Returns:        None
**/
void display_board(char dboard[][MAX_SIDES]) {
    cout <<"    ";

    for (int i=0; i<rows; i++) {
        cout << i << " ";
    }
    cout << endl << endl;

    for (int i=0; i<rows; i++) {
        cout << i <<"   ";

        for (int j=0; j<columns; j++) {
            cout << dboard[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

/**
Description:       Collects the move of the user
Arguments:
    x               x-component:row
    y               y-component:columns
Returns:
    void            none
**/
void user_movement(int *x, int *y) {
    cout <<"Enter your move, (row, column): " << endl;
    scanf("%d %d", x, y);
    return;
}

/**
Description:        Function for checking if selected cell is a mine.
Arguments:
    row             gives the x-component
    col             gives the y-component
    board           an array that has a data type char to compare if there is a X (mine)
Returns:
    bool            returns true or false
**/
bool check_if_mine (int row, int col, char board[][MAX_SIDES]) {
    if (board[row][col] == 'X') {
        return (true);
    }
    else
        return (false);
}

/**
Description:        Function for checking space if available
Arguments:
    row             gives the x-component
    col             gives the y-component
Returns:
    bool            returns either true or false
**/
bool check_space (int row, int col) {
    if ((row >= 0) && (row < rows) && (col >= 0) && (col < columns)) {
        return true;
    }
    else
        return false;
}

/**
Description:        Function for counting surrounding mines
Arguments:
    row             gives the x-component
    col             gives the y-component
    pmines          an array that has data type int which has the index of the mine
    mine_count      has int data type that holds the number of adjacent mines                
    game_board      has data type char to compare if there is a mine (X)
Returns:
    int             whole numbers, the number of adjacent mines
**/
int count_mines(int row, int col, int pmines[][2], char game_board[][MAX_SIDES]) {
    int mine_count = 0;
 
    /*      
    Guide for Positions:
    Center       (row, col)
    North        (row-1, col)
    South        (row+1, col)
    East         (row, col+1)
    West         (row, col-1)
    North-East   (row-1, col+1)
    South-East   (row+1, col+1)
    North-West   (row-1, col-1)
    South-West   (row+1, col-1) 
    */
 
    //North
    if (check_space (row-1, col) == true) {
        if (check_if_mine (row-1, col, game_board) == true)
            mine_count++;
    }
 
    //South
    if (check_space (row+1, col) == true) {
        if (check_if_mine (row+1, col, game_board) == true)
            mine_count++;
    }
 
    //East
    if (check_space (row, col+1) == true) {
        if (check_if_mine (row, col+1, game_board) == true)
            mine_count++;
    }
 
    //West
    if (check_space (row, col-1) == true) {
        if (check_if_mine (row, col-1, game_board) == true)
            mine_count++;
    }
 
    //North-East
    if (check_space (row-1, col+1) == true) {
        if (check_if_mine (row-1, col+1, game_board) == true)
            mine_count++;
    }

    //North-West
    if (check_space (row-1, col-1) == true) {
        if (check_if_mine (row-1, col-1, game_board) == true)
            mine_count++;
    }
 
    //South-East
    if (check_space (row+1, col+1) == true) {
        if (check_if_mine (row+1, col+1, game_board) == true)
            mine_count++;
    }
 
    //South-West
    if (check_space (row+1, col-1) == true) {
        if (check_if_mine (row+1, col-1, game_board) == true)
            mine_count++;
    }
 
return (mine_count);
} 

/**
Description:        Recursive Fcn to play Minesweeper
Arguments:
    dboard          an array with data type char that prints current gameplay board
    game_board      an array with data type char that responsible for counting mines in the adjacent cells
    pmines          an array that has data type int which has the index of the mine
    row             gives the index of row
    col             gives the index of column
    *movesleft      a pointer
Returns:
    bool            either true or false
**/ 
bool recur_MS(char dboard[][MAX_SIDES], char game_board[][MAX_SIDES], int pmines[][2], int row, int col, int *movesLeft) {
 
    //Base Case of Recursion
    if (dboard[row][col] != '-')
        return (false);
 
    int i, j;
 
    //You will lose if you opened a mine
    if (game_board[row][col] == 'X') {
        dboard[row][col]='X';
 
        for (i=0; i < mine; i++)
            dboard[pmines[i][0]][pmines[i][1]]='X';
 
        display_board (dboard);
        return (true) ;
    }
 
    else {
        //counts adjacent mine and display it on the board
        int mine_count = count_mines(row, col, pmines, game_board);
        (*movesLeft)--;
 
        dboard[row][col] = mine_count + '0';
 
        if (!mine_count) {
            
            //North
            if (check_space (row-1, col) == true) {
                if (check_if_mine (row-1, col, game_board) == false)
                recur_MS(dboard, game_board, pmines, row-1, col, movesLeft);
            }
 
            //South
            if (check_space (row+1, col) == true) {
                if (check_if_mine (row+1, col, game_board) == false)
                recur_MS(dboard, game_board, pmines, row+1, col, movesLeft);
            }
 
            //East
            if (check_space (row, col+1) == true) {
                if (check_if_mine (row, col+1, game_board) == false)
                recur_MS(dboard, game_board, pmines, row, col+1, movesLeft);
            }
 
            //West
            if (check_space (row, col-1) == true) {
                if (check_if_mine (row, col-1, game_board) == false)
                recur_MS(dboard, game_board, pmines, row, col-1, movesLeft);
            }
 
            //North-East
            if (check_space (row-1, col+1) == true) {
                if (check_if_mine (row-1, col+1, game_board) == false)
                recur_MS(dboard, game_board, pmines, row-1, col+1, movesLeft);
            }
 
            //North-West
            if (check_space (row-1, col-1) == true) {
                if (check_if_mine (row-1, col-1, game_board) == false)
                recur_MS(dboard, game_board, pmines, row-1, col-1, movesLeft);
            }
 
            //South-East
            if (check_space (row+1, col+1) == true) {
                if (check_if_mine (row+1, col+1, game_board) == false)
                recur_MS(dboard, game_board, pmines, row+1, col+1, movesLeft);
            }
 
            //South-West
            if (check_space (row+1, col-1) == true) {
                if (check_if_mine (row+1, col-1, game_board) == false)
                recur_MS(dboard, game_board, pmines, row+1, col-1, movesLeft);
            }
        }
 
        return false;
    }
}

/**
Description:        Function that plants mine randomly on the board
Arguments:
    pmines          an array that has data type int which has the index of the mine
    game_board      an array with data type char that responsible for counting mines in the adjacent cells
Returns:
    void            none
**/
void plantmines(int pmines[][2], char game_board[][MAX_SIDES]) {
    bool mark[MAX_SIDES*MAX_SIDES];
    memset (mark, false, sizeof (mark));
    //Loop runs until all mines been planted
    for (int i=0; i<mine; ) {
        int random = rand() % (rows*columns);
        int x = random / rows;
        int y = random % columns;
        //Add mine if there's no existing mine
        if (mark[random] == false) {
            //Row index of the mine
            pmines[i][0]= x;
            //Column index of the mine
            pmines[i][1] = y;
             //Place the mine
            game_board[pmines[i][0]][pmines[i][1]] = 'X';
            mark[random] = true;
            i++;
        }
    }
 
    return;
}

/**
Description:        Function to start the game
Arguments:
    game_board      an array with data type char that responsible for counting mines in the adjacent cells
    dboard          an array with data type char that prints current gameplay board
Returns:
    void            none
**/
//
void start(char game_board[][MAX_SIDES], char dboard[][MAX_SIDES]) {

    srand(time (NULL));
 
    //Makes all cells as mine-free
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            dboard[i][j] = game_board[i][j] = '-';
        }
    }

    return;
}

/**
Description:        Function to replace the mine as a safe tile for the 1st move
Arguments:
    row             gives the x-component
    col             gives the y-component
    board           an array that has a data type char that contains the mine (X)
Returns:
    void            none
**/
void putSpace (int row, int col, char board[][MAX_SIDES]) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            //Used to put the mine to the 1st location with no mine
            if (board[i][j] != 'X') {
                board[i][j] = 'X';
                board[row][col] = '-';
                return;
            }
        }
    }
    return;
}

/**
Description:        Function to play Minesweeper
Arguments:
    N/A             recursive function
Returns:
    void            none
**/
void playMS () {
    string player_name;
    //Initially the game is not over
    bool game_over = false;
    int flags = mine;

    //Declarations for timer
    clock_t start_timer;
    clock_t end_timer;
 
    //Actual Board and My Board
    char game_board[MAX_SIDES][MAX_SIDES], dboard[MAX_SIDES][MAX_SIDES];
    
    //To store (x,y) coordinates of mines.
    int movesLeft = rows * columns - mine, x, y;
    int pmines[MAX_MINES][2]; 
    
    //To call the start function
    start (game_board, dboard);
 
    //Plant mines on the board randomly
    plantmines (pmines, game_board);
 
    //During Game
    int present_move = 0;
    while (game_over == false) {
        //Initialize timer
        start_timer = clock();

        //Prints out the board
        cout << "Current Status of Board : " << endl;
        display_board (dboard);
        user_movement (&x, &y);

        //Option to reveal or flag
        cout << "Enter 1 to reveal, 2 to flag" << endl;
        cin >> act;

        //to reveal
        if (act == 1){
            //To make sure the 1st move is safe
            if (present_move == 0) {
                //If it is a mine, then replace it with space
                if (check_if_mine (x, y, game_board) == true)
                putSpace (x, y, game_board);
            }
            present_move++;


            if (recur_MS (dboard, game_board, pmines, x, y, &movesLeft) == true){
                end_timer = clock(); 
                double time_elapsed = ((double)( end_timer - start_timer)) / CLOCKS_PER_SEC;
                std::cout << endl << "Time: " << time_elapsed << " seconds" << endl;
                printf ("\nYou Lost !\n");
                game_over = true;
            }

            else if ((game_over == false) && (movesLeft == 0)) {
                end_timer = clock();
                double time_elapsed = ((double)( end_timer - start_timer)) / CLOCKS_PER_SEC;
                std::cout << endl << "Time: " << time_elapsed << " seconds" << endl;
                printf ("\nYou Won !\n");
            
                std::cout << "Enter Name:";
                std::cin >> player_name;
                if (marker >= 1) {
                    enter_leaderboard(player_name,level,time_elapsed);
                    display_leaderboard(level);
                }
            game_over = true;
            }
        }

        //to flag
        else if (act == 2){
            if (dboard[rows][columns] == '-'){
                dboard[rows][columns] = 'F';
            }
            else if (dboard[rows][columns] == 'F'){
                dboard[rows][columns] = '-';              
            }
            else {
                cout << "Invalid" << endl;
            }
        }
        
    }
    return;
}

/**
Description:        Function for choosing difficulty  
Arguments:
    level           contains an integer to compare which difficulty will it satisfy
Returns:
    void            none
**/
//
void difficulty () {
    cout << "Choose Difficulty" << endl;
    cout << "Enter 1 for EASY (9 * 9 Cells with 10 Mines)" << endl;
    cout << "Enter 2 for MEDIUM (16 * 16 Cells with 40 Mines)" << endl;
    cout << "Enter 3 for HARD (16 * 30 Cells with 10 Mines)" << endl;
    
    scanf ("%d", &level);
 
    if (level == EASY) {
        rows = 9;
        columns = 9;
        mine = 10;
        //For leaderboard activation.
        marker += 1;
    }
 
    if (level == MEDIUM) {
        rows = 16;
        columns = 16;
        mine = 40;
        //For leaderboard activation.
        marker += 1;
    }
 
    if (level == HARD) {
        rows = 16;
        columns = 30;
        mine = 99;
        //For leaderboard activation.
        marker += 1;
    }
    
    return;
}

/**
Description:        Main funtion
Arguments:
    argc            contains the number of argument
    argv            stores the size of customize map
Returns:
    int             goes as an exit code
**/
int main(int argc, char* argv[]) {
    
    //To create a customize board
    if (argc > 1){
        rows = atoi(argv[2]);
        columns = atoi(argv[4]);
        mine = atoi(argv[6]);
    }
    else{
        //To call difficulty fcn
        difficulty ();
    }
    //To call the recusive fcn playMS
    playMS ();
 
    return (0);
}