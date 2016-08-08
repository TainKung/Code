program p1738;
const
  width=4;
	heigh=6;
var
  form:array[0..4,0..6] of 1..10;
	act:array[1..1000] of
	    record x,y:0..6;g:[-1,1]; end;
	fresh:array[0..4,0..6] of boolean;
	top:array[0..4] of 1..10;
	step,sum:longint;

function drop(a,b:longint):boolean;
  var
	  i,j:longint;
	begin
	  drop:=false;
	  for i:=a to b do
			for j:=2 to heigh do
			  while (form[i,j]>0)and(form[i,j-1]=0) do
					begin
					  fresh[i,j]:=false;
					  form[i,j-1]:=form[i,j];
						form[i,j]:=0;
						fresh[i,j-1]:=true;
					  drop:=true;
					end;
	end;

procedure clean;
  begin
	  fillchar(fresh,sizeof(fresh),false);
	end;

procedure check(x,y,c,dir:0..10);
  begin
	  if form[x,y]<>c then exit(k);
		case dir of
		  0:begin sum:=1;check(x,y-1,c,1);check(x,y+1,c,2);
			        if sum>2 then form[x,y]:=0;
			        sum:=1;check(x-1,y,c,3);check(x+1,y,c,4);
							if sum>2 then form[x,y];=0;exit end;
		  1:check(x,y-1,c,dir);
			2:check(x,y+1,c,dir);
			3:check(x-1,y,c,dir);
			4:check(x+1,y,c,dir);
		end;
		if sum>2 then form[x,y]:=0;
	end;

procedure boom;
  begin
	  repeat
  	  for i:=0 to width do
  			for j:=0 to heigh do
  				if fresh[i,j] then check(i,j,form[i,j],0);
			clean;
		until not drop(0,4);
	end;

procedure gettop;
  var
	  i,j:longint;
	begin
	  for i:=0 to width do
			begin
			  j:=heigh;
				while (j>0)and(form[i,j]=0) do dec(j);
				top[i]:=form[i,j];
			end;
	end;
