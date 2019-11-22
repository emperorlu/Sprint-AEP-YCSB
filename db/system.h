//
// 
//

#ifndef YCSB_C_ROCKSDB_DB_H
#define YCSB_C_ROCKSDB_DB_H

#include "core/db.h"
#include <iostream>
#include <string>
#include "core/properties.h"
#include "sys/aep_system.h"
#include "sys/nvm_common2.h"

using std::cout;
using std::endl;
using namespace rocksdb;

namespace ycsbc {
    class AepSystem : public DB{
    public:
        AepSystem(const char *dbfilename, utils::Properties &props, int to_cache, int num_size);
        int Read(const std::string &table, const std::string &key,
                 const std::vector<std::string> *fields,
                 std::vector<KVPair> &result);

        int Scan(const std::string &table, const std::string &key,
                 int len, const std::vector<std::string> *fields,
                 std::vector<std::vector<KVPair>> &result);

        int Insert(const std::string &table, const std::string &key,
                   std::vector<KVPair> &values);

        int Update(const std::string &table, const std::string &key,
                   std::vector<KVPair> &values);


        int Delete(const std::string &table, const std::string &key);

        void PrintStats();
        void Print();

        ~AepSystem();

    private:
        rocksdb::aepsystem *db_;
        unsigned noResult;

        void SetOptions(utils::Properties &props);
        // void SerializeValues(std::vector<KVPair> &kvs, std::string &value);
        // void DeSerializeValues(std::string &value, std::vector<KVPair> &kvs);

        // std::string path;
        // std::string valuepath;
        // size_t nvm_size;
        // size_t nvm_value_size;
        // int m;
        size_t key_size;
        size_t value_size;
        // size_t buf_size;

    };
}


#endif //YCSB_C_ROCKSDB_DB_H
