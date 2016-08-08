program GradeSort;
type student=record
	             name:string;
	             grade:longint;
	           end;
const maxn=20;
var
  n,i:longint;
  stu:array[1..maxn] of student;

procedure get;
	var i,p:longint;
	begin
	  readln(n);
	  for i:=1 to n do
	    with stu[i] do
	      begin
	        readln(name);
	        p:=pos(' ',name);
	        val(copy(name,p+1,length(name)-p),grade);
	        name:=copy(name,1,p-1);
	      end;
	end;

procedure NameQsort(l,r:longint);
	var
	  i,j:longint;
	  p:string;
	  t:student;
	begin
	  i:=l; j:=r;
	  p:=stu[(l+r) div 2].name;
	  repeat
	    while stu[i].name<p do inc(i);
	    while stu[j].name>p do dec(j);
	    if i<=j then
	      begin
	        t:=stu[i];
	        stu[i]:=stu[j];
	        stu[j]:=t;
	        inc(i); dec(j);
	      end;
	  until i>j;
	  if l<j then NameQsort(l,j);
	  if i<r then NameQsort(i,r);
	end;

procedure GradeBubbleSort(l,r:longint);
	var
	  i,j:longint;
	  t:student;
	  finish:boolean;
	begin
	  for i:=r downto l+1 do
	    begin
	      finish:=true;
	      for j:=l to i-1 do
	        if stu[j].grade<stu[j+1].grade then
	          begin
	            t:=stu[j];
	            stu[j]:=stu[j+1];
	            stu[j+1]:=t;
	            finish:=false;
	          end;
	      if finish then break;
	    end;
	end;

begin
	get;
	NameQsort(1,n);
	GradeBubbleSort(1,n);
	for i:=1 to n do 
	  with stu[i] do writeln(name,' ',grade);
end.
