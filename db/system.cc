//
// Created by wujy on 1/23/19.
//
#include <iostream>
#include "system.h"
#include "lib/coding.h"
using namespace std;
using namespace rocksdb;


namespace ycsbc {
    AepSystem::AepSystem(const char *dbfilename, utils::Properties &props, int to_cache, int num_size) :noResult(0){
    
        //set option
        SetOptions(props);
        // aepsystem::AllocatorInit();
        
        db_ = new rocksdb::aepsystem(to_cache, num_size);
        if(!db_) {
            printf("creat AepSystem error\n");
            // AllocatorExit();
        }
        db_->Initialize();
    }

    void AepSystem::SetOptions(utils::Properties &props) {
    //     path = "/pmem0/key";
    //     valuepath = "/pmem0/value";
    //     nvm_size = 100 * (1ULL << 30);
    //     nvm_value_size = 200 * (1ULL << 30);
    //     m = 10;
        key_size = rocksdb::NVM_KeySize;
        value_size = rocksdb::NVM_ValueSize;
    //     buf_size = key_size + value_size + 1;

    }


    int AepSystem::Read(const std::string &table, const std::string &key, const std::vector<std::string> *fields,
                      std::vector<KVPair> &result) {
        string value;
        value = db_->Get(key);
        if(value.empty()){
            noResult++;
        }
        return DB::kOK;
    }

    void AepSystem::Print()
    {
        db_->Print();
    }


    // int AepSystem::Scan(const std::string &table, const std::string &key, int len, const std::vector<std::string> *fields,
    //                   std::vector<std::vector<KVPair>> &result) {
    //     std::vector<std::string> values;
    //     db_->GetRange(key, "", values, len);
    //     return DB::kOK;
    // }

    int AepSystem::Insert(const std::string &table, const std::string &key,
                        std::vector<KVPair> &values){
        string value;
        // string mkey = key.c_str();
        // cout << "AepSystem::Insert: " << mkey << "size: " << mkey.size() << endl;
        value.append(value_size, 'a');
        db_->Insert(key, value);
        return DB::kOK;
    }

    // int AepSystem::Update(const std::string &table, const std::string &key, std::vector<KVPair> &values) {
    //     string value;
    //     value.append(value_size, 'b');
    //     db_->Update(key, value);
    //     return DB::kOK;
    // }

    int AepSystem::Delete(const std::string &table, const std::string &key) {
        db_->Delete(key);
        return DB::kOK;
    }

    void AepSystem::PrintStats() {
        //if(noResult != 0) {
            cout<<"read not found:"<<noResult<<endl;
        //}
        //db_->Print();
    }

    AepSystem::~AepSystem() {
        db_->End();
        delete db_;      
        // AllocatorExit();
    }

    // void AepSystem::SerializeValues(std::vector<KVPair> &kvs, std::string &value) {
    //     value.clear();
    //     PutFixed64(&value, kvs.size());
    //     for(unsigned int i=0; i < kvs.size(); i++){
    //         PutFixed64(&value, kvs[i].first.size());
    //         value.append(kvs[i].first);
    //         PutFixed64(&value, kvs[i].second.size());
    //         value.append(kvs[i].second);
    //     }
    // }

    // void AepSystem::DeSerializeValues(std::string &value, std::vector<KVPair> &kvs){
    //     uint64_t offset = 0;
    //     uint64_t kv_num = 0;
    //     uint64_t key_size = 0;
    //     uint64_t value_size = 0;

    //     kv_num = DecodeFixed64(value.c_str());
    //     offset += 8;
    //     for( unsigned int i = 0; i < kv_num; i++){
    //         ycsbc::DB::KVPair pair;
    //         key_size = DecodeFixed64(value.c_str() + offset);
    //         offset += 8;

    //         pair.first.assign(value.c_str() + offset, key_size);
    //         offset += key_size;

    //         value_size = DecodeFixed64(value.c_str() + offset);
    //         offset += 8;

    //         pair.second.assign(value.c_str() + offset, value_size);
    //         offset += value_size;
    //         kvs.push_back(pair);
    //     }
    // }
}
