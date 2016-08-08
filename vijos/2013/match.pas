program match;
var
  a,b,oa,ob:array[1..100000] of longint;
	n,sum:longint;

procedure get;
  var i:longint;
	begin
	  readln(n);
		for i:=1 to n do
			begin
			  read(a[i]);
				oa[i]:=i;
			end;
		readln;
		for i:=1 to n do
			begin
			  read(b[i]);
				ob[i]:=i;
			end;
	end;

procedure swap(var a,b:longint);
  var t:longint;
	begin
	  t:=a;
		a:=b;
		b:=t;
	end;

procedure sorta(l,r:longint);
  var
	  i,j,p:longint;
	begin
	  i:=l; j:=r;
		p:=a[(i+j)div 2];
		repeat
		  while a[i]<p do inc(i);
			while a[j]>p do dec(j);
			if i<=j then
				begin
				  swap(a[i],a[j]);
					swap(oa[i],oa[j]);
				  inc(i); dec(j);
				end;
		until i>j;
		if i<r then sorta(i,r);
		if l<j then sorta(l,j);
	end;

procedure sortb(l,r:longint);
  var
	  i,j,p:longint;
	begin
	  i:=l; j:=r;
		p:=b[(i+j)div 2];
		repeat
		  while b[i]<p do inc(i);
			while b[j]>p do dec(j);
			if i<=j then
				begin
				  swap(b[i],b[j]);
					swap(ob[i],ob[j]);
				  inc(i); dec(j);
				end;
		until i>j;
		if i<r then sortb(i,r);
		if l<j then sortb(l,j);
	end;

procedure count(l,r:longint);
  var
	  i,j,p,k:longint;
  begin
	  if l>=r then exit;
		p:=(l+r)div 2;
		count(l,p);
		count(p+1,r);
		i:=l; j:=p+1;
		k:=l;
		repeat
		  if a[i]>a[j] then
				begin
				  inc(sum,p-i+1);
					b[k]:=a[j];
					inc(j); inc(k);
				end
			else
				begin
					b[k]:=a[i];
				  inc(i); inc(k);
				end;
		until (i>p)or(j>r);
		while i<=p do
			begin b[k]:=a[i];inc(k);inc(i) end;
		while j<=r do
			begin b[k]:=a[j];inc(k);inc(j) end;
		for i:=l to r do a[i]:=b[i];
	  sum:=sum mod 99999997;
	end;

procedure work;
  var i:longint;
	begin
	  for i:=1 to n do b[ob[i]]:=i;
		for i:=1 to n do a[oa[b[i]]]:=i;
		sum:=0;
		count(1,n);
	end;

begin
  get;
	sorta(1,n);
	sortb(1,n);
	work;
	writeln(sum);
end.
