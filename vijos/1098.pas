program p1098;
const maxn=100;
var
  h,a,b:array[0..maxn+1] of longint;
  n,i,j,max:longint;
begin
  readln(n);
  for i:=1 to n do read(h[i]);
  a[1]:=1;b[n]:=1;
  a[0]:=0;b[n+1]:=0;
  for i:=2 to n do
  begin
    j:=i-1;
    while (j>0)and(h[j]>=h[i]) do dec(j);
    a[i]:=a[j]+1;
  end;
  for i:=n-1 downto 1 do
  begin
    j:=i+1;
    while (j<n+1)and(h[j]>=h[i]) do inc(j);
    b[i]:=b[j]+1;
  end;
  max:=0;
  for i:=1 to n do
    if a[i]+b[i]>max then
      max:=a[i]+b[i];
  writeln(n-max+1);
end.