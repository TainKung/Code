program p1018;
const max=20;
var
	s:array['a'..'z',1..max] of string;
	time:array['a'..'z',1..max] of longint;
	num:array[1..max] of longint;
	n,ans:longint;

procedure get;
	var
		i:longint;
		t:string;
		p:char
	begin
		readln(n);
		for i:=1 to n do
			begin
				readln(t);
				p:=t[1];
				inc(s[p,0]);
				s[p,s[p,0]]:=t;
			end;
	end;
