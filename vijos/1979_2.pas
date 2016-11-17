program p1979;
const
  maxn=200000;
var
  aim, visit, sign:array[1..maxn] of longint;
  n, ans, k, i:longint;

procedure dfs(u:longint);
  var
    v, m:longint;
  begin
    v:=u;
    m:=1;
    inc(k);
    while visit[v]=0 do
    begin
      visit[v]:=m;
      sign[v]:=k;
      v:=aim[v];
      inc(m);
    end;
    if (visit[v]<>0) and (sign[v]=sign[u]) then
      if ans > m-visit[v] then
        ans:=m-visit[v];
  end;

begin
  readln(n);
  for i:=1 to n do read(aim[i]);
  ans:=maxlongint; k:=0;
  fillchar(visit, sizeof(visit), 0);
  fillchar(sign, sizeof(sign), 0);
  for i:=1 to n do 
    if visit[i]=0 then
      dfs(i);
  writeln(ans);
end.
