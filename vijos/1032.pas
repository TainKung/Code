program p1032;
const maxn=200;
type big=array[1..maxn+1] of longint;
var
  s:string;
  k:longint;
  x,ans:big;

procedure print(a:big);
  var i,j:longint;
  begin
    i:=maxn;
    while a[i]=0 do dec(i);
    for j:=i downto 1 do write(a[j]);
    writeln;
  end;

function cut(var s:string):longint;
  var p,i:longint;
  begin
    p:=pos(' ',s);
    val(copy(s,p+1,length(s)-p),cut);
    if p>cut then s:=copy(s,p-cut,cut)
    else
      begin
        s:=copy(s,1,p-1);
        for i:=p to cut do s:='0'+s;
      end;
  end;

procedure reserve(var s:string);
  var
    i,l:longint;
    t:char;
  begin
    l:=length(s);
    for i:=1 to l shr 1 do
      begin
        t:=s[i];s[i]:=s[l-i+1];s[l-i+1]:=t;
      end;
  end;

procedure change(s:string;var a:big);
  var i:longint;
  begin
    reserve(s);
    fillchar(a,sizeof(a),0);
    for i:=1 to k do
      a[i]:=ord(s[i])-48;
  end;

procedure bcopy(a:big;var b:big;len:longint);
  var i:longint;
  begin
    fillchar(b,sizeof(b),0);
    for i:=1 to len do
      b[i]:=a[i];
  end;

procedure mult(var a:big;b:big;len:longint);
  var
    i,j:longint;
    c:big;
  begin
    fillchar(c,sizeof(c),0);
    for i:=1 to len do
      for j:=1 to len do
        begin
          if i+j-1>len then break;
          inc(c[i+j-1],a[i]*b[j]);
        end;
    for i:=1 to len do
      begin
        inc(c[i+1],c[i] div 10);
        c[i]:=c[i] mod 10;
      end;
    bcopy(c,a,len);
  end;

procedure wrong;
  begin
    writeln(-1);
    halt;
  end;

procedure work(a:big;k:longint;var ans:big);
  var
    need:array[0..maxn] of longint;
    exist:array[0..9] of boolean;
    i,j,pre:longint;
    t,x:big;
  begin
    fillchar(ans,sizeof(ans),0);
    fillchar(need,sizeof(need),0);
    ans[1]:=1;
    bcopy(a,x,k);
    for i:=1 to k do
      begin
        bcopy(x,t,k);
        for j:=1 to need[i-1]-1 do mult(x,t,k);
        fillchar(exist,sizeof(exist),false);
        bcopy(a,t,i);
        pre:=t[i]; exist[t[i]]:=true;
        for j:=1 to 11 do
          begin
            mult(t,x,i);
            if not exist[t[i]] then
              exist[t[i]]:=true
            else
              if t[i]=pre then break
              else wrong;
          end;
        need[i]:=j;
        fillchar(t,sizeof(t),0);
        if j=10 then t[2]:=1 else t[1]:=j;
        mult(ans,t,maxn);
      end;
  end;

begin
  readln(s);
  k:=cut(s);
  change(s,x);
  work(x,k,ans);
  print(ans);
end.