program p3038;
var
  a:array[1..100] of longint;
	n,i:longint;

function check(n,k:longint):longint;
	var t:longint;
  begin
		if k>100000 then exit(-1);
	  if n=1 then exit(0);
		if n mod 2=0 then 
			t:=check(n div 2,k+1)
		else
			t:=check(3*n+1,k+1);
		if t=-1 then exit(-1) else exit(t+1);
	end;

begin
  readln(n);
	for i:=1 to n do read(a[i]);
	for i:=1 to n do writeln(check(a[i],1));
end.
