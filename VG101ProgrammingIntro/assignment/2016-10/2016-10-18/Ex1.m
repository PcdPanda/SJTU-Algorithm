clear all,clc;
n=0;
for i=1:64
    n=n+2^(i-1);
end
%n=uint64(n);
%disp([,' grains of wheat had to be given to the creator']);