// Battle frame sequencing, rendering and round ownership.
#include "SceneBattle.h"
#include "Backgrounds.h"
#include <mmsystem.h>
#include <cstdlib>

unsigned char Scene3::Step()
{
    int frame;
    if (timeGetTime() - field0438 >= 1000) {
        field0438 = timeGetTime();
        field043c = field0434;
        field0434 = 0;
    }
    ++field0434;
    if (phase == 1) {
        contextOwner->effectFlag1350 = 1;
        secondary[0] = *secondarySlotA;
        secondary[1] = *secondarySlotB;
        field0440 = 0;
        field0444 = -50;
        field0448 = field0440;
        field044c = field0444;
        field0450 = 5;
        field0454 = -160;
        field0458 = 0;
        field0578 = 3;
        field0574 = 0;
        field0576 = 9999;
        UpdateCamera();
        Slot0();
        FadeIn(contextOwner->characterPalette, 0);
        phase = 0;
    } else if (flag002d == 1) {
        FadeOut(contextOwner->characterPalette, 1, 0, 100);
        delete *secondarySlotA;
        *secondarySlotA = 0;
        delete *secondarySlotB;
        *secondarySlotB = 0;
        if (contextOwner->blob != 0) {
            delete contextOwner->blob;
            contextOwner->blob = 0;
        }
        flag002d = 0;
        phase = 1;
        if (contextOwner->flag14283 > 0) {
            contextOwner->replayFile.Close();
            contextOwner->flag14283 = 0;
            contextOwner->ReleaseMusic();
            return 8;
        }
        if (contextOwner->mode1364 == 6) return 0;
        return 1;
    }
    PollKeyboard();
    if (field0588 != 0) return 3;
    {
        if (flag002d == 2) {
            field0578 = 1;
            if (UpdateRoundExit() != 0) {
                flag002d = 0;
                phase = 1;
                if (contextOwner->flag14283 > 0) {
                    contextOwner->replayFile.Close();
                    contextOwner->flag14283 = 0;
                    contextOwner->ReleaseMusic();
                    delete *secondarySlotA;
                    *secondarySlotA = 0;
                    delete *secondarySlotB;
                    *secondarySlotB = 0;
                    if (contextOwner->blob != 0) {
                        delete contextOwner->blob;
                        contextOwner->blob = 0;
                    }
                    return 8;
                }
                return 5;
            }
        } else if (contextOwner->state1427c != 0) {
            field0578 = contextOwner->state14280;
            contextOwner->state1427c = 0;
        }
        for (frame = 0; frame < (int)(unsigned int)field0578; ++frame) {
            secondary[0]->UpdateInput();
            secondary[1]->UpdateInput();
            UpdateIntro();
            secondary[0]->DispatchState();
            secondary[1]->DispatchState();
            secondary[0]->Slot08();
            secondary[1]->Slot08();
            secondary[0]->Slot06();
            secondary[1]->Slot06();
            secondary[0]->Slot07();
            secondary[1]->Slot07();
            if (contextOwner->counter1354 == 0 && contextOwner->effectFlag1350 == 0) DispatchCollisions();
            ResolvePushboxes();
            secondary[0]->UpdateMovement();
            secondary[1]->UpdateMovement();
            if (secondary[0]->hitstunFrames > 0) --secondary[0]->hitstunFrames;
            else secondary[0]->hitstunFrames = 0;
            if (secondary[1]->hitstunFrames > 0) --secondary[1]->hitstunFrames;
            else secondary[1]->hitstunFrames = 0;
            secondary[0]->UpdateTimers();
            secondary[1]->UpdateTimers();
            PlayCharacterSounds();
            PlayEffectSounds();
            UpdateRound();
        }
        contextOwner->UpdatePaletteFade();
        contextOwner->UpdateFrameControls();
        UpdateCamera();
        if (contextOwner->setting136c != 0 || (contextOwner->setting136c == 0 && contextOwner->framePhase != 0)) Slot0();
        contextOwner->UpdateEffects();
        if (contextOwner->blob != 0) reinterpret_cast<BattleBackground *>(contextOwner->blob)->Update();
    }
    return 3;
}

