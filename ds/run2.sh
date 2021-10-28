for m in "DutchPartition"
do
    for idx in $(seq 10 24)
    do
        for i in $(seq 1 10)
        do
            ./main.exe -index $idx -method $m -save $m.csv
        done
    done
done
