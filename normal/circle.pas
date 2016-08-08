program circle;
const
  maxint=10e8;
var
  k,m,n,x:longint;

function power(x,n:longint):longint;
  var
    i:longint;
  begin
    power:=1;
    for i:=1 to n do
      power:=x*power;
  end;

function h_mod(x,n,y:longint):longint;
  var
    t:longint;

  function test(x:longint):longint;
    var
      t:longint;
    begin
      test:=0;
      t:=1;
      while t<maxint do
        begin
          t:=t*x;
          inc(test);
        end;
    end;

  begin
    t:=test(x);
    if t>=n then
      h_mod:=power(x,n) mod y
    else
      h_mod:=h_mod(power(x,t) mod y,n div t,y)+power(x,n mod t) mod y;
  end;

begin
  readln(n,m,k,x);
  writeln((m*h_mod(10,k,n)+x) mod n);
end.