program p2559;
var
  x,y:longint;
begin
	readln(x,y);
  if x/60*3+y>=8 then writeln('YES')
		             else writeln('NO');
end.
