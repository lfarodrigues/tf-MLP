/**********************************************************************************
// Magenta (C�digo Fonte)
// 
// Cria��o:     10 Out 2012
// Atualiza��o: 01 Dez 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Objeto faz um persegui��o direta
//
**********************************************************************************/

#include "GeoWars.h"
#include "Magenta.h"
#include "Random.h" 
#include "Hud.h"
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Magenta::Magenta(float pX, float pY, Player * p)
{
    player = p;
    sprite = new Sprite(GeoWars::magenta);
    BBox(new Circle(18.0f));
    
    speed.RotateTo(0);
    speed.ScaleTo(2.0f);
    
    MoveTo(pX, pY);
    type = MAGENTA;

    // incrementa contador
    ++Hud::magentas;
}

// ---------------------------------------------------------------------------------

Magenta::~Magenta()
{
    delete sprite;

    // decrementa contador
    --Hud::magentas;
}

// -------------------------------------------------------------------------------

void Magenta::OnCollision(Object * obj)
{
    if (obj->Type() == MISSILE)
    {
        GeoWars::scene->Delete(obj, STATIC);
        GeoWars::scene->Delete(this, MOVING);
        GeoWars::scene->Add(new Explosion(x, y), STATIC);
        GeoWars::audio->Play(EXPLODE);
    }
}

// -------------------------------------------------------------------------------

void Magenta::Update()
{
    // ajusta �ngulo do vetor 
    speed.RotateTo(Line::Angle(Point(x, y), Point(player->X(), player->Y())));
    Rotate(200 * gameTime);

    // movimenta objeto pelo seu vetor velocidade
    Translate(speed.XComponent() * 60.0f * gameTime, -speed.YComponent() * 60.0f * gameTime);
}

// -------------------------------------------------------------------------------