program p1097;
const maxn=10000;
var
	n,ans,p,i,t:longint;
	a:array[1..maxn] of longint;

procedure swap(var a,b:longint);
	var t:longint;
	begin
		t:=a;a:=b;b:=t;
	end;

procedure push(x:longint);
	var i:longint;
	begin
		inc(p); i:=p;
		a[p]:=x;
		while (i>1)and(a[i shr 1]>a[i]) do
		begin
			swap(a[i shr 1],a[i]);
			i:=i shr 1;
		end;
	end;

function pop:longint;
	var i:longint;
	begin
		pop:=a[1];
		a[1]:=a[p];
		a[p]:=maxlongint;
		dec(p); i:=2;
		while (i<=p)and((a[i shr 1]>a[i])or(a[i shr 1]>a[i+1])) do
			if a[i]<a[i+1] then
			begin
				swap(a[i],a[i shr 1]);
				i:=i shl 1;
			end
			else
			begin
				swap(a[i+1],a[i shr 1]);
				i:=(i+1) shl 1;
			end;
	end;

begin
	readln(n);
	for i:=1 to n do
	begin
		read(t);
		push(t);
	end;
	ans:=0;
	while p>1 do
	begin
		t:=pop+pop;
		push(t);
		inc(ans,t);
	end;
	writeln(ans);
end.
