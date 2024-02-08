/*
    This header file contains the Chessman class.
*/

#ifndef _PIECE_H
#define _PIECE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "pieceTextures.h"

class Chessman : public sf::Drawable{

public:
    
    ///Default constructor, when the game starts, it makes sure that all the variables assigned
    Chessman(char type='P', bool player=true, int pos=-1, bool moved=false)
    : m_type{type}, m_player{player},
    m_position{-1}, m_moved{true}
    { }

    ///Sets all set functions inside piece.h except setEnPassant
    void setPiece(char type, bool player, int pos, bool moved=false);
    
    ///Assigns the piece to the m_type (e.g. 'P' for pawn or 'R' for rook) to use it in gameLogic
    void setType(char ch){m_type = ch; setTexture();}
    
    ///Gets which piece is already assigned to m_type
    char getType()       {return m_type;}

    ///Sets player, true=white , false=black
    void setPlayer(bool bl){m_player = bl; setTexture();}
    
    ///Gets player to make moves, setting textures etc.
    bool getPlayer()       {return m_player;}

    ///Takes mouse position on the board and assigns it to m_position, also calls moveChessman function to place all the pieces on the board
    void setPosition(int pos){m_position = pos;
        moveChessman();}
    
    ///Gets position of the piece
    int getPosition()        {return m_position;}
    
    //Sets m_moved true, if the piece is moved
    void setMoved(bool moved){m_moved = moved;}
    
    ///Helps to understand, the piece is moved or not.
    bool getMoved()           {return m_moved;}

    ///Calculates all possible moves that a piece can make. To prevent random access from other files, it is assigned as pointer.
    std::vector<int>& getPossibleMoves(){return possibleMoves;}
    
    ///Takes the possible moveChessman of the piece if King is threatening
    std::vector<int>& getDangerMoves(){return dangerMoves;}

    ///Creates Content of textLastMove in gameLogic.h file
    std::string toString();

private:
	
	///Builtin class comes with sfml. It can take multiple textures to position all the pieces on the board.
    sf::Sprite m_sprite;
    
    ///Private version of getPossibleMoves
    std::vector<int> possibleMoves;
    
    ///Private version of dangerMoves
    std::vector<int> dangerMoves; // Moves that endanger opposite king
    
    ///Takes single char to represent piece
    char m_type; //'K'=King , 'Q' = Queen , 'R' = Rook , 'B' = Bishop , 'N' = Knight , 'P' = Pawn
    
	///true == White , false == Black
	bool m_player; // true == White , false == Black
	
	/// 0-63 piece is on the board, less or equal to -1 and greater or equal to 64 means dead
    int m_position; // 0-63 board, -1 dead
    
    /// true= piece is moved , false= piece is not moved
    bool m_moved;

    /// Used for creating textures of the pieces
    void setTexture();
    
    /// Checks if the piece is out of the board or not and positions the piece texture on the board depending on this information.
    void moveChessman();

    /// Renders all the pieces on the board.
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {   target.draw(m_sprite);  }
};

#endif
