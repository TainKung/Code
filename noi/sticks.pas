program sticks;
var
  n,k,sum,t,p,i:longint;
	count:array[1..50] of longint;
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
		for i:=k to 1 do
			if (ex[i]<=m)and(count[ex[i]]>0) then
				begin
					dec(count[ex[i]]);
					if check(m-ex[i],len,num) then
						exit(true);
				  inc(count[ex[i]]);
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
	repeat
	  fillchar(count,sizeof(count),0);
		ex[i]:=0; sum:=0;
		for i:=1 to n do
			begin
			  read(t);
				inc(count[t]);
				inc(sum,t);
			end;
		cou;
		inc(p);
		ans[p]:=work;
		readln(n);
	until n=0;
	for i:=1 to p do writeln(ans[i]);
end.
