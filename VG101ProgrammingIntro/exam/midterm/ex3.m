clear all,clc;
F = getframe(gca,[10 10 200 200]);
c = F.cdata(:,:,1);
[i,j] = find(c==0);
load mandrill
ind = sub2ind(size(X),i,j);
X(ind) = uint8(255);
image(X);