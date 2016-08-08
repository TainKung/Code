program deseq;
const
  ipath='deseq.in';
  opath='deseq.out';
  max=105;
var
  n,ans:longint;
  a:array[1..max] of longint;

procedure get;
  var
    i:longint;
  begin
    assign(input,ipath);
    reset(input);
    readln(n);
    for i:=1 to n do
      readln(a[i]);
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
    i,j:longint;
  begin
    ans:=0;
    for i:=1 to n do
      for j:=i+1 to n do
        if a[i]>a[j] then
          inc(ans);
  end;

begin
  get;
  work;
  put;
end.