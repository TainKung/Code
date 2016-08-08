program p1436_1;
uses math;
const maxn=300;
type big=record
           a:array[1..maxn]of longint;
           len:longint;
         end;
var
  n,i,t,tot:longint;
  a,b,c,s:double;
  srg:string;
  sum:big;

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

function plus(a:big;b:longint):big;
  var i:longint;
  begin
    with a do
    begin
      inc(a[1],b);
      i:=1;
      while a[i]>=10 do
      begin
        inc(a[i+1],a[i] div 10);
        a[i]:=a[i] mod 10;
        inc(i);
      end;
      len:=max(i,len);
    end;
    for i:=1 to a.len do
      plus.a[i]:=a.a[i];
    plus.len:=a.len;
  end;

function fix(a:double):double;
  begin
    exit(round(a*100)/100);
  end;

begin
  readln(n); n:=round(log2(n));
  s:=100;
  for i:=1 to n do
  begin
    readln(a,b,c);
    s:=a*b*c*s/1000000;
  end;
  writeln(s:0:2);
  tot:=0;
  for i:=1 to n do
  begin
    readln(a,b,c,t);
    inc(tot,trunc(a*b*c*t/1000000)+t);
  end;
  readln(n);
  readln(srg);
  print(plus(change(srg),tot));
end.