#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace sf;
using namespace std;

class Textures{
public:
	//Texture class'� 2d oyun geli�tirmede g�rsel veri y�klemek i�in kullan�lan classt�r.  
    
	static Texture Textureyukle(string str);//String de�eri al�yor ��nk� dosya konumlar�n� string olarak al�yoruz.
    
    static Texture beyaz_piyon;
	static Texture siyah_piyon;
	static Texture beyaz_sah;
	static Texture siyah_sah;
    static Texture beyaz_vezir;
    static Texture siyah_vezir;
    static Texture beyaz_kale;
    static Texture siyah_kale;
    static Texture beyaz_at;
    static Texture siyah_at;
    static Texture beyaz_fil;
    static Texture siyah_fil;

};
