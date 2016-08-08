program p1447;
const maxn=200;
type
  big=record
        a:array[1..maxn] of longint;
        len:longint;
      end;
var
  n:string;

procedure print(a:big);
  var i:longint;
  begin
    with a do
      for i:=len downto 1 do
        write(a[i]);
    writeln;
  end;

function change(s:string):big;
  var i:longint;
  begin
    with change do
    begin
      len:=length(s);
      fillchar(a,sizeof(a),0);
      for i:=1 to len do
        a[i]:=ord(s[len-i+1])-48;
    end;
  end;

function isbig(a,b:big):boolean;
  var i:longint;
  begin
    if a.len<b.len then exit(false);
    if a.len>b.len then exit(true);
    for i:=a.len downto 1 do
      if a.a[i]<b.a[i] then exit(false)
      else if a.a[i]>b.a[i] then exit(true);
    isbig:=false;
  end;

function subt(a,b:big):big;
  var i:longint;
  begin
    subt.len:=a.len;
    fillchar(subt.a,sizeof(subt.a),0);
    for i:=1 to a.len do
      subt.a[i]:=a.a[i]-b.a[i];
    with subt do
    begin
      for i:=1 to len-1 do
        if a[i]<0 then
        begin inc(a[i],10);dec(a[i+1]) end;
      while (len>1)and(a[len]=0) do dec(len);
    end;
  end;

function mult(a:big;b:longint):big;
  var i:longint;
  begin
    mult.len:=a.len+1;
    fillchar(mult.a,sizeof(mult.a),0);
    for i:=1 to a.len do
      mult.a[i]:=a.a[i]*b;
    with mult do
    begin
      for i:=1 to len-1 do
      begin inc(a[i+1],a[i] div 10);a[i]:=a[i] mod 10 end;
      while (a[len]=0)and(len>1) do dec(len);
    end;
  end;

function sqrt(x:big):big;
  var
    i,j,t:longint;
    p,pre,pre2:big;
  begin
    sqrt.len:=(x.len+1)shr 1;
    p.len:=1;p.a[1]:=0;
    pre.len:=1;pre.a[1]:=0;
    for i:=sqrt.len downto 1 do
    begin
      t:=i shl 1-1;
      with p do
      begin
        for j:=len+2 downto 3 do a[j]:=a[j-2];
        inc(len,2); a[2]:=x.a[t+1]; a[1]:=x.a[t];
        while (a[len]=0)and(len>1) do dec(len);
      end;
      with pre do
      begin
        for j:=len+1 downto 2 do a[j]:=a[j-1];
        inc(len); a[1]:=0;
        while (a[len]=0)and(len>1) do dec(len);
      end;
      pre2:=mult(pre,2);
      with pre2 do
      begin
        a[1]:=9;
        while isbig(mult(pre2,a[1]),p) do dec(a[1]);
      end;
      pre.a[1]:=pre2.a[1];
      p:=subt(p,mult(pre2,pre2.a[1]));
      sqrt.a[i]:=pre.a[1];
    end;
  end;

begin
  readln(n);
  print(sqrt(change(n)));
end.