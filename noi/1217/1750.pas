program p1750;
const maxn=10000;
var
  s:ansistring;
	a:array[1..maxn] of char;
	b:array[1..maxn] of boolean;
	n:longint;

procedure get;
  var i:longint;
	begin
	  readln(s);
		n:=length(s);
		for i:=1 to n do
			a[i]:=s[i];
		fillchar(b,sizeof(b),true);
	end;

procedure work(k:longint;s:string);
  var i:longint;
	begin
	  if k=0 then begin writeln(s);exit end;
	  for i:=1 to n do
			if b[i] then
				begin
				  b[i]:=false;
					work(k-1,s+a[i]);
					b[i]:=true;
				end;
	end;

begin
  get;
	work(n,'');
end.
