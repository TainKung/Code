program p1076;
var
  a:array[1..100000] of longint;
  n,i:longint;
  
procedure qsort(l,r:longint);
  var
    i,j,t,p:longint;
  begin
    i:=l; j:=r;
    p:=a[(i+j) div 2];
    repeat
      while a[i]<p do inc(i);
      while a[j]>p do dec(j);
      if i<=j then
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
          inc(i); dec(j);
        end;
		until i>j;
    if i<r then qsort(i,r);
    if j>l then qsort(l,j);
  end;
  
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  qsort(1,n);
  for i:=1 to n do write(a[i],' ');
end.
