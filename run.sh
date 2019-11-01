#!/bin/bash

./ycsbc -db aepsystem -dbpath /home/lk/ceshi -threads 1 -P workloads/400M_load.spec -load true -run true -dbstatistics true
