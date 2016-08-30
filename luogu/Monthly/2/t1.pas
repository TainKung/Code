program t1;
const
  maxn=20;
var
  dis:array [0..maxn, 0..maxn] of double;
  count:array [0..maxn, 0..maxn] of longint;
  x1, x2, y1, y2:longint;
  sum, num:double;

procedure makeData();
  const rp=2333333;
  var
    n, i:longint;
    x, y, z:int64;
    a, b:double;
    sa, sb:array[1..3] of longint;
  begin
    readln(n);
    for i:=1 to 3 do read(sa[i], sb[i]);
    readln;
    x:=0; y:=0; z:=0;
    for i:=1 to n do
    begin
      x:=(y * sa[1] + sb[1]) mod rp;
      y:=(z * sa[2] + sb[2]) mod rp;
      z:=(x * sa[3] + sb[3]) mod rp;
      a:=x mod 20 + y mod 10 / 10 + z mod 10 / 100;

      x:=(y * sa[1] + sb[1]) mod rp;
      y:=(z * sa[2] + sb[2]) mod rp;
      z:=(x * sa[3] + sb[3]) mod rp;
      b:=x mod 20 + y mod 10 / 10 + z mod 10 / 100;

      dis[trunc(a), trunc(b)]:=dis[trunc(a), trunc(b)]+ a+b-trunc(a)-trunc(b);
      inc(count[trunc(a), trunc(b)]);
    end;
  end;

begin
  makeData;
  sum:=0.0; num:=0.0;
  for x1:=0 to maxn-2 do for y1:=0 to maxn-2 do
  for x2:=x1+1 to maxn-1 do for y2:=y1+1 to maxn-1 do
  begin
    num:=num+count[x1, y1]*count[x2, y2];
    sum:=sum + (x2+y2-x1-y1)*count[x1, y1]*count[x2, y2] - dis[x1, y1]*count[x2, y2] + dis[x2, y2]*count[x1, y1];
  end;
  if num=0 then writeln(0.0:0:5)
  else writeln(sum/num:0:5);
end.