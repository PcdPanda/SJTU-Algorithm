#!/bin/bash
#All the lines in this bash script are just basic linux commands
#Type bash p3judge.sh in the command line to use this script
#If cannot excute this bash, type chmod +x p3judge.sh in the command line
directory="difffiles"
program1="p3jmh"
program2="p3pcd"
while(true);do
sleep 1
./generate_world species world
./$program1 ./species world 10 v >out
./$program2 ./species world 10 v >outpcd
diff  out outpcd
if [ $? = 1 ]
then
break 
else
echo "same"
fi
done

