program p1083;
var
  x,i,m,n:longint;
  dir:boolean;
const
  RIGHT=true;
  LEFT=false;
begin
  readln(x);
	m:=1; n:=1;
	dir:=RIGHT;
  for i:=2 to x do
    if dir=RIGHT then
      if m=1 then
        begin
          inc(n);
          dir:=LEFT;
        end
      else
        begin
          dec(m);
          inc(n);
        end
    else
      if n=1 then
        begin
          inc(m);
          dir:=RIGHT;
        end
      else
        begin
          dec(n);
          inc(m);
        end;
  writeln(m,'/',n);
end.
