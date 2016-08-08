program p1212;
var
  a,b,i,min,ans:longint;

begin
  readln(a,b);
	ans:=1;
	if a>b then min:=b else min:=a;
	for i:=min downto 1 do
		if (a mod i=0)and(b mod i=0) then
			begin
			  a:=a div i;
				b:=b div i;
				ans:=ans*i;
			end;
	writeln(ans);
end.
