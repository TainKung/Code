program p1301;
const
  maxn=1000;
	s='0123456789ABCDEFGHI';
var
  p,k,i,j,la,lb,t:longint;
	sa,sb,ans:ansistring;
	a,b,c:array[1..maxn] of longint;

function c2i(x:char):longint;
  begin
	  exit(pos(x,s)-1);
	end;

function i2c(x:longint):char;
  begin
	  exit(s[x+1]);
	end;

function deal(var s:ansistring):longint;
  begin
	  deal:=pos('.',s);
		if deal=0 then exit;
		delete(s,deal,1);
		deal:=length(s)-deal+1;
	end;

begin
  readln(k);
	readln(sa);
	readln(sb);
	t:=deal(sa)+deal(sb);
	la:=length(sa); lb:=length(sb);
	fillchar(c,sizeof(c),0);
	ans:='';
	for i:=1 to la do a[i]:=c2i(sa[la-i+1]);
	for i:=1 to lb do b[i]:=c2i(sb[lb-i+1]);
	for i:=1 to la do
		for j:=1 to lb do
			inc(c[i+j-1],a[i]*b[j]);
	p:=0;
	for i:=1 to la+lb do
		begin
		  inc(c[i],p);
			p:=c[i] div k;
			c[i]:=c[i] mod k;
		end;
	j:=la+lb;
	while (j>t+1) and (c[j]=0) do dec(j);
	for i:=1 to j do ans:=i2c(c[i])+ans;
	if t>0 then
		begin
		  insert('.',ans,j-t+1);
	    inc(j);
			while ans[j]='0' do dec(j);
			if ans[j]='.' then dec(j);
		end;
	writeln(copy(ans,1,j));
end.
