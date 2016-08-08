program family;
const
  ipath='family.in';
  opath='family.out';
  w=100;
var
  n,k,count:longint;
  a:array[1..w,1..w] of longint;
  p:array[0..w] of longint;

procedure create;
  begin
    inc(p[0]);
    p[p[0]]:=0;
  end;

procedure push(i,x:longint);
  var
    j:longint;
  begin
    for j:=1 to p[i] do
      if a[i,j]=x then exit;
    inc(p[i]);
    a[i,p[i]]:=x;
    inc(count);
  end;

function find(x:longint):longint;
  var
    i,j:longint;
    f:boolean;
  begin
    f:=false;
    for i:=1 to p[0] do
      for j:=1 to p[i] do
        if a[i,j]=x then
          f:=true;
    if f then find:=i
         else find:=0;
  end;

procedure work(x,y:longint);
  var
    t:longint;
  begin
    t:=find(x);
    if t=0 then t:=find(y);
    if t=0 then
      begin
        create;
        t:=p[0];
      end;
    push(t,x);
    push(t,y);
  end;

procedure get;
  var
    i,x,y:longint;
  begin
    assign(input,ipath);
    reset(input);
    readln(n,k);
    for i:=1 to k do
      begin
        readln(x,y);
        work(x,y);
      end;
    close(input);
  end;

function max:longint;
  var
    i:longint;
  begin
    max:=0;
    for i:=1 to p[0] do
      if p[i]>max then max:=p[i];
  end;

procedure put;
  begin
    assign(output,opath);
    rewrite(output);
    writeln(p[0],' ',max);
    close(output);
  end;

procedure one;
  var
    i:longint;
  begin
    for i:=1 to n-count do
      begin
        create;
        push(p[0],1);
      end;
  end;

begin
  count:=0;
  get;
  one;
  put;
end.