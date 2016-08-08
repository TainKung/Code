program p1068;
const maxn=350;
type tcard=array[1..4] of longint;
var
  n,m:longint;
  a:array[1..maxn] of longint;
  card:tcard;

procedure get;
	var i,t:longint;
	begin
	  readln(n,m);
	  for i:=1 to n do read(a[i]);
	  for i:=1 to m do
	    begin
	      read(t);
	      inc(card[t]);
	    end;
	end;
