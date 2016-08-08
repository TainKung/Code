program p1630;
uses math;
const
  maxn = 30;
type
  big=record
        a:array[1..maxn] of Longint;
        len:longint;
      end;
var
  n,i,l:longint;
  s:string;
  a,b,c,fz,fm:big;

procedure swap(var a,b:char);
  var
    t: char;
  begin
    t:=a;a:=b;b:=t;
  end;

procedure swap(var a,b:big);
  var t:big;
  begin
    t:=a;a:=b;b:=t;
  end;

procedure print(a:big);
  var
    i,j:longint;
    s:string;
  begin
    s:='';
    with a do
    begin
      for i := 1 to len do
        for j := 1 to 4 do
        begin
          s:=chr(a[i] mod 10+48)+s;
          a[i]:=a[i] div 10;
        end;
      j:=len shl 2;
    end;
    i:=1;
    while (i<j)and(s[i]='0') do inc(i);
    write(copy(s,i,j-i+1));
  end;

function isBig(a,b:big):boolean;
  var i:longint;
  begin
    if a.len<b.len then exit(false);
    if a.len>b.len then exit(true);
    for i:=a.len downto 1 do
      if a.a[i]<b.a[i] then exit(false)
      else if a.a[i]>b.a[i] then exit(true);
    isBig:=true;
  end;

function plus(a,b:big):big;
  var
    i,j:longint;
  begin
    fillchar(plus.a,sizeof(plus.a),0);
    for i:=1 to max(a.len,b.len) do
      plus.a[i]:=a.a[i]+b.a[i];
    with plus do
    begin
      for j := 1 to i do
      begin
        inc(a[j+1],a[j] div 10000);
        a[j]:=a[j] mod 10000;
      end;
      if a[j+1]>0 then inc(j);
      len:=j;
    end;
  end;

function subt(a,b:big):big;
  var
    i:longint;
  begin
    fillchar(subt.a,sizeof(subt.a),0);
    if isBig(b,a) then swap(a,b);
    for i:=1 to a.len do
      subt.a[i]:=a.a[i]-b.a[i];
    subt.len:=a.len;
    with subt do
    begin
      for i := 1 to len-1 do
        if a[i]<0 then
        begin
          inc(a[i],10000);
          dec(a[i+1]);
        end;
      while (a[len]=0)and(len>1) do dec(len);
    end;
  end;

function mult(a,b:big):big;
  var
    i,j,l,p: longint;
  begin
    fillchar(mult.a,sizeof(mult.a),0);
    l:=a.len+b.len;
    for i:=1 to a.len do
      for j:=1 to b.len do
        begin
          p:=a.a[i]*b.a[j];
          inc(mult.a[i+j-1],p mod 10000);
          inc(mult.a[i+j],p div 10000);
        end;
    for i:=1 to l-1 do
      begin
        inc(mult.a[i+1],mult.a[i] div 10000);
        mult.a[i]:=mult.a[i] mod 10000;
      end;
    while (l>1)and(mult.a[l]=0) do dec(l);
    mult.len:=l;
  end;

function divi(a,b:big):big;
  var i,j:longint;

  function ispos(a,b:big;p:longint):boolean;
    var i:longint;
    begin
      if a.len<b.len+p-1 then exit(false);
      if a.len>b.len+p-1 then exit(true);
      for i:=b.len downto 1 do
        if a.a[i+p-1]>b.a[i] then exit(true)
        else if a.a[i+p-1]<b.a[i] then exit(false);
      ispos:=true;
    end;

  begin
    if ((a.len=1)and(a.a[1]=0))
    or((b.len=1)and(b.a[1]=1)) then exit(a);
    fillchar(divi.a,sizeof(divi.a),0);
    divi.len:=a.len-b.len+1;
    for i := divi.len downto 1 do
    begin
      while ispos(a,b,i) do
      begin
        for j:=i to a.len do
          a.a[j]:=a.a[j]-b.a[j-i+1];
        with a do
        begin
          for j:=i to len-1 do
            if a[j]<0 then
            begin
              inc(a[j],10000);
              dec(a[j+1]);
            end;
          while (a[len]=0)and(len>1) do dec(len);
        end;
        inc(divi.a[i]);
      end;
    end;
    with divi do
      while (a[len]=0)and(len>1) do dec(len);
  end;

function bpower(a,b:big):big;
  var i:longint;
  begin
    if (a.len=1)and((a.a[1]=0)or(a.a[1]=1)) then exit(a);
    bpower.len:=1; bpower.a[1]:=1;
    for i:=1 to b.a[1] do
      bpower:=mult(a,bpower);
  end;

function change(s:string):big;
  var i:longint;
  begin
    with change do
    begin
      fillchar(a,sizeof(a),0);
      len:=length(s) and 3;
      if len<>0 then
        for i:=3 downto len do
          s:='0'+s;
      len:=length(s) shr 2;
      for i := 1 to len do
        val(copy(s,(len-i+1) shl 2-3,4),a[i]);
    end;
  end;

function opera(s:string):longint;
  const
    a:set of char=['+','-','*','/','^'];
  begin
    opera:=7;
    while not (s[opera] in a) do inc(opera);
  end;

begin
  readln(s);
  n:=pos('/',s);
  fz:=change(copy(s,1,n-1));
  fm:=change(copy(s,n+1,length(s)-n));
  readln(n);
  for i:=1 to n do
    begin
      readln(s);
      if s='swap' then begin swap(fz,fm);continue end;
      n:=opera(s);
      l:=length(s);
      case s[n-1] of 
        'i':a:=fz;
        'u':a:=fm;
      else
        a:=change(copy(s,7,n-7));
      end;
      case s[l] of 
        'i':b:=fz;
        'u':b:=fm;
      else
        b:=change(copy(s,n+1,l-n));
      end;
      case s[n] of
        '+':c:=plus(a,b);
        '-':c:=subt(a,b);
        '*':c:=mult(a,b);
        '/':c:=divi(a,b);
        '^':c:=bpower(a,b);
      end;
      if s[5]='i' then fz:=c else fm:=c;
    end;
  if (fm.len=1)and(fm.a[1]=0) then writeln('Error')
  else begin print(fz);write('/');print(fm) end;
end.