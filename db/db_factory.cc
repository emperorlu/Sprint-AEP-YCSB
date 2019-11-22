//
//  basic_db.cc
//  YCSB-C
//
//  Created by Jinglei Ren on 12/17/14.
//  Copyright (c) 2014 Jinglei Ren <jinglei@ren.systems>.
//

#include "db/db_factory.h"

#include <string>
#include "db/basic_db.h"

using namespace std;
using ycsbc::DB;
using ycsbc::DBFactory;

DB* DBFactory::CreateDB(utils::Properties &props, int to_cache, int num_size) {
  if (props["dbname"] == "basic") {
    return new BasicDB;
  } else if (props["dbname"] == "aepsystem") {
    std::string dbpath = props.GetProperty("dbpath","/tmp/test-aepsystem");
    return new AepSystem(dbpath.c_str(), props, to_cache, num_size);
  } else return NULL;
}

