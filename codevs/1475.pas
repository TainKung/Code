program p1475;
const
  s='0123456789ABCDEF';
var
  m,n,i:longint;
	x:string;

function sint(a:char):longint;
  var
	  i:longint;
	begin
	  for i:=1 to 16 do
			if s[i]=a then exit(i-1);
	end;

begin
	readln(x);
  n:=pos(' ',x);
	val(copy(x,n+1,length(x)-n),m);
	x:=copy(x,1,n-1);
	n:=0;
  for i:=1 to length(x) do
		n:=n*m+sint(x[i]);
	writeln(n);
end.
