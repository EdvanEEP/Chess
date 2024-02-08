#include "chessman.h"

void Chessman::setPiece(char type, bool player, int pos, bool moved){
    setType(type); //Hangi taþýn güncel olduðunu ayarlar (char)
    setPlayer(player); //Hangi oyuncunun güncel olduðunu ayarlar (bool)
    setPosition(pos); //m_moved true (Fare'den gelen pozisyon deðerini alýr, m_position'a atar ve moveChessman'ý çaðýrýr (int))
    setMoved(moved); // m_moved false (Taþ hareketi saðlandýktan sonra gameLogic dosyasýndan gelen deðer ile m_moved false olur (bool))
}

/// Taþlarýn hareketinden sorumlu fonksiyon
void Chessman::moveChessman(){
    if(m_position<=-1 || 64<=m_position){ //0 dan küçük ve 64 ten büyük olursa, taþ tahta dýþýdýr
        m_position = -1;
        m_sprite.setColor(sf::Color(0x00000000)); //buradaki color deðeri taþlarýn texture rengini transparan hale getirir ve taþ görünmez olur
        m_sprite.setPosition(sf::Vector2f((m_position % 8) * 64.f + 32.f, (m_position / 8) * 64.f + 32.f)); // taþý tahtanýn dýþýna çýkarýr
        possibleMoves.clear();            //x ekseni konumu               //x ekseni konumu 
        m_moved = true;
    }
    //yukarýdaki þartlarý saðlamazsa taþ tahta üstündeki konumuna atanýr
    else{
        m_sprite.setPosition(sf::Vector2f((m_position % 8) * 64.f + 32.f, (m_position / 8) * 64.f + 32.f));
        m_moved = true;                   //x ekseni konumu               //y ekseni konumu
    }
    return;
}

/*! Hangi texture'ýn hangi taþa ait olduðunu ve texture'larýn merkez noktalarýný moveChessman'in taþlarý hareket ettirebilmesi için belirler 
   Texture'larýn merkezlerini belirlemek, texture'larý tahtanýn karolarý üzerinde tam ortalayabilmek için önemlidir. */
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

    // Taþ texture'larýnýn merkezlerini belirler ve merkezlerinden hareket ettirir
    m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize().x/2 ,
                                    m_sprite.getTexture()->getSize().y/2));
                                    
    // taþ texture'larýnýn büyüklüðünü ayarlar. Aksi takdirde taþlar tahta üstünde devasa olurdu
	 m_sprite.setScale(sf::Vector2f(0.375f,0.375f));
}
