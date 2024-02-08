#include "chessman.h"

void Chessman::setPiece(char type, bool player, int pos, bool moved){
    setType(type); //Hangi ta��n g�ncel oldu�unu ayarlar (char)
    setPlayer(player); //Hangi oyuncunun g�ncel oldu�unu ayarlar (bool)
    setPosition(pos); //m_moved true (Fare'den gelen pozisyon de�erini al�r, m_position'a atar ve moveChessman'� �a��r�r (int))
    setMoved(moved); // m_moved false (Ta� hareketi sa�land�ktan sonra gameLogic dosyas�ndan gelen de�er ile m_moved false olur (bool))
}

/// Ta�lar�n hareketinden sorumlu fonksiyon
void Chessman::moveChessman(){
    if(m_position<=-1 || 64<=m_position){ //0 dan k���k ve 64 ten b�y�k olursa, ta� tahta d���d�r
        m_position = -1;
        m_sprite.setColor(sf::Color(0x00000000)); //buradaki color de�eri ta�lar�n texture rengini transparan hale getirir ve ta� g�r�nmez olur
        m_sprite.setPosition(sf::Vector2f((m_position % 8) * 64.f + 32.f, (m_position / 8) * 64.f + 32.f)); // ta�� tahtan�n d���na ��kar�r
        possibleMoves.clear();            //x ekseni konumu               //x ekseni konumu 
        m_moved = true;
    }
    //yukar�daki �artlar� sa�lamazsa ta� tahta �st�ndeki konumuna atan�r
    else{
        m_sprite.setPosition(sf::Vector2f((m_position % 8) * 64.f + 32.f, (m_position / 8) * 64.f + 32.f));
        m_moved = true;                   //x ekseni konumu               //y ekseni konumu
    }
    return;
}

/*! Hangi texture'�n hangi ta�a ait oldu�unu ve texture'lar�n merkez noktalar�n� moveChessman'in ta�lar� hareket ettirebilmesi i�in belirler 
   Texture'lar�n merkezlerini belirlemek, texture'lar� tahtan�n karolar� �zerinde tam ortalayabilmek i�in �nemlidir. */
void Chessman::setTexture(){
    m_sprite = sf::Sprite();
    switch (m_type)
    {
        case 'K':
            m_sprite.setTexture(m_player ? PieceTextures::beyaz_sah
                                                : PieceTextures::siyah_sah);
            break;
        case 'Q':
            m_sprite.setTexture(m_player ? PieceTextures::beyaz_vezir
                                                : PieceTextures::siyah_vezir);
            break;
        case 'R':
            m_sprite.setTexture(m_player ? PieceTextures::beyaz_kale
                                                : PieceTextures::siyah_kale);
            break;
        case 'B':
            m_sprite.setTexture(m_player ? PieceTextures::beyaz_fil
                                                : PieceTextures::siyah_fil);
            break;
        case 'N':
            m_sprite.setTexture(m_player ? PieceTextures::beyaz_at
                                                : PieceTextures::siyah_at);
            break;
        case 'P':
            m_sprite.setTexture(m_player ? PieceTextures::beyaz_piyon
                                                : PieceTextures::siyah_piyon);
            break;
        default:
            std::cerr << "Error piece type does not exist.\n";
            break;
    }

    // Ta� texture'lar�n�n merkezlerini belirler ve merkezlerinden hareket ettirir
    m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize().x/2 ,
                                    m_sprite.getTexture()->getSize().y/2));
                                    
    // ta� texture'lar�n�n b�y�kl���n� ayarlar. Aksi takdirde ta�lar tahta �st�nde devasa olurdu
	 m_sprite.setScale(sf::Vector2f(0.375f,0.375f));
}
