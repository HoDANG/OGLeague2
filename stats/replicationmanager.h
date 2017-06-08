#ifndef REPLICATIONMANAGER_H
#define REPLICATIONMANAGER_H

#include <vector>
#include <string.h>
#include <bitset>
#include <sstream>
#include "stringutils.hpp"

enum ReplicationType
{
    CLIENT_ONLY_REP_DATA = 0x1,
    LOCAL_REP_DATA1 = 0x2,
    LOCAL_REP_DATA2 = 0x4,
    MAP_REPDATA = 0x8,
    ONVISIBLE_REP_DATA = 0x10,
};

struct ReplicateI
{
    virtual void Set(std::string newValue);
    virtual std::string Value();
    virtual ReplicationType Type();
    virtual uint32_t Index();
    virtual uint32_t Value32();
};

struct CReplInfo32
{
    int numVars = 0;
    std::string varNames[32];
    void* varOffsets[32];
    int addVar(std::string name, void *offset);
    void *find(std::string name);
};

struct CReplData32
{
    CReplInfo32 *info = nullptr;
    uint32_t valuesThatHaveChanged = 0;
    uint32_t mValueCopy[32];
    bool firstTime = false;
    void Init(CReplInfo32 *ri);
    void *find(std::string name);
    bool Dump(std::vector<uint32_t> &data);
};

struct ReplicationManager
{
    CReplData32 mClientOnlyRepData1;
    CReplData32 mLocalRepData1;
    CReplData32 mLocalRepData2;
    CReplData32 mMapRepData;
    CReplData32 mOnVisibleRepData;
    uint32_t mModified = 0;
    void *mBase = nullptr;
    void Init(CReplInfo32 *npc_ClientOnly, CReplInfo32 *npc_LocalRepData1, CReplInfo32 *npc_LocalRepData2,
              CReplInfo32 *npc_MapRepData, CReplInfo32 *npc_OnVisibleRepData, void *base = nullptr);
    void MarkChanged(ReplicationType type, int index, uint32_t value);
    uint8_t DumpReplication(std::vector<uint32_t> &data);
    ReplicateI* find(std::string name);
};

#endif // REPLICATIONMANAGER_H
