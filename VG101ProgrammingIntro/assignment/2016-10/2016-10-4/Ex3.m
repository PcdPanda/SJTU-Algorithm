function [ R ] = Ex3( n )%Main function
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
    global R;%Define a variable R used to read the number
    R='';
    if(n==0)
        R='zero';
        return;
    end
    read(n);
end
function read(n)%A subfunction to divide the input number by three digits
    global R;
    if n>=1000000
        read3(fix(n/1000000));
        R=[R,'million '];
        n=mod(n,1000000);
        read(n);%Recurse to next 3 numbers
    elseif n>=1000
        read3(fix(n/1000));
        R=[R,'thousand '];
        n=mod(n,1000);
        if(n<100)
            R=[R,'and '];
        end
        read(n);%recursion
    else
        read3(n);%Read 3 numbers
    end
end
function read3(n)%A subfunction to read three numbers 
    global R;
    if n==0
        return;   
    elseif n>=100
        r1(fix(n/100));
        R=[R,'hundred '];
        if mod(n,100)~=0
            R=[R,'and '];
            read3(mod(n,100));%resursion
        end;    
    elseif n>=20
            r2(fix(n/10));
            read3(mod(n,10));%recursion
    else
        r1(n);
    end
end
function r1(n)%A subfunction to read one number at third or first place
    global R;
    switch n    
        case 1
            R=[R,'one '];
        case 2
             R=[R,'two '];    
        case 3
            R=[R,'three '];  
        case 4
            R=[R,'four '];  
        case 5
            R=[R,'five '];
        case 6
            R=[R,'six '];
        case 7         
            R=[R,'seven '];
        case 8
            R=[R,'eight '];
        case 9
            R=[R,'nine '];
        case 10 
            R=[R,'ten '];
        case 11                  %Especially read numbers from 11-19
            R=[R,'eleven '];
        case 12
            R=[R,'twelve '];
        case 13
        	R=[R,'thirteen '];
        case 14
            R=[R,'forteen '];
        case 15
            R=[R,'fifteen '];
        case 16      
            R=[R,'sixteen '];    
        case 17
            R=[R,'seventeeen '];
        case 18
            R=[R,'eighteen '];
        case 19
            R=[R,'nineteen '];
     end
end
function r2(n)%A subfunction to read one number at second place
    global R;
    switch n
        case 2
            R=[R,'twenty '];
        case 3
            R=[R,'thirty '];  
        case 4
            R=[R,'forty '] ;  
        case 5
            R=[R,'fifty '];
        case 6
            R=[R,'sixty '];
        case 7
            R=[R 'seventy '];
        case 8
            R=[R 'eighty '];
        case 9
            R=[R,'ninty '];
    end
end
