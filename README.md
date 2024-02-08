GROUP 21 - CHESS GAME PROJECT 

# Group Members

230******** - Mehmet ÖZDEMİR  
230******** - Semi Bertuğ ÇAĞ  
210******** - İrem ŞAHAR  
210******** - Emine Sena TOP  
170******** - Gürkan ER  

# GAME OVERVIEW AND USAGE DESCRIPTION

This project is a 2-player version of the classic chess game developed using C++ and SFML library. The game follows traditional rules and uses composition in accordance with OOP (Object-Oriented Programming) principles, using a general "piece" class instead of separate classes for pieces.
The game starts with the main class running, with all the pieces placed in accordance with the board layout logic. The movements of the pieces are controlled using the mouse and the game, as usual, starts with the starting move of white.
Sound has been added to piece movements to improve user experience. Possible movements of all pieces are controlled in the gameLogic class.
The allowed moves of each piece are as follows:
- King: Can move one square in any direction.
- Knight: Moves in an L shape.
- Rook: Can move one or more squares vertically or horizontally.
- Bishop: Can move diagonally to any number of squares.
- Pawn: Can move forward one or two squares on the first move.
- Queen: Can move any distance horizontally, vertically or diagonally.

Although the game does not include the special moves en passant and castling, the ability of the pawn to move one or two steps in the first move is controlled.

The points where the selected piece can go are colored, thus showing the user its possible moves. For each move, the number of moves is displayed on the right side of the screen. 

![alt text](/readme_pic1.png)

There is a "NEW GAME" button to restart the game. By clicking this button, the game is reset and all pieces return to their original places.
At the end of the game, a victory screen appears on the right with the name of the winning side. The program automatically closes 2 seconds after the game is completed.

![alt text](/readme_pic2.png)

# Contribution of each group member

1. REPORTS: 
	- İrem Şahar
	- Semi Bertuğ Çağ
	- Mehmet Özdemir
	- Gürkan Er
	- Emine Sena Top

2. CODING PART:
	- Main Class
		- Mehmet Özdemir
	
	- ChessBoard Class
 		- Mehmet Özdemir

 	- GameLogic Class
		- Mehmet Özdemir
		- Gürkan Er
		- Emine Sena Top
		- Semi Bertuğ Çağ
		- İrem Şahar

	- Chessman Class
		- Semi Bertuğ Çağ
		- İrem Şahar

	- PieceTextures Class
		- Semi Bertuğ Çağ
		- İrem Şahar
	
 3. CODE COMMENTS AND FINAL REPORTS: 
 	- Semi Bertuğ Çağ
	- İrem Şahar
	- Emine Sena Top




