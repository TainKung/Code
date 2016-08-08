program p1078;
const max=39;
var
  a:array[0..max+1,0..max+1] of longint;
	n:longint;

procedure work(n:longint);
  var x,y,i:longint;
	begin
	  x:=1; y:=n div 2+1;
		a[x,y]:=1;
	  for i:=2 to n*n do
			begin
			  if (x=1)and(y<>n) then
					begin x:=n;inc(y) end
				else if (y=n)and(x<>1) then
					begin y:=1;dec(x) end
				else if (x=1)and(y=n) then
					inc(x)
				else if a[x-1,y+1]=0 then
					begin dec(x);inc(y) end
				else
					inc(x);
				a[x,y]:=i;
			end;
	end;

procedure put;
  var i,j:longint;
	begin
	  for i:=1 to n do
			begin
			  for j:=1 to n do
					write(a[i,j],' ');
				writeln;
			end;
	end;

begin
  readln(n);
	fillchar(a,sizeof(a),0);
	work(n);
	put;
end.
