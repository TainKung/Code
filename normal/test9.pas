program test9;
var
  a:array[1..100] of longint;
  i:longint;
begin
  fillchar(a, sizeof(a), $ff);
  for i:=1 to 5 do writeln(a[1]);
end.