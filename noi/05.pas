program GradeDivide;
const maxn=5000;
type node=record no,grade:longint end;
var
  n,m,i,p:longint;
  a:array[1..maxn] of node;

procedure get;
	var i:longint;
	begin
	  readln(n,m);
	  m:=trunc(1.5*m);
	  for i:=1 to n do
	    with a[i] do
	      readln(no,grade);
	end;

procedure swap(var a,b:node);
	var t:node;
	begin
	  t:=a;a:=b;b:=t;
	end;

procedure No_Qsort(l,r:longint);
	var i,j,p:longint;
  begin
    i:=l; j:=r;
    p:=a[(l+r)div 2].no;
    repeat
      while a[i].no<p do inc(i);
      while a[j].no>p do dec(j);
      if i<=j then
        begin
          swap(a[i],a[j]);
          inc(i); dec(j);
        end;
    until i>j;
    if l<j then No_Qsort(l,j);
    if i<r then No_Qsort(i,r);
  end;

procedure Grade_BubbleSort(l,r:longint);
	var
	  i,j:longint;
	  finish:boolean;
	begin
	  for i:=r downto l+1 do
	    begin
	      finish:=true;
	      for j:=l to i-1 do
	        if a[j].grade<a[j+1].grade then
	          begin
	            swap(a[j],a[j+1]);
	            finish:=false;
	          end;
	      if finish then break;
	    end;
	end;

begin
	get;
	No_Qsort(1,n);
	Grade_BubbleSort(1,n);
	p:=a[m].grade;
	while (m<=n)and(a[m].grade=p) do inc(m);
	writeln(p,' ',m-1);
	for i:=1 to m-1 do
	  writeln(a[i].no,' ',a[i].grade);
end.
