program change;
const
  ipath='change.in';
  opath='change.out';
  s='0123456789';
var
  a:longint;
  b:string;

procedure get;
  begin
    assign(input,ipath);
    reset(input);
    readln(a);
    close(input);
  end;

procedure put;
  begin
    assign(output,opath);
    rewrite(output);
    writeln(b);
    close(output);
  end;

function change(n:longint):string;
  begin
    if n=1 then
      begin
        change:='1';
        exit;
      end;
    change:=change(n div 8)+s[n mod 8+1];
  end;

begin
  get;
  b:=change(a);
  put;
end.