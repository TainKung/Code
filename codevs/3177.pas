program p3177;
const max=1000;
var
	a,b,n:ansistring;
	na,nb,nc:array[1..500] of longint;
	la,lb,lc,i,j:longint;

function int(x:char):longint;
	const
		zero=ord('0');
	begin
		int:=ord(x)-zero;
	end;

begin
	fillchar(nc,sizeof(nc),0);
	readln(n);
	i:=pos(' ',n);
	la:=i-1;
	lb:=length(n)-i;
	a:=copy(n,1,la);
	b:=copy(n,i+1,lb);
	for i:=1 to la do na[i]:=int(a[la-i+1]);
	for i:=1 to lb do nb[i]:=int(b[lb-i+1]);
	for i:=1 to la do
		for j:=1 to lb do
			inc(nc[i+j-1],na[i]*nb[j]);
	lc:=la+lb;
	for i:=1 to lc-1 do
		begin
			nc[i+1]:=nc[i+1]+nc[i] div 10;
			nc[i]:=nc[i] mod 10;
		end;
	i:=lc;
	while (nc[i]=0)and(i<>1) do dec(i);
	for j:=i downto 1 do write(nc[j]);
end.
