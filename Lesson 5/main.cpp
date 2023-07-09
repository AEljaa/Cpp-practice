#include <iostream>
#include <string>

struct BoardSquare {
    enum E { X, O, EMPTY };
};

struct WinningPlayer {
    enum E { X, O, Stalemate, None };
};

class Board {
private:
    int _width;
    BoardSquare::E* _squares;
public:
    Board(int width) :_width(width) {

        _squares = new BoardSquare::E[width * width];
        for (auto i = 0; i < GetTotalSquares(); i++) {
            _squares[i] = BoardSquare::EMPTY;
        }
    }




    int GetWidth() {return _width;}
    int GetTotalSquares() {return _width * _width;}

    BoardSquare::E GetSquare(int index) {return _squares[index];}
    void SetSquare(int index, BoardSquare::E square) {_squares[index] = square;}

    ~Board() {delete[] _squares;}
};
//interface class
class IRuleEngine {
public:
//pure virtual function method , abstract class (=0 is syntax,to show that it is pure virtual function )
    virtual WinningPlayer::E GetWinningPlayer(Board& board) = 0;
};

class Game {
private:
    Board& _board;
    IRuleEngine& _ruleEngine;

public:
    Game(Board& board, IRuleEngine& ruleEngine) :_board(board), _ruleEngine(ruleEngine) {}

    WinningPlayer::E Run(){
        WinningPlayer::E winningPlayer,currentPlayer = WinningPlayer::X;
        while ((winningPlayer = _ruleEngine.GetWinningPlayer(_board)) == WinningPlayer::None) {
            Render();
            std::cout<<"\n";
            int input;
            std::cout<<"Move for player "<<(currentPlayer == WinningPlayer::X ? 'X': 'O') <<" : ";
            std::cin>>input;
            std::cin.ignore();
            //translate to 0 based index used by the board
            input-=1;
            //check if the move is valid and if it is, set the square to the current player
            if(input < 0 || input > _board.GetTotalSquares() || _board.GetSquare(input) != BoardSquare::EMPTY){
                std::cout<<"Invalid move!"<<std::endl;
                continue;
            }
            _board.SetSquare(input, currentPlayer == WinningPlayer::X ? BoardSquare::X : BoardSquare::O);
            //switch player for next turn
            currentPlayer = currentPlayer == WinningPlayer::X ? WinningPlayer::O : WinningPlayer::X;
        }
         return winningPlayer;
    }
private:
    void Render(){   
        for (auto i = 1; i <= _board.GetTotalSquares(); i++) {
            std::cout << GetSquareSymbol(i, _board.GetSquare(i-1))<< " "<<std::endl;
            if ((i % _board.GetWidth()) == 0) {
                std::cout << "\n";
            }
        }
    }

char GetSquareSymbol(int index, BoardSquare::E square) {
    switch (square) {
    case BoardSquare::X:
        return 'X';
    case BoardSquare::O:
        return 'O';
    case BoardSquare::EMPTY:
        return ' ';
    }
    }
//     return index + '0';
// }

};

class NullRuleEngine : public IRuleEngine {
private:
    int GetIndexForXY(int x, int y, int width) {
        return (y * width) + x;
    }
public:
    virtual WinningPlayer::E GetWinningPlayer(Board& board) {
        bool foundAnyEmpty=false;
        for (auto i = 0; i < board.GetTotalSquares(); i++) {
            if (board.GetSquare(i) == BoardSquare::EMPTY) {
                foundAnyEmpty = true;
                break;
            }
        }
        if (!foundAnyEmpty) {
            return WinningPlayer::Stalemate;
        }

        for(auto y=0; y<board.GetWidth();y++){
            BoardSquare::E allOfType ;
            WinningPlayer::E winningPlayer;
            auto firstIndex = GetIndexForXY(0,y,board.GetWidth());
            allOfType = board.GetSquare(firstIndex);
            if(allOfType == BoardSquare::EMPTY){
                continue;
            }
            winningPlayer = allOfType == BoardSquare::X ? WinningPlayer::X : WinningPlayer::O;

            for (auto x = 1; x < board.GetWidth(); x++) {
                if(allOfType != board.GetSquare(GetIndexForXY(y,x,board.GetWidth()))){
                    allOfType = BoardSquare::EMPTY;
                    break;
                }
            }
            if(winningPlayer != WinningPlayer::None){
                return winningPlayer;
            }
        }
        
        

        for(auto x=0; x<board.GetWidth();x++){
            BoardSquare::E allOfType ;
            WinningPlayer::E winningPlayer;
            auto firstIndex = GetIndexForXY(x,0,board.GetWidth());
            allOfType = board.GetSquare(firstIndex);
            if(allOfType == BoardSquare::EMPTY){
                continue;
            }
            winningPlayer = allOfType == BoardSquare::X ? WinningPlayer::X : WinningPlayer::O;

            for (auto y = 1; y < board.GetWidth(); y++) {
                if(allOfType != board.GetSquare(GetIndexForXY(y,x,board.GetWidth()))){
                    allOfType = BoardSquare::EMPTY;
                    break;
                }
            }
            if(winningPlayer != WinningPlayer::None){
                return winningPlayer;
            }
        }


        return WinningPlayer::None;
    }
};

int main(){
    Board board(3);
    NullRuleEngine ruleEngine;
    Game game(board, ruleEngine);
    game.Run();
    return 0;
}