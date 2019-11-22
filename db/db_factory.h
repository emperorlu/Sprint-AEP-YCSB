//
//  db.h
//  YCSB-C
//
//  Created by Jinglei Ren on 12/18/14.
//  Copyright (c) 2014 Jinglei Ren <jinglei@ren.systems>.
//

#ifndef YCSB_C_DB_FACTORY_H_
#define YCSB_C_DB_FACTORY_H_

#include "core/db.h"
#include "core/properties.h"
#include "db/system.h"
// #include "sys/aep_system.h"

namespace ycsbc {

class DBFactory {
 public:
  static DB* CreateDB(utils::Properties &props, int to_cache, int num_size);
};

} // ycsbc

#endif // YCSB_C_DB_FACTORY_H_

