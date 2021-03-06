
#pragma once

/*
* nvm_btree.h
*/

#include <array>
#include <thread>
#include <mutex>
#include <string>
#include <assert.h>

#include "nvm_common2.h"
#include "nvm_allocator.h"
#include "con_btree.h"
// #ifdef SINGLE_BTREE
// #include "single_btree.h"
// #else 
// #include "con_btree.h"
// #endif

using namespace std;

class NVMBtree{
public:
    NVMBtree();
    ~NVMBtree();

    void Initial(const std::string &path, uint64_t keysize, const std::string &valuepath, 
                uint64_t valuesize);

    void Insert(const unsigned long key, const string &value);
    void Insert(const unsigned long key, const unsigned long hot, const string &value);

    void Delete(const unsigned long key);
    vector<entry_key_t> BacktoDram(int hot, size_t read);

    const std::string Get(const unsigned long key);
    void Updakey(const unsigned long key, const unsigned long hot);

    void GetRange(unsigned long key1, unsigned long key2, std::vector<std::string> &values, int &size);

    void FunctionTest(int ops);
    void motivationtest();

    int GetCacheSzie(){
        if(bt) {
            return bt->cache_size();
        }
        exit(0);
    }
    void Print();
    void PrintInfo();

    bool StorageIsFull() {
        return node_alloc->StorageIsFull() || value_alloc->StorageIsFull();
    }

    void PrintStorage() {
        node_alloc->PrintStorage();
        value_alloc->PrintStorage();
    }

private:
    NVMAllocator *value_alloc;
    btree *bt;
};