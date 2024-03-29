#include "revolution.h"
#include "kamek/hooks.h"
#include "GstRecord.h"
#include "PadRecord.h"

typedef void (*Func)();
extern Func __ctor_loc;
extern Func __ctor_end;

namespace {
    // ----------------------------------------------------------------------------------------------------------------
    // Calls all static initializers after MR::initAcosTable. This is necessary to initialize static variables and 
    // constants in the BSS segment. Custom Nerve instances will be stored there, for example.

    void init() {
        for (Func* f = &__ctor_loc; f < &__ctor_end; f++) {
            (*f)();
        }
    }

#if defined(TWN) || defined(KOR)
    kmBranch(0x804B6A64, init);
#else
    kmBranch(0x804B69F4, init);
#endif


    // ----------------------------------------------------------------------------------------------------------------
    // Events to be handled after GameScene::start

    void handleGameSceneStart() {
        pad::startPadRecorderPrepared();
    }

    kmBranch(0x80451888, handleGameSceneStart);


    // ----------------------------------------------------------------------------------------------------------------
    // Events to be handled after any scene gets destroyed

    void handleAnySceneDestroyed() {
        gst::waitGstRecorder();
        pad::waitPadRecorderNotPrepared();
    }

#if defined(PAL) || defined(USA) || defined(JPN)
    kmBranch(0x804BAB30, handleAnySceneDestroyed);
#elif defined(TWN) || defined(KOR)
    kmBranch(0x804BABA0, handleAnySceneDestroyed);
#endif
}
