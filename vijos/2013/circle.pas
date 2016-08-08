program circle;
var
  n,m,k,x:longint;

function work:longint;
  var
	  i:longint;
	begin
	  work:=m;
	  for i:=1 to k div 5 do
			work:=work*100000 mod n;
		for i:=1 to k mod 5 do
			work:=work*10 mod n;
	end;

begin
  readln(n,m,k,x);
	writeln((x+work)mod n);
end.
