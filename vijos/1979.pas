program p1979;
const max=200000;
var
  aim:array[1..max] of longint;
	done:array[1..max] of boolean;
	n,ans,i:longint;

procedure get;
  var i:longint;
	begin
	  readln(n);
		for i:=1 to n do
			read(aim[i]);
	end;

procedure work(p:longint);
  var
	  i:longint;
		dis:array[1..max] of longint;
	begin
	  i:=1;
		done[p]:=true;
		fillchar(dis,sizeof(dis),0);
		dis[p]:=i;
		while true do
			begin
			  p:=aim[p];
				inc(i);
				if dis[p]>0 then
					begin
					  if i-dis[p]<ans then
							ans:=i-dis[p];
						exit;
					end;
				if done[p] then exit;
				done[p]:=true;
				dis[p]:=i;
			end;
	end;

begin
  get;
	ans:=maxlongint;
	fillchar(done,sizeof(done),false);
  for i:=1 to n do
	  if not done[i] then
		  work(i);
	writeln(ans);
end.
