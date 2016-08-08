program p1099;
type
  tfree=array['A'..'Z'] of boolean;
  tuse=array[0..25] of boolean;
var
  num:array['A'..'Z'] of 0..25;
	free:tfree;
	use:tuse;
	a,b,c:string;
	n:longint;
	i:char;

function work(k,p:longint;free:tfree;use:tuse):boolean;
  var
	  i,j,t:longint;
		c1,c2,c3:char;
		f1,f2,f3:boolean;
  
	procedure give(p:char;x:longint);
	  begin
		  num[p]:=x;
			free[p]:=false;
			use[x]:=false;
		end;

	procedure zero(p:char);
	  begin
		  free[p]:=true;
			use[num[p]]:=true;
		end;

  begin
	  if k=0 then if p=0 then exit(true) else exit(false);
	  c1:=a[k];c2:=b[k];c3:=c[k];
		f1:=free[c1];f2:=free[c2];f3:=free[c3];
		work:=false;
	  for i:=0 to n-1 do
			begin
  			if not free[c1] and(i=1) then break;
				if (c2=c3)and((i<>0)and(i<>n-1)) then continue;
				if free[c1] then if use[i] then give(c1,i)
					                   else continue;
				for j:=0 to n-1 do
					begin
				    if not free[c2] and(j=1) then break;
						if (c1=c3)and((j<>0)and(j<>n-1)) then continue;
						if free[c2] then if use[j] then give(c2,j)
							                   else continue;
						t:=num[c1]+num[c2]+p;
						if not free[c3] then
							begin
							if t mod n=num[c3] then
							  if work(k-1,t div n,free,use) then exit(true);
							end
						else
							if use[t mod n] then
								begin
								  give(c3,t mod n);
									if work(k-1,t div n,free,use) then exit(true);
									zero(c3);
								end;
						if f2 then zero(c2);
					end;
				if f1 then zero(c1);
			end;
  end;

begin
  readln(n);
	readln(a);
	readln(b);
	readln(c);
	fillchar(num,sizeof(num),0);
	fillchar(use,sizeof(use),true);
	fillchar(free,sizeof(free),true);
	if work(n,0,free,use) then
		for i:='A' to chr(64+n) do
			write(num[i],' ');
end.
