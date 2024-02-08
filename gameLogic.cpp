/*
    This code file contains member functions of gameLogic.h
*/
#include <iostream>
#include "gameLogic.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


gameLogic::gameLogic(sf::Color bordCol1 = sf::Color::White, sf::Color bordCol2 = sf::Color::Black)
: board(bordCol1,bordCol2)
{
    // The code is taking account of these indexes.
    // Changing them may brake normal chess rules.
    // Comment out pieces if you want to remove some pieces at beggining.

    font.loadFromFile("Textures/arial.ttf");
    
    
    infoRestart.setFillColor(sf::Color::White);
    infoRestart.setOutlineThickness(-5.f);
    infoRestart.setOutlineColor(sf::Color::Black);
    infoRestart.setPosition(sf::Vector2f(512.f,0.f));
    infoRestart.setSize(sf::Vector2f(256.f, 50.f));

    textRestart.setFont(font);
    textRestart.setString("NEW GAME");
    textRestart.setCharacterSize(24);
    textRestart.setStyle(sf::Text::Bold);
    textRestart.setFillColor(sf::Color::Black);
    textRestart.setPosition(infoRestart.getPosition().x + 55.f, infoRestart.getPosition().y + 10.f);

	textTurn.setFont(font);
    textTurn.setCharacterSize(24);
    textTurn.setStyle(sf::Text::Bold);
    textTurn.setFillColor(sf::Color::Cyan);
    textTurn.setPosition(530.f, 70.f);

    textSituation.setFont(font);
    textSituation.setCharacterSize(24);
    textSituation.setStyle(sf::Text::Bold);
    textSituation.setFillColor(sf::Color::White);
    textSituation.setPosition(520.f, 110.f);
    
    

    restart();

}

