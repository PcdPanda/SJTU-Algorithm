#!/bin/bash
#All the lines in this bash script are just basic linux commands
#Type bash p3judge.sh in the command line to use this script
#If cannot excute this bash, type chmod +x p3judge.sh in the command line
program1="main"
program2="template"
declare -i idx
idx=0
while(true);do
#sleep 0.1
./test 500 2000 >in
./$program1 <in >out_p
./$program2 <in >out_s
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
