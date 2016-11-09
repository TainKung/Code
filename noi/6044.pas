program p6044;
type
  coordinate=record x,y:longint end;
  element=record
            point:coordinate;
            time, energy:longint;
          end;
const
  maxn=200;
var
  map:array[1..maxn, 1..maxn] of boolean;
  ene:array[1..maxn, 1..maxn] of longint;
  s, t:coordinate;
  list:array[0..1000000] of element;
  head, tail:longint;
  m, n, k:longint;

function coor(x, y:longint):coordinate;
  begin
    coor.x:=x;
    coor.y:=y;
  end;

procedure init;
  begin
    fillchar(map, sizeof(map), true);
    fillchar(ene, sizeof(ene), -1);
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
        case c of
          '#':map[i, j]:=false;
          '@':s:=coor(i, j);
          '+':t:=coor(i, j);
        end;
      end;
      readln;
    end;
  end;

procedure list_init;
  begin
    head:=0;
    tail:=0;
  end;

procedure list_push(point:coordinate; time, energy:longint);
  begin
    list[tail].point:=point;
    list[tail].time:=time;
    list[tail].energy:=energy;
    inc(tail);
  end; 

function list_pop:element;
  begin
    list_pop:=list[head];
    inc(head);
  end;

function list_empty:boolean;
  begin
    exit(head >= tail);
  end;

function bfs(source:coordinate):longint;
  const
    dx:array[1..4] of longint=( 0, 0, 1,-1);
    dy:array[1..4] of longint=( 1,-1, 0, 0);
  var
    u:element;
    i, nx, ny:longint;
  begin
    list_init;
    list_push(source, 0, k);
    while not list_empty do
    begin
      u:=list_pop;
      with u do
      begin
        if (point.x = t.x) and (point.y = t.y) then exit(time);
        with point do
          for i:=1 to 4 do
          begin
            nx:=x+dx[i];
            ny:=y+dy[i];
            if (nx < 1) or (nx > m) or (ny < 1) or (ny > n) then continue;
            if map[nx, ny] and (ene[x, y] > ene[nx, ny]) then
            begin
              list_push(coor(nx, ny), time+1, ene[x, y]);
              ene[nx, ny]:=ene[x, y];
            end
            else if not map[nx, ny] and (ene[x, y]-1 > ene[nx, ny]) then
            begin
              list_push(coor(nx, ny), time+1, ene[x, y]-1);
              ene[nx, ny]:=ene[x, y]-1;
            end;
          end;
      end;
    end;
  end;

begin
  init;
  readin;
  writeln(bfs(s));
end.
