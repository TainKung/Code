uses math;
const
  k=100;
	maxn=300;
	zero=ord('0');
var
  a:array[1..maxn] of longint;
	p,t,ia,b,i,j,l,la:longint;
	ans:string;
	found:boolean;

function c2i(x:char):longint;
  begin
	  exit(ord(x)-zero);
	end;

function i2c(x:longint):char;
  begin
	  exit(chr(x+zero));
	end;

function len(x:longint):longint;
  begin
	  if x=0 then exit(1)
		else exit(trunc(log10(x)+1));
	end;

begin
  fillchar(a,sizeof(a),0);
  ans:=''; readln(ia,b);
	if ia=0 then begin writeln(0); exit end;
	if b=1 then begin writeln(ia); exit end;
	l:=len(ia div b);
	la:=len(ia);
	for i:=la downto 1 do
		begin
		  a[i]:=ia mod 10;
			ia:=ia div 10;
		end;
	p:=0;
	for i:=1 to la+200 do
		begin
		  inc(a[i],p*10);
			p:=a[i] mod b;
			a[i]:=a[i] div b;
		  if (i>=la) and (p=0) then break;
		end;
	j:=la-l+1;
	if p=0 then
		begin
			la:=i;
			for i:=j to la do
				ans:=ans+i2c(a[i]);
			if l<la-j+1 then insert('.',ans,l+1);
		end
	else
		begin
		  while j<=la do begin ans:=ans+i2c(a[j]);inc(j) end;
			ans:=ans+'.';
		  for p:=1 to 100 do
		    begin
			    for i:=la+1 to la+5 do
						begin
						  found:=true;
						  for j:=1 to min(6,200 div p-1) do
								if found then
							    for t:=i+(j-1)*p to i+p*j-1 do
									  if a[t]<>a[t+p] then
											begin found:=false;break end;
							if found then break;
						end;
					if found then break;
				end;
			if found then
				begin
				  for j:=la+1 to i-1 do ans:=ans+i2c(a[j]);
					ans:=ans+'(';
					for j:=i to i+p-1 do ans:=ans+i2c(a[j]);
					ans:=ans+')';
					inc(j);
				end
			else
				begin
				  for j:=la+1 to la+100 do ans:=ans+i2c(a[j]);
					if a[j+1]>=5 then inc(a[j]);
					if a[j]>=0 then inc(a[j-1]);dec(a[j],10);
				end;
		end;
	writeln(ans);
end.
