#include "Textures.h"



Texture Textures::Textureyukle(string str){
    Texture pic;
    if (!pic.loadFromFile(str))
        cout << "Error loading file\n";
    return pic;
}

Texture Textures::beyaz_sah = Textures::Textureyukle("Textures/beyaz_þah.png");
Texture Textures::beyaz_vezir = Textures::Textureyukle("Textures/beyaz_vezir.png");
Texture Textures::beyaz_kale = Textures::Textureyukle("Textures/beyaz_kale.png");
Texture Textures::beyaz_at = Textures::Textureyukle("Textures/beyaz_at.png");
Texture Textures::beyaz_fil = Textures::Textureyukle("Textures/beyaz_fil.png");
Texture Textures::beyaz_piyon = Textures::Textureyukle("Textures/beyaz_piyon.png");

Texture Textures::siyah_sah = Textures::Textureyukle("Textures/siyah_þah.png");
Texture Textures::siyah_vezir = Textures::Textureyukle("Textures/siyah_vezir.png");
Texture Textures::siyah_kale = Textures::Textureyukle("Textures/siyah_kale.png");
Texture Textures::siyah_at = Textures::Textureyukle("Textures/siyah_at.png");
Texture Textures::siyah_fil = Textures::Textureyukle("Textures/siyah_fil.png");
Texture Textures::siyah_piyon = Textures::Textureyukle("Textures/siyah_piyon.png");


