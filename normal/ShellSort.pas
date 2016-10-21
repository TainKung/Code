program ShellSort;
const
  maxn=1000000;
var
  a:array[1..maxn] of longint;
  n,i:longint;

function check(n:longint):boolean;
  var i:longint;
  begin
    for i:=2 to n do
      if a[i] < a[i-1] then
        exit(false);
    check:=true;
  end;

procedure shellSort(l, r:longint);
  var
    d, t, i, p:longint;
  begin
    d:=(r-l) div 3;
    while d >= 1 do
    begin
      for i:=l to r do
      begin
        p:=i-d;
        t:=a[i];
        while (p>=l) and (a[p] >= t) do
        begin
          a[p+d] := a[p];
          dec(p, d);
        end;
        inc(p, d);
        a[p]:=t;
      end;
      d := d shr 1;
    end;
  end;

begin
  randomize;
  while true do
  begin
    n:=random(maxn);
    writeln('n=', n);
    for i:=1 to n do a[i]:=random(100);
    shellSort(1,n);
    writeln(check(n));
    if not check(n) then
    begin
      for i:=1 to n do write(a[i],' ');
      writeln;
    end;
    writeln;
  end;
end.