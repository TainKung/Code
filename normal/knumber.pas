program knumber;
const
  ipath='knumber.in';
  opath='knumber.out';
  max=10000;
var
  n,k,p:longint;
  a:array[1..max] of longint;

procedure push(x:longint);
  var
    i:longint;
  begin
    for i:=1 to p do
      if x=a[i] then exit;
    inc(p);
    a[p]:=x;
  end;

procedure get;
  var
    i,t:longint;
  begin
    assign(input,ipath);
    reset(input);
    readln(n,k);
    for i:=1 to n do
      begin
        read(t);
        push(t);
      end;
    close(input);
  end;

procedure put;
  begin
    assign(output,opath);
    rewrite(output);
    if k>p then writeln('No result')
           else writeln(a[k]);
    close(output);
  end;

procedure qsort(l,r:longint);
  var
    i,j,p,t:longint;
  begin
    i:=l;
    j:=r;
    p:=a[(l+r) div 2];
    repeat
      while a[i]<p do inc(i);
      while a[j]>p do dec(j);
      if i<=j then
        begin
          t:=a[i];
          a[i]:=a[j];
          a[j]:=t;
          inc(i);
          dec(j);
        end;
    until i>j;
    if i<r then qsort(i,r);
    if j>l then qsort(l,j);
  end;

begin
  p:=0;
  get;
  qsort(1,p);
  put;
end.