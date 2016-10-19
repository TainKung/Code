program ArrayCopy;
const maxn=1000;
var
  a, b:array[1..maxn] of longint;
  n, i:longint;
begin
  // readln(n);
  a[1]:=10;
  a[10]:=1;
  a[5]:=9999;
  b:=a;
  writeln(b[1], b[5], b[10]);
  a[5]:=0;
  writeln(b[5]);
end.