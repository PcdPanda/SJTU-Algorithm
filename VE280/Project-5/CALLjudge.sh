#!/bin/bash
#All the lines in this bash script are just basic linux commands
#Type bash p4jedge.sh in the command line to use this script
#If cannot excute this bash, type chmod +x p4jedge.sh in the command line
directory="difffiles"
#bankroll=$(($RANDOM%10000+1))


program1="call"
program2="callPANDA"
while(true);do
sleep 1
./generate
./$program1<INCALL >out
./$program1<INCALL >outPANDA
diff  out outPANDA >outcome
if [ $? = 1 ]
then
break 
else
echo "same"
fi
done

