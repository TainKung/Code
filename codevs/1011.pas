program p1011;
var
  a:array[1..1000] of longint;
	n,i,j:longint;
begin
  readln(n);
	for i:=1 to n do a[i]:=1;
	for i:=2 to n do
		for j:=1 to i div 2 do
			a[i]:=a[i]+a[j];
	writeln(a[n]);
end.
