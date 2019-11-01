#/bin/bash

workload="workloads/1M_workloada.spec"
dbpath="/home/lk/ceshi"
# moreworkloads="workloads/50M_workloada.spec:workloads/50M_workloadb.spec:workloads/50M_workloadc.spec:workloads/50M_workloadd.spec:workloads/1M_workloade.spec:workloads/50M_workloadf.spec"

#./ycsbc -db aepsystem -dbpath $dbpath -threads 1 -P $workload -load true -run true -dbstatistics true

#./ycsbc -db aepsystem -dbpath $dbpath -threads 1 -P $workload -load true -morerun $moreworkloads -dbstatistics true


cmd="./ycsbc -db aepsystem -dbpath $dbpath -threads 1 -P $workload -load true -morerun $moreworkloads -dbstatistics true >>out.out 2>&1 "

if [ "$1" == "numa" ];then
    cmd="numactl -N 1 -m 1 ./ycsbc -db aepsystem -dbpath $dbpath -threads 1 -P $workload -load true -morerun $moreworkloads -dbstatistics true >>out.out 2>&1 "
fi

echo $cmd >out.out
echo $cmd
eval $cmd