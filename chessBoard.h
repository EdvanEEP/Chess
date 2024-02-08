#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
using namespace sf;
using namespace std;


class chessBoard : public Drawable{

public:
    
    ///Default constructor for the colors of the board.
    chessBoard(Color renk1, Color renk2);
    
    
    void load(Color renk1 = Color::White, Color renk2 = Color::Black);

private:
    ///We created an array for the squares on the board. It has type of RectangleShape and 64 Element 
	///since a Chess board contains 8x8=64 squares in it.\n 
	///All squares have numbers 0 to 63,, starts 0 from top left and ends with 63 bottom right.
    array<RectangleShape, 64> chess_board;
    
    ///Draws all the squares of chess board one by one and gives it a shape.
    virtual void draw(RenderTarget& cizimhedefi, RenderStates cizimdurumu) const;

};
