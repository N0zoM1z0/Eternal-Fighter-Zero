// Animated backgrounds for stages 1, 10, 12 and 16.
#include "Backgrounds.h"
extern SurfaceRect __cdecl MakeSurfaceRect(int, int, int, int);


Background01::Background01(Video *video)
{
    videoOwner = video;
    stage = 1;
    lastSurface = 57;
    surfaces = new IUnknown *[58];
    effects = new EffectSlot[2];
    patterns = new PatternSequence[2];
    LoadImages();
    LoadPatterns();
    for (int i = 0; i < 2; ++i) {
        effects[i].type = i;
        effects[i].x = 0.0;
        effects[i].y = -450.0;
        effects[i].frame = 0;
        effects[i].tick = 0;
        effects[i].flag0048 = 1;
        effects[i].group = 2;
        effects[i].layer = 0;
    }
}
Background01::~Background01()
{
    for (int i = 0; i < 58; ++i) {
        if (surfaces[i]) { surfaces[i]->Release(); surfaces[i] = 0; }
    }
    delete[] surfaces;
    delete[] effects;
    delete patterns;
}
void Background01::Update()
{
    for (int i = 0; i < 2; ++i) {
        unsigned short duration;
        {
            unsigned short frames;
            duration = patterns[effects[i].type].frames[effects[i].frame].duration;
            frames = patterns[effects[i].type].count;
            switch (effects[i].type) {
                case 0: case 1:
                ++effects[i].tick;
                if (effects[i].tick >= duration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frames) effects[i].frame = 0;
                }
                break;
            }
        }
    }
}
void Background01::Render(int x, int y, char layer)
{
    if (layer == 1) return;
    SurfaceRect destination;
    {
        PatternFrame frame;
        {
            SurfaceRect source;
            {
                for (int i = 0; i < 2; ++i) {
                    {
                        frame = patterns[effects[i].type].frames[effects[i].frame];
                        source = MakeSurfaceRect(0, 0, frame.width, frame.height);
                        if (effects[i].flag0048 == -1) {
                            destination.left = (int)effects[i].x + x - (frame.width - frame.u);
                            destination.top = y + 210 + (int)effects[i].y - frame.v;
                            destination.right = frame.width + destination.left;
                            destination.bottom = frame.height + destination.top;
                        } else {
                            destination.left = (int)effects[i].x + x - frame.u;
                            destination.top = y + 210 + (int)effects[i].y - frame.v;
                            destination.right = frame.width + destination.left;
                            destination.bottom = frame.height + destination.top;
                        }
                        if (effects[i].group > 0) {
                            videoOwner->DrawBlendedSurface(destination, surfaces[frame.texture], source, colorKey, effects[i].flag0048 == -1, effects[i].group - 1);
                        } else {
                            videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, effects[i].flag0048 == -1);
                        }
                    }
                }
            }
        }
    }
}

Background10::Background10(Video *video)
{
    videoOwner = video;
    stage = 10;
    lastSurface = 4;
    surfaces = new IUnknown *[5];
    effects = new EffectSlot[1];
    patterns = new PatternSequence[1];
    LoadImages();
    LoadPatterns();
    for (int i = 0; i < 1; ++i) {
        effects[i].type = i;
        effects[i].x = 0.0;
        effects[i].y = -450.0;
        effects[i].frame = 0;
        effects[i].tick = 0;
        effects[i].flag0048 = 1;
        effects[i].group = 2;
        effects[i].layer = 1;
    }
}
Background10::~Background10()
{
    for (int i = 0; i < 5; ++i) {
        if (surfaces[i]) { surfaces[i]->Release(); surfaces[i] = 0; }
    }
    delete[] surfaces;
    delete[] effects;
    delete patterns;
}
void Background10::Update()
{
    for (int i = 0; i < 1; ++i) {
        unsigned short duration;
        {
            unsigned short frames;
            duration = patterns[effects[i].type].frames[effects[i].frame].duration;
            frames = patterns[effects[i].type].count;
            switch (effects[i].type) {
                case 0: case 1:
                ++effects[i].tick;
                if (effects[i].tick >= duration) {
                    effects[i].tick = 0;
                    ++effects[i].frame;
                    if (effects[i].frame >= frames) effects[i].frame = 0;
                }
                break;
            }
        }
    }
}
void Background10::Render(int x, int y, char layer)
{
    if (layer == 0) return;
    SurfaceRect destination;
    {
        PatternFrame frame;
        {
            SurfaceRect source;
            {
                for (int i = 0; i < 1; ++i) {
                    {
                        frame = patterns[effects[i].type].frames[effects[i].frame];
                        source = MakeSurfaceRect(0, 0, frame.width, frame.height);
                        if (effects[i].flag0048 == -1) {
                            destination.left = (int)effects[i].x + x - (frame.width - frame.u);
                            destination.top = y + 210 + (int)effects[i].y - frame.v;
                            destination.right = frame.width + destination.left;
                            destination.bottom = frame.height + destination.top;
                        } else {
                            destination.left = (int)effects[i].x + x - frame.u;
                            destination.top = y + 210 + (int)effects[i].y - frame.v;
                            destination.right = frame.width + destination.left;
                            destination.bottom = frame.height + destination.top;
                        }
                        if (effects[i].group > 0) {
                            videoOwner->DrawBlendedSurface(destination, surfaces[frame.texture], source, colorKey, effects[i].flag0048 == -1, effects[i].group - 1);
                        } else {
                            videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, effects[i].flag0048 == -1);
                        }
                    }
                }
            }
        }
    }
}

