program check;
var
  a:array[1..10000] of char;
  p:longint;
  s:ansistring;

procedure push(x:char);
  begin
    a[p]:=x;
    inc(p);
  end;

function pop:char;
  begin
    if p=0 then exit('0');
    dec(p);
    exit(a[p]);
  end;

function check(s:string):boolean;
  var
    i,l:longint;
  begin
    i:=1;
    p:=0;
    l:=length(s);
    while i<=l do
      begin
        case s[i] of
          '(','[':push(s[i]);
          ')':if not (pop='(') then exit(false);
          ']':if not (pop='[') then exit(false);
        end;
        inc(i);
      end;
    if p>0 then check:=false;
  end;

begin
  readln(s);
  writeln(check(s));
end.