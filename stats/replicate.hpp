#ifndef REPLICATE_H
#define REPLICATE_H

#include "replicationmanager.h"

template<typename T>
struct Replicate : ReplicateI
{
    T mValue;
    int mIndex = 0;
    ReplicationType mType;
    ReplicationManager *mReplicator = nullptr;
    void SetReplicator(std::string name, CReplInfo32 *crep, ReplicationType type,
                        ReplicationManager *replicator)
    {
        void *offset = nullptr;
        if(replicator->mBase != nullptr)
            offset = (void*) (uint64_t(this) - uint64_t(replicator->mBase));
        mIndex = crep->addVar(name, offset);
        mType = type;
        mReplicator = replicator;
        Set(mValue);
    }

    void Set(T newValue)
    {
        mValue = newValue;
        if(mReplicator != nullptr)
            mReplicator->MarkChanged(mType, mIndex, *((uint32_t*)&mValue));
    }

    void Set(std::string newValue)
    {
        T value;
        std::stringstream ss;
        ss<<newValue;
        ss>>value;
        Set(value);
    }
    std::string Value()
    {
        std::stringstream ss;
        ss<<mValue;
        return ss.str();
    }

    ReplicationType Type()
    {
        return mType;
    }

    uint32_t Index()
    {
        return mIndex;
    }

    uint32_t Value32()
    {
        return *((uint32_t*)&mValue);
    }

    Replicate<T>& operator=(T &rhs)
    {
        Set(rhs);
        return *this;
    }
};


#endif // REPLICATE_H