Background12::Background12(Video *video)
{
    videoOwner = video;
    stage = 12;
    lastSurface = 1;
    surfaces = new IUnknown *[2];
    effects = new EffectSlot[2];
    patterns = new PatternSequence[2];
    LoadImages();
    LoadPatterns();
    for (int i = 0; i < 2; ++i) {
        effects[i].type = i;
        effects[i].x = 0.0;
        effects[i].y = -450.0;
        effects[i].frame = 0;
        effects[i].tick = 0;
        effects[i].flag0048 = 1;
        effects[i].group = 2;
        effects[i].layer = 1 - i;
    }
}
Background12::~Background12()
{
    for (int i = 0; i < 2; ++i) {
        if (surfaces[i]) { surfaces[i]->Release(); surfaces[i] = 0; }
    }
    delete[] surfaces;
    delete[] effects;
    delete patterns;
}
void Background12::Update()
{
    for (int i = 0; i < 2; ++i) {
        unsigned short duration;
        {
            unsigned short frames;
            duration = patterns[effects[i].type].frames[effects[i].frame].duration;
            frames = patterns[effects[i].type].count;
            switch (effects[i].type) {
                case 0:
                effects[i].x += 0.5;
                if (effects[i].x >= 640.0) effects[i].x = 0.0;
                case 1:
                effects[i].x += 0.25;
                if (effects[i].x >= 640.0) effects[i].x = 0.0;
                break;
            }
        }
    }
}
void Background12::Render(int x, int y, char layer)
{
    SurfaceRect repeated;
    {
        SurfaceRect destination;
        {
            PatternFrame frame;
            {
                SurfaceRect source;
                {
                    for (int i = 0; i < 2; ++i) {
                        if (layer != effects[i].layer) continue;
                        {
                            frame = patterns[effects[i].type].frames[effects[i].frame];
                            source = MakeSurfaceRect(0, 0, frame.width, frame.height);
                            if (effects[i].flag0048 == -1) {
                                destination.left = (int)effects[i].x + x - (frame.width - frame.u);
                                destination.top = y + 210 + (int)effects[i].y - frame.v;
                                destination.right = frame.width + destination.left;
                                destination.bottom = frame.height + destination.top;
                                repeated.left = (int)effects[i].x + x - (frame.width - frame.u) - 640;
                                repeated.top = y + 210 + (int)effects[i].y - frame.v;
                                repeated.right = frame.width + repeated.left;
                                repeated.bottom = frame.height + repeated.top;
                            } else {
                                destination.left = (int)effects[i].x + x - frame.u;
                                destination.top = y + 210 + (int)effects[i].y - frame.v;
                                destination.right = frame.width + destination.left;
                                destination.bottom = frame.height + destination.top;
                                repeated.left = (int)effects[i].x + x - frame.u - 640;
                                repeated.top = y + 210 + (int)effects[i].y - frame.v;
                                repeated.right = frame.width + repeated.left;
                                repeated.bottom = frame.height + repeated.top;
                            }
                            if (effects[i].group > 0) {
                                videoOwner->DrawBlendedSurface(destination, surfaces[frame.texture], source, colorKey, effects[i].flag0048 == -1, effects[i].group - 1);
                                videoOwner->DrawBlendedSurface(repeated, surfaces[frame.texture], source, colorKey, effects[i].flag0048 == -1, effects[i].group - 1);
                            } else {
                                videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, effects[i].flag0048 == -1);
                                videoOwner->DrawSurface(repeated, surfaces[frame.texture], source, colorKey, effects[i].flag0048 == -1);
                            }
                        }
                    }
                }
            }
        }
    }
}

