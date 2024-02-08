#include "chessBoard.h"

chessBoard::chessBoard(Color renk1, Color renk2){
    load(renk1, renk2);
}

///load, determines all the colors on the board, column by column and row by row, positions all the squares
///and gives all the squares the size of 64x64 frames by using builtin vector function and
///functions of RectangleShape class that sfml library provides.
void chessBoard::load(Color renk1, Color renk2){
    for(int i=0; i<8;i++){

        bool renk = ((i % 2)==0)?true:false;

        for(int j = 0; j < 8;j++){

            chess_board[j + (i * 8)].setPosition(sf::Vector2f( j*64.f , i*64.f ));
            chess_board[j + (i * 8)].setSize(sf::Vector2f(64.f, 64.f));
            chess_board[j + (i * 8)].setFillColor(renk ? renk1 : renk2);
            
            renk = !renk;
        }
    }
}


void chessBoard::draw(RenderTarget& cizim, RenderStates cizimdurumu) const{ //chessBoard'� �izen fonksiyon.
    for(int i=0;i<64;i++){
        cizim.draw(chess_board[i]); 
    }
}
