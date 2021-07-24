#!/bin/bash
#All the lines in this bash script are just basic linux commands
#Type bash p4jedge.sh in the command line to use this script
#If cannot excute this bash, type chmod +x p4jedge.sh in the command line
directory="difffiles"
#bankroll=$(($RANDOM%10000+1))


program1="p4"
program2="p4PANDA"
while(true);do
sleep 1
bankroll=$(($RANDOM%10000+1))
hands=$(($RANDOM%100+1))
./decks
./$program1 $bankroll 5 $hands simple IN >out
./$program2 $bankroll 5 $hands simple IN >outPANDA
diff  out outPANDA >outcome
if [ $? = 1 ]
then
break 
else
echo "same"
fi
done