void gameLogic::moveQueenCalc(Chessman* tmpPiece){

    int piecePos{tmpPiece->getPosition()};
    int posCounter{1};

    bool dangerMove{false};
    bool finishLoop{false};

    tmpPiece->getPossibleMoves().clear();
    tmpPiece->getDangerMoves().clear();

    // Queen moves left on X axis
    while( ((piecePos-posCounter) >= 0) && ((piecePos/8) == ((piecePos-posCounter)/8)) ){
        
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if(  ( piecesWhite[i].getPosition() == (piecePos-posCounter) ) || ( piecesBlack[i].getPosition() == (piecePos-posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }
            tmpPiece->getPossibleMoves().push_back(piecePos-posCounter);
        }
        
        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            tmpPiece->getDangerMoves().push_back(piecePos-posCounter);
            if(!playerTurn){
                if( (piecePos-posCounter) == piecesBlack[3].getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos-posCounter) == piecesWhite[4].getPosition() )
                    dangerMove = true;
            }

        }
        
        posCounter += 1;
    }


    // Queen moves right on X axis
    if(!dangerMove) tmpPiece->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 1;
    while( (piecePos/8) == ((piecePos+posCounter)/8) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (piecesWhite[i].getPosition() == (piecePos+posCounter)) || ( piecesBlack[i].getPosition() == (piecePos+posCounter) ) ){
                    finishLoop = true;
                    break;
                }
            }
            tmpPiece->getPossibleMoves().push_back(piecePos+posCounter);
        }

        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            tmpPiece->getDangerMoves().push_back(piecePos+posCounter);
            if(!playerTurn){
                if( (piecePos+posCounter) == piecesBlack[3].getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos+posCounter) == piecesWhite[4].getPosition() )
                    dangerMove = true;
            }

        }
        
        posCounter += 1;
    }
    //Queen moves up on Y axis
    if(!dangerMove) tmpPiece->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 8;
    while(((piecePos-posCounter) >= 0) && (posCounter < 64) && ((piecePos%8) == ((piecePos-posCounter)%8)) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (piecesWhite[i].getPosition() == (piecePos-posCounter)) || (piecesBlack[i].getPosition() == (piecePos-posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }        
            tmpPiece->getPossibleMoves().push_back(piecePos-posCounter);
        }

        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            tmpPiece->getDangerMoves().push_back(piecePos-posCounter);
            if(!playerTurn){
                if( (piecePos-posCounter) == piecesBlack[3].getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos-posCounter) == piecesWhite[4].getPosition() )
                    dangerMove = true;
            }

        }

        posCounter += 8;
    }
    //Queen moves down on Y axis
    if(!dangerMove) tmpPiece->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 8;
    while(((piecePos+posCounter) <= 63) && (posCounter < 64) && ((piecePos%8) == ((piecePos+posCounter)%8)) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (piecesWhite[i].getPosition() == (piecePos+posCounter)) || (piecesBlack[i].getPosition() == (piecePos+posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }
            tmpPiece->getPossibleMoves().push_back(piecePos+posCounter);
        }
        
        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            tmpPiece->getDangerMoves().push_back(piecePos+posCounter);
            if(!playerTurn){
                if( (piecePos+posCounter) == piecesBlack[3].getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos+posCounter) == piecesWhite[4].getPosition() )
                    dangerMove = true;
            }
        }

        posCounter += 8;
    }
    // Queen moves towards top left
    if(!dangerMove) tmpPiece->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 9;
    while( ((piecePos-posCounter) >= 0) && (((piecePos-posCounter) % 8) < (piecePos % 8)) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (piecesWhite[i].getPosition() == (piecePos-posCounter)) || (piecesBlack[i].getPosition() == (piecePos-posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }
            tmpPiece->getPossibleMoves().push_back(piecePos-posCounter);
        }

        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            tmpPiece->getDangerMoves().push_back(piecePos-posCounter);
            if(!playerTurn){
                if( (piecePos-posCounter) == piecesBlack[3].getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos-posCounter) == piecesWhite[4].getPosition() )
                    dangerMove = true;
            }
        }

        posCounter += 9;
    }
    // Queen moves towards bottom right
    if(!dangerMove) tmpPiece->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 9;
    while( ((piecePos+posCounter) <= 63) && (((piecePos+posCounter) % 8) > (piecePos % 8)) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (piecesWhite[i].getPosition() == (piecePos+posCounter)) || (piecesBlack[i].getPosition() == (piecePos+posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }        
            tmpPiece->getPossibleMoves().push_back(piecePos+posCounter);
        }

        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            tmpPiece->getDangerMoves().push_back(piecePos+posCounter);
            if(!playerTurn){
                if( (piecePos+posCounter) == piecesBlack[3].getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos+posCounter) == piecesWhite[4].getPosition() )
                    dangerMove = true;
            }
        }

        posCounter += 9;
    }
    // Queen moves towards top right
    if(!dangerMove) tmpPiece->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 7;
    while( ((piecePos-posCounter) >= 0) && (((piecePos-posCounter) % 8) > (piecePos % 8)) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (piecesWhite[i].getPosition() == (piecePos-posCounter)) || (piecesBlack[i].getPosition() == (piecePos-posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }        
            tmpPiece->getPossibleMoves().push_back(piecePos-posCounter);
        }

        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            tmpPiece->getDangerMoves().push_back(piecePos-posCounter);
            if(!playerTurn){
                if( (piecePos-posCounter) == piecesBlack[3].getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos-posCounter) == piecesWhite[4].getPosition() )
                    dangerMove = true;
            }
        }

        posCounter += 7;
    }
    // Queen moves towards bottom left
    if(!dangerMove) tmpPiece->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 7;
    while( ((piecePos+posCounter) <= 63) && (((piecePos+posCounter) % 8) < (piecePos % 8)) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (piecesWhite[i].getPosition() == (piecePos+posCounter)) || (piecesBlack[i].getPosition() == (piecePos+posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }        
            tmpPiece->getPossibleMoves().push_back(piecePos+posCounter);
        }

        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            tmpPiece->getDangerMoves().push_back(piecePos+posCounter);
            if(!playerTurn){
                if( (piecePos+posCounter) == piecesBlack[3].getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos+posCounter) == piecesWhite[4].getPosition() )
                    dangerMove = true;
            }
        }

        posCounter += 7;
    }

    if(!dangerMove) tmpPiece->getDangerMoves().clear();

    
    if(!tmpPiece->getDangerMoves().empty()){
        int collisions{0};
        for(int j=0; j<tmpPiece->getDangerMoves().size(); j++){
            for(int i=0; i<16; i++){
                if(tmpPiece->getDangerMoves().at(j) == piecesBlack[i].getPosition()){
                    collisions++;
                    if(!tmpPiece->getPlayer())
                        collisions++;
                }
                if(tmpPiece->getDangerMoves().at(j) == piecesWhite[i].getPosition()){
                    collisions++;
                    if(tmpPiece->getPlayer())
                        collisions++;
                }
            }
        }

        if(collisions > 2)
            tmpPiece->getDangerMoves().clear();
    }

    tmpPiece->getDangerMoves().push_back( tmpPiece->getPosition() );
    
}

