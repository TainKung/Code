program p1842;
const maxn=100000;
var
  a,b,t:array[1..maxn] of longint;
  pa,pb:array[1..maxn] of ^longint;
  n,ans,i:longint;

procedure qsorta(l,r:longint);
	var
	  i,j,p:longint;
	  t:^longint;
	begin
	  i:=l; j:=r;
	  p:=pa[(l+r)div 2]^;
	  repeat
	    while pa[i]^<p do inc(i);
	    while pa[j]^>p do dec(j);
	    if i<=j then
	      begin
	        t:=pa[i];pa[i]:=pa[j];pa[j]:=t;
	        inc(i); dec(j);
	      end;
	  until i>j;
	  if l<j then qsorta(l,j);
	  if i<r then qsorta(i,r);
	end;

procedure qsortb(l,r:longint);
	var
	  i,j,p:longint;
	  t:^longint;
	begin
	  i:=l; j:=r;
	  p:=pb[(l+r)div 2]^;
	  repeat
	    while pb[i]^<p do inc(i);
	    while pb[j]^>p do dec(j);
	    if i<=j then
	      begin
	        t:=pb[i];pb[i]:=pb[j];pb[j]:=t;
	        inc(i); dec(j);
	      end;
	  until i>j;
	  if l<j then qsortb(l,j);
	  if i<r then qsortb(i,r);
	end;

procedure deal;
	var i:longint;
	begin
	  for i:=1 to n do
	    begin a[i]:=i;pb[i]^:=i end;
	  for i:=1 to n do b[i]:=pa[b[i]]^;
	end;

procedure count(l,r:longint);
	var i,j,m,p:longint;
	begin
	  if l=r then exit;
	  m:=(l+r) div 2;
	  count(l,m);count(m+1,r);
	  i:=l;j:=m+1;p:=l;
	  while (i<=m)and(j<=r) do
	    if b[i]<=b[j] then
	      begin t[p]:=b[i];inc(p);inc(i) end
	    else
	      begin t[p]:=b[j];inc(p);inc(j);inc(ans,m-i+1) end;
	  while i<=m do begin t[p]:=b[i];inc(p);inc(i) end;
	  while j<=r do begin t[p]:=b[j];inc(p);inc(j) end;
	  for i:=l to r do b[i]:=t[i];
	  ans:=ans mod 99999997;
	end;

begin
	ans:=0;
	readln(n);
	for i:=1 to n do read(a[i]);
	for i:=1 to n do read(b[i]);
	for i:=1 to n do begin pa[i]:=@a[i];pb[i]:=@b[i] end;
	qsorta(1,n);qsortb(1,n);
	deal;
	count(1,n);
	writeln(ans);
end.
