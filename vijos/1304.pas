program p1304;
const
  s='0123456789ABCDEF';
  ipath='1304.in';
  opath='1304.out';
var
  n,ans:longint;
  m:string;

procedure get;
  begin
    readln(n);
    readln(m);
  end;

procedure put;
  begin
    if ans>30 then writeln('Impossible!')
              else writeln('Step=',ans);
  end;

function isr(s:string):boolean;
  var
    i,l:longint;
  begin
    isr:=false;
    l:=length(s);
    for i:=1 to l div 2 do
      if s[i]<>s[l-i+1] then exit;
    isr:=true;
  end;

function re(x:string):string;
  var
    i,l:longint;
  begin
    re:='';
    l:=length(x);
    for i:=1 to l do
      re:=re+x[l-i+1];
  end;

procedure replus(n:longint;var x:string);
  var
    y:string;
    i,l:longint;
    a:array[1..65500] of integer;
  begin
    y:=re(x);
    l:=length(x);
    fillchar(a,sizeof(a),0);
    for i:=1 to l do
      a[i]:=pos(y[i],s)+pos(x[i],s)-2;
    for i:=1 to l do
      begin
        a[i+1]:=a[i+1]+a[i] div n;
        a[i]:=a[i] mod n;
      end;
    for i:=1 to l do
      x[i]:=s[a[i]+1];
    if a[l+1]<>0 then x:=x+s[a[l+1]+1];
    x:=re(x);
  end;

procedure work;
  begin
    if isr(m) then
      begin
        ans:=0;
        exit;
      end;
    for ans:=1 to 31 do
      begin
        replus(n,m);
        if isr(m) then exit;
      end;
  end;

begin
  // assign(input,ipath); reset(input);
  // assign(output,opath); rewrite(output);
  get;
  work;
  put;
  // close(input); close(output);
end.