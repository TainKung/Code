program p1474;
const
  s='0123456789ABCDEF';
var
  m,n:longint;
	ans:string;
begin
  readln(n,m);
  ans:='';
	repeat
	  ans:=s[n mod m+1]+ans;
		n:=n div m;
	until n=0;
	writeln(ans);
end.
