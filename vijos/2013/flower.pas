program flower;
var
	h:array[1..100000] of longint;
  n,m:longint;

procedure get;
  var i:longint;
	begin
	  readln(n);
		for i:=1 to n do read(h[i]);
	end;

procedure work;
  var
	  i,max,min:longint;
    g:array[1..100000] of longint;
	begin
		fillchar(g,sizeof(g),0);
	  max:=1; min:=1;
		g[1]:=1;
		for i:=2 to n do
			if (h[i]<h[max])and(h[i]>h[min]) then
				if g[max]>g[min] then
					begin
					  g[i]:=g[max]+1;
						min:=i;
					end
				else
					begin
					  g[i]:=g[min]+1;
						max:=i;
					end
			else if h[i]>=h[max] then
				begin
				  g[i]:=g[min]+1;
					max:=i;
				end
			else if h[i]<=h[min] then
				begin
				  g[i]:=g[max]+1;
					min:=i;
				end;
		if g[max]>g[min] then m:=g[max]
			               else m:=g[min];
  end;

begin
  get;
	work;
	writeln(m);
end.
