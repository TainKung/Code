program stamp;
const
  ipath='stamp.in';
  opath='stamp.out';
  w=100;
var
  i,m,n:longint;
  a:array[1..w] of longint;

procedure get;
  var
    i:longint;
  begin
    assign(input,ipath);
    reset(input);
    readln(m,n);
    for i:=1 to m do
      read(a[i]);
    close(input);
  end;

procedure put;
  begin
    assign(output,opath);
    rewrite(output);
    writeln(i);
    close(output);
  end;

function check(x:longint):boolean;
  var
    i:longint;
  begin
    check:=true;
    if x=0 then exit;
    if n=0 then
      begin
        check:=false;
        exit;
      end;
    for i:=1 to m do
      if x-a[i]>=0 then
        begin
          dec(n);
          if check(x-a[i]) then
            begin
              inc(n);
              exit;
            end;
          inc(n);
        end;
    check:=false;
  end;

begin
  get;
  i:=1;ans:=0;
  while check(i) do
    begin
      inc(i);
    end;
  put;
end.