program p666;
const maxn=10;
var
  t,m,n,i:longint;
  a:array[1..maxn,1..maxn,0..maxn] of longint;

procedure work(m,n:longint);
  var i,j,k,p:longint;
  begin
    fillchar(a,sizeof(a),0);
    for i:=1 to m do a[i,1,i]:=1;
    a[1,1,1]:=1;
    for i:=2 to n do a[1,i,0]:=1;
    for i:=2 to m do
      for j:=2 to n do
        for k:=0 to i div j do
          for p:=k to (i-k)div(j-1) do
            inc(a[i,j,k],a[i-k,j-1,p]);
  end;

function sum(m,n:longint):longint;
  var i:longint;
  begin
    sum:=0;
    for i:=0 to m div n do
      inc(sum,a[m,n,i]);
  end;

begin
	readln(t);
	work(maxn,maxn);
	for i:=1 to t do
	  begin
      readln(m,n);
	    writeln(sum(m,n));
	  end;
end.
