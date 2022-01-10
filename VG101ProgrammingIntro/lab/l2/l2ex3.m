function [ day ] = l2ex3(A)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
d=A(1,1);
m=A(1,2);
cy=A(1,3);
if m<=2
    m=m+10;
    cy=cy-1;
else
    m=m-2;
end
y=mod(cy,100);
c=fix(cy/100);
day=1+mod((d+fix((13*m-1)/5)+y+fix(y/4)+fix(c/4)-2*c),7);
switch day
    case 0
        day='Sunday';
    case 1
        day='Saturday';
    case 2
        day='Monday';
    case 3
        day='Tuesday';
    case 4
        day='Wednesday';
    case 5
        day='Thursday';
    case 6
        day='Friday';    
end
end

