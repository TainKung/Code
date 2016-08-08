program p1844;
const maxn=100000;
var
	i,ans,n:longint;
	a:array[0..maxn] of longint;
begin
  readln(n);
	for i:=1 to n do read(a[i]);
	a[0]:=0; ans:=0;
	for i:=1 to n do
		if a[i]>a[i-1] then
			inc(ans,a[i]-a[i-1]);
	writeln(ans);
end.
