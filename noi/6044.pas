program p6044;
type
  coordinate=record x,y:longint end;
const
  maxn=200;
var
  map, visit:[1..maxn, 1..maxn] of boolean;
  s, t:coordinate;
  list:array[1..1000] of coordinate;
  ans, m, n, k:longint;

function coor(x, y:longint):coordinate;
  begin
    coor.x:=x;
    coor.y:=y;
  end;

procedure init;
  begin
    fillchar(map, sizeof(map), true);
    fillchar(visit, sizeof(visit), false);
    ans:=maxlongint;
  end;

procedure readin;
  var
    i, j:longint;
    c:char;
  begin
    readln(m, n, k);
    for i:=1 to m do
    begin
      for j:=1 to n do
      begin
        read(c);
        case c of:
          '#':map[i, j]:=false;
          '@':s:=coor(i, j);
          '+':t:=coor(i, j);
        end;
      end;
      readln;
    end;
  end;
