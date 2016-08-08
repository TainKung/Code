program p1980;
var
  card:array[0..13] of longint;
	sing,doub,four:array[0..13] of boolean;
	count:array[1..2] of longint;
	ans,t,n:longint;

procedure shunzi(var p:longint);
  var
	begin
	  l:=p; r:=p;
		while (r<=13)and(card[r]>0) do
			begin
			  if card[r]<min then min:=card[r];
				m[i]:=min;
			end;
		while (r-l+1)*m[r]<5 do
			if r-l>1 then dec(r) else exit;
		if (four<>0)and(min<=2)and(count[min]-(r-l+1)=1) then dec(r);
		for i:=l to r
