/**********************************************************************************
// Delay (C�digo Fonte)
//
// Cria��o:     02 Ago 2019
// Atualiza��o: 01 Dez 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Sincroniza uma a��o
//
**********************************************************************************/

#include "Delay.h"
#include "GeoWars.h"
#include "WaveO.h"
#include "WaveM.h"
#include "WaveB.h"
#include "WaveG.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

Delay::Delay()
{
    logo = new Sprite("Resources/Logo.png");
    timer.Start();

    notPlayed = true;
    fase1 = false;
    fase2 = false;
    fase3 = false;
    fase4 = false;
}

// ------------------------------------------------------------------------------

Delay::~Delay()
{
    delete logo;
}

// -------------------------------------------------------------------------------

void Delay::Update()
{
    if (notPlayed && timer.Elapsed(2.0f))
    {
        // toca �udio de introdu��o
        GeoWars::audio->Play(START);
        notPlayed = false;
    }

    if (!fase1 && timer.Elapsed(6.0f))
    {
        // toca m�sica do jogo
        GeoWars::audio->Play(THEME, true);
        GeoWars::scene->Add(new WaveO(), STATIC);
        GeoWars::viewHUD = true;
        fase1 = true;
    }

    if (!fase2 && timer.Elapsed(8.0f))
    {
        GeoWars::scene->Add(new WaveM(), STATIC);
        fase2 = true;
    }

    if (!fase3 && timer.Elapsed(10.0f))
    {
        GeoWars::scene->Add(new WaveB(), STATIC);
        fase3 = true;
    }

    if (!fase4 && timer.Elapsed(15.0f))
    {
        GeoWars::scene->Add(new WaveG(), STATIC);
        GeoWars::scene->Delete();
        fase4 = true;
    }
}

// -------------------------------------------------------------------------------

void Delay::Draw()
{
    if (!fase1)
        logo->Draw(game->viewport.left + window->CenterX() , game->viewport.top + window->CenterY(), Layer::FRONT);
}

// -------------------------------------------------------------------------------
