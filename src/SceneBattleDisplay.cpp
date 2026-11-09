// Battle health display, portraits, round marks and sampled frame count.
#include "SceneBattle.h"
extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);

void Scene3::RenderHealthBars()
{
    struct HealthDisplayWork {
        SurfaceRect source;
        int width;
        SurfaceRect destination;
    } work;
    if (secondary[0]->field0110 > secondary[0]->field0108) {
        secondary[0]->field0110 = secondary[0]->field0110 - 200;
        if (secondary[0]->field0110 < secondary[0]->field0108) secondary[0]->field0110 = secondary[0]->field0108;
    }
    if (secondary[0]->field0110 < secondary[0]->field0108) {
        secondary[0]->field0110 = secondary[0]->field0110 + 200;
        if (secondary[0]->field0110 > secondary[0]->field0108) secondary[0]->field0110 = secondary[0]->field0108;
    }
    if (secondary[1]->comboHitCount == 0) {
        secondary[0]->field010c -= (secondary[0]->field010c > secondary[0]->field0108) * 100;
        if (secondary[0]->field010c < secondary[0]->field0108) secondary[0]->field010c = secondary[0]->field0108;
    }
    if (secondary[1]->field0110 > secondary[1]->field0108) {
        secondary[1]->field0110 = secondary[1]->field0110 - 200;
        if (secondary[1]->field0110 < secondary[1]->field0108) secondary[1]->field0110 = secondary[1]->field0108;
    }
    if (secondary[1]->field0110 < secondary[1]->field0108) {
        secondary[1]->field0110 = secondary[1]->field0110 + 200;
        if (secondary[1]->field0110 > secondary[1]->field0108) secondary[1]->field0110 = secondary[1]->field0108;
    }
    if (secondary[0]->comboHitCount == 0) {
        secondary[1]->field010c -= (secondary[1]->field010c > secondary[1]->field0108) * 100;
        if (secondary[1]->field010c < secondary[1]->field0108) secondary[1]->field010c = secondary[1]->field0108;
    }
    if (contextOwner->state1420c > 0) return;
    {
        work.source = MakeSurfaceRect(0, 0, (int)secondary[0]->patterns[48].frames->width, (int)secondary[0]->patterns[48].frames->height);
        work.destination = MakeSurfaceRect(0, 0xe, (int)secondary[0]->patterns[48].frames->width, (int)secondary[0]->patterns[48].frames->height);
        videoOwner->DrawSurface(work.destination, secondary[0]->surfaces[secondary[0]->patterns[48].frames->texture], work.source, secondary[0]->colorKey, 0);
        work.source = MakeSurfaceRect(0, 0, (int)secondary[1]->patterns[48].frames->width, (int)secondary[1]->patterns[48].frames->height);
        work.destination = MakeSurfaceRect(0x140 - secondary[1]->patterns[48].frames->width, 0xe, (int)secondary[1]->patterns[48].frames->width, (int)secondary[1]->patterns[48].frames->height);
        videoOwner->DrawSurface(work.destination, secondary[1]->surfaces[secondary[1]->patterns[48].frames->texture], work.source, secondary[1]->colorKey, 1);
        work.source = MakeSurfaceRect(0, 0, 0x140, 0x2c);
        work.destination = MakeSurfaceRect(0, 0, 0x140, 0x2c);
        videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        work.source = MakeSurfaceRect(0, 0, (int)secondary[0]->patterns[45].frames->width, (int)secondary[0]->patterns[45].frames->height);
        work.destination = MakeSurfaceRect(1, 0x28, (int)secondary[0]->patterns[45].frames->width, (int)secondary[0]->patterns[45].frames->height);
        videoOwner->DrawSurface(work.destination, secondary[0]->surfaces[secondary[0]->patterns[45].frames->texture], work.source, secondary[0]->colorKey, 0);
        work.source = MakeSurfaceRect(0, 0, (int)secondary[1]->patterns[45].frames->width, (int)secondary[1]->patterns[45].frames->height);
        work.destination = MakeSurfaceRect(0x13f - secondary[1]->patterns[45].frames->width, 0x28, (int)secondary[1]->patterns[45].frames->width, (int)secondary[1]->patterns[45].frames->height);
        videoOwner->DrawSurface(work.destination, secondary[1]->surfaces[secondary[1]->patterns[45].frames->texture], work.source, secondary[1]->colorKey, 0);
        // The trail and current bars use distinct live health fields.
        work.width = (int)(secondary[0]->field010c * 120.0 / 9999.0);
        if (work.width > 0) {
            work.source = MakeSurfaceRect(0x78 - work.width, 0x5b, work.width, 6);
            work.destination = MakeSurfaceRect(0x8a - work.width, 0x12, work.width, 6);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        }
        work.width = (int)(secondary[0]->field0110 * 120.0 / 9999.0);
        if (work.width >= 40) {
            work.source = MakeSurfaceRect(0x78 - work.width, 0x49, work.width, 6);
            work.destination = MakeSurfaceRect(0x8a - work.width, 0x12, work.width, 6);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        } else {
            if (work.width > 0) {
                work.source = MakeSurfaceRect(0x78 - work.width, ((secondary[0]->field30f0 % 0x24) / 0x12) * 6 + 0x4f, work.width, 6);
                work.destination = MakeSurfaceRect(0x8a - work.width, 0x12, work.width, 6);
                videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
            }
        }
        work.width = (int)(secondary[1]->field010c * 120.0 / 9999.0);
        if (work.width > 0) {
            work.source = MakeSurfaceRect(0x78, 0x5b, work.width, 6);
            work.destination = MakeSurfaceRect(0xb6, 0x12, work.width, 6);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        }
        work.width = (int)(secondary[1]->field0110 * 120.0 / 9999.0);
        if (work.width >= 40) {
            work.source = MakeSurfaceRect(0x78, 0x49, work.width, 6);
            work.destination = MakeSurfaceRect(0xb6, 0x12, work.width, 6);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        } else {
            if (work.width > 0) {
                // The original right-side low-health source rectangle is eight pixels high.
                work.source = MakeSurfaceRect(0x78, ((secondary[1]->field30f0 % 0x24) / 0x12) * 6 + 0x4f, work.width, 8);
                work.destination = MakeSurfaceRect(0xb6, 0x12, work.width, 6);
                videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
            }
        }
        work.source = MakeSurfaceRect(0x53, 0x93, 7, 0xd);
        if ((char)contextOwner->selection134e >= 1) {
            work.destination = MakeSurfaceRect(0x7b, 0x21, 7, 0xd);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
            work.destination = MakeSurfaceRect(0xbe, 0x21, 7, 0xd);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        }
        if ((char)contextOwner->selection134e >= 2) {
            work.destination = MakeSurfaceRect(0x83, 0x21, 7, 0xd);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
            work.destination = MakeSurfaceRect(0xb6, 0x21, 7, 0xd);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        }
        if ((char)contextOwner->selection134e >= 3) {
            work.destination = MakeSurfaceRect(0x8b, 0x21, 7, 0xd);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
            work.destination = MakeSurfaceRect(0xae, 0x21, 7, 0xd);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        }
        work.source = MakeSurfaceRect(0x4c, 0x93, 7, 0xd);
        if (secondary[0]->field00ac >= 1) {
            work.destination = MakeSurfaceRect(0x7b, 0x21, 7, 0xd);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        }
        if (secondary[0]->field00ac >= 2) {
            work.destination = MakeSurfaceRect(0x83, 0x21, 7, 0xd);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        }
        if (secondary[0]->field00ac >= 3) {
            work.destination = MakeSurfaceRect(0x8b, 0x21, 7, 0xd);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        }
        if (secondary[1]->field00ac >= 1) {
            work.destination = MakeSurfaceRect(0xbe, 0x21, 7, 0xd);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        }
        if (secondary[1]->field00ac >= 2) {
            work.destination = MakeSurfaceRect(0xb6, 0x21, 7, 0xd);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        }
        if (secondary[1]->field00ac >= 3) {
            work.destination = MakeSurfaceRect(0xae, 0x21, 7, 0xd);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        }
        DrawNumber(0xa9,9,field043c,0,2,0);
    }
}

