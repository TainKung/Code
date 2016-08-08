program stone;
const maxn=50000;
var
  l,m,n:longint;
  a:array[0..maxn] of longint;
  f:array[1..maxn] of longint;

procedure get;
  var i:longint;
  begin
    readln(l,n,m);
    for i:=1 to n do readln(a[i]);
    a[0]:=0; a[i+1]:=l;
  end;

function work(min:longint):boolean;
  var i,pre,ans:longint;
  begin
    i:=1; pre:=0;
    ans:=0;
    repeat
      while (i<=l)and(a[i]-a[pre]<min) do
        if i=l then
          begin
            f[pre]:=false;
            while not f[pre] and (pre<l) do
              begin inc(pre);inc(ans) end;
            if pre=l then exit(ans>m);
          end
        else
          begin
            f[i]:=false;
            inc(i); inc(ans);
          end;
