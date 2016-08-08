program TogetherPhoto;
const maxn=40;
var
  n,nman,nwom:longint;
	male,female:array[1..maxn] of real;

procedure get;
  var
	  i,p:longint;
		t:string;
	begin
	  readln(n);
		nman:=0;nwom:=0;
		for i:=1 to n do
			begin
			  readln(t);
				p:=pos(' ',t);
				if t[1]='m' then
					begin
					  inc(nman);
						val(copy(t,p+1,length(t)-p),male[nman]);
					end
				else
					begin
					  inc(nwom);
						val(copy(t,p+1,length(t)-p),female[nwom]);
					end;
			end;
	end;

procedure Male_Qsort(l,r:longint);
  var
	  i,j:longint;
		p,t:real;
	begin
	  i:=l; j:=r;
		p:=male[(l+r)div 2];
		repeat
		  while male[i]<p do inc(i);
			while male[j]>p do dec(j);
			if i<=j then
				begin
				  t:=male[i];
					male[i]:=male[j];
					male[j]:=t;
					inc(i); dec(j);
				end;
		until i>j;
		if l<j then Male_Qsort(l,j);
		if i<r then Male_Qsort(i,r);
	end;

procedure Female_Qsort(l,r:longint);
  var
	  i,j:longint;
		p,t:real;
	begin
	  i:=l; j:=r;
		p:=female[(l+r)div 2];
		repeat
		  while female[i]>p do inc(i);
			while female[j]<p do dec(j);
			if i<=j then
				begin
				  t:=female[i];
					female[i]:=female[j];
					female[j]:=t;
					inc(i); dec(j);
				end;
		until i>j;
		if l<j then Female_Qsort(l,j);
		if i<r then Female_Qsort(i,r);
	end;

procedure put;
  var i:longint;
	begin
	  for i:=1 to nman do write(male[i]:0:2,' ');
		for i:=1 to nwom do write(female[i]:0:2,' ');
	end;

begin
  get;
	Male_Qsort(1,nman);
	Female_Qsort(1,nwom);
	put;
end.
