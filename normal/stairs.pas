program stairs;
const
  ipath='stairs.in';
  opath='stairs.out';
var
  n:longint;

procedure get;
  begin
    assign(input,ipath);
    reset(input);
    readln(n);
    close(input);
  end;

procedure put(x:longint);
  begin
    assign(output,opath);
    rewrite(output);
    writeln(x);
    close(output);
  end;

function go(n:longint):longint;
  begin
    go:=1;
    if (n=1) or (n=0) then exit;
    go:=go(n-1)+go(n-2);
  end;

begin
  get;
  put(go(n));
end.