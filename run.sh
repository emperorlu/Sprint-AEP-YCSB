#!/bin/bash

./rmsh
numactl --cpunodebind=1 --membind=1 ./ycsbc 0 20 -db aepsystem -dbpath /home/lk/ceshi -threads 1 -P workloads/20G_load.spec -load true -run true -dbstatistics true >> out.out

./rmsh
numactl --cpunodebind=1 --membind=1 ./ycsbc 0 15 -db aepsystem -dbpath /home/lk/ceshi -threads 1 -P workloads/15G_load.spec -load true -run true -dbstatistics true >> out.out

./rmsh
numactl --cpunodebind=1 --membind=1 ./ycsbc 0 10 -db aepsystem -dbpath /home/lk/ceshi -threads 1 -P workloads/10G_load.spec -load true -run true -dbstatistics true >> out.out

./rmsh
numactl --cpunodebind=1 --membind=1 ./ycsbc 0 5 -db aepsystem -dbpath /home/lk/ceshi -threads 1 -P workloads/5G_load.spec -load true -run true -dbstatistics true >> out.out

./rmsh
numactl --cpunodebind=1 --membind=1 ./ycsbc 0 1 -db aepsystem -dbpath /home/lk/ceshi -threads 1 -P workloads/1G_load.spec -load true -run true -dbstatistics true >> out.out

./rmsh
numactl --cpunodebind=1 --membind=1 ./ycsbc 1 20 -db aepsystem -dbpath /home/lk/ceshi -threads 1 -P workloads/20G_load.spec -load true -run true -dbstatistics true >> out1.out

./rmsh
numactl --cpunodebind=1 --membind=1 ./ycsbc 1 15 -db aepsystem -dbpath /home/lk/ceshi -threads 1 -P workloads/15G_load.spec -load true -run true -dbstatistics true >> out1.out

./rmsh
numactl --cpunodebind=1 --membind=1 ./ycsbc 1 10 -db aepsystem -dbpath /home/lk/ceshi -threads 1 -P workloads/10G_load.spec -load true -run true -dbstatistics true >> out1.out

./rmsh
numactl --cpunodebind=1 --membind=1 ./ycsbc 1 5 -db aepsystem -dbpath /home/lk/ceshi -threads 1 -P workloads/5G_load.spec -load true -run true -dbstatistics true >> out1.out

./rmsh
numactl --cpunodebind=1 --membind=1 ./ycsbc 1 1 -db aepsystem -dbpath /home/lk/ceshi -threads 1 -P workloads/1G_load.spec -load true -run true -dbstatistics true >> out1.out


