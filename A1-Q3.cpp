#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>

using namespace std ;

class ChessPiece
{
    string name ; 
    string color ; 
    string symbol ; 

    public:

    //default constructor
    ChessPiece() 
    {
        name = "Pawn" ;
        color = "White" ;
        symbol = "p" ; 
    }

    //parameterized constructor
    ChessPiece(string name , string color , string symbol)
    {
        this->name = name ; 
        this->color = color ; 
        this->symbol = symbol ; 
    }

    void setname(string pname)
    {
        name = pname ; 
    }

    void setcolor(string pcolor)
    {
        color = pcolor ;
    }

    void setsymbol(string psymbol)
    {
        symbol = psymbol ;
    }

    string getname()
    {
        return name ;
    }

    string getcolor()
    {
        return color ;
    }

    string getsymbol()
    {
        return symbol ;
    } 
} ;

class ChessBoard
{
    ChessPiece * board[8][8] ;

    public:
    //default constructor
    ChessBoard()
    {
        for(int i=0 ; i<8 ; i++)
        {
            for(int j=0 ; j<8 ; j++)
            {
                board[i][j] = nullptr ;  
            }
        }
        //White Pieces
        board[0][0] = new ChessPiece("Rook", "White" , "R") ;
        board[0][1] = new ChessPiece("Knight", "White" , "K") ;
        board[0][2] = new ChessPiece("Bishop", "White" , "B") ;
        board[0][3] = new ChessPiece("Queen", "White" , "Q") ;
        board[0][4] = new ChessPiece("King", "White" , "K") ;
        board[0][5] = new ChessPiece("Bishop", "White" , "B") ;
        board[0][6] = new ChessPiece("Knight", "White" , "K") ;
        board[0][7] = new ChessPiece("Rook", "White" , "R") ;
        for(int j=0 ; j<8 ; j++)
        {
            board[1][j] = new ChessPiece() ;
        }

        // Black pieces
        board[7][0] = new ChessPiece("Rook", "Black", "r");
        board[7][1] = new ChessPiece("Knight", "Black", "n");
        board[7][2] = new ChessPiece("Bishop", "Black", "b");
        board[7][3] = new ChessPiece("Queen", "Black", "q");
        board[7][4] = new ChessPiece("King", "Black", "k");
        board[7][5] = new ChessPiece("Bishop", "Black", "b");
        board[7][6] = new ChessPiece("Knight", "Black", "n");
        board[7][7] = new ChessPiece("Rook", "Black", "r");
        for (int j = 0; j < 8; ++j) 
        {
            board[6][j] = new ChessPiece();
        }

        for (int i = 2; i < 6; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                board[i][j] = new ChessPiece("", "", ".");
            }
        }


    }

    void display()
    {
        
        // Print the board
        cout << " a b c d e f g h" << endl ; 
        for (int i = 0; i < 8; ++i)
        {
            cout << 8-i << "" ;
            for (int j = 0; j < 8; ++j) 
            {
                
                cout << board[i][j]->getsymbol() << " ";
            }
            cout << 8-i << endl ; 
        }
        cout << " a b c d e f g h" << endl ; 
    }

    bool movePiece(string pos1 , string pos2)
    {
        int p1_row = 8 - (pos1[1] - '0');
        int p1_col = pos1[0] - 'a';
        int p2_row = 8 - (pos2[1] - '0');
        int p2_col = pos2[0] - 'a';
        if ((p1_row >= 0 && p1_row < 8) && (p1_col >= 0 && p1_col < 8) && (p2_row >= 0 && p2_row < 8) && (p2_col >= 0 && p2_col < 8))
        {
            ChessPiece *piece = board[p1_row][p1_col];
            if (piece != nullptr)
            { // now i have to check ke kya destination waali jagah null hai ya nhi ya opponent ka hai so i can remove it
                if (board[p2_row][p2_col] == nullptr || (piece->getcolor() != board[p2_row][p2_col]->getcolor() && board[p2_row][p2_col] != nullptr))
                {
                    // Pawn will only move one or two only jab wo initial position per hoga which means 6 and only rows will move
                    if ((piece->getname() == "Pawn"))
                    {
                        if (piece->getcolor() == "White")
                        {
                            if (p1_col == p2_col)
                            {
                                if ((p1_row == 6 && p2_row == 4) || (p2_row == p1_row - 1))
                                // position per lao+initial position null
                                {
                                    delete board[p2_row][p2_col];
                                    board[p2_row][p2_col] = piece;
                                    board[p1_row][p1_col] = nullptr;
                                    board[p1_row][p1_col] = new ChessPiece{"", "", "."};
                                    return true;
                                }
                            }
                        }
                        // black
                        else
                        {
                            if ((p1_row == 1 && p2_row == 3) || (p2_row == p1_row + 1))
                            {
                                delete board[p2_row][p2_col];
                                board[p2_row][p2_col] = piece;
                                board[p1_row][p1_col] = nullptr;
                                board[p1_row][p1_col] = new ChessPiece{"", "", "."};
                                return true;
                            }
                        }
                    }
                    else if (piece->getname() == "Knight")
                    {
                        int rowdiff, coldiff;
                        rowdiff = p2_row - p1_row;
                        coldiff = p2_col - p1_col;
                        if ((rowdiff == 2 && coldiff == 1) || (rowdiff == 2 && coldiff == -1) ||
                             (rowdiff == -2 && coldiff == 1) || (rowdiff == -2 && coldiff == -1) ||
                            (coldiff == 2 && rowdiff == 1) || (coldiff == 2 && rowdiff == -1) ||
                             (coldiff == -2 && rowdiff == 1) || (coldiff == -2 && rowdiff == -1))
                        {
                            delete board[p2_row][p2_col];
                            board[p2_row][p2_col] = piece;
                            board[p1_row][p1_col] = nullptr;
                            board[p1_row][p1_col] = new ChessPiece{"", "", "."};
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};


int main()
{
    cout << "Name : Muhammad Anas Siddiqui" << endl ; 
    cout << "ID: 23k-0575" << endl ;
    
    ChessBoard Board ;
    Board.display() ;
    cout << endl ; 

    Board.movePiece("b1" , "c3") ;
    Board.movePiece("b2" , "b3") ;
    Board.movePiece("g8" , "h6") ;
    Board.display() ; 

}



