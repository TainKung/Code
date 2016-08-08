program p1014;
const max=30;
var
	w:array[1..max] of longint;
	n,v:longint;

procedure get;
	var i:longint;
	begin
		readln(v,n);
		for i:=1 to n do read(w[i]);
	end;

procedure qsort(l,r:longint);
	var
		i,j,p,t:longint;
	begin
		i:=l; j:=r;
		p:=w[(l+r) div 2];
		repeat
			while w[i]<p do inc(i);
			while w[j]>p do dec(j);
			if i<=j then
				begin
					t:=w[i];
					w[i]:=w[j];
					w[j]:=t;
					inc(i); dec(j);
				end;
		until i>j;
		if l<j then qsort(l,j);
		if i<r then qsort(i,r);
	end;

function min(a,b:longint):longint;
	begin
		if a>b then exit(b) else exit(a);
	end;

function bag(v,k:longint):longint;
  begin
    if v<0 then exit(maxint);
    if (v<w[1])or(k=0) then exit(v);
    bag:=min(bag(v-w[k],k-1),bag(v,k-1));
  end;

begin
	get;
	qsort(1,n);
	writeln(bag(v,n));
end.
