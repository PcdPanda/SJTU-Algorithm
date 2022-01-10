clear all,clc;
while 1    %start a loop
    Y=input('Please enter your year number = ','s');%prompt the year number
    Y=str2num(Y);%judge whether Y is a number
    if fix(Y)-Y==0%judge whether Y is an integer
        if (mod(Y,400))==0||(mod(Y,4)==0 && mod(Y,100)~=0) %decide whether the given year is a leap year
            disp('The given year is a leap year.');%output 
        else
            disp('The given year is not a leap year.');%output
        end
        break;
    end
    disp('what you have prompted is not a year number,please prompt again.');
end
