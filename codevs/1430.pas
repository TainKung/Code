program p1430;
var
  x:longint;

function isgcd(x:longint):boolean;
  var
	  i:longint;
	begin
	  for i:=2 to trunc(sqrt(x)) do
			if x mod i=0 then exit(false);
		exit(true);
	end;

begin
  readln(x);
	if isgcd(x) then writeln('\t')
		          else writeln('\n');
end.
