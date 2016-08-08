program p1204;
var
  a,b:string;
  i:longint;
begin
  read(a);
  i:=pos(' ',a);
  while a[i]=' ' do inc(i);
  b:=copy(a,i,length(a)-i+1);
  writeln(pos(b,a));
end.
