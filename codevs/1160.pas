program p1160;
var
  a:array[1..99,1..99] of longint;
	dir,m,n,size,ans:longint;

procedure work;
  var
	  i:longint;
	begin
	  m:=size div 2 +1; n:=m;
		a[m,n]:=1;
		dir:=1;
	  for i:=2 to size*size do
			case dir of
			  1:begin inc(m);a[m,n]:=i;
				        if a[m,n-1]=0 then dir:=2 end;
				2:begin dec(n);a[m,n]:=i;
								if a[m-1,n]=0 then dir:=3 end;
				3:begin dec(m);a[m,n]:=i;
				        if a[m,n+1]=0 then dir:=4 end;
				4:begin inc(n);a[m,n]:=i;
				        if a[m+1,n]=0 then dir:=1 end;
			end;
	end;

procedure put;
  var
	  i,j:longint;
	begin
	  ans:=0;
	  for i:=1 to m do
			begin
			  for j:=1 to m do
					begin
  					write(a[j,i],' ');
						if (i+j=size+1)or(i=j) then ans:=ans+a[j,i];
					end;
				writeln;
			end;
		writeln(ans);
	end;

begin
  readln(size);
	fillchar(a,sizeof(a),0);
	work;
	put;
end.
