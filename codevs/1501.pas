program p1501;
var
  node:array[1..16] of record lch,rch:longint end;
	list:array[1..1000] of longint;
	n,w,h,l,r:longint;

procedure get;
  var i:longint;
  begin
	  readln(n);
		for i:=1 to n do
			readln(node[i].lch,node[i].rch);
	end;

procedure push(x:longint);
  begin
	  list[r]:=x;
		inc(r);
	end;

function pop:longint;
  begin
	  pop:=list[l];
		inc(l);
	end;

procedure search;
  var i:longint;
	begin
	  if l=r then exit;
		inc(h);
		if r-l>w then w:=r-l;
	  for i:=l to r-1 do
			with node[pop] do
			  begin
				  if lch>0 then push(lch);
					if rch>0 then push(rch);
				end;
		search;
	end;

begin
  get;
	l:=1; r:=1;
	push(1);
	w:=0; h:=0;
	search;
	writeln(w,' ',h);
end.
