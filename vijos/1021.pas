program p1021;
var
  n,k,sum,t,ans,i:longint;
begin
  ans:=0;
  readln(n,k);
  for i:=1 to n do
  begin
    sum:=0;
    repeat read(t);inc(sum); until t=0;
    if sum-1>=k then inc(ans);
  end;
  writeln(ans);
end.