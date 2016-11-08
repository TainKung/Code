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
  map, visit:array[1..maxn, 1..maxn] of boolean;
  energy:array[1..maxn, 1..maxn] of longint;
  s, t:coordinate;
  list:array[0..1000000] of element;
  head, tail:longint;
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
    fillchar(map, sizeof(map), true);
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

procedure bfs(source:coordinate);
  const
    dx:array[1..4] of longint=( 0, 0, 1,-1);
    dy:array[1..4] of longint=( 1,-1, 0, 0);
  begin
    list_init;
    list_push(source, 0, k);
    while not list_empty do
    begin
      u:=list_pop;
      for i:=1 to 4 do
      begin
        nx:=u.x+dx[i];
        ny:=u.y+dy[i];
        if map[nx, ny] and (energy[x, y] < energy[nx, ny]) then
          list_push(coor(nx, ny), u.time+1, energy[x, y]);
        else if not map[nx, ny] and (energy[x, y]+1 < energy[nx, ny]) then
          list_push(coor[nx, ny], u.time+1, energy[x, y]+1)
