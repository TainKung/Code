program stamp;
const
  ipath='stamp.in';
  opath='stamp.out';
  w=100;
var
  m,n,ans,max:longint;
  a:array[1..w] of longint;
  b:array[1..25500] of longint;

procedure get;
  var
    i:longint;
  begin
    assign(input,ipath);
    reset(input);
    readln(m,n);
    max:=0;
    for i:=1 to m do
      begin
        read(a[i]);
        b[a[i]]:=1;
        if a[i]>max then max:=a[i];
      end;
    close(input);
  end;

procedure put;
  begin
    assign(output,opath);
    rewrite(output);
    writeln(ans);
    close(output);
  end;

procedure work;
  var
    i,x,k:longint;
  begin
    x:=0;
    repeat
      inc(x);
      if (b[x]=0) or (b[x]=n) then continue;
      for i:=1 to m do
        begin
          k:=a[i]+x;
          if (b[k]=0) or (b[k]>b[x]+1) then b[k]:=b[x]+1;
        end;
    until x=max*n;
  end;

function count:longint;
  var
    i,k:longint;
  begin
    i:=1;
    count:=0;
    repeat
      while (b[i]=0) and (i in[1..max*n-1]) do inc(i);
      k:=i;
      repeat inc(i); until (b[i]=0) or not (i in[1..max*n]);
      k:=i-k;
      if k>count then count:=k;
    until i>=max*n;
  end;

begin
  get;
  work;
  ans:=count;
  put;
end.