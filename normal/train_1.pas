program train;
var
  a,b:string;
  s:array[1..10000] of char;
  p:longint;

procedure push(x:char);
  begin
    inc(p);
    s[p]:=x;
  end;

function pop:char;
  begin
    if p=0 then exit;
    pop:=s[p];
    dec(p);
  end;

function top:char;
  begin
    exit(s[p]);
  end;

procedure work(a,b:string);
  var
    i,j,len:longint;
  begin
    len:=length(a);
    i:=1;j:=1;
    while i<=len do
      if top=b[j] then
        begin pop;inc(j) end
      else
        begin
          push(a[i]);
          inc(i);
        end;
    while top=b[j] do
      begin pop;inc(j) end;
    if p=0 then writeln('yes')
           else writeln('no');
  end;

begin
  readln(a);
  readln(b);
  work(a,b);
end.