void Scene3::UpdateRound()
{
    if (field0574 != 0) return;
    if (contextOwner->mode1364 == 1) return;
    {
        if (contextOwner->counter1354 != 0) {
            secondary[0]->buttonPulse[0] = 0;
            secondary[0]->buttonPulse[1] = 0;
            secondary[0]->buttonPulse[2] = 0;
            secondary[0]->buttonPulse[3] = 0;
            secondary[1]->buttonPulse[0] = 0;
            secondary[1]->buttonPulse[1] = 0;
            secondary[1]->buttonPulse[2] = 0;
            secondary[1]->buttonPulse[3] = 0;
            if ((secondary[0]->field0008 >= 50 && secondary[0]->IsStateGroupC() == 0) ||
                (secondary[1]->field0008 >= 50 && secondary[1]->IsStateGroupC() == 0) || flag002d == 2) return;
            contextOwner->counter1354 = 0;
            secondary[0]->health = 9999;
            secondary[1]->health = 9999;
            contextOwner->effectFlag1350 = 2;
        } else {
            EffectSpawn effect;
            if (secondary[0]->health <= 0 && secondary[1]->health <= 0) {
                ++secondary[0]->field00ac;
                ++secondary[1]->field00ac;
                if (secondary[0]->field00ac >= (char)contextOwner->selection134e) --secondary[0]->field00ac;
                if (secondary[1]->field00ac >= (char)contextOwner->selection134e) --secondary[1]->field00ac;
                secondary[0]->field0008 = 59;
                secondary[0]->ResetPose();
                secondary[1]->field0008 = 59;
                secondary[1]->ResetPose();
                contextOwner->counter1354 = 1;
                if (contextOwner->effectSelector < 9) ++contextOwner->effectSelector;
            } else if (secondary[0]->health <= 0 && secondary[0]->koDelayFrames == 0) {
                secondary[1]->field30dc += secondary[1]->health;
                if (secondary[1]->field00ac < (char)contextOwner->selection134e - 1) {
                    ++secondary[1]->field00ac;
                    secondary[0]->hitstunFrames += 180;
                    secondary[1]->hitstunFrames += 180;
                    secondary[0]->ResetPose();
                    effect.owner = 0;
                    effect.x = 80.0;
                    effect.y = 100.0;
                    effect.facing = 0;
                    effect.group = 0;
                    effect.layer = 2;
                    effect.payload = 1;
                    effect.type = 19;
                    effect.palette = 29;
                    contextOwner->EmitEffect(&effect);
                    contextOwner->counter1354 = 1;
                    if (contextOwner->effectSelector < 9) ++contextOwner->effectSelector;
                } else {
                    ++secondary[1]->field00ac;
                    secondary[0]->ResetPose();
                    contextOwner->counter1354 = 1;
                    flag002d = 2;
                    field0580 = 0.0;
                    contextOwner->winner134c = 1;
                }
            } else if (secondary[1]->health <= 0 && secondary[1]->koDelayFrames == 0) {
                secondary[0]->field30dc += secondary[0]->health;
                if (secondary[0]->field00ac < (char)contextOwner->selection134e - 1) {
                    ++secondary[0]->field00ac;
                    secondary[0]->hitstunFrames += 180;
                    secondary[1]->hitstunFrames += 180;
                    effect.owner = 0;
                    effect.x = 240.0;
                    effect.y = 100.0;
                    effect.facing = 0;
                    effect.group = 0;
                    effect.layer = 2;
                    effect.payload = 1;
                    effect.type = 19;
                    effect.palette = 29;
                    contextOwner->EmitEffect(&effect);
                    secondary[1]->ResetPose();
                    contextOwner->counter1354 = 1;
                    if (contextOwner->effectSelector < 9) ++contextOwner->effectSelector;
                } else {
                    ++secondary[0]->field00ac;
                    secondary[1]->ResetPose();
                    contextOwner->counter1354 = 1;
                    flag002d = 2;
                    field0580 = 0.0;
                    contextOwner->winner134c = 0;
                }
            }
        }
    }
}

