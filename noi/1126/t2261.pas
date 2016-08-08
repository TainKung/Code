program t2261;
const maxn=255;
var
  a:array[1..maxint,0..maxn] of longint;
	n,i,p,s:longint;
begin
  readln(n);
	while n<>0 do
		begin
		  fillchar(a,sizeof(a),0);
		  for i:=1 to n do
				begin
				  read(s);inc(a[s,0]);
					a[s,a[s,0]]:=i;
				end;
			readln(p);
			i:=1;
			for s:=maxint downto 1 do
			  if a[s,0]>0 then
					begin
				    if i>=p then break;
					  inc(i,a[s,0]);
					end;
			if i<>p then
				begin writeln(0);readln(n);continue end;
			for i:=1 to a[s,0] do
				write(a[s,i],' ');
			writeln;
			readln(n);
		end;
end.
