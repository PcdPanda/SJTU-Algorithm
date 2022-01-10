function [ a ] = Ex5( n )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    while 1
        l=fix(log10(n))+1;
        n1=n;
        c=0;
        for i=1:1:l
            c=c+(mod(n1,10))^l;
            n1=fix(n1/10);
        end
        if c==n%judge whether n is an Armstrong number
            break;
        end
        n=n+1;
    end
    a=n;
end

