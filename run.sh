#!/bin/bash

./rmsh
numactl --cpunodebind=1 --membind=1 ./ycsbc -db aepsystem -dbpath /home/lk/ceshi -threads 1 -P workloads/20G_load.spec -load true -run true -dbstatistics true >> out.out

./rmsh
numactl --cpunodebind=1 --membind=1 ./ycsbc -db aepsystem -dbpath /home/lk/ceshi -threads 1 -P workloads/15G_load.spec -load true -run true -dbstatistics true >> out.out

./rmsh
numactl --cpunodebind=1 --membind=1 ./ycsbc -db aepsystem -dbpath /home/lk/ceshi -threads 1 -P workloads/10G_load.spec -load true -run true -dbstatistics true >> out.out

./rmsh
numactl --cpunodebind=1 --membind=1 ./ycsbc -db aepsystem -dbpath /home/lk/ceshi -threads 1 -P workloads/5G_load.spec -load true -run true -dbstatistics true >> out.out

./rmsh
numactl --cpunodebind=1 --membind=1 ./ycsbc -db aepsystem -dbpath /home/lk/ceshi -threads 1 -P workloads/1G_load.spec -load true -run true -dbstatistics true >> out.out

./rmsh


