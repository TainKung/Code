program p1908;
var
  d,n:longint;
	map,sum:array[0..128,0..128] of longint;

procedure get;
  var
	  i,x,y,k:longint;
	begin
	  readln(d,n);
		fillchar(map,sizeof(map),0);
		for i:=1 to n do
			begin
			  readln(x,y,k);
				map[x,y]:=k;
			end;
	end;

procedure work;
  var i,j,k:longint;
	begin
		fillchar(sum,sizeof(sum),0);
		for i:=0 to 2*d do
			for j:=0 to 2*d do
				inc(sum[d,d],map[i,j]);
		for i:=d to 128-d do
			for j:=d to 128-d do
				if sum[i-1,j]>=0 then
					begin
					  if (i=d)and(j=d) then continue;
					  sum[i,j]:=sum[i-1,j];
  					for k:=j-d to j+d do
  						sum[i,j]:=sum[i,j]+map[i+d,k]-map[i-1-d,k];
					end
				else if sum[i,j-1]>=0 then
					begin
					  sum[i,j]:=sum[i,j-1];
						for k:=i-d to i+d do
							sum[i,j]:=sum[i,j]+map[k,j+d]-map[k,j-1-d];
					end;
		for i:=0 to 10 do
			begin
			  for j:=0 to 10 do
					write(sum[i,j]:3);
				writeln;
			end;
	end;

procedure put;
  var
	  i,j,num,max:longint;
	begin
	  max:=0;
	  for i:=d to 128-d do
			for j:=d to 128-d do
				if sum[i,j]>max then
					begin
					  max:=sum[i,j];
						num:=1;
					end
				else if sum[i,j]=max then
					inc(num);
		writeln(num,' ',max);
	end;

begin
  get;
	work;
	put;
end.
