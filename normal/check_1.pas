program check;
const
  maxn=10000;
  ipath='check.in';
  opath='check.out';
var

  s,stack,o:string;
  i,len,top:integer;
  bl:boolean;
procedure get;
  begin
    assign(input,ipath);
    reset(input);
    readln(s);
    close(input);
    len:=length(s);
    i:=0;
    top:=0;
  end;

procedure push;

procedure pop;
  begin
    bl:=false;
    while i<=len do
      begin
        inc(i);
        if s[i]=')' then
          if stack[top]='(' then begin bl:=true;dec(top); end;
        if s[i]=']' then
          if stack[top]='[' then begin bl:=true;dec(top); end;
        if (s[i]='(') or (s[i]='[') then
          break;
      end;
      if bl then o:='OK!'
        else begin o:='Wrong!';exit; end;
      dec(i);
      push;
  end;


  begin
    while i<=len do
      begin
        inc(i);
        if (s[i]='(') or (s[i]='[') then
          begin
            inc(top);
            stack[top]:=s[i];
          end
        else
          break;
      end;
      dec(i);
      pop;
  end;

procedure ending;
  begin
    assign(output,opath);
    rewrite(output);
    writeln(o);
    close(output);
  end;

begin
  get;
  push;
  if top > 0 then
    o:='wrong';
  ending;
end.













