program p1075;
var
  a:array[1..1000] of longint;
  i,n,t:longint;
begin
  readln(n);
	fillchar(a,sizeof(a),0);
  for i:=1 to n do
    begin
      read(t);
      inc(a[t]);
    end;
  n:=0;
  for i:=1 to 1000 do
    if a[i]>0 then inc(n);
  writeln(n);
  for i:=1 to 1000 do
    if a[i]>0 then write(i,' ');
end.
