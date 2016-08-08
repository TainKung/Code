program p1205;
var
  a,b,t:string;
  i,len:longint;
begin
  readln(a);
	a:=a+' ';
  len:=length(a);
  i:=0;
	t:='';
	b:='';
  while i<len do
    begin
      repeat
        inc(i);
        t:=t+a[i];
			until (i=len)or(a[i]=' ');
      b:=t+b;
      t:='';
    end;
	writeln(b);
end.
