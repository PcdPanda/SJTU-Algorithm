clear all,clc;
t0=[6.5e-5 6.1e-5 3.6e-4 1.4e-3 3.7e-3 5.2e-3 0.13];
t1=[5.5e-5 6.3e-5 4.2e-4 2.6e-3 1.1e-2 1.9e-2 2.1];
t2=[1.2e-4 1.3e-4 1.7e-3 4.7e-3 1.9e-2 2.9e-2 0.92];
size=[5 10 20 50 75 100 1000];
semilogy(size,t0,'d-',size,t1,'*-',size,t2,'o-');
xlabel('array size');
ylabel('time');
legend('Binary Heap','Unsorted Heap','Fibonacci Heap');