program p3145;
var
  n:longint;

function sum(n:longint):longint;
  begin
	  if n=1 then exit(1);
		sum:=2*sum(n-1)+1;
	end;

procedure move(n:longint;l,r:char);
  var t:char;
  begin
	  for t:='A' to 'C' do
			if (t<>l)and(t<>r) then break;
	  if n=0 then exit;
	  move(n-1,l,t);
		writeln(n,' from ',l,' to ',r);
		move(n-1,t,r);
	end;

begin
  readln(n);
	writeln(sum(n));
	move(n,'A','C');
end.
