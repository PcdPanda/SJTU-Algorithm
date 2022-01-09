#!/bin/bash
#All the lines in this bash script are just basic linux commands
#Type bash p4jedge.sh in the command line to use this script
#If cannot excute this bash, type chmod +x p4jedge.sh in the command line
directory="difffiles"
#bankroll=$(($RANDOM%10000+1))


program1="calc"
program2="calcPANDA"
while(true);do
sleep 1
./generate
./$program1<INCALC >out
./$program1<INCALC >outPANDA
diff  out outPANDA >outcome
if [ $? = 1 ]
then
break 
else
echo "same"
fi
done

