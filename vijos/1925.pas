program p1925;
var
  a:array[1..100001] of longint;
	i,t,n:longint;
begin
  readln(n);
	for i:=1 to n do read(a[i]);
	inc(n); a[n]:=a[1];
	t:=-1;
	for i:=n-1 downto 1 do
	  if a[i+1]<a[i] then
			if t=-1 then t:=n-1-i
			else
				begin
				  t:=-1;
					break;
				end;
  writeln(t);
end.
