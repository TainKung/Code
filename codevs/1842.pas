program p1842;
var
  x:longint;

function f(x:longint):longint;
  begin
	  if x>=0 then f:=5
		else f:=f(x+1)+f(x+2)+1;
	end;

begin
  readln(x);
	writeln(f(x));
end.
