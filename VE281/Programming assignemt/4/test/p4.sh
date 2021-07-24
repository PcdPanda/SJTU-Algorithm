#!/bin/bash
#All the lines in this bash script are just basic linux commands
#Type bash p3judge.sh in the command line to use this script
#If cannot excute this bash, type chmod +x p3judge.sh in the command line
program1="main"
program2="set_debug"
declare -i idx
idx=0
while(true);do
#sleep 0.1
python trade_center.py
./$program1 -p --v -t  --median <in >out_p
./$program2 -p --v  -t --median <in >out_s
diff out_p out_s
if [ $? = 1 ]
then
break 
else
idx=$idx+1
echo "Same case number: $idx"
fi
done
exit 0
