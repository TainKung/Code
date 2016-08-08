program t806;
const maxn=1000;
var
  a,t:array[1..maxn] of longint;
	n,i,j,num:longint;

function msort(l,r:longint):longint;
  var i,j,p,pt:longint;
	begin
	  if l=r then exit(0);
	  p:=(l+r) div 2;
		msort:=msort(l,p)+msort(p+1,r);
		i:=l; j:=p+1;
		pt:=l-1;
		while(i<=p)and(j<=r) do
			begin
			  if a[i]<=a[j] then
					begin
					  inc(pt);
					  t[pt]:=a[i];
						inc(i);
					end
				else
					begin
					  inc(pt);
						t[pt]:=a[j];
						inc(msort,p-i+1);
					  inc(j);
					end;
			end;
		while (i<=p) do
			begin
			  inc(pt);
				t[pt]:=a[i];
				inc(i);
			end;
		while (j<=r) do
			begin
			  inc(pt);
				t[pt]:=a[j];
				inc(j);
			end;
		for i:=l to r do a[i]:=t[i];
	end;

function min(a,b:longint):longint;
  begin
	  if a<b then exit(a) else exit(b);
	end;

begin
  readln(n);
	for i:=1 to n do
		begin
		  read(num);
			for j:=1 to num do read(a[j]);
			readln;
			writeln('Scenario #',i,':');
			writeln(msort(1,num));
			writeln;
		end;
end.
