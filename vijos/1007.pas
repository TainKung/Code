program p1007;
type
  point=record
          x,y:real;
        end;
var
  n,i:longint;
  r,ans:real;
  a:array[0..99] of point;

function dis(a,b:point):real;
  begin
    exit(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
  end;

begin
  readln(n,r);
  ans:=0;
  for i:=0 to n-1 do
    with a[i] do
      readln(x,y);
  for i:=0 to n-1 do
    ans:=ans+dis(a[i],a[(i+1) mod n]);
  writeln(ans+pi*r*2:0:2);
end.