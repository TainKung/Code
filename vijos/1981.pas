program p1981;
const maxn=50000;
var
	a:array[0..maxn+1] of longint;
	l,m,n,i,j,p:longint;

function check(len:longint):boolean;
	var i,j,ans:longint;
	begin
		if len=l then exit(n<=m);
		i:=0;j:=1;
		ans:=0;
		while j<=n do 
			if a[j]-a[i]>=len then
			begin
				i:=j; inc(j);
			end
			else
			begin
				inc(j);inc(ans);
			end;
		while a[j]-a[i]<len do
		begin
			dec(i);inc(ans);
		end;
		check:=ans<=m;
	end;

begin
	readln(l,n,m);
	for i:=1 to n do readln(a[i]);
	a[0]:=0;a[n+1]:=l;
	i:=1;j:=l;
	while i<>j do
	begin
		p:=(i+j) shr 1+1;
		if check(p) then i:=p
		else j:=p-1;
	end;
	writeln(i);
end.
