#ifndef CHARACTERSTATE_H
#define CHARACTERSTATE_H

#include <streambuf>
#include "replicationmanager.h"

struct CharacterState
{
    union CompressedStates
    {
        struct
        {
          uint32_t mActionState : 3;
          uint32_t mStealthed : 1;
          uint32_t mRevealSpecificUnit : 1;
          uint32_t mTaunted : 1;
          uint32_t mFeared : 1;
          uint32_t mSuppressed : 1;
          uint32_t mSleep : 1;
          uint32_t mNearSight : 1;
          uint32_t mGhosted : 1;
          uint32_t mGhostProof : 1;
          uint32_t mCharmed : 1;
          uint32_t mNoRender : 1;
          uint32_t mForceRenderParticles : 1;
          uint32_t mDodgePiercing : 1;
          uint32_t mDisableAmbientGold : 1;
          uint32_t mBrushVisibilityFake : 1;
          uint32_t mRemain : 15;
        } flags;
        uint32_t Raw;
    };
    Replicate<CompressedStates> mStates;
    bool ignoringCallForHelp;
    bool suppressingCallForHelp;
    bool callForHelpSuppresser;
};

inline std::basic_istream<char> &
operator >> (std::basic_istream<char> & out, CharacterState::CompressedStates &data)
{
    return out >> data.Raw;
}


inline std::basic_ostream<char> &
operator << (std::basic_ostream<char> & out,  CharacterState::CompressedStates &data)
{
    return out << data.Raw;
}


#endif // CHARACTERSTATE_H
