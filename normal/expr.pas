program expr;
const
  SIM=['+','*','.'];
  NUM=['0'..'9'];
var
  s:ansistring;
  a:array[1..100000] of longint;
  p,l,sl,ans:longint;

procedure push(x:longint);
  begin
    inc(p);
    a[p]:=x;
  end;

function pop:longint;
  begin
    pop:=a[p];
    dec(p);
  end;

procedure get_n;
  var
    i,t:longint;
  begin
    i:=l;
    while (s[l] in NUM) and (l<sl) do inc(l);
    val(copy(s,i,l-i),t);
    t:=t mod 10000;
    push(t);
  end;

function get_s:char;
  begin
    get_s:=s[l];
    inc(l);
  end;

procedure time;
  var
    x,y:longint;
  begin
    x:=pop;
    y:=pop;
    push(x*y mod 10000);
  end;

procedure work;
  var
    i:longint;
  begin
    l:=1;
    s:=s+'.';
    sl:=length(s);
    while l<sl do
      if s[l]in NUM then get_n
      else
        if get_s='*' then
          begin
            get_n;
            time;
          end;
    ans:=0;
    for i:=1 to p do
      ans:=ans+a[i];
    ans:=ans mod 10000;
  end;

begin
  readln(s);
  work;
  writeln(ans);
end.