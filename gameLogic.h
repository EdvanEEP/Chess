#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <iostream>
#include "chessBoard.h"
#include "chessman.h"

class gameLogic: public sf::Drawable{
private:
    chessBoard board;
    
    std::array<Chessman, 16> piecesWhite;
    std::array<Chessman, 16> piecesBlack;
    Chessman* pieceSelected;
    std::vector<sf::RectangleShape> possibleSquares_toMove;
    std::string lastMove;

///Creates Rectangle Background for Restart Button and contains its properties
    sf::RectangleShape infoRestart;
    sf::RectangleShape exit;

///States fonts of all texts used on the game window
    sf::Font font;
    
///Contains the properties of Restart text on the screen 	
    sf::Text textRestart;
    sf::Text textExit;
///Contains the properties of Turn text on the screen  
    sf::Text textTurn;
    
///Contains the properties of Checkmate, Check, White's Turn and Black's Turn texts on the screen    
    sf::Text textSituation;
  
///Contains the properties of the text that gives information about which piece is moved to which position on Last Turn    
    sf::Text textLastMove;
    
    
    bool selected;
    bool playerTurn; // true = White turn, false = Black Turn
    bool playerTurnCheck;
    bool mate;
    int turn;

    void createMovesSquares();

    void movePossibleLocCalc();
    void moveQueenCalc(Chessman* tmpPiece);
    void moveRookCalc(Chessman* tmpPiece);
    void moveKingCalc(Chessman* tmpPiece);
    void moveBishopCalc(Chessman* tmpPiece);
    void moveKnightCalc(Chessman* tmpPiece);
    void movePawnCalc(Chessman* tmpPiece);

    void eraseMoves(Chessman* tmpPiece);

    void checkMate();

    void updateInfo();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    gameLogic(sf::Color bordCol1, sf::Color bordCol2);

    bool getSelected(){return selected;}

    bool selectPiece(int pos);

    void moveSelected(int pos);

    void restart();
		
	bool gameOver = false;

};
