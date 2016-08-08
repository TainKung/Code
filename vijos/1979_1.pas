program p1979_1;
const max=200000;
var
  aim,dis:array[1..max] of longint;
	root:array[1..max] of longint;
	n,ans,p,i:longint;

procedure get;
  var
	  fa:array[1..max] of longint;
		i:longint;

  function father(p:longint):longint;
	  begin
		  if fa[p]=p then exit(p);
			fa[p]:=father(fa[p]);
			exit(fa[p]);
		end;

	procedure union(a,b:longint);
	  begin
		  fa[father(b)]:=father(a);
		end;

	begin
	  readln(n);
		for i:=1 to n do fa[i]:=i;
		for i:=1 to n do
			begin
			  read(aim[i]);
				union(i,aim[i]);
			end;
		p:=0;
		for i:=1 to n do
			if fa[i]=i then
				begin
				  inc(p);
					root[p]:=i;
				end;
	end;

procedure work(p:longint);
  var i:longint;
	begin
	  i:=1;
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
					end
				else
					dis[p]:=i;
			end;
	end;

begin
  get;
	ans:=maxlongint;
	fillchar(dis,sizeof(dis),0);
	for i:=1 to p do work(root[i]);
	writeln(ans);
end.
