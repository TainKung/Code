program p1098;
var
  a:array[1..100] of longint;
	n,sum,i:longint;
begin
	sum:=0;
  readln(n);
	for i:=1 to n do
		begin
		  read(a[i]);
			inc(sum,a[i]);
		end;
	sum:=sum div n;
	for i:=1 to n do a[i]:=a[i]-sum;
	sum:=0;
	for i:=1 to n do
		if a[i]<>0 then
			begin
			  inc(a[i+1],a[i]);
				inc(sum);
			end;
	writeln(sum);
end.
