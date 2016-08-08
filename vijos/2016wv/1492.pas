program p1492;
uses math;
const maxn=800;
var
  n,i,j,p,l:longint;
  a:array[1..maxn] of longint;
  ans:ansistring;

function cr(n:longint):char;
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

begin
  readln(n); inc(n);
  fillchar(a,sizeof(a),0);
  a[1]:=1; ans:='';
  l:=ceil(n*log10(2));
  for i:=1 to n do
    begin
      p:=0;
      for j:=1 to l do
        begin
          a[j]:=a[j] shl 1+p;
          p:=a[j] div 10;
          a[j]:=a[j] mod 10;
        end;
    end;
  if n and 1=0 then dec(a[1],1) else dec(a[1],2);
  p:=0;
  for i:=l downto 1 do
    begin
      inc(a[i],p*10);
      p:=a[i] mod 3;
      a[i]:=a[i] div 3;
    end;
  if a[l]=0 then dec(l);
  for i:=1 to l do ans:=cr(a[i])+ans;
  writeln(ans);
end.