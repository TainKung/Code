program p1436;
uses math;
const maxn=255;
var
  n,i,l,t:longint;
  a,b,c,s:double;
  tot,sum:string;

function fix(x:double):double;
  begin
    exit(round(x*100)/100);
  end;

function fstr(x:double):string;
  var
    t:longint;
    t1,t2,t3:string;
  begin
    t:=round(x*100);
    str(t div 100,t1);
    if t mod 100<>0 then
      begin
        str(t mod 100 div 10,t2);
        if t mod 10<>0 then
          str(t mod 10,t3);
        t2:='.'+t2+t3;
      end
    else t2:='';
    exit(t1+t2);
  end;

function i2c(n:longint):char;
  begin
    case n of
      1:exit('1');
      2:exit('2');
      3:exit('3');
      4:exit('4');
      5:exit('5');
      6:exit('6');
      7:exit('7');
      8:exit('8');
      9:exit('9');
      0:exit('0');
    else
      exit('e');
    end;
  end;

function c2i(c:char):longint;
  begin
    case c of
      '1':exit(1);
      '2':exit(2);
      '3':exit(3);
      '4':exit(4);
      '5':exit(5);
      '6':exit(6);
      '7':exit(7);
      '8':exit(8);
      '9':exit(9);
      '0':exit(0);
    end;
  end;

function plus(a:longint;b:string):string;
  var
    i,p,l:longint;
  begin
    p:=0; i:=1; plus:='';
    l:=length(b);
    while (a<>0)and(i<=l) do
      begin
        p:=c2i(b[l-i+1])+a mod 10+p;
        plus:=i2c(p mod 10)+plus;
        p:=p div 10;
        inc(i); a:=a div 10;
      end;
    while a<>0 do
      begin
        p:=a mod 10+p;
        plus:=i2c(p mod 10)+plus;
        p:=p div 10;
        a:=a div 10;
      end;
    while i<=l do
      begin
        p:=c2i(b[l-i+1])+p;
        plus:=i2c(p mod 10)+plus;
        p:=p div 10; inc(i);
      end;
    if p<>0 then plus:=i2c(p)+plus;
  end;

function plus(a,b:string):string;
  var
    i,p,la,lb,l:longint;
  begin
    la:=length(a); lb:=length(b);
    p:=0; plus:='';
    for i:=1 to min(la,lb) do
      begin
        p:=c2i(a[la-i+1])+c2i(b[lb-i+1])+p;
        plus:=i2c(p mod 10)+plus;
        p:=p div 10;
      end;
    if i<la then     
      for l:=i+1 to la do
        begin
          p:=c2i(a[la-l+1])+p;
          plus:=i2c(p mod 10)+plus;
          p:=p div 10;
        end;
    if i<lb then   
      for l:=i+1 to lb do
        begin
          p:=c2i(b[lb-l+1])+p;
          plus:=i2c(p mod 10)+plus;
          p:=p div 10;
        end;
    if p<>0 then plus:=i2c(p)+plus;
  end;

begin
  readln(n);
  n:=round(log2(n));
  s:=100; sum:='0';
  for i:=1 to n do
    begin
      readln(a,b,c);
      s:=fix(s*a*b*c/1000000);
    end;
  for i:=1 to n do
    begin
      readln(a,b,c,t);
      sum:=plus(trunc(a*b*c*t/1000000)+t,sum);
    end;
  readln(l);
  readln(tot);
  writeln(fstr(s));
  writeln(plus(sum,tot));
end.