Background16::Background16(Video *video)
{
    videoOwner = video;
    stage = 16;
    lastSurface = 3;
    surfaces = new IUnknown *[4];
    effects = new EffectSlot[4];
    patterns = new PatternSequence[4];
    LoadImages();
    LoadPatterns();
    for (int i = 0; i < 4; ++i) {
        effects[i].type = i;
        effects[i].x = 0.0;
        effects[i].y = -450.0;
        effects[i].frame = 0;
        effects[i].tick = 0;
        effects[i].flag0048 = 1;
        effects[i].group = 2;
        effects[i].layer = i > 1;
    }
}
Background16::~Background16()
{
    for (int i = 0; i < 4; ++i) {
        if (surfaces[i]) { surfaces[i]->Release(); surfaces[i] = 0; }
    }
    delete[] surfaces;
    delete[] effects;
    delete patterns;
}
void Background16::Update()
{
    for (int i = 0; i < 4; ++i) {
        unsigned short duration;
        {
            unsigned short frames;
            duration = patterns[effects[i].type].frames[effects[i].frame].duration;
            frames = patterns[effects[i].type].count;
            switch (effects[i].type) {
                case 0:
                effects[i].x += 1.0;
                if (effects[i].x >= 850.0) effects[i].x -= 850.0;
                break;
                case 1:
                effects[i].x += 1.4;
                if (effects[i].x >= 806.0) effects[i].x -= 806.0;
                break;
                case 2:
                effects[i].x += 1.8;
                if (effects[i].x >= 789.0) effects[i].x -= 789.0;
                break;
                case 3:
                effects[i].x += 2.2;
                if (effects[i].x >= 947.0) effects[i].x = 947.0;
                break;
            }
        }
    }
}
void Background16::Render(int x, int y, char layer)
{
    SurfaceRect repeated;
    {
        SurfaceRect destination;
        {
            PatternFrame frame;
            {
                SurfaceRect source;
                {
                    for (int i = 0; i < 4; ++i) {
                        if (layer != effects[i].layer) continue;
                        {
                            frame = patterns[effects[i].type].frames[effects[i].frame];
                            source = MakeSurfaceRect(0, 0, frame.width, frame.height);
                            if (effects[i].flag0048 == -1) {
                                destination.left = (int)effects[i].x + x - (frame.width - frame.u);
                                destination.top = y + 210 + (int)effects[i].y - frame.v;
                                destination.right = frame.width + destination.left;
                                destination.bottom = frame.height + destination.top;
                                repeated.left = (int)effects[i].x + x - (frame.width - frame.u) - frame.width;
                                repeated.top = y + 210 + (int)effects[i].y - frame.v;
                                repeated.right = frame.width + repeated.left;
                                repeated.bottom = frame.height + repeated.top;
                            } else {
                                destination.left = (int)effects[i].x + x - frame.u;
                                destination.top = y + 210 + (int)effects[i].y - frame.v;
                                destination.right = frame.width + destination.left;
                                destination.bottom = frame.height + destination.top;
                                repeated.left = (int)effects[i].x + x - frame.u - frame.width;
                                repeated.top = y + 210 + (int)effects[i].y - frame.v;
                                repeated.right = frame.width + repeated.left;
                                repeated.bottom = frame.height + repeated.top;
                            }
                            if (effects[i].group > 0) {
                                videoOwner->DrawBlendedSurface(destination, surfaces[frame.texture], source, colorKey, effects[i].flag0048 == -1, effects[i].group - 1);
                                videoOwner->DrawBlendedSurface(repeated, surfaces[frame.texture], source, colorKey, effects[i].flag0048 == -1, effects[i].group - 1);
                            } else {
                                videoOwner->DrawSurface(destination, surfaces[frame.texture], source, colorKey, effects[i].flag0048 == -1);
                                videoOwner->DrawSurface(repeated, surfaces[frame.texture], source, colorKey, effects[i].flag0048 == -1);
                            }
                        }
                    }
                }
            }
        }
    }
}
