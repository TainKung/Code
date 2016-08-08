program Scholar;
const maxn=300;
type student=record g1,g2,g3,sum,no:longint end;
var
  n,i:longint;
  a:array[1..maxn] of student;

procedure get;
	var i:longint;
	begin
	  readln(n);
	  for i:=1 to n do
	    with a[i] do
	      begin
	        no:=i;
	        readln(g1,g2,g3);
	        sum:=g1+g2+g3;
	      end;
	end;

procedure swap(var a,b:student);
	var t:student;
	begin
	  t:=a;a:=b;b:=t;
	end;

procedure Ch_BubbleSort(l,r:longint);
	var
	  i,j:longint;
	  finish:boolean;
	begin
	  for i:=r downto l+1 do
	    begin
	      finish:=true;
	      for j:=1 to i-1 do
	        if a[j].g1<a[j+1].g1 then
	          begin
	            swap(a[j],a[j+1]);
	            finish:=false;
	          end;
	      if finish then break;
	    end;
	end;

procedure Sum_BubbleSort(l,r:longint);
	var
	  i,j:longint;
	  finish:boolean;
	begin
	  for i:=r downto l+1 do
	    begin
	      finish:=true;
	      for j:=1 to i-1 do
	        if a[j].sum<a[j+1].sum then
	          begin
	            swap(a[j],a[j+1]);
	            finish:=false;
	          end;
	      if finish then break;
	    end;
	end;

begin
	get;
	Ch_BubbleSort(1,n);
	Sum_BubbleSort(1,n);
	for i:=1 to 5 do
	  writeln(a[i].no,' ',a[i].sum);
end.
