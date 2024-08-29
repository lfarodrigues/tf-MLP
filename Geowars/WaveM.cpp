/**********************************************************************************
// WaveM (C�digo Fonte)
//
// Cria��o:     06 Ago 2019
// Atualiza��o: 01 Dez 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Cria uma onda de inimigos Magenta
//
**********************************************************************************/

#include "WaveM.h"
#include "GeoWars.h"
#include "Magenta.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

WaveM::WaveM() : posX(50, window->Width()-50), posY(50, game->Height()-50), secs(2.0f, 4.0f)
{
    // posi��o dos inimigos
    pX = posX.Rand();
    pY = posY.Rand();

    // atraso para a pr�xima onda 
    delay = secs.Rand();
}

// ------------------------------------------------------------------------------

WaveM::~WaveM()
{

}

// -------------------------------------------------------------------------------

void WaveM::Update()
{
    // se passou o tempo de atraso
    if (timer.Elapsed(delay) && Hud::magentas < 5)
    {
        // toca som de nova onda
        GeoWars::audio->Play(MAGENTA);

        // adiciona novo inimigo
        GeoWars::scene->Add(new Magenta(pX, pY, GeoWars::player), MOVING);

        // nova posi��o do inimigo
        pX = posX.Rand();
        pY = posY.Rand();

        // reinicia o timer
        timer.Start();
    }
}

// -------------------------------------------------------------------------------

void WaveM::Draw()
{
    
}

// -------------------------------------------------------------------------------
