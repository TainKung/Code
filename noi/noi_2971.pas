program noi_2971;
const
  maxn=100000;
var
  a,list:array[0..maxn] of longint;
  n,k,l,r:longint;

procedure push(x:longint);
  begin
    list[r]:=x;
    inc(r);
  end;

function pop():longint;
  begin
    pop:=list[l];
    inc(l);
  end;

function bfs(s,t:longint):longint;
  var p:longint;
  begin
    l:=0; r:=0;
    fillchar(a, sizeof(a), -1);
    push(s); a[s]:=0;
    while l<>r do
    begin
      p:=pop;
      if (p-1>=0) and (p-1<=maxn) and (a[p-1]=-1) then
      begin
        push(p-1); a[p-1]:=a[p]+1;
      end;
      if (p+1>=0) and (p+1<=maxn) and (a[p+1]=-1) then
      begin
        push(p+1); a[p+1]:=a[p]+1;
      end;
      if (p shl 1>=0) and (p shl 1<=maxn) and (a[p shl 1]=-1) then
      begin
        push(p shl 1); a[p shl 1]:=a[p]+1;
      end;
    end;
    bfs:=a[t];
  end;

begin
  readln(n,k);
  writeln(bfs(n,k));
end.