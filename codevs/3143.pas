program p3143;
var
  n:longint;
	a:array[1..16] of record l,r:longint end;

procedure fw(r:longint);
  begin
	  if r=0 then exit;
		write(r,' ');
		fw(a[r].l);
		fw(a[r].r);
	end;

procedure mw(r:longint);
  begin
	  if r=0 then exit;
		mw(a[r].l);
		write(r,' ');
		mw(a[r].r);
	end;

procedure ew(r:longint);
  begin
	  if r=0 then exit;
		ew(a[r].l);
		ew(a[r].r);
		write(r,' ');
	end;

procedure get;
  var i:longint;
	begin
	  readln(n);
		for i:=1 to n do
			readln(a[i].l,a[i].r);
	end;

begin
  get;
	fw(1);
	writeln;
	mw(1);
	writeln;
	ew(1);
end.
