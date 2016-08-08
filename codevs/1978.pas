program p1978;
var
  a:array[1..40] of longint;
	n,i:longint;

begin
  readln(n);
	fillchar(a,sizeof(a),0);
	a[1]:=1;
	a[2]:=1;
	for i:=3 to n do
		a[i]:=a[i-1]+a[i-2];
	writeln(a[n]);
end.