// Complete bottom status display and the per-character stun/angle overlays.
void Scene3::RenderHud()
{
    struct HudWork {
        int player;
        SurfaceRect source;
        int width;
        SurfaceRect destination;
        int stroke;
    } work;
    if (contextOwner->state1420c > 0) return;
    {
        work.source = MakeSurfaceRect(0, 0x28, 0x140, 0x21);
        work.destination = MakeSurfaceRect(0, 0xce, 0x140, 0x21);
        videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        work.width = (secondary[0]->meter * 0x6c) / 3000;
        if (secondary[0]->meter < 1000) {
            work.source = MakeSurfaceRect(0x6c - work.width, 0x73, work.width, 4);
            work.destination = MakeSurfaceRect(0x8c - work.width, 0xe0, work.width, 4);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        } else if (secondary[0]->meter < 2000) {
            work.source = MakeSurfaceRect(0, 0x94, 0x18, 0x18);
            work.destination = MakeSurfaceRect(6, 0xd1, 0x18, 0x18);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
            work.source = MakeSurfaceRect(0x6c - work.width, 0x77, work.width, 4);
            work.destination = MakeSurfaceRect(0x8c - work.width, 0xe0, work.width, 4);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        } else if (secondary[0]->meter < 3000) {
            work.source = MakeSurfaceRect(0x18, 0x94, 0x18, 0x18);
            work.destination = MakeSurfaceRect(6, 0xd1, 0x18, 0x18);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
            work.source = MakeSurfaceRect(0x6c - work.width, 0x7b, work.width, 4);
            work.destination = MakeSurfaceRect(0x8c - work.width, 0xe0, work.width, 4);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        } else {
            work.source = MakeSurfaceRect(0x30, 0x94, 0x18, 0x18);
            work.destination = MakeSurfaceRect(6, 0xd1, 0x18, 0x18);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
            work.source = MakeSurfaceRect(0x6c - work.width, ((secondary[0]->field30f0 % 0x5a) / 0x12) * 4 + 0x7f, work.width, 4);
            work.destination = MakeSurfaceRect(0x8c - work.width, 0xe0, work.width, 4);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        }
        work.width = (secondary[1]->meter * 0x6c) / 3000;
        if (secondary[1]->meter < 1000) {
            work.source = MakeSurfaceRect(0x6c, 0x73, work.width, 4);
            work.destination = MakeSurfaceRect(0xb4, 0xe0, work.width, 4);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        } else if (secondary[1]->meter < 2000) {
            work.source = MakeSurfaceRect(0, 0x94, 0x18, 0x18);
            work.destination = MakeSurfaceRect(0x122, 0xd1, 0x18, 0x18);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
            work.source = MakeSurfaceRect(0x6c, 0x77, work.width, 4);
            work.destination = MakeSurfaceRect(0xb4, 0xe0, work.width, 4);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        } else if (secondary[1]->meter < 3000) {
            work.source = MakeSurfaceRect(0x18, 0x94, 0x18, 0x18);
            work.destination = MakeSurfaceRect(0x122, 0xd1, 0x18, 0x18);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
            work.source = MakeSurfaceRect(0x6c, 0x7b, work.width, 4);
            work.destination = MakeSurfaceRect(0xb4, 0xe0, work.width, 4);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        } else {
            work.source = MakeSurfaceRect(0x30, 0x94, 0x18, 0x18);
            work.destination = MakeSurfaceRect(0x122, 0xd1, 0x18, 0x18);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
            work.source = MakeSurfaceRect(0x6c, ((secondary[1]->field30f0 % 0x5a) / 0x12) * 4 + 0x7f, work.width, 4);
            work.destination = MakeSurfaceRect(0xb4, 0xe0, work.width, 4);
            videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        }
        if (secondary[0]->field0120 == '\0') {
            if (secondary[0]->field0118 < 500.0) {
                work.width = (int)(60.0 * secondary[0]->field0118 * 2 / 1000.0);
                work.source = MakeSurfaceRect(0x3c - work.width, 0x66, work.width, 2);
            } else {
                work.source = MakeSurfaceRect(0, 0x66, 0x3c, 2);
                work.destination = MakeSurfaceRect(0x4f, 0xe8, 0x3c, 2);
                videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
                work.width = (int)((secondary[0]->field0118 - 500.0) * 60.0 * 2 / 1000.0);
                work.source = MakeSurfaceRect(0x3c - work.width, 100, work.width, 2);
            }
        } else {
            work.width = (int)(60.0 * secondary[0]->field0118 / 1000.0);
            work.source = MakeSurfaceRect(0x3c - work.width, ((secondary[0]->field30f0 % 0x5a) / 0x12) * 2 + 0x68, work.width, 2);
        }
        work.destination = MakeSurfaceRect(0x8b - work.width, 0xe8, work.width, 2);
        videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        if (secondary[1]->field0120 == '\0') {
            if (secondary[1]->field0118 < 500.0) {
                work.width = (int)(60.0 * secondary[1]->field0118 * 2 / 1000.0);
                work.source = MakeSurfaceRect(0x3c, 0x66, work.width, 2);
            } else {
                work.source = MakeSurfaceRect(0x3c, 0x66, 0x3c, 2);
                work.destination = MakeSurfaceRect(0xb5, 0xe8, 0x3c, 2);
                videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
                work.width = (int)((secondary[1]->field0118 - 500.0) * 60.0 * 2 / 1000.0);
                work.source = MakeSurfaceRect(0x3c, 100, work.width, 2);
            }
        } else {
            work.width = (int)(60.0 * secondary[1]->field0118 / 1000.0);
            work.source = MakeSurfaceRect(0x3c, ((secondary[1]->field30f0 % 0x5a) / 0x12) * 2 + 0x68, work.width, 2);
        }
        work.destination = MakeSurfaceRect(0xb5, 0xe8, work.width, 2);
        videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        if (contextOwner->counter1354 == 0) {
            for (work.player = 0; work.player < 2; work.player = work.player + 1) {
                if (((((0 < secondary[work.player]->airActionLockFrames) &&
                    (secondary[work.player]->airActionDisabled == 0)) &&
                    (secondary[work.player]->positionY < 0.0)) &&
                    ((secondary[work.player]->field0008 >= 50 &&
                    (secondary[work.player]->field0008 < 0x96)))) &&
                    ((secondary[work.player]->sequences[secondary[work.player]->field0008].data[secondary[work.player]->field000a].attackFlags & 0x400) == 0)) {
                    if (secondary[work.player]->facing == '\x01') {
                        for (work.stroke = 0; work.stroke < 3; work.stroke = work.stroke + 1) {
                            work.destination.left = (int)secondary[work.player]->positionX + field045c + work.stroke;
                            work.destination.top = ((field0460 + 0xd2 + (int)secondary[work.player]->positionY) - (unsigned int)(secondary[work.player]->positionY < 0.0)) + work.stroke;
                            work.destination.right = (int)secondary[work.player]->airActionLockFrames * (unsigned int)(secondary[work.player]->airActionLockFrames < 100) + work.destination.left + (unsigned int)(secondary[work.player]->airActionLockFrames >= 100) * 100;
                            work.destination.bottom = work.destination.top + 1;
                            videoOwner->FillRectangle(work.destination, 211 - (secondary[work.player]->airActionLockFrames > 30) * 3 - (secondary[work.player]->airActionLockFrames > 60) * 7);
                            work.destination.top = work.destination.top + 2;
                            work.destination.bottom = work.destination.top + 1;
                            videoOwner->FillRectangle(work.destination,0xc2);
                        }
                    } else {
                        for (work.stroke = 0; work.stroke < 3; work.stroke = work.stroke + 1) {
                            work.destination.left = (((int)secondary[work.player]->positionX + field045c) - ((int)secondary[work.player]->airActionLockFrames * (unsigned int)(secondary[work.player]->airActionLockFrames < 100) + (unsigned int)(secondary[work.player]->airActionLockFrames >= 100) * 100)) - work.stroke;
                            work.destination.top = ((field0460 + 0xd2 + (int)secondary[work.player]->positionY) - (unsigned int)(secondary[work.player]->positionY < 0.0)) + work.stroke;
                            work.destination.right = (int)secondary[work.player]->airActionLockFrames * (unsigned int)(secondary[work.player]->airActionLockFrames < 100) + work.destination.left + (unsigned int)(secondary[work.player]->airActionLockFrames >= 100) * 100;
                            work.destination.bottom = work.destination.top + 1;
                            videoOwner->FillRectangle(work.destination, 211 - (secondary[work.player]->airActionLockFrames > 30) * 3 - (secondary[work.player]->airActionLockFrames > 60) * 7);
                            work.destination.top = work.destination.top + 2;
                            work.destination.bottom = work.destination.top + 1;
                            videoOwner->FillRectangle(work.destination,0xc2);
                        }
                    }
                }
                if ((secondary[work.player]->airActionGauge != 0.0f) && secondary[work.player]->IsStateGroupA() != 0) {
                    if (secondary[work.player]->facing == '\x01') {
                        for (work.stroke = 0; work.stroke < 3; work.stroke = work.stroke + 1) {
                            work.destination.left = (int)secondary[work.player]->positionX + field045c + work.stroke;
                            work.destination.top = ((field0460 + 0xd2 + (int)secondary[work.player]->positionY) - (unsigned int)(secondary[work.player]->positionY < 0.0)) + work.stroke;
                            work.destination.right = (int)(work.destination.left + secondary[work.player]->airActionGauge * 100.0f / 360.0f);
                            work.destination.bottom = work.destination.top + 1;
                            videoOwner->FillRectangle(work.destination, 0xdc);
                            work.destination.top = work.destination.top + 2;
                            work.destination.bottom = work.destination.top + 1;
                            videoOwner->FillRectangle(work.destination,0xc2);
                        }
                    } else {
                        for (work.stroke = 0; work.stroke < 3; work.stroke = work.stroke + 1) {
                            work.destination.left = (int)(((int)secondary[work.player]->positionX + field045c) - secondary[work.player]->airActionGauge * 100.0f / 360.0f - work.stroke);
                            work.destination.top = ((field0460 + 0xd2 + (int)secondary[work.player]->positionY) - (unsigned int)(secondary[work.player]->positionY < 0.0)) + work.stroke;
                            work.destination.right = (int)(work.destination.left + secondary[work.player]->airActionGauge * 100.0f / 360.0f);
                            work.destination.bottom = work.destination.top + 1;
                            videoOwner->FillRectangle(work.destination, 0xdc);
                            work.destination.top = work.destination.top + 2;
                            work.destination.bottom = work.destination.top + 1;
                            videoOwner->FillRectangle(work.destination,0xc2);
                        }
                    }
                }
            }
        }
    }
}

