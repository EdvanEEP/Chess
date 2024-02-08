#include "pieceTextures.h"

Texture PieceTextures::Textureyukle(string str){
    Texture pic;
    if (!pic.loadFromFile(str))
        cout << "Error loading file\n";
    return pic;
}

Texture PieceTextures::beyaz_sah = PieceTextures::Textureyukle("Textures/beyaz_þah.png");
Texture PieceTextures::beyaz_vezir = PieceTextures::Textureyukle("Textures/beyaz_vezir.png");
Texture PieceTextures::beyaz_kale = PieceTextures::Textureyukle("Textures/beyaz_kale.png");
Texture PieceTextures::beyaz_at = PieceTextures::Textureyukle("Textures/beyaz_at.png");
Texture PieceTextures::beyaz_fil = PieceTextures::Textureyukle("Textures/beyaz_fil.png");
Texture PieceTextures::beyaz_piyon = PieceTextures::Textureyukle("Textures/beyaz_piyon.png");

Texture PieceTextures::siyah_sah = PieceTextures::Textureyukle("Textures/siyah_þah.png");
Texture PieceTextures::siyah_vezir = PieceTextures::Textureyukle("Textures/siyah_vezir.png");
Texture PieceTextures::siyah_kale = PieceTextures::Textureyukle("Textures/siyah_kale.png");
Texture PieceTextures::siyah_at = PieceTextures::Textureyukle("Textures/siyah_at.png");
Texture PieceTextures::siyah_fil = PieceTextures::Textureyukle("Textures/siyah_fil.png");
Texture PieceTextures::siyah_piyon = PieceTextures::Textureyukle("Textures/siyah_piyon.png");