void gameLogic::moveKingCalc(Chessman* tmpPiece){

    int piecePos{tmpPiece->getPosition()};
    tmpPiece->getPossibleMoves().clear();

    if((piecePos / 8) != 0){
        tmpPiece->getPossibleMoves().push_back(piecePos - 8);
        if((piecePos % 8) != 0)
            tmpPiece->getPossibleMoves().push_back(piecePos - 9);
        if((piecePos % 8) != 7)
            tmpPiece->getPossibleMoves().push_back(piecePos - 7);
    }
    if((piecePos / 8) != 7){
        tmpPiece->getPossibleMoves().push_back(piecePos + 8);
        if((piecePos % 8) != 0)
            tmpPiece->getPossibleMoves().push_back(piecePos + 7);
        if((piecePos % 8) != 7)
            tmpPiece->getPossibleMoves().push_back(piecePos + 9);
    }
    if((piecePos % 8) != 0)
        tmpPiece->getPossibleMoves().push_back(piecePos - 1);
    if((piecePos % 8) != 7)
        tmpPiece->getPossibleMoves().push_back(piecePos + 1);
    
}

void gameLogic::moveKnightCalc(Chessman* tmpPiece){

    tmpPiece->getPossibleMoves().clear();

    int piecePos{tmpPiece->getPosition()};

    if((piecePos / 8) != 0 ){
        if((piecePos % 8) >= 2 )
            tmpPiece->getPossibleMoves().push_back(piecePos - 10);
        if( (piecePos % 8) <= 5 )
            tmpPiece->getPossibleMoves().push_back(piecePos - 6);
        if((piecePos / 8) != 1){
            if((piecePos % 8) >= 1 )
                tmpPiece->getPossibleMoves().push_back(piecePos - 17);
            if((piecePos % 8) <= 6 )
                tmpPiece->getPossibleMoves().push_back(piecePos - 15);
        }
    }
    if((piecePos / 8) != 7){
        if((piecePos % 8) >= 2 )
            tmpPiece->getPossibleMoves().push_back(piecePos + 6);
        if( (piecePos % 8) <= 5 )
            tmpPiece->getPossibleMoves().push_back(piecePos + 10);
        if((piecePos / 8) != 6){
            if((piecePos % 8) >= 1 )
                tmpPiece->getPossibleMoves().push_back(piecePos + 15);
            if((piecePos % 8) <= 6 )
                tmpPiece->getPossibleMoves().push_back(piecePos + 17);
        }
    }

    tmpPiece->getDangerMoves().clear();

    for(int i = 0; i < tmpPiece->getPossibleMoves().size(); i++){

        if(!playerTurn){
            if((tmpPiece->getPossibleMoves().at(i)) == piecesBlack[3].getPosition() )
                tmpPiece->getDangerMoves().push_back( tmpPiece->getPossibleMoves().at(i) );
        }
        else{
            if((tmpPiece->getPossibleMoves().at(i)) == piecesWhite[4].getPosition() )
                tmpPiece->getDangerMoves().push_back( tmpPiece->getPossibleMoves().at(i) );
        }

    }

    tmpPiece->getDangerMoves().push_back( tmpPiece->getPosition() );

}

