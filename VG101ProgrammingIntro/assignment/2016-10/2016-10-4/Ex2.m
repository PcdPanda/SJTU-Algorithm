clear all,clc;
prompt=input('Please prompt the number from the key board = ');%Prompt the number
n=4*fix((prompt+3)/4)+1;%Decide the next Pythagorean prime
a=0;
while 1%Decide whether n is a prime
    c=primes(n);
    if n==c(1,end)
        break;
    end
    n=n+4;
end%Find the next Pythagorean prime number
while 1%Start a loop
    b=(n-a^2)^(1/2);%Find the second corresponding number
    if b==fix(b)%Use b to decide the first number a
        break
    else
        a=a+1;
    end
end
a=num2str(a);
b=num2str(b);
n=num2str(n);
disp(['the next Pythagorean prime number is ',n])%display the prime
disp(['The two corresponding numbers are ',a,' and ',b]);%display the numbers
