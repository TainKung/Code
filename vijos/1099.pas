program p1099;
type
  tfree=array['A'..'Z'] of boolean;
  tuse=array[0..25] of boolean;
var
  num:array['A'..'Z'] of -1..25;
	free:tfree;
	use:tuse;
	a,b,c:string;
	n:longint;
	i:char;

function work(k,p:longint;use:tuse):boolean;
  var
	  i,j,t:longint;
		c1,c2,c3:char;
		f1,f2:boolean;
  
	procedure give(p:char;x:longint);
	  begin
		  num[p]:=x;
			use[x]:=false;
			writeln('give:',p,',',x);
		end;

	procedure zero(p:char);
	  begin
			use[num[p]]:=true;
			writeln('zero:',p,',',num[p]);
			num[p]:=-1;
		end;

	procedure debug;
	  var 
		  i:longint;
		  j:char;
		begin
		  for i:=0 to n-1 do write(use[i],',');
			writeln;
			writeln(c1,c2,c3);
			writeln(f1,f2);
			writeln(t);
			for j:='A' to 'Z' do write(num[j],',');
			writeln;
			for j:='A' to 'Z' do write(free[j],',');
			writeln(k);
			writeln(work);
			writeln;
		end;

  begin
	  if k=0 then if p=0 then exit(true) else exit(false);
	  c1:=a[k];c2:=b[k];c3:=c[k];
		f1:=num[c1]<0; f2:=num[c2]<0;
		work:=false;
	  for i:=0 to n-1 do
			begin
  			if (num[c1]>=0) and(i=1) then break;
				if (c2=c3)and((i<>0)and(i<>n-1)) then continue;
				if num[c1]<0 then if use[i] then give(c1,i)
					                   else continue;
				for j:=0 to n-1 do
					begin
				    if not (num[c2]>=0) and(j=1) then break;
						if (c1=c3)and((j<>0)and(j<>n-1)) then continue;
						if num[c2]<0 then if use[j] then give(c2,j)
							                   else continue;
						t:=num[c1]+num[c2]+p;
						debug;
						if num[c3]>=0 then
							begin
							if t mod n=num[c3] then
							  if work(k-1,t div n,use) then
									exit(true)
							end
						else
							if use[t mod n] then
								begin
								  give(c3,t mod n);
									if work(k-1,t div n,use) then exit(true);
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
	fillchar(use,sizeof(use),true);
	for i:='A' to 'Z' do num[i]:=-1;
	if work(n,0,use) then
		for i:='A' to chr(64+n) do
			write(num[i],' ');
end.
