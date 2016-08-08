program sticks;
var
  n,k,sum,t,p,i:longint;
	count:array[1..100] of longint;
	ex:array[1..50] of longint;
	ans:array[1..10000] of longint;

function check(m,len,num:longint):boolean;
  var i:longint;
	begin
		if m=0 then
			begin
			  m:=len;
				dec(num);
			end;
	  if num=0 then exit(true);
		for i:=m downto 1 do
			if count[i]>0 then
				begin
					dec(count[i]);
					if check(m-i,len,num) then
						exit(true);
				  inc(count[i]);
				end;
		exit(false);
	end;

function work:longint;
  var i:longint;
	begin
	  for i:=ex[k] to sum div 2 do
			if (sum mod i=0)and check(i,i,sum div i) then
				exit(i);
		exit(sum);
	end;

procedure cou;
  var i:longint;
	begin
		k:=0;
	  for i:=1 to 50 do
			if count[i]>0 then
				begin
				  inc(k);
					ex[k]:=i;
				end;
	end;

begin
  readln(n);
	p:=0;
  fillchar(count,sizeof(count),0);
	ex[i]:=0; sum:=0;
	for i:=1 to n do
		begin
		  read(t);
			inc(count[t]);
			inc(sum,t);
		end;
  cou;
	writeln(work);
end.
