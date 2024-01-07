/*
 * drawmgr.cpp
 *
 *  Created on: May 22, 2017
 *      Author: nullifiedcat
 */

#include <MiscTemporary.hpp>
#include <hacks/hacklist.hpp>
#if ENABLE_IMGUI_DRAWING
#include "imgui/imrenderer.hpp"
#elif ENABLE_GLEZ_DRAWING
#include <glez/glez.hpp>
#include <glez/record.hpp>
#include <glez/draw.hpp>
#endif
#include <settings/Bool.hpp>
#include <menu/GuiInterface.hpp>
#include "common.hpp"
#include "visual/drawing.hpp"
#include "hack.hpp"
#include "drawmgr.hpp"

static settings::Boolean info_text{ "hack-info.enable", "true" };

void RenderCheatVisuals()
{
    {
        BeginCheatVisuals();
    }
    {
        DrawCheatVisuals();
    }
    {
        EndCheatVisuals();
    }
}
#if ENABLE_GLEZ_DRAWING
glez::record::Record bufferA{};
glez::record::Record bufferB{};

glez::record::Record *buffers[] = { &bufferA, &bufferB };
#endif
int currentBuffer = 0;

void BeginCheatVisuals()
{
#if ENABLE_IMGUI_DRAWING
    im_renderer::bufferBegin();
#elif ENABLE_GLEZ_DRAWING
    buffers[currentBuffer]->begin();
#endif
    ResetStrings();
}

void DrawCheatVisuals()
{
    {
        if (*info_text)
        {
            auto color = colors::orange;
            AddSideString("COWHOOK.FUN", color);
          } 
      }
    if (spectator_target)
        AddCenterString("Press SPACE to stop spectating");

#if ENABLE_GUI
    {
        gui::draw();
    }
#endif
    if (spectator_target)
        AddCenterString("Press SPACE to stop spectating");
        EC::run(EC::Draw);
        DrawStrings();

#if ENABLE_GUI
    {
        gui::draw();
    }
#endif
}

void EndCheatVisuals()
{
#if ENABLE_GLEZ_DRAWING
    buffers[currentBuffer]->end();
#endif
#if ENABLE_GLEZ_DRAWING || ENABLE_IMGUI_DRAWING
    currentBuffer = !currentBuffer;
#endif
}

void DrawCache()
{
#if ENABLE_GLEZ_DRAWING
    buffers[!currentBuffer]->replay();
#endif
}
