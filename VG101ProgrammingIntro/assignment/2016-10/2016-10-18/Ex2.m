clc,clear all;
y=0;
k=0;
clothes(1)=struct('type','Jumpers','color','Blue','quantity',2,'bought',[2005 4]);
clothes(2)=struct('type','Jumpers','color','Brown','quantity',3,'bought',[2013 2]);
clothes(3)=struct('type','Jumpers','color','Green','quantity',5,'bought',[2015 1]);
clothes(4)=struct('type','Trousers','color','Black','quantity',3,'bought',[2012 6]);
clothes(5)=struct('type','Trousers','color','Grey','quantity',2,'bought',[2011 4]);
clothes(6)=struct('type','Trousers','color','White','quantity',1,'bought',[2013 12]);
clothes(7)=struct('type','T-shirts','color','Blue','quantity',1,'bought',[2010 5]);
clothes(8)=struct('type','T-shirts','color','Green','quantity',2,'bought',[2014 9]);
clothes(9)=struct('type','T-shirts','color','Red','quantity',3,'bought',[2012 1]);
clothes(10)=struct('type','T-shirts','color','White','quantity',2,'bought',[2008 3]);
clothes(11)=struct('type','T-shirts','color','Yellow','quantity',1,'bought',[2012 11]);%construct as structre
[m i]=max([clothes(1:11).quantity]);
disp([clothes(i).color,' ',clothes(i).type,' is in the largest quantity']);
for i=1:11
    y=y+clothes(i).quantity*(2016-clothes(i).bought(1)+(10-clothes(i).bought(2))/12);
    k=k+clothes(i).quantity;
end
disp(['The items is ',num2str(fix(y/k)),' years old in average']);

