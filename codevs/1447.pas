program p1447;
var
  l,n,k,i,s:longint;
begin
  readln(n,k);
	l:=trunc(ln(n)/ln(10))+1;
	if abs(k)>l then writeln('Error')
	else if k=0 then writeln(n)
	else if k>0 then
		begin
		  s:=1;
			for i:=1 to l-k do s:=s*10;
			writeln(n div s);
		end
	else
		begin
		  s:=1;
			for i:=1 to -k do s:=s*10;
			writeln(n mod s);
		end;
end.