void gameLogic::moveBishopCalc(Chessman* tmpPiece){

    //Normal Bishop Moving
    int piecePos{tmpPiece->getPosition()};
    int posCounter{9};

    bool dangerMove{false};
    bool finishLoop{false};

    tmpPiece->getPossibleMoves().clear();
    tmpPiece->getDangerMoves().clear();

    // Bishop moves towards top left
    while( ((piecePos-posCounter) >= 0) && (((piecePos-posCounter) % 8) < (piecePos % 8)) ){
        if(!finishLoop){
            for(int i = 0; i < 16; i++){
                if((piecesWhite[i].getPosition() == (piecePos - posCounter)) || (piecesBlack[i].getPosition() == (piecePos - posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }
            tmpPiece->getPossibleMoves().push_back(piecePos-posCounter);
        }

        if(!dangerMove){
            // piecesWhite[4] is white King , piecesBlack[3] is black King
            tmpPiece->getDangerMoves().push_back(piecePos-posCounter);
            if(!playerTurn){
                if((piecePos-posCounter) == piecesBlack[3].getPosition() )
                    dangerMove = true;
            }
            else{
                if((piecePos-posCounter) == piecesWhite[4].getPosition() )
                    dangerMove = true;
            }
        }

        posCounter += 9;
    }

    // Bishop moves towards bottom right
    if(!dangerMove) tmpPiece->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 9;
    while( ((piecePos+posCounter) <= 63) && (((piecePos+posCounter) % 8) > (piecePos % 8)) ){
        if(!finishLoop){
            for(int i = 0; i < 16; i++){
                if((piecesWhite[i].getPosition() == (piecePos + posCounter)) || (piecesBlack[i].getPosition() == (piecePos + posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }
            tmpPiece->getPossibleMoves().push_back(piecePos+posCounter);
        }

        if(!dangerMove){
            // piecesWhite[4] is white King , piecesBlack[3] is black King
            tmpPiece->getDangerMoves().push_back(piecePos+posCounter);
            if(!playerTurn){
                if((piecePos+posCounter) == piecesBlack[3].getPosition() )
                    dangerMove = true;
            }
            else{
                if((piecePos+posCounter) == piecesWhite[4].getPosition() )
                    dangerMove = true;
            }
        }

        posCounter += 9;
    }

    // Bishop moves towards top right
    if(!dangerMove) tmpPiece->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 7;
    while( ((piecePos-posCounter) >= 0) && (((piecePos-posCounter) % 8) > (piecePos % 8)) ){
        if(!finishLoop){
            for(int i = 0; i < 16; i++){
                if((piecesWhite[i].getPosition() == (piecePos - posCounter)) || (piecesBlack[i].getPosition() == (piecePos - posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }
            tmpPiece->getPossibleMoves().push_back(piecePos-posCounter);
        }

        if(!dangerMove){
            // piecesWhite[4] is white King , piecesBlack[3] is black King
            tmpPiece->getDangerMoves().push_back(piecePos-posCounter);
            if(!playerTurn){
                if((piecePos-posCounter) == piecesBlack[3].getPosition() )
                    dangerMove = true;
            }
            else{
                if((piecePos-posCounter) == piecesWhite[4].getPosition() )
                    dangerMove = true;
            }
        }

        posCounter += 7;
    }

    // Bishop moves towards bottom left
    if(!dangerMove) tmpPiece->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 7;
    while( ((piecePos+posCounter) <= 63) && (((piecePos+posCounter) % 8) < (piecePos % 8)) ){
        if(!finishLoop){
            for(int i = 0; i < 16; i++){
                if((piecesWhite[i].getPosition() == (piecePos + posCounter)) || (piecesBlack[i].getPosition() == (piecePos + posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }
            tmpPiece->getPossibleMoves().push_back(piecePos+posCounter);
        }

        if(!dangerMove){
            // piecesWhite[4] is white King , piecesBlack[3] is black King
            tmpPiece->getDangerMoves().push_back(piecePos+posCounter);
            if(!playerTurn){
                if((piecePos+posCounter) == piecesBlack[3].getPosition() )
                    dangerMove = true;
            }
            else{
                if((piecePos+posCounter) == piecesWhite[4].getPosition() )
                    dangerMove = true;
            }
        }

        posCounter += 7;
    }

    if(!dangerMove) tmpPiece->getDangerMoves().clear();
    
    
    if(!tmpPiece->getDangerMoves().empty()){
        int collisions{0};
        for(int j = 0; j < tmpPiece->getDangerMoves().size(); j++){
            for(int i = 0; i < 16; i++){
                if(tmpPiece->getDangerMoves().at(j) == piecesBlack[i].getPosition()){
                    collisions++;
                    if(!tmpPiece->getPlayer())
                        collisions++;
                }
                if(tmpPiece->getDangerMoves().at(j) == piecesWhite[i].getPosition()){
                    collisions++;
                    if(tmpPiece->getPlayer())
                        collisions++;
                }
            }
        }

        if(collisions > 2)
            tmpPiece->getDangerMoves().clear();
    }
    
    tmpPiece->getDangerMoves().push_back( tmpPiece->getPosition() );

}

void gameLogic::movePawnCalc(Chessman* tmpPiece){
    
    tmpPiece->getPossibleMoves().clear();

    int piecePos{tmpPiece->getPosition()};
    
    if (tmpPiece->getPlayer()){ // If pawn is white
        if((piecePos / 8) != 0){
            int i{0};
            for(i = 0; i < 16;i++){
                if((piecesWhite[i].getPosition() == (piecePos - 8) ) || (piecesBlack[i].getPosition() == (piecePos - 8) ))
                    break;
            }
            if((i == 16) && playerTurn){
                tmpPiece->getPossibleMoves().push_back(piecePos - 8);

                if(!tmpPiece->getMoved()){
                    for(i = 0; i < 16;i++){
                        if((piecesWhite[i].getPosition() == (piecePos - 16) ) || (piecesBlack[i].getPosition() == (piecePos - 16) ))
                            break;
                    }
                    if(i == 16)
                        tmpPiece->getPossibleMoves().push_back(piecePos - 16);
                }
            }

            if((piecePos % 8) != 0){
                for(i = 0; i < 16; i++){
                    if(!playerTurn || (piecesBlack[i].getPosition() == (piecePos - 9)) || (piecesWhite[i].getPosition() == (piecePos - 9)) ){
                        tmpPiece->getPossibleMoves().push_back(piecePos - 9);
                        break;
                    }
                }
            }

            if((piecePos % 8) != 7){
                for(i = 0; i < 16; i++){
                    if(!playerTurn || (piecesBlack[i].getPosition() == (piecePos - 7)) || (piecesWhite[i].getPosition() == (piecePos - 7)) ){
                        tmpPiece->getPossibleMoves().push_back(piecePos - 7);
                        break;
                    }
                }                    
            }

        }
        

    }
    else{ //if pawn is black

        if((piecePos / 8) != 7){
            int i{0};
            for(i = 0; i < 16;i++){
                if((piecesWhite[i].getPosition() == (piecePos + 8) ) || (piecesBlack[i].getPosition() == (piecePos + 8) ))
                    break;
            }
            if((i == 16) && !playerTurn){
                tmpPiece->getPossibleMoves().push_back(piecePos + 8);

                if(!tmpPiece->getMoved()){
                    for(i = 0; i < 16;i++){
                        if((piecesWhite[i].getPosition() == (piecePos + 16) ) || (piecesBlack[i].getPosition() == (piecePos + 16) ))
                            break;
                    }
                    if(i == 16)
                        tmpPiece->getPossibleMoves().push_back(piecePos + 16);
                }
            }

            if((piecePos % 8) != 0){
                for(i = 0; i < 16; i++){
                    if(playerTurn || (piecesWhite[i].getPosition() == (piecePos + 7)) || (piecesBlack[i].getPosition() == (piecePos + 7)) ){
                        tmpPiece->getPossibleMoves().push_back(piecePos + 7);
                        break;
                    }
                }                    
            }

            if((piecePos % 8) != 7){
                for(i = 0; i < 16; i++){
                    if(playerTurn || (piecesWhite[i].getPosition() == (piecePos + 9)) || (piecesBlack[i].getPosition() == (piecePos + 9)) ){
                        tmpPiece->getPossibleMoves().push_back(piecePos + 9);
                        break;
                    }
                }                    
            }

        }

    }

    tmpPiece->getDangerMoves().clear();

    for(int i = 0; i < tmpPiece->getPossibleMoves().size(); i++){

        if(!playerTurn){
            if((tmpPiece->getPossibleMoves().at(i)) == piecesBlack[3].getPosition() )
                tmpPiece->getDangerMoves().push_back( tmpPiece->getPossibleMoves().at(i) );
        }
        else{
            if((tmpPiece->getPossibleMoves().at(i)) == piecesWhite[4].getPosition() )
                tmpPiece->getDangerMoves().push_back( tmpPiece->getPossibleMoves().at(i) );
        }

    }

    tmpPiece->getDangerMoves().push_back( tmpPiece->getPosition() );

}

void gameLogic::moveRookCalc(Chessman* tmpPiece){

    int piecePos = tmpPiece->getPosition();
    int posCounter{1};

    bool dangerMove{false};
    bool finishLoop{false};

    tmpPiece->getPossibleMoves().clear();
    tmpPiece->getDangerMoves().clear();

    // Rook moves left on X axis
    while( ((piecePos-posCounter) >= 0) && ((piecePos/8) == ((piecePos-posCounter)/8)) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (piecesWhite[i].getPosition() == (piecePos-posCounter)) || (piecesWhite[i].getPosition() == (piecePos-posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }
            tmpPiece->getPossibleMoves().push_back(piecePos-posCounter);
        }
        
        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            tmpPiece->getDangerMoves().push_back(piecePos-posCounter);
            if(!playerTurn){
                if( (piecePos-posCounter) == piecesBlack[3].getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos-posCounter) == piecesWhite[4].getPosition() )
                    dangerMove = true;
            }
        }

        posCounter += 1;
    }

    // Rook moves right on X axis
    if(!dangerMove) tmpPiece->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 1;
    while( (piecePos/8) == ((piecePos+posCounter)/8) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (piecesWhite[i].getPosition() == (piecePos+posCounter)) || (piecesBlack[i].getPosition() == (piecePos+posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }        
            tmpPiece->getPossibleMoves().push_back(piecePos+posCounter);
        }

        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            tmpPiece->getDangerMoves().push_back(piecePos+posCounter);
            if(!playerTurn){
                if( (piecePos+posCounter) == piecesBlack[3].getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos+posCounter) == piecesWhite[4].getPosition() )
                    dangerMove = true;
            }
        }
        
        posCounter += 1;
    }

    // Rook moves up on Y axis
    if(!dangerMove) tmpPiece->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 8;
    while(((piecePos-posCounter) >= 0) && (posCounter < 64) && ((piecePos%8) == ((piecePos-posCounter)%8)) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (piecesWhite[i].getPosition() == (piecePos-posCounter)) || (piecesBlack[i].getPosition() == (piecePos-posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }
            tmpPiece->getPossibleMoves().push_back(piecePos-posCounter);
        }

        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            tmpPiece->getDangerMoves().push_back(piecePos-posCounter);
            if(!playerTurn){
                if( (piecePos-posCounter) == piecesBlack[3].getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos-posCounter) == piecesWhite[4].getPosition() )
                    dangerMove = true;
            }
        }

        posCounter += 8;
    }

    // Rook moves down on Y axis
    if(!dangerMove) tmpPiece->getDangerMoves().clear();
    finishLoop = false;
    posCounter = 8;
    while(((piecePos+posCounter) <= 63) && (posCounter < 64) && ((piecePos%8) == ((piecePos+posCounter)%8)) ){
        if(!finishLoop){
            for(int i = 0; i<16; i++){
                if( (piecesWhite[i].getPosition() == (piecePos+posCounter)) || (piecesBlack[i].getPosition() == (piecePos+posCounter)) ){
                    finishLoop = true;
                    break;
                }
            }
            tmpPiece->getPossibleMoves().push_back(piecePos+posCounter);
        }

        if(!dangerMove){
            // whitePieces[4] is white King , blackPieces[3] is black King
            tmpPiece->getDangerMoves().push_back(piecePos+posCounter);
            if(!playerTurn){
                if( (piecePos+posCounter) == piecesBlack[3].getPosition() )
                    dangerMove = true;
            }
            else{
                if( (piecePos+posCounter) == piecesWhite[4].getPosition() )
                    dangerMove = true;
            }
        }

        posCounter += 8;
    }

    if(!dangerMove) tmpPiece->getDangerMoves().clear();

    
    if(!tmpPiece->getDangerMoves().empty()){
        int collisions{0};
        for(int j=0; j<tmpPiece->getDangerMoves().size(); j++){
            for(int i=0; i<16; i++){
                if(tmpPiece->getDangerMoves().at(j) == piecesBlack[i].getPosition()){
                    collisions++;
                    if(!tmpPiece->getPlayer())
                        collisions++;
                }
                if(tmpPiece->getDangerMoves().at(j) == piecesWhite[i].getPosition()){
                    collisions++;
                    if(tmpPiece->getPlayer())
                        collisions++;
                }
            }
        }

        if(collisions > 2)
            tmpPiece->getDangerMoves().clear();
    }

    tmpPiece->getDangerMoves().push_back( tmpPiece->getPosition() );
    
}

void gameLogic::createMovesSquares(){

    if(pieceSelected == NULL)
        return;

    possibleSquares_toMove.clear();

    for(int i = 0; i < pieceSelected->getPossibleMoves().size(); i++){
        sf::RectangleShape tmp;
        tmp.setPosition(sf::Vector2f((pieceSelected->getPossibleMoves().at(i) % 8) * 64.f , (pieceSelected->getPossibleMoves().at(i) / 8) * 64.f));
        tmp.setSize(sf::Vector2f(64.f, 64.f));
        tmp.setFillColor(sf::Color::Cyan);
        possibleSquares_toMove.push_back(tmp);
    }
    return;
}

void gameLogic::movePossibleLocCalc(){

    Chessman* tmpPiece;

    // LOOP for every piece
    for(int x=0; x<32; x++){

        if(x<16)
            tmpPiece = &piecesWhite[x];
        else
            tmpPiece = &piecesBlack[x - 16];
        tmpPiece->getPossibleMoves().clear();
        tmpPiece->getDangerMoves().clear();

        // Calculate Moves for tmpPiece by piece type
        switch (tmpPiece->getType())
        {
            case 'K':
                moveKingCalc(tmpPiece);
                break;
            case 'B':
                moveBishopCalc(tmpPiece);
                break;
            case 'N':
                moveKnightCalc(tmpPiece);
                break;
            case 'Q':
                moveQueenCalc(tmpPiece);
                break;
            case 'R':
                moveRookCalc(tmpPiece);
                break;
            case 'P':
                movePawnCalc(tmpPiece);
                break;
            default:
                std::cerr << "Error piece type does not exist.\n";
                break;
        }
    }


    // Erase illegal moves on current player's pieces
    for(int x = 0; x < 16; x++){
        if(playerTurn){
            eraseMoves(&piecesWhite[x]);
        }
        else{
            eraseMoves(&piecesBlack[x]);
        }
    }

    checkMate();

    updateInfo();
    turn++;
}

void gameLogic::eraseMoves(Chessman* tmpPiece){

    if(tmpPiece->getPosition() == -1)
        return;


    if(tmpPiece->getPlayer() == playerTurn){
        
        // Erase moves on same team pieces
        
        for(int row = 0; row < 16; row++){
            for(int col = 0; col < tmpPiece->getPossibleMoves().size(); col++){

                if(tmpPiece->getPlayer()){ // White
                    if(tmpPiece->getPossibleMoves().at(col) == piecesWhite[row].getPosition()){
                        tmpPiece->getPossibleMoves().erase(tmpPiece->getPossibleMoves().begin() + col );
                        break;
                    }
                }
                else{ // Black
                    if(tmpPiece->getPossibleMoves().at(col) == piecesBlack[row].getPosition()){
                        tmpPiece->getPossibleMoves().erase(tmpPiece->getPossibleMoves().begin() + col );
                        break;
                    } 
                }
            }
        }
    }
}

bool gameLogic::selectPiece(int pos){

    for(int i = 0; i < 16; i++){
        if(playerTurn){ // If white turn
            if(piecesWhite[i].getPosition() == pos){
                pieceSelected = &piecesWhite[i];
                selected = true;
                break;
            }
        }
        else{ // If black turn
            if(piecesBlack[i].getPosition() == pos){
                pieceSelected = &piecesBlack[i];
                selected = true;
                break;
            }
        }
        selected = false;
    }

    if(!selected){
        pieceSelected = NULL;
        possibleSquares_toMove.clear();
        return selected;
    }


    createMovesSquares();

    return selected;
}

void gameLogic::moveSelected(int pos){
    bool validMove{false};

    if((pieceSelected == NULL) || !selected ) //Probably doesnt need both
        return;

    // Check pos with the Chessman's possibleMoves
    for(int i = 0; i < pieceSelected->getPossibleMoves().size(); i++){
        if(pos == pieceSelected->getPossibleMoves().at(i)){
            validMove = true;
            break;
        }
    }

    if(validMove){

        pieceSelected->setPosition(pos);


        for(int i = 0; i < 16; i++){
            if(pieceSelected->getPlayer()){ // If White
                if(piecesBlack[i].getPosition() == pos){
                    piecesBlack[i].setPosition(-1);
                    break;
                }
            }
            else{ // If Black
                if(piecesWhite[i].getPosition() == pos){
                    piecesWhite[i].setPosition(-1);
                    break;
                }
            }
        }


        if(playerTurnCheck){
            playerTurnCheck = false;
        }

        playerTurn = !playerTurn; // Here player turn changes
        movePossibleLocCalc();
    }

    pieceSelected = NULL;
    selected = false;

}

void gameLogic::checkMate(){
	
    bool whiteKingAlive = (piecesWhite[4].getPosition() != -1);
    bool blackKingAlive = (piecesBlack[3].getPosition() != -1);

    if (!whiteKingAlive) {
        mate = true;
		gameOver = true;	
        textSituation.setString("\nBlack Wins");
    } else if (!blackKingAlive) {
        mate = true;
        gameOver = true;
        textSituation.setString("\nWhite Wins");
    }
    
}

void gameLogic::restart(){

    selected = false;
    playerTurn = true;
    playerTurnCheck = false;
    mate = false;
    turn = 1;

    piecesBlack[0].setPiece('R', false, 7);
    piecesBlack[1].setPiece('N', false, 6);
    piecesBlack[2].setPiece('B', false, 5);
    piecesBlack[3].setPiece('K', false, 4);
    piecesBlack[4].setPiece('Q', false, 3);
    piecesBlack[5].setPiece('B', false, 2);
    piecesBlack[6].setPiece('N', false, 1);
    piecesBlack[7].setPiece('R', false, 0);

    piecesWhite[0].setPiece('R', true, 56);
    piecesWhite[1].setPiece('N', true, 57);
    piecesWhite[2].setPiece('B', true, 58);
    piecesWhite[3].setPiece('Q', true, 59);
    piecesWhite[4].setPiece('K', true, 60);
    piecesWhite[5].setPiece('B', true, 61);
    piecesWhite[6].setPiece('N', true, 62);
    piecesWhite[7].setPiece('R', true, 63);

    
    for(int i = 8;i < 16;i++){
        piecesWhite[i].setPiece('P', true, 48 + (i - 8));
        piecesBlack[i].setPiece('P', false, 15 - (i - 8) );
    }

    movePossibleLocCalc();


}

void gameLogic::updateInfo(){
    textTurn.setString("Turn: " + std::to_string(turn));
    
    if(!mate){
        if(playerTurn)
            textSituation.setString("White's Turn");
        else
            textSituation.setString("Blacks's Turn");
    }
}

void gameLogic::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.clear(sf::Color::Black);

    target.draw(board);
    target.draw(infoRestart);
    target.draw(textRestart);
    target.draw(textTurn);
    target.draw(textSituation);

    if((pieceSelected != NULL) && (selected)){
        for(int i = 0; i < possibleSquares_toMove.size(); i++){
            target.draw(possibleSquares_toMove.at(i));
        }
    }

    for(int i = 0;i < 16;i++){
        target.draw(piecesWhite[i]);
        target.draw(piecesBlack[i]);
    }
}


