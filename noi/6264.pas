program p6264;
const
  maxn=100;
var
  a:array[0..maxn+1, 0..maxn+1] of boolean;
  n,m,i,j:longint;
  sx,sy,tx,ty:longint;
  c:char;

function min(a,b:longint):longint;
  begin
    if a<b then exit(a)
    else exit(b);
  end;

function dfs(x,y:longint):longint;
  const
    dx:array[1..4] of longint=( 0, 0, 1,-1);
    dy:array[1..4] of longint=( 1,-1, 0, 0);
  var
    i,nx,ny:longint;
  begin
    if (x=tx) and (y=ty) then exit(0);
    dfs:=maxint;
    a[x,y]:=false;
    for i:=1 to 4 do
    begin
      nx:=x+dx[i];
      ny:=y+dy[i];
      if a[nx, ny] then
        dfs:=min(dfs, dfs(nx, ny));
    end;
    inc(dfs);
    a[x,y]:=true;
  end;

begin
  readln(n,m);
  fillchar(a, sizeof(a), false);
  for i:=1 to n do
  begin
    for j:=1 to m do
    begin
      read(c);
      case c of
        '.':a[i,j]:=true;
        'S':begin
              sx:=i;
              sy:=j;
              a[i,j]:=true;
            end;
        'T':begin
              tx:=i;
              ty:=j;
              a[i,j]:=true;
            end;
      end;
    end;
    readln;
  end;
  writeln(dfs(sx, sy));
end.
