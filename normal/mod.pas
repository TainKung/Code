const
  ipath='mod.in';
  opath='mod.out';
var
  b,p,k,ans:longint;

procedure get;
  begin
    assign(input,ipath);
    reset(input);
    readln(b,p,k);
    close(input);
  end;

procedure put;
  begin
    assign(output,opath);
    rewrite(output);
    writeln(b,'^',p,' mod ',k,'=',ans);
    close(output);
  end;

procedure work;
  var
    i,m:longint;
  begin
    m:=1;
    for i:=1 to p do
      m:=m*b mod k;
    ans:=m;
  end;

begin
  get;
  work;
  put;
end.