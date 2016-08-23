program noi_2729;
const
  maxn=1000000;
var
  a:array[1..maxn] of longint;
  n,l1,l2,r,x,y:longint;
begin
  while not eoln do
  begin
    readln(a[1], n);
    l1:=1; l2:=1; r:=1;
    while r<>n do
    begin
      x:=2*a[l1]+1;
      y:=3*a[l2]+1;
      if x>y then
      begin
        inc(r);
        a[r]:=y;
        inc(l2);
      end
      else if x<y then
      begin
        inc(r);
        a[r]:=x;
        inc(l1);
      end
      else
      begin
        inc(r);
        a[r]:=x;
        inc(l1);
        inc(l2);
      end;
    end;
    writeln(a[n]);
  end;
end.