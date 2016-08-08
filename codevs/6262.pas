program p6262;
const
  maxn=100;
var
  a:array[0..maxn+1,1..maxn+1] of longint;
  n,m,ans:longint;

procedure get;
	var
	  i,j:longint;
	  t:char;
	begin
	  readln(n);
	  fillchar(a,sizeof(a),0);
	  for i:=1 to n do
	    begin
	      for j:=1 to n do
	        begin
	          read(t);
	          case t of
	            '.':a[i,j]:=0;
	            '#':a[i,j]:=-1;
	            '@':begin a[i,j]:=1;inc(ans) end;
	          end;
	        end;
	      readln;
	    end;
	  readln(m);
	end;

procedure work;
	var i,j,k:longint;
	begin
	  for k:=2 to m do
	    for i:=1 to n do
	      for j:=1 to n do
	        if (a[i,j]=0) and(
	           (a[i-1,j]=k-1) or
	           (a[i+1,j]=k-1) or
	           (a[i,j-1]=k-1) or
	           (a[i,j+1]=k-1))
	        then begin
	          inc(ans);
	          a[i,j]:=k;
	        end;
	end;

begin
	get;
	work;
	writeln(ans);
end.
