// Battle owner and collision snapshots; numerical views follow original accesses.
#ifndef EFZ_SCENE_BATTLE_H
#define EFZ_SCENE_BATTLE_H
#include "Engine.h"
struct BattleCollisionSnapshot {
    SecondaryFrame frame;
    PatternFrame sprite;
    double x, y;
    char facing, state;
    short command;
};
class Scene3 : public Scene {
    unsigned char unknown_0430[4];
    int field0434, field0438, field043c;
    int field0440, field0444, field0448, field044c;
    int field0450, field0454, field0458, field045c, field0460;
    SurfaceRect numberStyles[17];
    short field0574, field0576;
    unsigned char field0578, unknown_0579[7];
    double field0580;
    int field0588, field058c, field0590;
    unsigned char unknown_0594[4];
public:
    Scene3(HWND, Secondary **, Secondary **, Context *, Video *, Input *, Audio *);
    virtual void Slot0();
    virtual unsigned char Step();
    virtual void PollKeyboard();
    void UpdateCamera();
    void PlayCharacterSounds();
    void PlayEffectSounds();
    void UpdateIntro();
    void ResetReplay();
    void UpdateRound();
    int UpdateRoundExit();
    void ResolvePushboxes();
    void RenderBackground();
    void RenderHealthBars();
    void RenderShadows();
    void RenderHud();
    void RenderCombo(Secondary *);
    void ClipFrame();
    void DrawNumber(int, int, unsigned int, unsigned char, unsigned char, int);
    SurfaceRect TransformPoseBox(const SecondaryPose *, const SurfaceRect *);
    SurfaceRect TransformSnapshotBox(const BattleCollisionSnapshot *, const SurfaceRect *);
    int BoxesOverlap(const SurfaceRect *, const SurfaceRect *);
    void DispatchCollisions();
    int TestBodyInteraction(Secondary *, Secondary *, const BattleCollisionSnapshot *, const BattleCollisionSnapshot *);
    void ResolveEffectClash(Secondary *, Secondary *, int, int);
    void ResolveEffectPair(Secondary *, Secondary *, int, int);
    void ResolveEffectHit(Secondary *, Secondary *, int, BattleCollisionSnapshot *);
    void ResolveBodyEffect(Secondary *, Secondary *, BattleCollisionSnapshot *, BattleCollisionSnapshot *, int);
    void ResolveBodyHit(Secondary *, Secondary *, BattleCollisionSnapshot *, BattleCollisionSnapshot *);

};
#endif
