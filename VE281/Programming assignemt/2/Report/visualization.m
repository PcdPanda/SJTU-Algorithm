clear all,clc;
t0=[8e-6 2.5e-5 4e-5 2.5e-4 4e-4 4.6e-3 7.5e-3 5.2e-2];
t1=[1.4e-5 6.4e-5 8.6e-5 6e-4 4.4e-4 1.7e-3 3.3e-3 0.033];
t2=[1.8e-5 1.2e-4 2.1e-4 4.1e-4 9.6e-4 4e-3 8.3e-3 9e-2];
size=[100 500 1000 5000 10000 50000 100000 1000000];
semilogy(size,t0,'d-',size,t1,'*-',size,t2,'o-');
xlabel('array size');
ylabel('time');
legend('Random Selection','Deterministic Selection','quick sort');