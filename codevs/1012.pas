program p1012;
var
  x,y,i,j,ans:longint;

function mintime(a,b:longint):longint;
  var
	  i,min:longint;
	begin
	  mintime:=1;
	  if a>b then min:=b else min:=a;
		for i:=min downto 2 do
			if (a mod i=0)and(b mod i=0) then
				begin
				  a:=a mod i;
					b:=b mod i;
					mintime:=mintime*i;
				end;
		mintime:=mintime*a*b;
	end;

begin
	ans:=0;
  readln(x,y);
	if y mod x=0 then
		begin
    	y:=y div x;
    	for i:=1 to y do
    		for j:=1 to y do
    			if mintime(i,j)=y then inc(ans);
	  end;
	writeln(ans);
end.