// Combo count, damage and decimal percentage for either player's side.
void Scene3::RenderCombo(Secondary *character)
{
    struct ComboDisplayWork {
        SurfaceRect source;
        int count;
        SurfaceRect destination;
    } work;
    work.count = character->comboDisplayHitCount;
    if (work.count > 99) work.count = 99;
    if (character->player > 0) {
        work.source = MakeSurfaceRect(0, 172, 61, 38);
        work.destination = MakeSurfaceRect(258, 63, 61, 38);
        if (character->comboDisplayTimer <= 6) videoOwner->DrawBlendedSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0, 0);
        else videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        // Preserve the two original digit-count branches, including identical calls.
        if (work.count > 9) DrawNumber(286, 59, work.count, 1, 0, character->comboDisplayTimer <= 6);
        else DrawNumber(286, 59, work.count, 1, 0, character->comboDisplayTimer <= 6);
        DrawNumber(285, 82, character->comboDamage, 2, 0, character->comboDisplayTimer <= 6);
        DrawNumber(275, 92, (int)character->comboDamageScaleDisplay, 2, 0, character->comboDisplayTimer <= 6);
        DrawNumber(285, 92, (int)(character->comboDamageScaleDisplay * 10.0) % 10, 2, 0, character->comboDisplayTimer <= 6);
        work.source = MakeSurfaceRect(70, 225, 3, 9);
        work.destination = MakeSurfaceRect(275, 92, 3, 9);
        if (character->comboDisplayTimer <= 6) videoOwner->DrawBlendedSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0, 0);
        else videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
    } else {
        work.source = MakeSurfaceRect(0, 172, 61, 38);
        work.destination = MakeSurfaceRect(6, 63, 61, 38);
        if (character->comboDisplayTimer <= 6) videoOwner->DrawBlendedSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0, 0);
        else videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
        // Preserve the two original digit-count branches, including identical calls.
        if (work.count > 9) DrawNumber(34, 59, work.count, 1, 0, character->comboDisplayTimer <= 6);
        else DrawNumber(34, 59, work.count, 1, 0, character->comboDisplayTimer <= 6);
        DrawNumber(33, 82, character->comboDamage, 2, 0, character->comboDisplayTimer <= 6);
        DrawNumber(23, 92, (int)character->comboDamageScaleDisplay, 2, 0, character->comboDisplayTimer <= 6);
        DrawNumber(33, 92, (int)(character->comboDamageScaleDisplay * 10.0) % 10, 2, 0, character->comboDisplayTimer <= 6);
        work.source = MakeSurfaceRect(70, 225, 3, 9);
        work.destination = MakeSurfaceRect(23, 92, 3, 9);
        if (character->comboDisplayTimer <= 6) videoOwner->DrawBlendedSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0, 0);
        else videoOwner->DrawSurface(work.destination, contextOwner->extraC, work.source, contextOwner->colorKey, 0);
    }
}
