program graphlst;
const
  maxn=1000;
  ipath='graphlst.in';
  opath='graphlst.out';
var
  map:array[1..maxn,1..maxn] of boolean;
  exist:array[1..maxn] of boolean;
  list:array[1..maxn] of longint;
  n,m,i,lh,lr,a,b:longint;

procedure listPush(x:longint);
  begin
    list[lr]:=x;
    inc(lr);
    exist[x]:=true;
  end;

function listPop:longint;
  begin
    listPop:=list[lh];
    inc(lh);
  end;

procedure dfs(p:longint);
  var i:longint;
  begin
    write(p,' ');exist[p]:=true;
    for i:=1 to n do
      if map[p,i] and not exist[i] then
        dfs(i);
  end;

procedure bfs;
  var i,p:longint;
  begin
    while lh<>lr do
    begin
      p:=listPop;
      write(p,' ');
      for i:=1 to n do
        if map[p,i] and not exist[i] then
          listPush(i);
    end;
  end;

begin
  assign(input,ipath); reset(input);
  readln(n,m);
  lh:=1;lr:=1;
  fillchar(map,sizeof(map),false);
  for i:=1 to m do
  begin
    readln(a,b);
    map[a,b]:=true;
    map[b,a]:=true;
  end;
  close(input);
  assign(output,opath); rewrite(output);
  fillchar(exist,sizeof(exist),false);
  dfs(1); writeln;
  fillchar(exist,sizeof(exist),false);
  listPush(1); bfs; writeln;
  close(output);
end.