int Scene3::UpdateRoundExit()
{
    if (field0580 < 100.0) {
        videoOwner->LightenPalette(contextOwner->characterPalette, 0, 255, (int)(100.0 - field0580));
        audioOwner->SetSoundVolume(contextOwner->audioMode, (int)(-field0580 * 100.0 / 2.0) + contextOwner->currentVolume);
    }
    field0580 = field0580 + 1.0;
    if (field0580 >= 200.0) return 1;
    return 0;
}

void Scene3::Slot0()
{
    secondary[0]->AdvanceTrail();
    secondary[1]->AdvanceTrail();
    RenderBackground();
    RenderHealthBars();
    RenderShadows();
    contextOwner->RenderEffects(field045c, field0460, 0);
    secondary[0]->RenderLocalEffects(field045c, field0460, 0);
    secondary[1]->RenderLocalEffects(field045c, field0460, 0);
    if (secondary[1]->field0008 >= 200) {
        secondary[0]->Render(field045c + secondary[0]->IsStateGroupB() * (secondary[0]->hitstopFrames % 2) * 2, field0460);
        secondary[1]->Render(field045c + secondary[1]->IsStateGroupB() * (secondary[1]->hitstopFrames % 2) * 2, field0460);
    } else {
        secondary[1]->Render(field045c + secondary[1]->IsStateGroupB() * (secondary[1]->hitstopFrames % 2) * 2, field0460);
        secondary[0]->Render(field045c + secondary[0]->IsStateGroupB() * (secondary[0]->hitstopFrames % 2) * 2, field0460);
    }
    secondary[0]->RenderLocalEffects(field045c, field0460, 1);
    secondary[1]->RenderLocalEffects(field045c, field0460, 1);
    contextOwner->RenderEffects(field045c, field0460, 1);
    contextOwner->RenderEffects(field045c, field0460, 2);
    contextOwner->RenderEffects(field045c, field0460, 3);
    if (contextOwner->blob != 0 && secondary[0]->field30c4 == 0 && secondary[1]->field30c4 == 0 && contextOwner->state14278 == 0) {
        reinterpret_cast<BattleBackground *>(contextOwner->blob)->Render(field045c, field0460, 1);
    }
    if (contextOwner->state1420c == 0) {
        secondary[0]->Slot01();
        secondary[1]->Slot01();
    }
    RenderHud();
    if (secondary[0]->comboDisplayHitCount > 1 && secondary[0]->comboDisplayTimer > 0) RenderCombo(secondary[0]);
    if (secondary[1]->comboDisplayHitCount > 1 && secondary[1]->comboDisplayTimer > 0) RenderCombo(secondary[1]);
    if (field058c != 0) {
        if (field0590 % 2 == 0) videoOwner->SaveScreenshot(field0590 / 2, contextOwner->characterPalette);
        ++field0590;
    }
    // Disabled diagnostics are present in the complete original /Od contribution.
    if (false) {
        DrawNumber(80, 100, secondary[0]->health, 2, 0, 0);
        DrawNumber(80, 110, secondary[0]->field0008, 2, 0, 0);
        DrawNumber(80, 120, secondary[0]->field000a, 2, 0, 0);
        DrawNumber(80, 130, (unsigned short)secondary[0]->field000c, 2, 0, 0);
        DrawNumber(280, 100, secondary[1]->health, 2, 0, 0);
        DrawNumber(280, 110, secondary[1]->field0008, 2, 0, 0);
        DrawNumber(280, 120, secondary[1]->field000a, 2, 0, 0);
        DrawNumber(280, 130, (unsigned short)secondary[1]->field000c, 2, 0, 0);
    }
    ClipFrame();
}

extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);

void Scene3::ClipFrame()
{
    struct ClipWork {
        int vertical, x, y, horizontal;
    } work;
    work.x = -field045c;
    work.y = 240 - field0460;
    work.horizontal = 0;
    work.vertical = 0;
    if (work.x > 320) {
        work.horizontal = 320 - work.x;
        work.x = 320;
    } else if (work.x < 0) {
        work.horizontal = -work.x;
        work.x = 0;
    }
    if (work.y > 240) {
        work.vertical = 240 - work.y;
        work.y = 240;
    } else if (work.y < 0) {
        work.vertical = -work.y;
        work.y = 0;
    }
    videoOwner->FillRectangle(MakeSurfaceRect(0, (work.vertical + 240) * (work.vertical < 0), 320, std::abs(work.vertical)), 0);
    videoOwner->FillRectangle(MakeSurfaceRect((work.horizontal + 320) * (work.horizontal < 0), (work.vertical >= 0) * work.vertical,
        std::abs(work.horizontal), 240 - std::abs(work.vertical)), 0);
    videoOwner->Present();
}

void Scene3::RenderBackground()
{
    struct BackgroundWork {
        SurfaceRect destination;
        int vertical;
        SurfaceRect source;
        int x, y, horizontal;
    } work;
    work.x = (int)(-field045c * contextOwner->backgroundScale + (160.0 - 160.0 * contextOwner->backgroundScale));
    work.y = (int)((240 - field0460) * contextOwner->backgroundScale + (120.0 - 120.0 * contextOwner->backgroundScale));
    work.horizontal = 0;
    work.vertical = 0;
    if (work.x > 320) {
        work.horizontal = 320 - work.x;
        work.x = 320;
    } else if (work.x < 0) {
        work.horizontal = -work.x;
        work.x = 0;
    }
    if (work.y > 240) {
        work.vertical = 240 - work.y;
        work.y = 240;
    } else if (work.y < 0) {
        work.vertical = -work.y;
        work.y = 0;
    }
    work.destination = MakeSurfaceRect(work.x, work.y, 320, 240);
    work.source = MakeSurfaceRect(work.horizontal, work.vertical, 320, 240);
    if (secondary[0]->field30c4 > 0 && secondary[1]->field30c4 > 0) {
        if (contextOwner->field0f33 == 0) videoOwner->FillRectangle(work.source, secondary[0]->field30c0);
        else videoOwner->FillRectangle(work.source, secondary[1]->field30c0);
        if (secondary[0]->hitstunFrames == 0 && secondary[1]->hitstunFrames == 0) {
            --secondary[0]->field30c4;
            --secondary[1]->field30c4;
        }
    } else if (secondary[0]->field30c4 > 0) {
        videoOwner->FillRectangle(work.source, secondary[0]->field30c0);
        if (secondary[0]->hitstunFrames == 0 && secondary[1]->hitstunFrames == 0) --secondary[0]->field30c4;
    } else if (secondary[1]->field30c4 > 0) {
        videoOwner->FillRectangle(work.source, secondary[1]->field30c0);
        if (secondary[0]->hitstunFrames == 0 && secondary[1]->hitstunFrames == 0) --secondary[1]->field30c4;
    } else if (contextOwner->state14278 > 0) {
        videoOwner->DrawSurface(work.source, contextOwner->extraB, work.destination, 0, 0);
        if (secondary[0]->hitstunFrames == 0 && secondary[1]->hitstunFrames == 0) --contextOwner->state14278;
    } else {
        videoOwner->DrawSurface(work.source, contextOwner->extraA, work.destination, 0, 0);
        if (contextOwner->blob != 0) reinterpret_cast<BattleBackground *>(contextOwner->blob)->Render(field045c, field0460, 0);
    }
}
