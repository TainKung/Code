program FindMid;
const
  maxn=1000;
var
  a:array[1..maxn] of longint;
  n, i, t:longint;
begin
  readln(n);
  fillchar(a, sizeof(a), 0);
  for i:=1 to n do
  begin
    read(t);
    inc(a[t]);
  end;
  t:=0;
  for i:=1 to maxn do
  begin
    inc(t, a[i]);
    if t>=n shr 1 then break;
  end;
  writeln(i);
end.